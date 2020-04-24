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

void yellow_triangle_on_sword_back() {

    int i = 0;
    float z = -1.25;
    float height_triangle = 0.07;
    float length_triangle = 0.07;

    for(i = 0; i < 10; i++)
    {
        glPushMatrix();
        glRotatef(77, 1, 0, 0);
        glColor3f(0.80, 0.80, 0);
        glTranslatef(2.085,-0.5,z);

        glBegin(GL_QUADS);
            glVertex3f (0,0, 0); //top
            glVertex3f (0,length_triangle, height_triangle/2);// left
            glVertex3f (0, 0, height_triangle);// bottom
            glVertex3f (0, -length_triangle, height_triangle/2);// right
        glEnd();
        glPopMatrix();

        z += 0.10;
    }

}

void yellow_triangle_on_sword_front() {

    int i = 0;
    float z = -1.25;
    float height_triangle = 0.07;
    float length_triangle = 0.07;

    for(i = 0; i < 10; i++)
    {
        glPushMatrix();
        glRotatef(77, 1, 0, 0);
        glColor3f(0.80, 0.80, 0);
        glTranslatef(1.915,-0.5,z);

        glBegin(GL_QUADS);
            glVertex3f (0,0, 0); //top
            glVertex3f (0,length_triangle, height_triangle/2);// left
            glVertex3f (0, 0, height_triangle);// bottom
            glVertex3f (0, -length_triangle, height_triangle/2);// right
        glEnd();
        glPopMatrix();

        z += 0.10;
    }

}

void black_stripes_fabric_left() {

    float z = 0.05;
    int i = 0;

    for(i = 0; i < 13; i++)
    {
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glColor3f(0.1, 0.1, 0.1);
        glTranslatef(2.5,0.8,z);

        glBegin(GL_POLYGON);
            glVertex3f (0,0, 0.1); //bottom left
            glVertex3f (0,0,0);// top left
            glVertex3f (0, -0.6, 0);// top right
            glVertex3f (0, -0.6, 0.1);//bottom right
        glEnd();
        glPopMatrix();

        z = z + 0.15;
    }
}

