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
// DEBUT DU BUSTE

    // BUSTE

    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(0,0,0);
        glColor3f(0.86,0.86,0.86);
        gluCylinder(params,1.5,1.5,2,50,50);
    glPopMatrix();

    // HAUT DU BUSTE

   glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(0,0,0);
         glColor3f(0.5,0.5,0.5);
         glScalef(0.65,0.65,0.2);
         glutSolidTorus(1.15,1.15,50,50);
    glPopMatrix();

   glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(0,0,-0.1);
         glColor3f(0.86,0.86,0.86);
         glScalef(0.79,0.79,0.3);
         glutSolidTorus(0.8,1.15,50,50);
    glPopMatrix();

    //BAS DU BUSTE

    glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(0,0,2);
         glColor3f(0.86,0.86,0.86);
         glScalef(0.65,0.65,0.2);
         glutSolidTorus(1.15,1.15,30,30);
    glPopMatrix();

    Draw_handles();

    // Couche inférieur du buste
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(0,0,1);
        glColor3f(0,0,0);
        gluCylinder(params,1.55,1.55,1,30,10);
    glPopMatrix();

    //Rectangles décalés qui traverse le buste
    glPushMatrix();
        glColor3f (1,0.65,0);
        glRotatef(90,0,1,0);
        glTranslatef(1,-1,-1.55);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,0);
            glVertex3f (0.25,-0.9,0);
            glVertex3f (0,-0.9,0);
            glVertex3f (-0.25,0,0);
        glEnd();

    glPopMatrix();
        glPushMatrix();
        glColor3f (1,0.65,0);
        glRotatef(90,0,1,0);
        glTranslatef(0.5,-1,-1.55);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,0);
            glVertex3f (0.25,-0.9,0);
            glVertex3f (0,-0.9,0);
            glVertex3f (-0.25,0,0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f (1,0.65,0);
        glRotatef(90,0,1,0);
        glTranslatef(0,-1,-1.55);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,0);
            glVertex3f (0.25,-0.9,0);
            glVertex3f (0,-0.9,0);
            glVertex3f (-0.25,0,0);
        glEnd();
    glPopMatrix();

        glPushMatrix();
        glColor3f (1,0.65,0);
        glRotatef(90,0,1,0);
        glTranslatef(-0.5,-1,-1.55);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,0);
            glVertex3f (0.25,-0.9,0);
            glVertex3f (0,-0.9,0);
            glVertex3f (-0.25,0,0);
        glEnd();
    glPopMatrix();

        glPushMatrix();
        glColor3f (1,0.65,0);
        glRotatef(90,0,1,0);
        glTranslatef(-1,-1,-1.55);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,0);
            glVertex3f (0.25,-0.9,0);
            glVertex3f (0,-0.9,0);
            glVertex3f (-0.25,0,0);
        glEnd();
    glPopMatrix();

    // Cercle au milieu du buste
    glPushMatrix();
         glRotatef(90,0,1,0);
         glTranslatef(0,-1,-1.56);
         glColor3f(0,0,0);
         glScalef(0.5,0.5,0.1);
         glutSolidTorus(0.5,0.5,30,30);
    glPopMatrix();

    // Remplissage du cercle au milieu du buste
    glPushMatrix();
         glRotatef(90,0,1,0);
         glTranslatef(0,-1,-1.565);
         glColor3f(1,0.65,0);
         glScalef(0.45,0.45,0.1);
         glutSolidTorus(0.5,0.5,30,30);
    glPopMatrix();

// FIN DU BUSTE




