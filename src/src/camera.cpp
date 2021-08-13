#include "camera.h"

#include <la.h>
#include <iostream>

Camera::Camera():
    Camera(400, 400)
{
    look = glm::vec3(0,0,-1);
    up = glm::vec3(0,1,0);
    right = glm::vec3(1,0,0);
}

Camera::Camera(unsigned int w, unsigned int h):
    Camera(w, h, glm::vec3(0,0,10), glm::vec3(0,0,0), glm::vec3(0,1,0))
{}

Camera::Camera(unsigned int w, unsigned int h, const glm::vec3 &e, const glm::vec3 &r, const glm::vec3 &worldUp):
    fovy(45),
    width(w),
    height(h),
    near_clip(0.1f),
    far_clip(1000),
    eye(e),
    ref(r),
  #ifdef SPHERICAL_CAMERA
      unit_eye(glm::vec4(e, 1)),
      unit_forward(0, 0, 1, 0),
      unit_up(0, 1, 0, 0),
      unit_right(1, 0, 0, 0),
      theta(0.0),
      phi(0.0),
      zoom(0.0),
  #endif
    world_up(worldUp)
{

    RecomputeAttributes();
}

Camera::Camera(const Camera &c):
    fovy(c.fovy),
    width(c.width),
    height(c.height),
    near_clip(c.near_clip),
    far_clip(c.far_clip),
    aspect(c.aspect),
    eye(c.eye),
    ref(c.ref),
    look(c.look),
    up(c.up),
    right(c.right),
    world_up(c.world_up),
    V(c.V),
    H(c.H)
{}


void Camera::RecomputeAttributes()
{
#ifdef SPHERICAL_CAMERA
    glm::mat4 trans = glm::rotate(glm::mat4(1.0f), glm::radians(theta), glm::vec3(0, 1, 0))
            * glm::rotate(glm::mat4(1.0f), glm::radians(phi), glm::vec3(1, 0, 0))
            * glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -zoom));
    eye = glm::vec3(trans * unit_eye) + ref;

    // set reference
    look = glm::vec3(trans * unit_forward);
    right = glm::vec3(trans * unit_right);
    up = glm::vec3(trans * unit_up);
#else
    look = glm::normalize(ref - eye);
    right = glm::normalize(glm::cross(look, world_up));
    up = glm::cross(right, look);
#endif

    float tan_fovy = tan(glm::radians(fovy/2));
    float len = glm::length(ref - eye);
    aspect = (float)width/height;
    V = up*len*tan_fovy;
    H = right*len*aspect*tan_fovy;
}

glm::mat4 Camera::getViewProj()
{
    return glm::perspective(glm::radians(fovy), width / (float)height, near_clip, far_clip) * glm::lookAt(eye, ref, up);
}

void Camera::RotateAboutUp(float deg)
{
#ifdef SPHERICAL_CAMERA
    theta += deg;
#else
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(deg), up);
    ref = ref - eye;
    ref = glm::vec3(rotation * glm::vec4(ref, 1));
    ref = ref + eye;
#endif
    RecomputeAttributes();
}
void Camera::RotateAboutRight(float deg)
{
#ifdef SPHERICAL_CAMERA
    phi += deg;
#else
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(deg), right);
    ref = ref - eye;
    ref = glm::vec3(rotation * glm::vec4(ref, 1));
    ref = ref + eye;
#endif
    RecomputeAttributes();
}

void Camera::TranslateAlongLook(float amt)
{
    glm::vec3 translation = look * amt;
#ifdef SPHERICAL_CAMERA
    zoom += amt;
#else
    eye += translation;
    ref += translation;
#endif
}

void Camera::TranslateAlongRight(float amt)
{
    glm::vec3 translation = right * amt;
    eye += translation;
    ref += translation;
}
void Camera::TranslateAlongUp(float amt)
{
    glm::vec3 translation = up * amt;
    eye += translation;
    ref += translation;
}
