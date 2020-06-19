#include "Robot.h"

Robot::Robot()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    test = 60.0f;
}

int increase = 0;
void Robot::update_mov()
{
    if(increase)
    {
        test += 1;

        if(test >= 60)
        {
            increase = 0;
        }

    }else {

        test -= 1;

        if(test <= 0)
        {
            increase = 1;
        }
    }
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

    Draw_arms();
    Draw_torso();
    Draw_handles();
    Draw_custom_torso();
    Draw_screws();
    Draw_right_leg();
    Draw_left_leg();
    Draw_head();
    Draw_back();
    Draw_shoulders();

}
/*
void update(int value){
    if (angle >= 360){
        angle = 0;
    } else {
        angle = angle + 0.2 ;
    }

    glutPostRedisplay();
    glutTimerFunc(1,update,0);
}

    glPushMatrix();
        glTranslatef(-1,0,0);
        glColor3f(0.5,0.5,0);
        glutWireSphere(0.5,10,10);
        glRotatef(angle,0,0,1);
        glTranslatef(1,0,0);
        glPushMatrix();
            glScalef(2,1,1);
            glColor3f(0.5,0.5,0);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
    */

void Robot::Draw_arms()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    // DEBUT BRAS
    float left_arm_x = 0;
    float left_arm_y = -0.4;
    float left_arm_z = 1.15;
    float angleArmLeft = 60.0;



     // BRAS GAUCHE

     glPopMatrix();

    //Decos bras1

    glPopMatrix();
      glPushMatrix();
        glColor3f(1,0.65,0);
        glTranslated(left_arm_x, left_arm_y - 0.45, left_arm_z + 1.8);
        glRotated(180,1,0,0);
        glutSolidSphere(0.04,20,10);
    glPopMatrix();


    //Deco bras 2
    glPopMatrix();
      glPushMatrix();
        glColor3f(1,0.65,0);
        glTranslated(left_arm_x, left_arm_y - 1.05, left_arm_z + 2.14);
        glRotated(180,1,0,0);
        glutSolidSphere(0.04,20,10);
    glPopMatrix();


     //Anneau1
     glPushMatrix();
        glRotatef(60,1,0,0);
        glColor3f(0, 0, 0);
        glTranslatef(left_arm_x,left_arm_y + 2.2, left_arm_z + 1);
        gluCylinder(params,0.32,0.32,0.1,16,16);
    glPopMatrix();

     //Anneau2
     glPushMatrix();
        glRotatef(60,1,0,0);
        glColor3f(0, 0, 0);
        glTranslatef(left_arm_x,left_arm_y + 2.2, left_arm_z + 1.70);
        gluCylinder(params,0.32,0.32,0.1,16,16);
    glPopMatrix();


    // first cylinder
     glPushMatrix();
        glTranslatef(left_arm_x,left_arm_y + 0.3,left_arm_z + 0.992);
        glRotatef(test, 1.0f, 0.0f, 0.0f);
        glColor3f(0.80, 0.80, 0.80);
        gluCylinder(params,0.15,0.15,0.5,20,5);
    glPopMatrix();


    // second cylinder
    glPushMatrix();

        glTranslatef(left_arm_x,left_arm_y + 0.3,left_arm_z + 0.992);
        glRotatef(test, 1.0f, 0.0f, 0.0f);

        glTranslatef(left_arm_x,left_arm_y + 0.4 ,left_arm_z - 0.6);
        glRotatef(test,1,0,0);

        glColor3f(0.80, 0.80, 0.80);
        gluCylinder(params,0.16,0.25,0.5,20,5);
    glPopMatrix();

    // anneau autour du bras
   glPushMatrix();

        glTranslatef(left_arm_x,left_arm_y + 0.3,left_arm_z + 0.992);
        glRotatef(test, 1.0f, 0.0f, 0.0f);

        glTranslatef(left_arm_x ,left_arm_y + 0.42,left_arm_z - 0.60);
        glRotatef(test,1,0,0);

        glColor3f(0,0,0);
        glScalef(0.1,0.1,0.02);
        glutSolidTorus(0.6,1.15,50,50);
    glPopMatrix();

     // third cylinder
    glPushMatrix();

        glTranslatef(left_arm_x,left_arm_y + 0.3,left_arm_z + 0.992);
        glRotatef(test, 1.0f, 0.0f, 0.0f);



        glTranslatef(left_arm_x,left_arm_y - 0.15,left_arm_z - 0.35);
         glRotatef(test,1,0,0);

        glColor3f(0.6,0,0);


        gluCylinder(params,0.3,0.3,0.8,20,5);
    glPopMatrix();

    /* HAND */

    // finger 1
    glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.2,left_arm_z+2);
        glColor3f(0,0,0.6);
        glScalef(2, 2, 10);
        glutSolidCube(0.04);
    glPopMatrix();

    //finger 2
    glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.0,left_arm_z+2);
        glColor3f(0,0,0.6);
        glScalef(2, 2, 18);
        glutSolidCube(0.04);
    glPopMatrix();

    // finger 3
    glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.1,left_arm_z+2);
        glColor3f(0,0,0.6);
        glScalef(2, 2, 19);
        glutSolidCube(0.04);
    glPopMatrix();

    // finger 4
    glPushMatrix();
        glRotatef(60,1,0,0);
        glTranslatef(left_arm_x,left_arm_y+2.35,left_arm_z+2);
        glColor3f(0,0,0.6);
        glScalef(2, 2, 15);
        glutSolidCube(0.04);
    glPopMatrix();



    glPopMatrix();




    // BRAS DROIT

    int right_arm_x = 0;
    int right_arm_y = 0.5;
    int right_arm_z = -1.8;


    //epaule



         //Anneau1
     glPushMatrix();
        glRotatef(130,1,0,0);
        glColor3f(0, 0, 0);
        glTranslatef(0,-1.8, 2.4);
        gluCylinder(params,0.32,0.32,0.1,16,16);
    glPopMatrix();





        //Decos bras1

    glPopMatrix();
      glPushMatrix();
        glColor3f(1,0.65,0);
        glTranslated(left_arm_x, -0.46, -3.2);
        glRotated(180,1,0,0);
        glutSolidSphere(0.04,20,10);
    glPopMatrix();

         //Deco bras 2
    glPopMatrix();
      glPushMatrix();
        glColor3f(1,0.65,0);
        glTranslated(0, -1.09, -3.68);
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
        glRotatef(130,1,0,0);
        glColor3f(0, 0, 0);
        glTranslatef(0,-1.8, 3.15);
        gluCylinder(params,0.32,0.32,0.1,16,16);
    glPopMatrix();



    // second cylinder
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.8,right_arm_z+2.95);
        glColor3f(0.80, 0.80, 0.80);
        gluCylinder(params,0.16,0.25,0.5,20,5);
    glPopMatrix();


    // anneau autour du bras
   glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.8,right_arm_z+2.95);
        glColor3f(0,0,0);
        glScalef(0.1,0.1,0.02);
        glutSolidTorus(0.6,1.15,50,50);
    glPopMatrix();

     // third cylinder
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.8,right_arm_z+3.45);
        glColor3f(0.6,0,0);
        gluCylinder(params,0.3,0.3,0.8,20,5);
    glPopMatrix();

    /* HAND */

    // finger 1
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.8,right_arm_z+4.40);
        glColor3f(0,0,0.6);
        glScalef(2, 2, 10);
        glutSolidCube(0.04);
    glPopMatrix();

    //finger 2
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.9,right_arm_z+4.40);
        glColor3f(0,0,0.6);
        glScalef(2, 2, 18);
        glutSolidCube(0.04);
    glPopMatrix();

    // finger 3
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x,right_arm_y-1.7,right_arm_z+4.40);
        glColor3f(0,0,0.6);
        glScalef(2, 2, 19);
        glutSolidCube(0.04);
    glPopMatrix();

    // finger 4
    glPushMatrix();
        glRotatef(130,1,0,0);
        glTranslatef(right_arm_x+0.2,right_arm_y-1.7,right_arm_z+4.40);
        glColor3f(0,0,0.6);
        glScalef(2, 2, 15);
        glutSolidCube(0.04);
    glPopMatrix();