// DEBUT BRAS

    int left_arm_x = 0;
    int left_arm_y = 0.5;
    int left_arm_z = 1.8;

     // BRAS GAUCHE

     // epaule
     glPushMatrix();
        glTranslatef(0,0.5,1.8);
        glColor3f(1,0,0);
        glutSolidSphere(0.75,20,20);
     glPopMatrix();

      //Anneau1
     glPushMatrix();
        glRotatef(130,1,0,0);
        glColor3f(0, 0, 0);
        glTranslatef(0,-1.8, 2.4);
        gluCylinder(params,0.32,0.32,0.1,16,16);
    glPopMatrix();

    //D�cos bras1

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0, -0.46, -3.2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.04,20,10);
    glPopMatrix();

    // first cylinder
     glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.2,left_arm_z);
        glColor3f(0.80, 0.80, 0.80);
        gluCylinder(params,0.15,0.15,0.5,20,5);
    glPopMatrix();

     //Anneau2
     glPushMatrix();
        glRotatef(130,1,0,0);
        glColor3f(0, 0, 0);
        glTranslatef(0,-1.8, 3.15);
        gluCylinder(params,0.32,0.32,0.1,16,16);
    glPopMatrix();

     //D�co bras 2
    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0, -1.09, -3.68);
        glRotated(180,1,0,0);
        glutSolidSphere(0.04,20,10);
    glPopMatrix();

    // second cylinder
    glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.2,left_arm_z+0.5);
        glColor3f(0.80, 0.80, 0.80);
        gluCylinder(params,0.16,0.25,0.5,20,5);
    glPopMatrix();

     // third cylinder
    glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.2,left_arm_z+1);
        glColor3f(1, 0, 0);
        gluCylinder(params,0.3,0.3,0.8,20,5);
    glPopMatrix();

    /* HAND */

    // finger 1
    glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.2,left_arm_z+2);
        glColor3f(0, 0, 1);
        glScalef(2, 2, 10);
        glutSolidCube(0.04);
    glPopMatrix();

    //finger 2
    glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.0,left_arm_z+2);
        glColor3f(0, 0, 1);
        glScalef(2, 2, 18);
        glutSolidCube(0.04);
    glPopMatrix();

    // finger 3
    glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.1,left_arm_z+2);
        glColor3f(0, 0, 1);
        glScalef(2, 2, 19);
        glutSolidCube(0.04);
    glPopMatrix();

    // finger 4
    glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.35,left_arm_z+2);
        glColor3f(0, 0, 1);
        glScalef(2, 2, 15);
        glutSolidCube(0.04);
    glPopMatrix();


    // BRAS DROIT

    int right_arm_x = 0;
    int right_arm_y = 0.5;
    int right_arm_z = -1.8;


    //epaule
    glPushMatrix();
        glTranslatef(0,0.5,-1.8);
        glColor3f(1,0,0);
        glutSolidSphere(0.75,20,20);
    glPopMatrix();

    //Anneau1
     glPushMatrix();
        glRotatef(60,1,0,0);
        glColor3f(0, 0, 0);
        glTranslatef(0,2.2, 2);
        gluCylinder(params,0.32,0.32,0.1,16,16);
    glPopMatrix();

     //D�cos bras1

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0, -0.47, 3.25);
        glRotated(180,1,0,0);
        glutSolidSphere(0.04,20,10);
    glPopMatrix();





    // first cylinder
     glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.8,right_arm_z+2.45);
        glColor3f(0.80, 0.80, 0.80);
        gluCylinder(params,0.15,0.15,0.5,20,5);
    glPopMatrix();


     //Anneau2
     glPushMatrix();
        glRotatef(60,1,0,0);
        glColor3f(0, 0, 0);
        glTranslatef(0,2.18, 2.79);
        gluCylinder(params,0.32,0.32,0.1,16,16);
    glPopMatrix();

    //D�co bras 2
    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0, -1.15, 3.65);
        glRotated(180,1,0,0);
        glutSolidSphere(0.04,20,10);
    glPopMatrix();


    // second cylinder
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.8,right_arm_z+2.95);
        glColor3f(0.80, 0.80, 0.80);
        gluCylinder(params,0.16,0.25,0.5,20,5);
    glPopMatrix();

     // third cylinder
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.8,right_arm_z+3.45);
        glColor3f(1, 0, 0);
        gluCylinder(params,0.3,0.3,0.8,20,5);
    glPopMatrix();

    /* HAND */

    // finger 1
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.8,right_arm_z+4.40);
        glColor3f(0, 0, 1);
        glScalef(2, 2, 10);
        glutSolidCube(0.04);
    glPopMatrix();

    //finger 2
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.9,right_arm_z+4.40);
        glColor3f(0, 0, 1);
        glScalef(2, 2, 18);
        glutSolidCube(0.04);
    glPopMatrix();

    // finger 3
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.7,right_arm_z+4.40);
        glColor3f(0, 0, 1);
        glScalef(2, 2, 19);
        glutSolidCube(0.04);
    glPopMatrix();

    // finger 4
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x+0.2,right_arm_y-1.7,right_arm_z+4.40);
        glColor3f(0, 0, 1);
        glScalef(2, 2, 15);
        glutSolidCube(0.04);
    glPopMatrix();
