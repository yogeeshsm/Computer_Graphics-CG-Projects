#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
int thet=0;
 double winHt=10.0;
 void  leaf()
{
glPushMatrix();
glScaled(0.5,0.5,0.5);
glTranslated(0,0,0);
glRotated(45,0,0,1);
glutSolidCube(1);
glPopMatrix();
glPushMatrix();

glScaled(0.5,0.5,0.5);
glTranslated(0.0,-0.5,0);
glutSolidCube(1);
glPopMatrix();

}
void leafseries()
{
glPushMatrix();
glScaled(0.25,0.35,0.05);
for(float i=0;i<4.8;i+=0.8)
{
glPushMatrix();

glTranslated(i,0.0,0);
leaf();
glPopMatrix();
}
glPopMatrix();
}
void drawtop()
{
glPushMatrix();
glTranslated(0.25,-0.0,0.0);
glScaled(3.5,1.5,0.5);
glutSolidCube(0.2);
glPopMatrix();

}
void octtop()
{
glPushMatrix();
glScaled(2,2,2);
glRotated(90,0,1,0);
glTranslated(0.55,0.0,1.05);
drawtop();

glTranslated(0.0,0.25,-0.0);
glScaled(0.5,0.75,2);
leafseries();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(90,0,1,0);
glTranslated(0.55,0.0,-0.53);
drawtop();
glTranslated(0.0,0.25,-0.0);
glScaled(0.5,0.75,2);
leafseries();
glPopMatrix();

glPushMatrix();

glPushMatrix();
glScaled(2,2,2);
glTranslated(0.0,0,0);
drawtop();

glTranslated(0.0,0.25,-0.0);
glScaled(0.5,0.75,2);
leafseries();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(45,0,1,0);
glTranslated(0.5,0.0,0.4);
drawtop();

glTranslated(0.0,0.25,-0.0);
glScaled(0.5,0.75,2);
leafseries();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(315,0,1,0);
glTranslated(-0.63,0,0.05);
drawtop();

glTranslated(0.0,0.25,-0.0);
glScaled(0.5,0.75,2);
leafseries();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glRotated(180,0,1,0);
glTranslated(-1,0,3.1);

glPushMatrix();
glScaled(2,2,2);
glTranslated(0.0,0,0);
drawtop();

glTranslated(0.0,0.25,-0.0);
glScaled(0.5,0.75,2);
leafseries();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(45,0,1,0);
glTranslated(0.5,0.0,0.4);
drawtop();

glTranslated(0.0,0.25,-0.0);
glScaled(0.5,0.75,2);
leafseries();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(315,0,1,0);
glTranslated(-0.63,0,0.05);
drawtop();

glTranslated(0.0,0.25,-0.0);
glScaled(0.5,0.75,2);
leafseries();
glPopMatrix();
glPopMatrix();

}
void drawdoor()
{
glPushMatrix();
glColor3d(1.0,0.6,0.0);
glPushMatrix();
glScaled(1,3,0.5);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glTranslated(0.5,0,0);
glScaled(1,3,0.5);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glTranslated(0.25,0.25,0);
glScaled(3,0.75,0.5);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glRotated(45,0,0,1);
glTranslated(0.15,0.0,0);
glScaled(2,0.65,0.5);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glRotated(315,0,0,1);
glTranslated(0.15,0.35,0);
glScaled(2,0.65,0.5);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glRotated(70,0,0,1);
glScaled(0.5,0.5,0.5);
glTranslated(0.1,-0.10,0);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glRotated(290,0,0,1);
glScaled(0.5,0.5,0.5);
glTranslated(0.21,0.83,0);
glutSolidCube(0.2);
glPopMatrix();
glPopMatrix();
}
void drawdoor1()
{
glPushMatrix();
glRotated(45,1,0,0);
glTranslated(0.25,-0.2,0.25);
glScaled(3.5,0.5,0.5);
glutSolidCube(0.2);
glPopMatrix();
}
void octagon()
{

glPushMatrix();
glScaled(2,2,2);
glRotated(90,0,1,0);
glTranslated(0.55,0.0,1.05);
drawdoor();
glPopMatrix();

    glPushMatrix();
glScaled(2,2,2);
glRotated(90,0,1,0);
glTranslated(0.55,0.0,-0.53);
drawdoor();
glPopMatrix();

glPushMatrix();

glPushMatrix();
glScaled(2,2,2);
glTranslated(0.0,0,0);
drawdoor();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(45,0,1,0);
glTranslated(0.5,0.0,0.4);
drawdoor();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(315,0,1,0);
glTranslated(-0.63,0,0.05);
drawdoor();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glRotated(180,0,1,0);
glTranslated(-1,0,3.1);

glPushMatrix();
glScaled(2,2,2);
glTranslated(0.0,0,0);
drawdoor();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(45,0,1,0);
glTranslated(0.5,0.0,0.4);
drawdoor();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(315,0,1,0);
glTranslated(-0.63,0,0.05);
drawdoor();
glPopMatrix();
glPopMatrix();

}
void baseoctagon()
{

glPushMatrix();
glScaled(2,2,2);
glRotated(90,0,1,0);
glTranslated(0.55,0.0,1.05);
drawdoor1();
glPopMatrix();

    glPushMatrix();
glScaled(2,2,2);
glRotated(90,0,1,0);
glTranslated(0.55,0.0,-0.53);
drawdoor1();
glPopMatrix();

glPushMatrix();

glPushMatrix();
glScaled(2,2,2);
glTranslated(0.0,0,0);
drawdoor1();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(45,0,1,0);
glTranslated(0.5,0.0,0.4);
drawdoor1();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(315,0,1,0);
glTranslated(-0.63,0,0.05);
drawdoor1();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glRotated(180,0,1,0);
glTranslated(-1,0,3.1);

glPushMatrix();
glScaled(2,2,2);
glTranslated(0.0,0,0);
drawdoor1();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(45,0,1,0);
glTranslated(0.5,0.0,0.4);
drawdoor1();
glPopMatrix();

glPushMatrix();
glScaled(2,2,2);
glRotated(315,0,1,0);
glTranslated(-0.63,0,0.05);
drawdoor1();
glPopMatrix();
glPopMatrix();

}
void drawpillers()
{
for(float i=0;i<7;i++)
{
glPushMatrix();
glTranslated(0,i,0);
glColor3d(1.0,0.8,0.4);
octagon();
glColor3d(0.2,0.1,0.0);
baseoctagon();
glPopMatrix();
}
glPushMatrix();
glTranslated(0,7,0);
glColor3d(0.2,0.1,0.0);
octtop();
glPopMatrix();
glPushMatrix();
glTranslated(0.5,8.5,-1.5);
glColor3d(1.0,0.6,0.0);
glutSolidSphere(1.75,50,50);
glTranslated(0,1.5,0);
glRotated(270,1,0,0);
glutSolidCone(0.75,0.75,30,30);
glPopMatrix();
}
void drawmaingumbaz()
{

glPushMatrix();
glColor3f(0.556863,0.137255,0.137255);
glTranslated(0,7,0);
octtop();
glPopMatrix();
glPushMatrix();
glColor3f(0.556863,0.137255,0.137255);
glTranslated(0.5,8.5,-1.5);
glutSolidSphere(1.75,50,50);
glTranslated(0,1.5,0);
glRotated(270,1,0,0);
glutSolidCone(0.75,0.75,30,30);
glPopMatrix();
glPushMatrix();

glTranslated(0.4,8.6,-1.5);
    glPushMatrix();
    glTranslated(0,2,0);
    glutSolidSphere(0.2,50,50);
    glTranslated(0,0.2,0);
    glutSolidSphere(0.15,50,50);
    glTranslated(0,0.25,0);
    glutSolidSphere(0.2,50,50);
    glPopMatrix();
glPushMatrix();
    glPushMatrix();
    glTranslated(0,1.5,0);
    glRotated(270,1,0,0);
    glutSolidCone(0.6,0.75,30,30);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0,2.53,0);
    glRotated(270,1,0,0);
    glutSolidCone(0.2,0.2,30,30);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0,1.5,0);
    glRotated(270,1,0,0);
    glutSolidCone(0.05,1.75,30,30);
    glPopMatrix();