// FIN BRAS
}

void Robot::Draw_torso()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    // BUSTE
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

    // Rebord sur le haut du buste
   glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(0,0,-0.1);
         glColor3f(0.86,0.86,0.86);
         glScalef(0.78,0.78,0.3);
         glutSolidTorus(0.8,1.15,50,50);
    glPopMatrix();

    //BAS DU BUSTE
    glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(0,0,2);
         glColor3f(0.6,0,0);
         glScalef(0.65,0.65,0.2);
         glutSolidTorus(1.15,1.15,30,30);
    glPopMatrix();

    // Rebord sur le bas du buste
   glPushMatrix();
         glRotatef(90,1,0,0);
         glTranslatef(0,0,1.9);
         glColor3f(0.86,0.86,0.86);
         glScalef(0.78,0.78,0.3);
         glutSolidTorus(0.8,1.15,50,50);
    glPopMatrix();

}

void Robot::Draw_custom_torso()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    // Couche inférieur du buste
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(0,0,1);
        glColor3f(0,0,0);
        gluCylinder(params,1.55,1.55,1,30,10);
    glPopMatrix();

    //Rectangles décalés qui traverse le buste
    /*
    glPushMatrix();
        glColor3f(1,0.65,0);
        glRotatef(90,0,1,0);
        glTranslatef(1,-1,-1.55);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,0);
            glVertex3f (0.25,-0.9,0);
            glVertex3f (0,-0.9,0);
            glVertex3f (-0.25,0,0);
        glEnd();
    glPopMatrix();
    */

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

    /*
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
    */

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

