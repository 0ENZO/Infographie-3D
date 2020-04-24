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
        void Draw_torso();
        void Draw_custom_torso();
        void Draw_handles();
        void Draw_screws();
        void Draw_right_leg();
        void Draw_left_leg();

        float x;
        float y;
        float z;
};

#endif