glPopMatrix();
glPopMatrix();
}
void drawgumbaz()
{
glPushMatrix();
glTranslated(1.9,1,-1.6);
glScaled(0.125,0.14,0.125);
drawpillers();
glPopMatrix();
glPushMatrix();
glTranslated(1.9,1,2.2);
glScaled(0.125,0.14,0.125);
drawpillers();
glPopMatrix();
glPushMatrix();
glTranslated(-2.2,1,2.2);
glScaled(0.125,0.14,0.125);
drawpillers();
glPopMatrix();
glPushMatrix();
glTranslated(-2.2,01,-1.6);
glScaled(0.125,0.14,0.125);
drawpillers();
glPopMatrix();
glPushMatrix();
glScaled(1.1,1.1,1.1);
glTranslated(-0.5,-6,1.5);
drawmaingumbaz();
glPopMatrix();
glPushMatrix();
glTranslated(0,1,0);
glScaled(5.2,0.5,5.2);
glutSolidCube(1);
glPopMatrix();

}
void drawPiller()
{


 glPushMatrix();
glColor3f(1,1,1);
glTranslated(0.0,0.95,0.0);
glScaled(0.3,0.2,0.3);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);
glTranslated(0.0,1.3,0.0);
glRotated(-90,1,0,0);
glutSolidSphere(0.15,50,50);