void Robot::Draw_screws()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    // x profondeur
    // y horizontale
    // z verticale

    int i;
    int j;
    int sign = 1;

    float outline_horizontal = 0;
    float outline_vertical = -0.35;
    float outline_depth = 1;

    float screw_horizontal = 0; // 0.3 - 0.6 puis -0.3 -0.6
    float screw_vertical = - 0.36;
    float screw_depth = 1;

    for(i = 0; i < 2; i++){

        if (i != 0){
            sign = -1;
            outline_horizontal = 0;
            screw_horizontal = 0;
        }

        for(j = 1; j < 3; j ++){
            glPushMatrix();
                 glRotatef(90,1,0,0);
                 glTranslatef(outline_depth,outline_horizontal + (sign*j*0.3),outline_vertical);
                 glColor3f(0.1,0.1,0.1);
                 glScalef(0.06,0.06,0.012);
                 glutSolidTorus(0.5,0.5,30,30);
            glPopMatrix();

            glPushMatrix();
                 glRotatef(90,1,0,0);
                 glTranslatef(screw_depth,screw_horizontal + (sign*j*0.3),screw_vertical);
                 glColor3f(0.75,0.75,0.75);
                 glScalef(0.057,0.057,0.0114);
                 glutSolidTorus(0.5,0.5,30,30);
            glPopMatrix();
        }
    }
}

