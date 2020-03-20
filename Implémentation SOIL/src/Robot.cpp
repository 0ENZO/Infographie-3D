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
    // TORSE CYLINDRE
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(0,0,0);
        glColor3f(1,0,0);
        gluCylinder(params,2.5,2.5,3,30,5);
    glPopMatrix();

    //gluTorus
    //gluDisk

    /*
    glPushMatrix();
        // glRotatef(90,1,0,0);
        glTranslatef(0,-3,0);
        glColor3f(1,0,0);
        gluDisk(params,10,10,10,10);
    glPopMatrix();
    */

    glPushMatrix();
     glRotatef(90,1,0,0);
     // glTranslatef(0,3,-2.5);
     glTranslatef(0,0,0);
     glColor3f(0,1,0);
     //glutSolidTorus(0.15,1,10,25);
     glutSolidTorus(0.1,2.4,30,30);
    glPopMatrix();

}