// FIN BRAS

// DEBUT JAMBE

    /* JAMBE DROITE */
    glPushMatrix();
        glRotatef(93,1,0,0);
        glTranslatef(0, -0.5, 3.5);
        glColor3f(0.95, 0.95, 0.95);
        glScalef(2, 2, 20);
        glutSolidCube(0.13);
    glPopMatrix();

    glPushMatrix();
        glRotatef(93,1,0,0);
        glTranslatef(0, -0.5, 4.9);
        glColor3f(1, 0, 0);
        glScalef(13, 8, 2);
        glutSolidCube(0.08);
    glPopMatrix();

    /* JAMBE GAUCHE */
    glPushMatrix();
        glRotatef(87,1,0,0);
        glTranslatef(0, 0.5, 3.5);
        glColor3f(0.95, 0.95, 0.95);
        glScalef(2, 2, 20);
        glutSolidCube(0.13);
    glPopMatrix();

    glPushMatrix();
        glRotatef(93,1,0,0);
        glTranslatef(0, 1, 4.9);
        glColor3f(1, 0, 0);
        glScalef(13, 8, 2);
        glutSolidCube(0.08);
    glPopMatrix();

// FIN JAMBE

     // EPAULE WITH SPHERE / GAUCHE

     // epaule

     glPushMatrix();
        glTranslatef(0,0.5,1.8);
        glColor3f(255,0,0);
        glutSolidSphere(0.75,20,20);
     glPopMatrix();

     // etoile

     glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0, 1.2, -2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0.25, 1, -2.25);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(-0.25, 1, -2.25);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0.25, 0.7, -2.43);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(-0.25, 0.7, -2.43);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0, 0.5, -2.5);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0.5, 0.8, -2.2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(-0.5, 0.8, -2.2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0.4, 0.3, -2.35);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(-0.4, 0.3, -2.35);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();



    //Anneau
     glPushMatrix();
        glRotatef(20,3,1,0);
        glColor3f(0, 0, 0);
        glTranslatef(0.2, -0.1, -2);
        gluCylinder(params,0.77,0.77,0.2,16,16);
    glPopMatrix();

     //D�cos �paules jaune

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0, 1.25, -1.56);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0, -0.23, -2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.4, 1.19, -1.65);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.4, 1.15, -1.57);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.4, -0.10, -2.1);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.4, -0.1, -2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();


    glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.7,0.9 ,-1.8);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.7,0.9,-1.65);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.76, 0.6, -1.9);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.76, 0.6, -1.75);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.6, 0.1, -2.05);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.6, 0.1, -1.9);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();


    glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.75,0.3 ,-2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.75,0.3 ,-1.85);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();





      // EPAULE WITH SPHERE / DROIT


     //epaule
     glPushMatrix();
        glTranslatef(0,0.5,-1.8);
        glColor3f(255,0,0);
        glutSolidSphere(0.75,20,20);
     glPopMatrix();

     //etoile

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0, 1.2, 2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0.25, 1, 2.25);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(-0.25, 1, 2.25);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0.25, 0.7, 2.43);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(-0.25, 0.7, 2.43);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0, 0.5, 2.5);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0.5, 0.8, 2.2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(-0.5, 0.8, 2.2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(0.4, 0.3, 2.35);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 1, 0);
        glTranslated(-0.4, 0.3, 2.35);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();


    /*glPushMatrix();
      glRotatef(-30,1,0,0);
      glTranslatef(0,0,4);
        glBegin(GL_LINES);
        glColor3f(1,1,0);
         glVertex2f(0, 0);
         glVertex2f(0, 1);
        glEnd();
      glPopMatrix();*/


     //Anneau
     glPushMatrix();
        glRotatef(-20,3,1,0);
        glColor3f(0, 0, 0);
        glTranslatef(0.2, -0.1, 1.8);
        gluCylinder(params,0.77,0.77,0.2,16,16);

    //D�cos �paules jaune

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0, 1.25, 1.55);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0, -0.23, 2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.4, 1.19, 1.65);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.4, 1.15, 1.57);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.4, -0.10, 2.1);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPopMatrix();
      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.4, -0.1, 2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();


    glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.7,0.9 ,1.8);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.7,0.9,1.65);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

      glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.76, 0.6, 1.9);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.76, 0.6, 1.7);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.6, 0.1, 2.05);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.6, 0.1, 1.9);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();


    glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(0.75,0.3 ,2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();

     glPushMatrix();
        glColor3f(1, 0.85, 0);
        glTranslated(-0.75,0.3 ,1.85);
        glRotated(180,1,0,0);
        glutSolidSphere(0.07,20,10);
    glPopMatrix();


// FIN BRAS

// DEBUT DOS

    gluQuadricTexture(params,GL_TRUE);
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(1,0,0);
        glColor3f(0, 0, 1);
        gluCylinder(params,1,1,2,20,10);
    glPopMatrix();


     glTranslatef(3, 0, 0);
    glColor3f(0.3, 0.3, 0.3);
    glRectf(0.3, 0.5, 0.5, 0.5);
/*
    glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen

   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  // End of drawing color-cube
    */



// FIN DOS



}