void Robot::Draw_right_leg()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    // Jambe
    glPushMatrix();
        glRotatef(87,1,0,0);
        glTranslatef(0, 0.5, 3.15);
        // glColor3f(0.95, 0.95, 0.95);
        glColor3f(0,0,0);
        glScalef(2, 2, 20);
        glutSolidCube(0.13);
    glPopMatrix();

    // Devant pied
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(-0.6, 1, 5.1);
        glColor3f(0.6,0,0);
        //x : profondeur  / y : horizontal / z : vertical
        glScalef(5, 8, 2);
        glutSolidCube(0.08);
    glPopMatrix();

    // Dessous de pied bleu
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(-0.59, 1, 5.1);
        glColor3f(0,0,0.6);
        glScalef(4.9, 8.01, 1.9);
        glutSolidCube(0.08);
    glPopMatrix();

    //Diagonale
    glPushMatrix();
        glColor3f(0.6, 0, 0);
        glRotatef(95,0,1,0);
        glTranslatef(-1.2,-4.6,-1.5);
        glScalef(2.2,0.5,1);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,1.35);
            glVertex3f (0,-0.9,1);
            glVertex3f (0.25,-0.9,1);
            glVertex3f (0.25,0,1.35);
        glEnd();
    glPopMatrix();

    // Diagonale dessous de pied
    glPushMatrix();
        glColor3f(0,0,0.6);
        glRotatef(95,0,1,0);
        glTranslatef(-1.2,-4.7,-1.485);
        glScalef(2.2,0.5,1);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,1.35);
            glVertex3f (0,-0.9,1);
            glVertex3f (0.25,-0.9,1);
            glVertex3f (0.25,0,1.35);
        glEnd();
    glPopMatrix();

    // cylindre milieu pied
    glPushMatrix();
        glTranslatef(0,-4.5,0.65);
        glColor3f(0.6,0,0);
        gluCylinder(params,0.1,0.1,0.5,20,20);
    glPopMatrix();

    // surcouche en bleu
    glPushMatrix();
        glTranslatef(0,-4.5,0.65);
        glColor3f(0,0,0.6);
        gluCylinder(params,0.105,0.105,0.15,20,20);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,-4.5,1);
        glColor3f(0,0,0.6);
        gluCylinder(params,0.105,0.105,0.15,20,20);
    glPopMatrix();

    // côtés du cylindre
    glPushMatrix();
         glTranslatef(0,-4.5,1.15);
         glColor3f(0.6, 0, 0);
         glScalef(0.1,0.1,0.02);
         glutSolidTorus(0.5,0.5,30,30);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0,-4.5,0.65);
         glColor3f(0.6, 0, 0);
         glScalef(0.1,0.1,0.02);
         glutSolidTorus(0.5,0.5,30,30);
    glPopMatrix();

    // arriere pied
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(0.6, 1, 5.1);
        glColor3f(0.6,0,0);
        glScalef(5, 8, 2);
        glutSolidCube(0.08);
    glPopMatrix();

    // dessous du pied
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(0.59, 1, 5.1);
        glColor3f(0,0,0.6);
        glScalef(4.9, 8.01, 1.9);
        glutSolidCube(0.08);
    glPopMatrix();

    // diagonale
    glPushMatrix();
        glColor3f(0.6, 0, 0);
        glRotatef(95,0,1,0);
        glTranslatef(-1.2,-4.6,-1);
        glScalef(2.2,0.5,1);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,1);
            glVertex3f (0,-0.9,1.35);
            glVertex3f (0.25,-0.9,1.35);
            glVertex3f (0.25,0,1);
        glEnd();
    glPopMatrix();

    // diagonale dessous de pied
    glPushMatrix();
        glColor3f(0,0,0.6);
        glRotatef(95,0,1,0);
        glTranslatef(-1.2,-4.7,-1.015);
        glScalef(2.2,0.5,1);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,1);
            glVertex3f (0,-0.9,1.35);
            glVertex3f (0.25,-0.9,1.35);
            glVertex3f (0.25,0,1);
        glEnd();
    glPopMatrix();

}

void Robot::Draw_left_leg()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    // Jambe
    glPushMatrix();
        glRotatef(93,1,0,0);
        glTranslatef(0, -0.5, 3.15);
        //glColor3f(0.95, 0.95, 0.95);
        glColor3f(0,0,0);
        glScalef(2, 2, 20);
        glutSolidCube(0.13);
    glPopMatrix();

    // devant pied
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(-0.6, -1, 5.1);
        glColor3f(0.6,0,0);
        //x : profondeur  / y : horizontal / z : vertical
        glScalef(5, 8, 2);
        glutSolidCube(0.08);
    glPopMatrix();

    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(-0.59, -1, 5.1);
        glColor3f(0,0,0.6);
        glScalef(4.9, 8.01, 1.9);
        glutSolidCube(0.08);
    glPopMatrix();

    // diagonale
    glPushMatrix();
        glColor3f(0.6, 0, 0);
        glRotatef(90,0,1,0);
        glTranslatef(0.75,-4.6,-1.5);
        glScalef(2.2,0.5,1);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,1.35);
            glVertex3f (0,-0.9,1);
            glVertex3f (0.25,-0.9,1);
            glVertex3f (0.25,0,1.35);
        glEnd();
    glPopMatrix();

    //diagonale dessous
    glPushMatrix();
        glColor3f(0,0,0.6);
        glRotatef(90,0,1,0);
        glTranslatef(0.75,-4.7,-1.485);
        glScalef(2.2,0.5,1);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,1.35);
            glVertex3f (0,-0.9,1);
            glVertex3f (0.25,-0.9,1);
            glVertex3f (0.25,0,1.35);
        glEnd();
    glPopMatrix();

    // cylindre milieu pied

    glPushMatrix();
        glTranslatef(0,-4.5,-1.3);
        glColor3f(0.6,0,0);
        gluCylinder(params,0.1,0.1,0.5,20,20);
    glPopMatrix();

    // surcouche en bleu
    glPushMatrix();
        glTranslatef(0,-4.5,-1.3);
        glColor3f(0,0,0.6);
        gluCylinder(params,0.105,0.105,0.15,20,20);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,-4.5,-0.95);
        glColor3f(0,0,0.6);
        gluCylinder(params,0.105,0.105,0.15,20,20);
    glPopMatrix();

    // côtés du cylindre
    glPushMatrix();
         glTranslatef(0,-4.5,-1);
         glColor3f(0.6, 0, 0);
         glScalef(0.1,0.1,0.02);
         glutSolidTorus(0.5,0.5,30,30);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0,-4.5,-1.3);
         glColor3f(0.6, 0, 0);
         glScalef(0.1,0.1,0.02);
         glutSolidTorus(0.5,0.5,30,30);
    glPopMatrix();

    // fin cylindre

    // arriere pied
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(0.6, -1, 5.1);
        glColor3f(0.6,0,0);
        glScalef(5, 8, 2);
        glutSolidCube(0.08);
    glPopMatrix();

    // dessous du pied
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(0.59, -1, 5.1);
        glColor3f(0,0,0.6);
        glScalef(4.9, 8.01, 1.9);
        glutSolidCube(0.08);
    glPopMatrix();

    // diagonale
    glPushMatrix();
        glColor3f(0.6, 0, 0);
        glRotatef(90,0,1,0);
        glTranslatef(0.75,-4.6,-1);
        glScalef(2.2,0.5,1);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,1);
            glVertex3f (0,-0.9,1.35);
            glVertex3f (0.25,-0.9,1.35);
            glVertex3f (0.25,0,1);
        glEnd();
    glPopMatrix();

    // dessous diagonale
    glPushMatrix();
        glColor3f(0,0,0.6);
        glRotatef(90,0,1,0);
        glTranslatef(0.75,-4.7,-1.015);
        glScalef(2.2,0.5,1);
        glBegin(GL_POLYGON);
            glVertex3f (0,0,1);
            glVertex3f (0,-0.9,1.35);
            glVertex3f (0.25,-0.9,1.35);
            glVertex3f (0.25,0,1);
        glEnd();
    glPopMatrix();

}

