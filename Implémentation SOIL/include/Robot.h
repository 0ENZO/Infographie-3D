#ifndef ROBOT_H
#define ROBOT_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "glut.h"
#include "SOIL.h"

class Robot
{
    public:
        Robot();
        Robot(float x, float y, float z);
        void Draw();

        float x;
        float y;
        float z;
};

#endif