void Robot::Draw_handles()
{

    float handle_horizontal = 0.95;
    float handle_vertical = 0.15;
    float handle_depth = -1.25;

    float support_horizontal = -0.95;
    float support_vertical = -0.165;
    float difference_vertical = -0.2;
    float support_depth = -1.15;

    float i;
    float j;
    float sign = 1;

    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    // Poign�es en haut du buste

    // x: horizontal positif vers la gacuche
    // y: vertical negatif vers le bas
    // z: profondeur negatif devant
    for (j = 0; j < 2; j++) {

        if (j != 0){

            sign = -1;
            handle_horizontal = -1;
            support_horizontal = 1;

            handle_depth = -1.25;
            support_depth = -1.15;
        }

        for(i = 0; i < 3; i++){

            glPushMatrix();
                 glRotatef(90,0,1,0);
                 glTranslatef(support_horizontal - (sign*i*2*0.09), support_vertical,support_depth);
                 glColor3f(0.1,0.1,0.1);
                 glScalef(0.05,0.05,0.01);
                 glutSolidTorus(0.5,0.5,30,30);
            glPopMatrix();

            glPushMatrix();
                glRotatef(90,0,1,0);
                glTranslatef(support_horizontal - (sign*i*2*0.09), support_vertical,support_depth - 0.1);
                glColor3f(0.1,0.1,0.1);
                gluCylinder(params,0.025,0.025,0.10,15,5);
            glPopMatrix();

            glPushMatrix();
                 glRotatef(90,0,1,0);
                 glTranslatef(support_horizontal - (sign*i*2*0.09), support_vertical + difference_vertical,support_depth);
                 glColor3f(0.1,0.1,0.1);
                 glScalef(0.05,0.05,0.01);
                 glutSolidTorus(0.5,0.5,30,30);
            glPopMatrix();

            glPushMatrix();
                glRotatef(90,0,1,0);
                glTranslatef(support_horizontal - (sign*i*2*0.09), support_vertical + difference_vertical,support_depth - 0.1);
                glColor3f(0.1,0.1,0.1);
                gluCylinder(params,0.025,0.025,0.10,15,5);
            glPopMatrix();

            glPushMatrix();
                glRotatef(90,1,0,0);
                // z: plan vertical en n�gatif, on monte vers le haut
                // y: plan horizontal en positif vers la droite
                // x: profondeur en positif vers l'arri�re
                glTranslatef(handle_depth,handle_horizontal + (sign*i*2*0.09),handle_vertical);
                glColor3f(0.1,0.1,0.1);
                gluCylinder(params,0.025,0.025,0.2,15,5);
            glPopMatrix();


            handle_depth += 0.2;
            support_depth += 0.2;
        }
    }

}