void Robot::Draw_head()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

     //Visage
    glPushMatrix();
         glRotatef(0,0,0,0);
         glTranslatef(0,0.6,0);
         glColor3f(0.95,0.95,0.95);
         glutSolidSphere(0.6,5,5);
    glPopMatrix();

    //Oreille droite
    glPushMatrix();
         glRotatef(0,0,0,0);
         glTranslatef(0.1,0.75,-0.3);
         glColor3f(1,0.65,0);
         glutSolidSphere(0.3,20,20);
    glPopMatrix();

    //Oreille gauche
    glPushMatrix();
         glRotatef(0,0,0,0);
         glTranslatef(0.1,0.75,0.3);
         glColor3f(1,0.65,0);
         glutSolidSphere(0.3,20,20);
    glPopMatrix();

    //Cheveux
    glPushMatrix();
         glRotatef(0,0,0,0);
         glTranslatef(0.05,0.6,0);
         glColor3f(0.2,0.64,0.76);
         glutSolidSphere(0.6,5,5);
    glPopMatrix();

    //Corne
    glPushMatrix();
        glRotatef(90,1,1,-0.5);
        glTranslatef(0,0.38,-1.9);
        glColor3f(0.29,0.3,0.32);
        gluCylinder(params,0,0.26,0.9,10,1);
    glPopMatrix();

    /* Cercles autour de la corne */

    // y : positif sur la droite
    // x :negatif devant
    // z : negatif vers le haut

    // très petit
   glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(-0.45,-0.02,-1.7);
        glColor3f(0.835,0.85,0.827);
        glScalef(0.0525,0.0525,0.02);
        glutSolidTorus(0.2,1.15,50,50);
    glPopMatrix();

    // petit
   glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(-0.375,-0.02,-1.55);
        glColor3f(0.835,0.85,0.827);
        glScalef(0.1,0.1,0.01);
        glutSolidTorus(0.2,1.15,50,50);
    glPopMatrix();

    // moyen
   glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(-0.315,0,-1.4);
        glColor3f(0.835,0.85,0.827);
        glScalef(0.15,0.15,0.01);
        glutSolidTorus(0.2,1.15,50,50);
    glPopMatrix();

    // grand
   glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(-0.22,0.025,-1.25);
        glColor3f(0.835,0.85,0.827);
        glScalef(0.185,0.185,0.01);
        glutSolidTorus(0.2,1.15,50,50);
    glPopMatrix();

    //Yeux
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(-0.35,0.15,-0.9);
        glColor3f(1, 1, 0);
        gluCylinder(params,0.12,0.12,0.06,5,1);
    glPopMatrix();

    //Yeux
    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(-0.35,-0.15,-0.9);
        glColor3f(1, 1, 0);
        gluCylinder(params,0.12,0.12,0.06,5,1);
    glPopMatrix();

    //Menton
    glPushMatrix();
         glRotatef(90,0,1,0);
         glColor3f(0.92,0.92, 0.92);
         glTranslatef(0.2,0.15,-0.45);
         glBegin(GL_TRIANGLES);
         glVertex2f(0.2, 0.0);
         glVertex2f(-0.2, 0.0);
         glVertex2f(0.05, 0.3);
         glEnd();
    glPopMatrix();

     glPushMatrix();
         glRotatef(90,0,1,0);
         glColor3f(0.92, 0.92, 0.92);
         glTranslatef(0.1,0.15,-0.45);
         glBegin(GL_TRIANGLES);
         glVertex2f(0.2, 0.0);
         glVertex2f(-0.2, 0.0);
         glVertex2f(0.05, 0.3);
         glEnd();
    glPopMatrix();

     glPushMatrix();
         glRotatef(90,0,1,0);
         glColor3f(0.92, 0.92, 0.92);
         glTranslatef(-0.25,0.15,-0.45);
         glBegin(GL_TRIANGLES);
         glVertex2f(0.2, 0.0);
         glVertex2f(-0.2, 0.0);
         glVertex2f(0.05, 0.3);
         glEnd();
    glPopMatrix();

     glPushMatrix();
         glRotatef(90,0,1,0);
         glColor3f(0.92, 0.92, 0.92);
         glTranslatef(-0.35,0.15,-0.45);
         glBegin(GL_TRIANGLES);
         glVertex2f(0.2, 0.0);
         glVertex2f(-0.2, 0.0);
         glVertex2f(0.05, 0.3);
         glEnd();
    glPopMatrix();

     //Bouche
     glPushMatrix();
        glRotatef(90,1,0,0);
        glColor3f(0, 0, 0);
        glTranslatef(-0.05, 0, -0.6);
        gluCylinder(params,0.56,0.56,0.01,12,12);
    glPopMatrix();

    //Nez
    glPushMatrix();
        glRotatef(0,0,0,0);
        glTranslatef(-0.5,0.78,0);
        glColor3f(0.6, 0.6, 0.6);
        gluCylinder(params,0.1,0.1,0.06,5,1);
    glPopMatrix();
}

