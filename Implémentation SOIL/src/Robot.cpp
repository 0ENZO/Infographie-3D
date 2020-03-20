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

    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);
    glPushMatrix();
        glRotatef(35,0,0,1);
        // glTranslatef(10,10,10);
        glColor3f(1,0,0);
        gluCylinder(params,3,3,3,30,5);
    glPopMatrix();

}
