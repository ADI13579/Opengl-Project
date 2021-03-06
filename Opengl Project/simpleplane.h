#pragma once
#include"coordinate.h"
#include<vector>
class simpleplane
{
public:
    simpleplane()
    {
        v.resize(3,0);
        vt.resize(3,0);
        vn.resize(3,0);
    }
    //To be taken from the .obj file
    //=================================
    std::vector<coordinate3f> v;//vertices of plane
    std::vector<coordinate3f> vt;//texture mapped to the above vertices if any
    std::vector<coordinate3f> vn;//avg unit normal of the vertices above
    //======================================
    //to be calculated
    //=====================================
    coordinate3f centroid;
    coordinate3f centroidNormal;
    //=====================================
    void makeCalculations();
    void scale(float x, float y, float z);
    void translate(coordinate3f shiftVector);
    void print();
};