void Robot::Draw_back()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricTexture(params,GL_TRUE);

    glPushMatrix();
        glRotatef(90,1,0,0);
        glTranslatef(1,0,0);
        glColor3f(0, 0,0.6);
        gluCylinder(params,1,1,2,20,10);
    glPopMatrix();


    //COTE GAUCHE
        float length_quad = 0.6;

        // carre bleu
        glPushMatrix();
            glRotatef(90, 0, 1, 0);
            glColor3f(0,0,0.6);
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

    // carre bleu
    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glColor3f(0,0,0.6);
        glTranslatef(1, -1.2, 2.1); // z , y, x // 2,-0.5,0

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
            glTranslatef(-0.3, -2, -1); // +y,+x,+z
            glColor3f(0.86,0.86,0.86);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.28,0.28,30,30);
        glPopMatrix();

        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-0.3, -2, -1.02); // +y,+x,+z
            glColor3f(0.2, 0.2, 0.2);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.2,0.2,30,30);
        glPopMatrix();

        // rouage gros 2
        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-1.5, -2, -1); // +y,+x,+z
            glColor3f(0.86,0.86,0.86);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.28,0.28,30,30);
        glPopMatrix();

        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-1.5, -2, -1.02); // +y,+x,+z
            glColor3f(0.2, 0.2, 0.2);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.2,0.2,30,30);
        glPopMatrix();

        // rouage petit 1
        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-0.7, -2.3, -1); // +y,+x,+z
            glColor3f(0.86,0.86,0.86);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.15,0.15,30,30);
        glPopMatrix();

        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-0.7, -2.3, -1.02); // +y,+x,+z
            glColor3f(0.2, 0.2, 0.2);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.1,0.1,30,30);
        glPopMatrix();

        // rouage petit 2
        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-1.05, -2.3, -1); // +y,+x,+z
            glColor3f(0.86,0.86,0.86);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.15,0.15,30,30);
        glPopMatrix();

        glPushMatrix();
            glRotatef(90,0,0,1);
            glTranslatef(-1.05, -2.3, -1.02); // +y,+x,+z
            glColor3f(0.2, 0.2, 0.2);
            glScalef(0.5,0.5,0.1);
            glutSolidTorus(0.1,0.1,30,30);
        glPopMatrix();


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

}