glPopMatrix();
glPushMatrix();
glTranslated(0.0,1.3,0.0);
glRotated(90,1,0,0);
glutSolidCone(0.15,0.5,5,5);
glPopMatrix();
glColor3f(0.8, 0.4, 0.0);
glNormal3f(-1.0f, 0.4f, 1.0f);
glutSolidSphere(0.15,50,50);
glPushMatrix();
glRotated(-90,1,0,0);
glutSolidCone(0.15,1.3,100,100);
glPopMatrix();

glPushMatrix();
glRotated(90,1,0,0);
glutSolidCone(0.15,1.3,10,100);
glPopMatrix();

glPushMatrix();
glTranslated(0.0,1,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();
glPushMatrix();
glTranslated(0.0,-1,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();
glPushMatrix();
glColor3f(1,1,1);
glTranslated(0.0,-1.0,0.0);
glScaled(0.3,0.2,0.3);
glutSolidCube(1.0);
glPopMatrix();
}
void compound()
{
glColor3f(0.8, 0.4, 0.0);
glPushMatrix();
glTranslated(0.0,0.0,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();

glPushMatrix();
glRotated(-90,1,0,0);
glutSolidCone(0.08,0.5,100,100);
glPopMatrix();

glPushMatrix();
glRotated(90,1,0,0);
glutSolidCone(0.08,0.5,10,100);
glPopMatrix();

glPushMatrix();
glTranslated(0.0,-0.5,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();
glPushMatrix();
glTranslated(0.0,0.5,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();

for(float x=0.5;x<=1.5;x+=0.5)
{
glPushMatrix();
glTranslated(x,0.0,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();

glPushMatrix();
glTranslated(x,0.0,0.0);
glRotated(-90,1,0,0);
glutSolidCone(0.08,0.5,100,100);
glPopMatrix();

glPushMatrix();
glTranslated(x,0.0,0.0);
glRotated(90,1,0,0);
glutSolidCone(0.08,0.5,10,100);
glPopMatrix();

glPushMatrix();
glTranslated(x,-0.5,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();
glPushMatrix();
glTranslated(x,0.5,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();
glPushMatrix();
glTranslated(-x,0.0,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();

glPushMatrix();
glTranslated(-x,0.0,0.0);
glRotated(-90,1,0,0);
glutSolidCone(0.08,0.5,100,100);
glPopMatrix();

glPushMatrix();
glTranslated(-x,0.0,0.0);
glRotated(90,1,0,0);
glutSolidCone(0.08,0.5,10,100);
glPopMatrix();

glPushMatrix();
glTranslated(-x,-0.5,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();
glPushMatrix();
glTranslated(-x,0.5,0.0);
glutSolidSphere(0.15,50,50);
glPopMatrix();
}


glPushMatrix();
glColor3f(1,1,1);
glTranslated(0.0,0.6,0.0);
glScaled(3.5,0.2,0.3);
glutSolidCube(1.0);
glPopMatrix();
glPushMatrix();
glColor3f(1,1,1);
glTranslated(0.0,-0.6,0.0);
glScaled(3.5,0.2,0.3);
glutSolidCube(1.0);
glPopMatrix();

}
void drawBase()
{//base


    glPushMatrix();
    glColor3f(1,0.8,0.0);//pillars'background
    glTranslated(0.0,-0.7,0.8);
    glScaled(4.5,2,1.2);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6,0.0,0.4);//line strip behind the pillar
    glTranslated(0.0,-0.7,0.0);
    glScaled(4.5,0.3,0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.6,2.0,1.0);//top of the pillars
    glTranslated(0.0,0.3,0.0);
    glScaled(4.75,0.3,1.2);
    glutSolidCube(1.0);
    glPopMatrix();


}
void drawedge1()
{
    glPushMatrix();
	glTranslated(0,-0.75,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

for(float x=0.3;x<=1.5;x+=0.3)
  {

    glPushMatrix();
	glTranslated(-x,-0.75,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

    glPushMatrix();
	glTranslated(x,-0.75,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

  }
    glPushMatrix();
	glTranslated(-1.65,-0.75,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

    glPushMatrix();
	glTranslated(1.7,-0.75,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();


}
void drawedge()
{
    glPushMatrix();
	glTranslated(0,-0.75,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

for(float x=0.3;x<=1.2;x+=0.3)
  {

    glPushMatrix();
	glTranslated(-x,-0.75,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

    glPushMatrix();
	glTranslated(x,-0.75,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

  }
    glPushMatrix();
	glTranslated(1.2,-0.75,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

}
void design()
{
    for(float x=0.25;x<=2.25;x+=0.5)
    {
    glPushMatrix();
	glTranslated(x,-0.8,-0.3);
	glScaled(0.5,0.7,0.5);
    drawPiller();
    glPopMatrix();

    glPushMatrix();
	glTranslated(-x,-0.8,-0.3);
	glScaled(0.5,0.7,0.5);
    drawPiller();
    glPopMatrix();
    }

    glPushMatrix();
	glTranslated(0,-0.5,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

for(float x=0.3;x<=2.1;x+=0.3)
  {

    glPushMatrix();
	glTranslated(-x,-0.5,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

    glPushMatrix();
	glTranslated(x,-0.5,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

  }
}
void design1()
{
    glPushMatrix();
	glTranslated(0,-0.5,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

for(float x=0.3;x<=2.1;x+=0.3)
  {

    glPushMatrix();
	glTranslated(-x,-0.5,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

    glPushMatrix();
	glTranslated(x,-0.5,-0.25);
	glScaled(0.1,0.2,0.1);
    compound();
    glPopMatrix();

  }
}
void kalasa()
{
glPushMatrix();
glTranslated(0,2,0);
glutSolidSphere(0.2,50,50);
glTranslated(0,0.2,0);
glutSolidSphere(0.15,50,50);
glTranslated(0,0.25,0);
glutSolidSphere(0.2,50,50);
glPopMatrix();
glPushMatrix();
glPushMatrix();
glTranslated(0,1.5,0);
glRotated(270,1,0,0);
glutSolidCone(0.6,0.75,30,30);
glPopMatrix();
glPushMatrix();
glTranslated(0,2.53,0);
glRotated(270,1,0,0);
glutSolidCone(0.2,0.2,30,30);
glPopMatrix();
glPushMatrix();
glTranslated(0,1.5,0);
glRotated(270,1,0,0);
glutSolidCone(0.05,1.75,30,30);
glPopMatrix();
glPopMatrix();

}

void towers()
{


glPushMatrix();
    glTranslated(3.0,1.5,5.2);
    glColor3f(1.6,2.0,1.0);//blue tower
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();
     glPushMatrix();
    glTranslated(4.0,1.0,5.0);
    glColor3f(1.6,2.0,1.0);//block btw red n green
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.0,1.5,5.2);
    glColor3f(1.6,2.0,1.0);//green tower
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

     glPushMatrix();
    glTranslated(4.8,1.0,4.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glPopMatrix();



    glPushMatrix();
    glTranslated(5.0,1.5,3.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();

    glPopMatrix();


}
void towers2()
{

     glPushMatrix();
    glTranslated(4.0,1.0,3.2);
    glColor3f(1.6,2.0,1.0);//cyan
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(5.0,1.5,5.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.0,1.5,3.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();


     glPushMatrix();
    glTranslated(4.8,1.0,4.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.0,1.5,3.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();



}
void towers1()
{
    glPushMatrix();
    glTranslated(3.0,1.5,5.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();


     glPushMatrix();
    glTranslated(4.0,1.0,5.0);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.0,1.5,5.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.0,1.5,3.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

     glPushMatrix();
    glTranslated(3.2,1.0,4.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glPopMatrix();


}
void towers3()
{

    glPushMatrix();
    glTranslated(3.0,1.5,5.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();



     glPushMatrix();
    glTranslated(4.0,1.0,3.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.0,1.5,3.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

     glPushMatrix();
    glTranslated(3.2,1.0,4.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.0,1.5,3.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,3,1);
    glutSolidCube(1.0);

    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();
}
void towers4()
{
glPushMatrix();
glScaled(0.6,1,0.6);
    glPushMatrix();
    glTranslated(2.0,2,6.0);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.0,2,2.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(6.0,2,2.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(6.0,2,6.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();
glPopMatrix();
glPushMatrix();
glTranslated(6,0,6);
glScaled(0.4,1,0.4);
    glPushMatrix();
    glTranslated(2.0,2,6.0);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.0,2,2.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(6.0,2,2.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(6.0,2,6.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();
glPopMatrix();


glPushMatrix();
glTranslated(-4,0,6);
glScaled(0.4,1,0.4);
    glPushMatrix();
    glTranslated(2.0,2,6.0);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.0,2,2.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(6.0,2,2.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();

    glPushMatrix();
    glTranslated(6.0,2,6.2);
    glColor3f(1.6,2.0,1.0);
    glScaled(1,2,1);
    glutSolidCube(1.0);
    glTranslated(0,0.4,0);
    glScaled(0.2,0.09,0.2);
    drawgumbaz();
    glPopMatrix();
glPopMatrix();
}

void drawarch()
{

 glPushMatrix();
  glTranslated(0,0,0);
glPushMatrix();
glScaled(1,2,0.5);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glTranslated(0.5,0,0);
glScaled(1,2,0.5);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glTranslated(0.25,0.175,0);
glScaled(3.5,0.75,0.5);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glRotated(45,0,0,1);
glTranslated(0.15,0.0,0);
glScaled(1.3,0.65,0.5);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glRotated(315,0,0,1);
glTranslated(0.15,0.35,0);
glScaled(0.9,0.65,0.5);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glRotated(70,0,0,1);
glScaled(0.5,0.5,0.5);
glTranslated(0.1,-0.10,0);
glutSolidCube(0.2);
glPopMatrix();
glPushMatrix();
glRotated(290,0,0,1);
glScaled(0.5,0.5,0.5);
glTranslated(0.21,0.83,0);
glutSolidCube(0.2);
glPopMatrix();

glPushMatrix();
glTranslated(0.18,0.13,0.0);
glRotated(25,0,0,1);
glScaled(0.5,0.5,0.5);
glutSolidCube(0.2);
glPopMatrix();

glPushMatrix();
glTranslated(0.32,0.13,0.0);
glRotated(335,0,0,1);
glScaled(0.5,0.5,0.5);
glutSolidCube(0.2);
glPopMatrix();


glPopMatrix();
}
void frontarch()
{

    glPushMatrix();
    glColor3f(1.6,2.0,1.0);
    glTranslated(-1,1.5,5);
    glScaled(2.5,2,1);
    drawarch();
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.6,2.0,1.0);
    glTranslated(0.5,1.5,5);
    glScaled(2,2,1);
    drawarch();
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.6,2.0,1.0);
    glTranslated(-2,1.5,5);
    glScaled(2,2,1);
    drawarch();
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.6,2.0,1.0);
    glTranslated(-3.3,1.5,5);
    glScaled(2.5,2,1);
    drawarch();
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.6,2.0,1.0);
    glTranslated(-4.8,1.5,5);
    glScaled(2.5,2,1);
    drawarch();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.6,2.0,1.0);
    glTranslated(-6.2,1.5,5);
    glScaled(2.5,2,1);
    drawarch();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.6,2.0,1.0);
    glTranslated(4.8,1.5,5);
    glScaled(2.5,2,1);
    drawarch();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.6,2.0,1.0);
    glTranslated(3.3,1.5,5);
    glScaled(2.5,2,1);
    drawarch();
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.6,2.0,1.0);
    glTranslated(1.7,1.5,5);
    glScaled(2.5,2,1);
    drawarch();
    glPopMatrix();

}
void drawfrontpillers()
{
    glPushMatrix();
	glTranslated(0.35,0.6,5);
	glScaled(1,0.4,1);
    drawPiller();
    glPopMatrix();

    glPushMatrix();
	glTranslated(-1,0.6,5);
	glScaled(1,0.4,1);
    drawPiller();
    glPopMatrix();

    glPushMatrix();
	glTranslated(-2.05,0.6,5);
	glScaled(1,0.4,1);
    drawPiller();
    glPopMatrix();


    glPushMatrix();
	glTranslated(-3.45,0.6,5);
	glScaled(1,0.4,1);
    drawPiller();
    glPopMatrix();

    glPushMatrix();
	glTranslated(-4.85,0.6,5);
	glScaled(1,0.4,1);
    drawPiller();
    glPopMatrix();


    glPushMatrix();
	glTranslated(-6.05,0.6,5);
	glScaled(1,0.4,1);
    drawPiller();
    glPopMatrix();

        glPushMatrix();
	glTranslated(1.65,0.6,5);
	glScaled(1,0.4,1);
    drawPiller();
    glPopMatrix();

    glPushMatrix();
	glTranslated(3.15,0.6,5);
	glScaled(1,0.4,1);
    drawPiller();
    glPopMatrix();


    glPushMatrix();
	glTranslated(4.65,0.6,5);
	glScaled(1,0.4,1);
    drawPiller();
    glPopMatrix();

    glPushMatrix();
	glTranslated(6,0.6,5);
	glScaled(1,0.4,1);
    drawPiller();
    glPopMatrix();


}
void drawpalace()
{


	glPushMatrix();
    glRotated(270,0,1,0);
	glTranslated(0.3,1.7,-8.0);
	drawBase();
	design();
	glPopMatrix();

    glPushMatrix();
    glRotated(90,0,1,0);
	glTranslated(-0.3,1.7,-8);
	drawBase();
	design();
	glPopMatrix();

    glPushMatrix();
   glTranslated(0,1,0);
    glColor3f(2.0,2.0,0.0);
    glScaled(15,2,6);
    glutSolidCube(1.0);
    glPopMatrix();

glPushMatrix();
glTranslated(3.5,0,0);
towers();
glPopMatrix();

glPushMatrix();
glTranslated(-11.5,0,0);
towers1();
glPopMatrix();

glPushMatrix();
glTranslated(-11.5,0,-7.8);
towers3();
glPopMatrix();

glPushMatrix();
glTranslated(3.5,0,-7.8);
towers2();
glPopMatrix();


glPushMatrix();
glTranslated(0,2.3,0.4);
glColor3f(1.6,2.0,1.0);
glScaled(17.8,0.6,10.4);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslated(0,0.8,0);
glColor3f(1.6,2.0,1.0);
glScaled(14.8,0.01,9.4);
glutSolidCube(1.0);
glPopMatrix();

frontarch();
drawfrontpillers();

glPushMatrix();
glTranslated(0,0,-9.8);
frontarch();
drawfrontpillers();
glPopMatrix();

glPushMatrix();
glTranslated(0,1.1,5);
glScaled(3.5,0.5,2);
design1();
glPopMatrix();

glPushMatrix();
glTranslated(3.8,0.2,-0.2);
glScaled(0.4,0.30,1);
frontarch();
drawfrontpillers();
glPopMatrix();

glPushMatrix();
glTranslated(-4.2,0.2,-0.2);
glScaled(0.4,0.30,1);
frontarch();
drawfrontpillers();
glPopMatrix();


glPushMatrix();
glTranslated(0,1.1,-4.3);
glScaled(3.5,0.5,2);
design1();
glPopMatrix();

glPushMatrix();
glTranslated(3.8,0.2,-9.5);
glScaled(0.4,0.30,1);
frontarch();
drawfrontpillers();
glPopMatrix();

glPushMatrix();
glTranslated(-4.2,0.2,-9.5);
glScaled(0.4,0.30,1);
frontarch();
drawfrontpillers();
glPopMatrix();


glPushMatrix();
glTranslated(3.8,1.9,-10);
glScaled(0.4,0.30,1);
frontarch();
drawfrontpillers();
glPopMatrix();

glPushMatrix();
glTranslated(-4.2,1.9,-10);
glScaled(0.4,0.30,1);
frontarch();
drawfrontpillers();
glPopMatrix();


glPushMatrix();
glTranslated(3.8,1.9,0.7);
glScaled(0.4,0.30,1);
frontarch();
drawfrontpillers();
glPopMatrix();

glPushMatrix();
glTranslated(-4.2,1.9,0.7);
glScaled(0.4,0.30,1);
frontarch();
drawfrontpillers();
glPopMatrix();

glPushMatrix();
glTranslated(0,2,5.8);
glScaled(14,0.1,0.5);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-2.5,0,-5);
towers4();
glPopMatrix();
}

void drawmantapa()
{
glPushMatrix();
glTranslated(1.9,-2.6,-1.6);
glScaled(0.125,0.5,0.125);
drawpillers();
glPopMatrix();
glPushMatrix();
glTranslated(1.9,-2.6,2.2);
glScaled(0.125,0.5,0.125);
drawpillers();
glPopMatrix();
glPushMatrix();
glTranslated(-2.2,-2.6,2.2);
glScaled(0.125,0.5,0.125);
drawpillers();
glPopMatrix();
glPushMatrix();
glTranslated(-2.2,-2.6,-1.6);
glScaled(0.125,0.5,0.125);
drawpillers();
glPopMatrix();
glPushMatrix();
glScaled(1.1,1.1,1.1);
glTranslated(-0.5,-6,1.5);
drawmaingumbaz();
glPopMatrix();
glPushMatrix();
glTranslated(0,1,0);
glScaled(5,0.5,5);
glutSolidCube(1);
glPopMatrix();

}

void drawdomes()
{
    glPushMatrix();
    glColor3f(1,1,1);
    drawpalace();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.5,2.5,5);
    glutSolidCube(1);
    glScaled(0.2,0.2,0.2);
    glTranslated(0,4,0);
    drawmantapa();

    glPopMatrix();
    glPushMatrix();
    glTranslated(-1.5,2.5,5);
    glutSolidCube(1);
    glScaled(0.2,0.2,0.2);
    glTranslated(0,4,0);
    drawmantapa();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0,2.6,5);
    glScaled(0.3,0.18,0.5);
    glutSolidTorus(.8,3,50,50);
glPushMatrix();
    glTranslated(-1.5,0,0);
    glScaled(0.5,2,0.5);
    kalasa();
    glTranslated(1.5,0,0);
    kalasa();
    glTranslated(1.5,0,0);
    kalasa();
    glTranslated(1.5,0,0);
    kalasa();
    glTranslated(1.5,0,0);
    kalasa();
glPopMatrix();
   glTranslated(0,2.8,0);
    glScaled(4,1,1);
    glutSolidCube(1);
glPopMatrix();

}

void maingopura()
{
    glTranslated(0,-5,0);
glPushMatrix();
glTranslated(0,6.2,0);
glColor3d(1.0,0.8,0.4);
octagon();
glColor3d(0.2,0.1,0.0);
baseoctagon();
glPopMatrix();

glPushMatrix();
glTranslated(0,7,0);
glColor3d(0.2,0.1,0.0);
octtop();
glPopMatrix();

glPushMatrix();
glTranslated(0.5,8.5,-1.5);
glColor3d(1.0,0.6,0.0);
glutSolidSphere(1.75,50,50);
glTranslated(0,1.5,0);
glRotated(270,1,0,0);
//glutSolidCone(0.75,0.75,30,30);
glPopMatrix();

glPushMatrix();
glTranslated(0.35,8.2,-1);
glScaled(0.4,0.35,0.4);
glPushMatrix();
glTranslated(0,6.2,0);
glColor3d(1.0,0.8,0.4);
octagon();
glColor3d(0.2,0.1,0.0);
baseoctagon();
glPopMatrix();

glPushMatrix();
glTranslated(0,7,0);
glColor3d(0.2,0.1,0.0);
octtop();
glPopMatrix();
glPushMatrix();
glTranslated(0.5,8.5,-1.5);
glColor3d(1.0,0.6,0.0);
glutSolidSphere(1.75,50,50);
glTranslated(0,1.5,0);
glRotated(270,1,0,0);
glutSolidCone(0.75,0.75,30,30);
glPopMatrix();

glPopMatrix();
glScaled(1.2,1.2,1.2);
glTranslated(-0.1,2,-0);
glPushMatrix();
glTranslated(0,-5,0);
glPushMatrix();
glTranslated(0,6.2,0);
glColor3d(1.0,0.8,0.4);
octagon();
glColor3d(0.2,0.1,0.0);
baseoctagon();
glPopMatrix();

glPushMatrix();
glTranslated(0,7,0);
glColor3d(0.2,0.1,0.0);
octtop();
glPopMatrix();

glPopMatrix();
}
void mainpalace()
{
 drawdomes();
   glPushMatrix();
        glScaled(0.5,0.5,0.5);
    glTranslated(-0.8,6,-3);
    maingopura();
    glScaled(0.6,0.6,0.6);
    glTranslated(15,3,13);
    maingopura();
    glPushMatrix();
    glTranslated(-23,2.5,0);
      glScaled(0.8,0.8,0.8);
    maingopura();
    glPopMatrix();
    glPopMatrix();
}


float theta[5]={0};
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
static void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	glLoadIdentity();                // Reset the model-view matrix
     //set the camera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-winHt*64/48.0,winHt*64/48.0,-winHt,winHt,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,10.0,50.0,0,0,0,0.0,10.0,0.0);

    glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 1.0, 0.0, 0.0);
	glRotatef(theta[2]+thet, 0.0, 1.0, 0.0);
	glRotatef(theta[3], 0.0, 1.0, 0.0);

      glPushMatrix();
    glColor3f(0.65,.49,.24);
    glTranslated(0.0,0.0,0.0);
    glScaled(6,0.05,6);
    glutSolidCube(5.0);
    glPopMatrix();
    mainpalace();
    glFlush();
	    glutSwapBuffers();
}
static void mouse(int btn,int statu,int x,int y)
{
    if(btn==GLUT_LEFT_BUTTON)winHt=winHt+0.1;
    if(btn==GLUT_RIGHT_BUTTON)winHt=winHt-0.1;
    glutPostRedisplay();
}
static void key(unsigned char key, int x, int y)
{
  if(key=='w')
    {theta[0] += 0.5;
	if( theta[0] > 45.0 ) theta[0] -= 45.0;
	glutPostRedisplay();
    }
    else

    if(key=='s')
    {theta[0] -= 0.50;
	if( theta[0] > 45.0 || theta[0] < -20 ) theta[0] = 0.0;
	glutPostRedisplay();
    }
    else

    if(key=='a')
    {theta[2] -= 5.0;
	if( theta[2] > 360.0 ) theta[2] -= 360.0;
	glutPostRedisplay();
    }
    else

    if(key=='d')
    {theta[3] += 5.0;
	if( theta[3] > 360.0  ) theta[3] -= 360.0;
	glutPostRedisplay();
    }
}
static void idle(void)
{
thet++;
glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 20.0f, 50.0f, 50.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("replica of Mysore Place");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0.7,1.0,0);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMouseFunc(mouse);
    glutMainLoop();

    return EXIT_SUCCESS;
}
