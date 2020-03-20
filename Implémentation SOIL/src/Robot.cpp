#include "Robot.h"

Robot::Robot()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Robot::Robot(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Robot::Draw()
{
    glPushMatrix();
        glScalef(2,1,1);
        glColor3f(0.5,0.5,0);
        glutWireCube(1.0);
    glPopMatrix();
}