void Robot::Draw_shoulders()

{
      GLUquadric* params = gluNewQuadric();
      gluQuadricTexture(params,GL_TRUE);


// EPAULE WITH SPHERE / GAUCHE

// epaule

 glPushMatrix();
    glTranslatef(0,0.5,1.8);
    glColor3f(255,0,0);
    glRotated(test,1,1,1);
    glutSolidSphere(0.75,20,20);

 glPopMatrix();

//Anneau
 glPushMatrix();
    glRotatef(20,3,1,0);
    glColor3f(0, 0, 0);
    glTranslatef(0.2, -0.1, -2);
    gluCylinder(params,0.77,0.77,0.2,16,16);
glPopMatrix();

//Deco épaules jaune
//Boule haut

x = 0;
y = 1.25;
z = -1.56;
int i;
for(i=0; i<3; i++){
glPopMatrix();
  glPushMatrix();
    glColor3f(1,0.65,0);
    glTranslated(x, y, z);
    glutSolidSphere(0.07,20,10);
glPopMatrix();
x = x + 0.35;
y = y - 0.2;
z = z - 0.1;
}

x = 0;
y = -0.17;
z = -2.1;

for(i=0; i<3; i++){
glPopMatrix();
  glPushMatrix();
    glColor3f(1,0.65,0);
    glTranslated(x, y, z);
    glutSolidSphere(0.07,20,10);
glPopMatrix();
x = x + 0.35;
y = y + 0.17;
z = z + 0.05;

}

x = 0;
y = 1.25;
z = -1.56;

for(i=0; i<3; i++){
glPopMatrix();
  glPushMatrix();
    glColor3f(1,0.65,0);
    glTranslated(x, y, z);
    glutSolidSphere(0.07,20,10);
glPopMatrix();
x = x - 0.35;
y = y - 0.2;
z = z - 0.05;
}

x = 0;
y = -0.17;
z = -2.1;

 for(i=0; i<3; i++){
glPopMatrix();
  glPushMatrix();
    glColor3f(1,0.65,0);
    glTranslated(x, y, z);
    glutSolidSphere(0.07,20,10);
glPopMatrix();
x = x - 0.35;
y = y + 0.17;
z = z + 0.09;

}





  // EPAULE WITH SPHERE / DROIT


 //epaule
 glPushMatrix();
    glTranslatef(0,0.5,-1.8);
    glColor3f(255,0,0);
    //glRotated(a,0,0,1);
    glutSolidSphere(0.75,20,20);
 glPopMatrix();



 //Anneau
 glPushMatrix();
    glRotatef(-20,3,1,0);
    glColor3f(0, 0, 0);
    glTranslatef(0.2, -0.1, 1.8);
    gluCylinder(params,0.77,0.77,0.2,16,16);

//D�cos �paules jaune

x = 0;
y = 1.25;
z = 1.55;


for(i=0; i<3; i++){
glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.65,0);
    glTranslated(x, y, z);
    glutSolidSphere(0.07,20,10);
glPopMatrix();
x = x + 0.35;
y = y - 0.2;
z = z + 0.15;

}

x = 0;
y = -0.23;
z = 2;

for(i=0; i<3; i++){
glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.65,0);
    glTranslated(x, y, z);
    glutSolidSphere(0.07,20,10);
glPopMatrix();
x = x + 0.33;
y = y + 0.2;
z = z + 0.02;

}

x = 0;
y = -0.23;
z = 2;

for(i=0; i<3; i++){
glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.65,0);
    glTranslated(x, y, z);
    glutSolidSphere(0.07,20,10);
glPopMatrix();
x = x - 0.33;
y = y + 0.2;
z = z - 0.05;
}

x = 0;
y = 1.25;
z = 1.55;

for(i=0; i<3; i++){
glPopMatrix();
    glPushMatrix();
    glColor3f(1,0.65,0);
    glTranslated(x, y, z);
    glutSolidSphere(0.07,20,10);
glPopMatrix();
x = x - 0.35;
y = y - 0.2;
z = z + 0.05;

}
}

// FIN BRAS

