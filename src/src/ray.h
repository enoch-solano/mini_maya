#ifndef RAY_H
#define RAY_H

#include <la.h>
#include "camera.h"
#include "mesh.h"

class Ray {
    glm::vec3 m_original, m_direction;

    float m_t;

    QListWidgetItem *mp_selected;

    void intersect(Vertex *v);
    void intersect(HalfEdge *v);
    void intersect(Face *v);

public:
    Ray(glm::vec3 original, glm::vec3 direction);
    Ray(Camera &c, int x, int y);

    QListWidgetItem *calculateIntersect(Mesh& mesh);
};



#endif // RAY_H
