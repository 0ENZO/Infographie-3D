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
        void Draw();
        void Draw_torso();
        void Draw_custom_torso();
        void Draw_handles();
        void Draw_screws();
        void Draw_right_leg();
        void Draw_left_leg();
        void Draw_head();
        void Draw_back();
        void Draw_arms();
        void Draw_shoulders();
        void update_mov();

        float x;
        float y;
        float z;

        float test;
};

#endif