void black_stripes_fabric_right() {

    float z = 0.05;
    int i = 0;

    for(i = 0; i < 13; i++)
    {
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glColor3f(0.1, 0.1, 0.1);
        glTranslatef(2.5,-0.2,z);

        glBegin(GL_POLYGON);
            glVertex3f (0,0, 0.1); //bottom left
            glVertex3f (0,0,0);// top left
            glVertex3f (0, -0.6, 0);// top right
            glVertex3f (0, -0.6, 0.1);//bottom right
        glEnd();
        glPopMatrix();

        z = z + 0.15;
    }
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
        glColor3f(1,1,1);
        gluCylinder(params,1.5,1.5,2,20,5);
    glPopMatrix();

Draw_handles();

    // Couche inf�rieur du buste
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(0,0,1);
        glColor3f(0,0,0);
        gluCylinder(params,1.55,1.55,1,30,10);
    glPopMatrix();

    //Rectangles d�cal�s qui traverse le buste
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

    // HAUT DU BUSTE

   glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(0,0,0);
         glColor3f(1,1,0);
         glScalef(0.65,0.65,0.2);
         glutSolidTorus(1.15,1.15,30,30);
    glPopMatrix();

    //BAS DU BUSTE

    glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(0,0,2);
         glColor3f(1,0,0);
         glScalef(0.65,0.65,0.2);
         glutSolidTorus(1.15,1.15,30,30);
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

    // pied
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

    // pied
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


    //COTE GAUCHE
        float length_quad = 0.6;

        // carre bleu
        glPushMatrix();
            glRotatef(90, 0, 1, 0);
            glColor3f(0, 0, 1);
            glTranslatef(-1, -1.2, 2.1); // z , y, x

            glBegin(GL_QUADS);
                glVertex3f (0,0, 0); //bottom left
                glVertex3f (0,0,-length_quad);// top left
                glVertex3f (0, length_quad, -length_quad);// top right
                glVertex3f (0, length_quad, 0);//bottom right
            glEnd();
        glPopMatrix();

        /* ROUAGES */



        // rouage gros 1
        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-0.3, -2, 1); // +y,+x,+z
            glColor3f(0.86,0.86,0.86);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.28,0.28,30,30);
        glPopMatrix();

        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-0.3, -2, 1.02); // +y,+x,+z
            glColor3f(0.2, 0.2, 0.2);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.2,0.2,30,30);
        glPopMatrix();

        // rouage gros 2
        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-1.5, -2, 1); // +y,+x,+z
            glColor3f(0.86,0.86,0.86);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.28,0.28,30,30);
        glPopMatrix();

        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-1.5, -2, 1.02); // +y,+x,+z
            glColor3f(0.2, 0.2, 0.2);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.2,0.2,30,30);
        glPopMatrix();

        // rouage petit 1
        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-0.7, -2.3, 1); // +y,+x,+z
            glColor3f(0.86,0.86,0.86);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.15,0.15,30,30);
        glPopMatrix();

        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-0.7, -2.3, 1.03); // +y,+x,+z
            glColor3f(0.2, 0.2, 0.2);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.1,0.1,30,30);
        glPopMatrix();

        // rouage petit 2
        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-1.05, -2.3, 1); // +y,+x,+z
            glColor3f(0.86,0.86,0.86);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.15,0.15,30,30);
        glPopMatrix();

        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-1.05, -2.3, 1.03); // +y,+x,+z
            glColor3f(0.2, 0.2, 0.2);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.1,0.1,30,30);
        glPopMatrix();


    /* ROUE GRISE GAUCHE */

    // roue grise gauche
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(2,0.5,0);
        glColor3f(0.60,0.60,0.60);
        gluCylinder(params,0.5,0.5,2,20,1);
    glPopMatrix();

        // haut de la roue gauche
    glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(2,0.5,0);
         glColor3f(0.60,0.60,0.60);
         glScalef(0.65,0.65,0.2);
         glutSolidTorus(0.38,0.38,30,30);
    glPopMatrix();

    // bas de la roue gauche
     glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(2,0.5,1.9);
         glColor3f(0.60,0.60,0.60);
         glScalef(0.65,0.65,0.2);
         glutSolidTorus(0.38,0.38,30,30);
    glPopMatrix();



    /* ROUE GRISE DROITE */

    // roue grise droite
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(2,-0.5,0);
        glColor3f(0.60,0.60,0.60);
        gluCylinder(params,0.5,0.5,2,20,1);
    glPopMatrix();

    // haut de la roue droite
    glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(2,-0.5,0);
         glColor3f(0.60,0.60,0.60);
         glScalef(0.65,0.65,0.2);
         glutSolidTorus(0.38,0.38,30,30);
    glPopMatrix();

    // bas de la roue droite
     glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(2,-0.5,1.9);
         glColor3f(0.60,0.60,0.60);
         glScalef(0.65,0.65,0.2);
         glutSolidTorus(0.38,0.38,30,30);
    glPopMatrix();


    black_stripes_fabric_left();
    black_stripes_fabric_right();

    /* EPEE */

    glPushMatrix();
        glRotatef(77,1,0,0);
        glTranslatef(2,-0.5,-0.5);
        glColor3f(1, 0, 0);
        glScalef(2, 2, 20);
        glutSolidCube(0.08);
    glPopMatrix();

    // haut de l'epee
    glPushMatrix();
         glRotatef(77,1,0,0);
         glTranslatef(2,-0.5,-1.32);
         glColor3f(0.80, 0.80, 0);
         glutSolidTorus(0.05,0.05,30,30);
    glPopMatrix();

    yellow_triangle_on_sword_back();
    yellow_triangle_on_sword_front();




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
                 glColor3f(0.41,0.41,0.41);
                 glScalef(0.05,0.05,0.01);
                 glutSolidTorus(0.5,0.5,30,30);
            glPopMatrix();

            glPushMatrix();
                glRotatef(90,0,1,0);
                glTranslatef(support_horizontal - (sign*i*2*0.09), support_vertical,support_depth - 0.1);
                glColor3f(0.41,0.41,0.41);
                gluCylinder(params,0.025,0.025,0.10,15,5);
            glPopMatrix();

            glPushMatrix();
                 glRotatef(90,0,1,0);
                 glTranslatef(support_horizontal - (sign*i*2*0.09), support_vertical + difference_vertical,support_depth);
                 glColor3f(0.41,0.41,0.41);
                 glScalef(0.05,0.05,0.01);
                 glutSolidTorus(0.5,0.5,30,30);
            glPopMatrix();

            glPushMatrix();
                glRotatef(90,0,1,0);
                glTranslatef(support_horizontal - (sign*i*2*0.09), support_vertical + difference_vertical,support_depth - 0.1);
                glColor3f(0.41,0.41,0.41);
                gluCylinder(params,0.025,0.025,0.10,15,5);
            glPopMatrix();

            glPushMatrix();
                glRotatef(90,1,0,0);
                // z: plan vertical en n�gatif, on monte vers le haut
                // y: plan horizontal en positif vers la droite
                // x: profondeur en positif vers l'arri�re
                glTranslatef(handle_depth,handle_horizontal + (sign*i*2*0.09),handle_vertical);
                glColor3f(0.41,0.41,0.41);
                gluCylinder(params,0.025,0.025,0.2,15,5);
            glPopMatrix();


            handle_depth += 0.2;
            support_depth += 0.2;
        }
    }

}

