#include "ray.h"

Ray::Ray(glm::vec3 original, glm::vec3 direction)
    :m_original(original), m_direction(direction)
{}

Ray::Ray(Camera &c, int x, int y)
{
    m_original = c.eye;
    m_direction = c.ref - c.eye;
    m_direction += c.H * float(2.0 * x / c.width - 1.0)
            + c.V * float(1.0 - 2.0 * y / c.height);
    m_direction = glm::normalize(m_direction);
}

QListWidgetItem *Ray::calculateIntersect(Mesh &mesh)
{
    m_t = 10000; // set t to a large number
    mp_selected = nullptr;

    for (int i = 0; i < mesh.m_faces.size(); i++) {
        intersect(mesh.m_faces[i]);
    }

    m_t += 0.1; // change the t value here too make the following items more easily be selected

    for(int i = 0; i < mesh.m_edges.size(); i++) {
        intersect(mesh.m_edges[i]);
    }

    m_t += 0.1; // change the t value here too make the following items more easily be selected

    for(int i = 0; i < mesh.m_verts.size(); i++) {
        intersect(mesh.m_verts[i]);
    }

    return mp_selected;
}
// =======================================================
// Ray-Sphere intersection
// =======================================================

// https://groups.csail.mit.edu/graphics/classes/6.837/F04/lectures/02_RayCasting_II.pdf
// http://www.iquilezles.org/www/articles/intersectors/intersectors.htm

// sphere of size ra centered at point ce
float sphIntersect( glm::vec3 ro, glm::vec3 rd, glm::vec3 ce, float ra )
{
    glm::vec3 oc = ro - ce;
    float b = glm::dot(oc, rd);
    float c = glm::dot(oc, oc) - ra*ra;
    float h = b*b - c;
    if (h < 0.0)
    {
        return -1.0; // no intersection
    }
    h = std::sqrt(h);
    return -b-h;
}

void Ray::intersect(Vertex *v)
{
    float radius = 0.1;
    float tempt = sphIntersect(m_original, m_direction, v->m_pos, radius);
    if (tempt > 0 && tempt < m_t)
    {
        m_t = tempt;
        mp_selected = static_cast<QListWidgetItem*>(v);
    }
}

// =======================================================
// Ray-Capsule intersection
// =======================================================

// intersect capsule : http://www.iquilezles.org/www/articles/intersectors/intersectors.htm

float capIntersect(glm::vec3 ro, glm::vec3 rd, glm::vec3 pa, glm::vec3 pb, float r)
{
    glm::vec3 ba = pb - pa;
    glm::vec3 oa = ro - pa;

    float baba = glm::dot(ba,ba);
    float bard = glm::dot(ba,rd);
    float baoa = glm::dot(ba,oa);
    float rdoa = glm::dot(rd,oa);
    float oaoa = glm::dot(oa,oa);

    float a = baba      - bard*bard;
    float b = baba*rdoa - baoa*bard;
    float c = baba*oaoa - baoa*baoa - r*r*baba;
    float h = b*b - a*c;
    if( h>=0.0 )
    {
        float t = (-b-std::sqrt(h))/a;

        float y = baoa + t * bard;

        // body
        if( y>0.0 && y<baba ) return t;

        // caps
        glm::vec3 oc = (y<=0.0) ? oa : ro - pb;
        b = glm::dot(rd,oc);
        c = glm::dot(oc,oc) - r*r;
        h = b*b - c;
        if( h>0.0 )
        {
            return -b - sqrt(h);
        }
    }
    return -1.0;
}

void Ray::intersect(HalfEdge *v)
{
    float radius = 0.1;
    float tempt = capIntersect(m_original, m_direction, v->mp_vert->m_pos,
                               v->mp_sym->mp_vert->m_pos, radius);
    if(tempt > 0 && tempt < m_t)
    {
        m_t = tempt;
        mp_selected = static_cast<QListWidgetItem*>(v);
    }
}

// =======================================================
// Ray-Triangle intersection
// =======================================================

// http://www.iquilezles.org/www/articles/intersectors/intersectors.htm
// triangle degined by vertices v0, v1 and v2
float triIntersect(glm::vec3 ro, glm::vec3 rd, glm::vec3 v0, glm::vec3 v1, glm::vec3 v2 )
{
    glm::vec3 v1v0 = v1 - v0;
    glm::vec3 v2v0 = v2 - v0;
    glm::vec3 rov0 = ro - v0;
    glm::vec3 n = glm::cross(v1v0, v2v0);
    glm::vec3 q = glm::cross(rov0, rd);
    float d = 1.0/glm::dot( rd, n );
    float u = d*glm::dot( -q, v2v0 );
    float v = d*glm::dot(  q, v1v0 );
    float t = d*glm::dot( -n, rov0 );
    if( u<0.0 || u>1.0 || v<0.0 || (u+v)>1.0 ) t = -1.0;
    return t;
}

void Ray::intersect(Face *v)
{
    std::vector<glm::vec3> pos;
    HalfEdge *currentedge = v->mp_edge;
    do
    {
        pos.push_back(currentedge->mp_vert->m_pos);
        currentedge = currentedge->mp_next;
    }
    while(currentedge != v->mp_edge);

    int numvertics = pos.size();
    for(int i = 0; i < numvertics; i++)
    {
        int index0 = (i) % numvertics;
        int index1 = (i + 1) % numvertics;
        int index2 = (i + 2) % numvertics;

        float tempt = triIntersect(m_original, m_direction, pos[index0],
                                   pos[index1], pos[index2]);
        if(tempt > 0 && tempt < m_t)
        {
            m_t = tempt;
            mp_selected = static_cast<QListWidgetItem*>(v);
            return;
        }
    }
}
