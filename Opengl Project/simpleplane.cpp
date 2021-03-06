#include"simpleplane.h"

//calculates the values requires unaviable from the obj files
void simpleplane::makeCalculations()
{
    if (v.empty())
        return;

    centroid = (v[0] + v[1] + v[2]) / 3;
    centroidNormal = !((centroid - v[0]) * (centroid - v[1]));
    if ((vn[0] ^ centroidNormal) <= 0)
        centroidNormal = centroidNormal * -1;
}

//sorts the vertices and their relative properties on the basis of y in ascending order

//scale the plane
void simpleplane::scale(float x, float y, float z)
{
    for (int i = 0; i < v.size(); i++)
        v[i] = v[i].scaling(x, y, z);
}

void simpleplane::translate(coordinate3f shiftVector)
{
    for (int i = 0; i < v.size(); i++)
        v[i] = v[i] + shiftVector;
}


void simpleplane::print()
{
    std::cout << "Vertices" << std::endl;
    for (auto i : v)
        i.print();
    std::cout << "Vertex Texture" << std::endl;
    for (auto i : vt)
        i.print();
    std::cout << "Vertex Normal(avg)" << std::endl;
    for (auto i : vn)
        i.print();
    std::cout << "Vertex Normal" << std::endl;
    std::cout << "Centroid:"; centroid.print();
    std::cout << "Centroid Normal:"; centroidNormal.print();
}