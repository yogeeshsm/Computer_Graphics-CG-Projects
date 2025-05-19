#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>

int global = 0,tex1=0;
float pos,y=0;
int flag=0;

char s[30]="press s to start";
char s1[100]="DAYANANDA SAGAR ACADEMY OF TECHNOLOGY";
char s2[100]="DEPARTMENT OF CSE";
char s3[100]="Mini Project : ";
char s4[100]="Implementation of a Windmill using OpenGL";
char s5[100]="By SUMANTH BS";
char s6[100]="Under the Guidance of :";
char s7[50]="Press q to exit";
char s8[75]="Mr. Manjunath D R";

void myinit()
{
    glClearColor(0.0, 0.012, 0.086,1.0);
  glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-150,150,-150,150);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

static GLfloat theta[]={0.0,0.0,1.0};
static GLint axis=2;

GLfloat *make_texture(int maxs, int maxt)
{
    int s, t;
    static GLfloat *texture;

    texture = (GLfloat *)malloc(maxs * maxt * sizeof(GLfloat));
    for(t = 0; t < maxt; t++) {
	for(s = 0; s < maxs; s++) {
	    texture[s + maxs * t] = ((s >> 4) & 0x1) ^ ((t >> 4) & 0x1);
	}
    }
    return texture;
}

void fan()
{
    glColor3f(0.439,0.502,0.565);          /*circle holding the fan*/
            glutSolidSphere(2.8,500,100);

    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(0.0,2.0);
        glVertex2f(3.0,10.0);
        glVertex2f(25.0,30.0);
        glVertex2f(5.0,2.0);

        glVertex2f(0.0,2.0);
        glVertex2f(-3.0,10.0);
        glVertex2f(-25.0,30.0);
        glVertex2f(-5.0,2.0);

        glVertex2f(0.0,2.0);
        glVertex2f(-4.0,-5.0);
        glVertex2f(0.0,-35.0);
        glVertex2f(4.0,-5.0);
    glEnd();

    if(global==1 && tex1==1)    //Default-White color texture
    {
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_POLYGON);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(0.0,0.0,0.0);
            glTexCoord2i(0,1);
            glVertex2f(3.0,10.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(25.0,30.0);
            glColor3f(0.0,0.0,0.0);
            glTexCoord2i(0,0);
            glVertex2f(5.0,2.0);

            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(0.0,0.0,0.0);
            glTexCoord2i(0,1);
            glVertex2f(-3.0,10.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(-25.0,30.0);
            glColor3f(0.0,0.0,0.0);
            glTexCoord2i(0,0);
            glVertex2f(-5.0,2.0);

            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(0.0,0.0,0.0);
            glTexCoord2i(0,1);
            glVertex2f(-4.0,-5.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(0.0,-35.0);
            glColor3f(0.0,0.0,0.0);
            glTexCoord2i(0,0);
            glVertex2f(4.0,-5.0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }

    if(global==2 && tex1==1) //Brown texture color
    {
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_POLYGON);
            glColor3f(0.6,0.3,0.1);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(3.0,10.0);
            glColor3f(0.6,0.3,0.1);
            glTexCoord2i(0,1);
            glVertex2f(25.0,30.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(5.0,2.0);

            glColor3f(0.6,0.3,0.1);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(-3.0,10.0);
            glColor3f(0.6,0.3,0.1);
            glTexCoord2i(0,1);
            glVertex2f(-25.0,30.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(-5.0,2.0);

            glColor3f(0.6,0.3,0.1);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(-4.0,-5.0);
            glColor3f(0.6,0.3,0.1);
            glTexCoord2i(0,1);
            glVertex2f(0.0,-35.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(4.0,-5.0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }

    if(global==3 && tex1==1)    //Red color texture
    {
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_POLYGON);
            glColor3f(1.0,0.0,0.0);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(3.0,10.0);
            glColor3f(1.0,0.0,0.0);
            glTexCoord2i(0,1);
            glVertex2f(25.0,30.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(5.0,2.0);

            glColor3f(1.0,0.0,0.0);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(-3.0,10.0);
            glColor3f(1.0,0.0,0.0);
            glTexCoord2i(0,1);
            glVertex2f(-25.0,30.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(-5.0,2.0);

            glColor3f(1.0,0.0,0.0);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(-4.0,-5.0);
            glColor3f(1.0,0.0,0.0);
            glTexCoord2i(0,1);
            glVertex2f(0.0,-35.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(4.0,-5.0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }

    if(global==4 && tex1==1)    //Blue color texture
    {
         glEnable(GL_TEXTURE_2D);
        glBegin(GL_POLYGON);
            glColor3f(0.0,0.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(3.0,10.0);
            glColor3f(0.0,0.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(25.0,30.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(5.0,2.0);

            glColor3f(0.0,0.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(-3.0,10.0);
            glColor3f(0.0,0.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(-25.0,30.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(-5.0,2.0);

            glColor3f(0.0,0.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(0.0,2.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(-4.0,-5.0);
            glColor3f(0.0,0.0,1.0);
            glTexCoord2i(0,1);
            glVertex2f(0.0,-35.0);
            glColor3f(1.0,1.0,1.0);
            glTexCoord2i(0,0);
            glVertex2f(4.0,-5.0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }

    if(global==1 && tex1==0)    //Default-White color without texture
    {
        glBegin(GL_POLYGON);
            glColor3f(1.0,1.0,1.0);
            glVertex2f(0.0,2.0);
            glVertex2f(3.0,10.0);
            glVertex2f(25.0,30.0);
            glVertex2f(5.0,2.0);

            glVertex2f(0.0,2.0);
            glVertex2f(-3.0,10.0);
            glVertex2f(-25.0,30.0);
            glVertex2f(-5.0,2.0);

            glVertex2f(0.0,2.0);
            glVertex2f(-4.0,-5.0);
            glVertex2f(0.0,-35.0);
            glVertex2f(4.0,-5.0);
        glEnd();
    }

    if(global==2 && tex1==0)    //Brown color without texture
    {
        glBegin(GL_POLYGON);
            glColor3f(0.6,0.3,0.1);
            glVertex2f(0.0,2.0);
            glVertex2f(3.0,10.0);
            glVertex2f(25.0,30.0);
            glVertex2f(5.0,2.0);

            glVertex2f(0.0,2.0);
            glVertex2f(-3.0,10.0);
            glVertex2f(-25.0,30.0);
            glVertex2f(-5.0,2.0);

            glVertex2f(0.0,2.0);
            glVertex2f(-4.0,-5.0);
            glVertex2f(0.0,-35.0);
            glVertex2f(4.0,-5.0);
        glEnd();
    }

    if(global==3 && tex1==0)    //Red color without texture
    {
        glBegin(GL_POLYGON);
            glColor3f(1.0,0.0,0.0);
            glVertex2f(0.0,2.0);
            glVertex2f(3.0,10.0);
            glVertex2f(25.0,30.0);
            glVertex2f(5.0,2.0);

            glVertex2f(0.0,2.0);
            glVertex2f(-3.0,10.0);
            glVertex2f(-25.0,30.0);
            glVertex2f(-5.0,2.0);

            glVertex2f(0.0,2.0);
            glVertex2f(-4.0,-5.0);
            glVertex2f(0.0,-35.0);
            glVertex2f(4.0,-5.0);
        glEnd();
    }

    if(global==4 && tex1==0)    //Blue color without texture
    {
        glBegin(GL_POLYGON);
            glColor3f(0.0,0.0,1.0);
            glVertex2f(0.0,2.0);
            glVertex2f(3.0,10.0);
            glVertex2f(25.0,30.0);
            glVertex2f(5.0,2.0);

            glVertex2f(0.0,2.0);
            glVertex2f(-3.0,10.0);
            glVertex2f(-25.0,30.0);
            glVertex2f(-5.0,2.0);

            glVertex2f(0.0,2.0);
            glVertex2f(-4.0,-5.0);
            glVertex2f(0.0,-35.0);
            glVertex2f(4.0,-5.0);
        glEnd();
    }
}

void grass1()
{
    glBegin(GL_POLYGON);
		glColor3f(0.196, 0.804, 0.196);
        glVertex2f(-3.0,-70.0);
		glVertex2f(-150.0,-70.0);
		glVertex2f(-150.0,-150.0);
		glVertex2f(-3.0,-150);
	glEnd();

	glBegin(GL_POLYGON);
        glVertex2f(-3.0,-70.0);
        glVertex2f(150.0,-70);
        glVertex2f(150.0,-150.0);
        glVertex2f(-3.0,-150.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(8.0,-60.0);
        glVertex2f(150.0,-60.0);
        glVertex2f(150.0,-150.0);
        glVertex2f(5.0,-150.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(8.0,-60.0);
        glVertex2f(8.0,-70.0);
        glVertex2f(5.0,-70.0);
    glEnd();

     glBegin(GL_POLYGON);
        glVertex2f(-5.0,-60.0);
        glVertex2f(-150.0,-60.0);
        glVertex2f(-150.0,-150.0);
        glVertex2f(-5.0,-150.0);
    glEnd();

     glBegin(GL_POLYGON);
        glVertex2f(-5.0,-60.0);
        glVertex2f(-5.0,-70.0);
        glVertex2f(-3.0,-70.0);
    glEnd();
}

void grasselev()
{
    glColor3f(0.196, 0.804, 0.196);
    glBegin(GL_POLYGON);
        glVertex2f(-5.0,-60.0);
        glVertex2f(-80.0,-50.0);
        glVertex2f(-80.0,-60.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-80.0,-50.0);
        glVertex2f(-150.0,-38.0);
        glVertex2f(-150.0,-60.0);
        glVertex2f(-80.0,-60.0);
    glEnd();
}

void drawhouse()
{

    glBegin(GL_POLYGON);    //square base
    glColor3f(1.000, 0.843, 0.000);
        glVertex2f(90.0,-60.0);
        glVertex2f(90.0,-30.0);
        glVertex2f(120.0,-30.0);
        glVertex2f(120.0,-60.0);
    glEnd();

    glBegin(GL_POLYGON);    //triangular top
    glColor3f(1.0,0.0,0.0);
        glVertex2f(90.0,-30.0);
        glVertex2f(105.0,-10.0);
        glVertex2f(120.0,-30.0);
    glEnd();

    glBegin(GL_POLYGON);    //door
    glColor3f(2.0,0.0,0.0);
        glVertex2f(100.0,-60.0);
        glVertex2f(100.0,-45.0);
        glVertex2f(110.0,-45.0);
        glVertex2f(110.0,-60.0);
    glEnd();

    glBegin(GL_POLYGON);                //chimney
    glColor3f(0.184, 0.310, 0.310);
        glVertex2f(120.0,-30.0);
        glVertex2f(120.0,-20.0);
        glVertex2f(118.0,-20.0);
        glVertex2f(118.0,-28.0);
    glEnd();

    /*House side */
    glBegin(GL_POLYGON);        //side wall
    glColor3f(1.000, 0.843, 0.000);
        glVertex2f(85.0,-30.6);
        glVertex2f(90.0,-30.0);
        glVertex2f(90.0,-60.0);
        glVertex2f(85.0,-60.0);
    glEnd();

    glBegin(GL_POLYGON);        //roof
    glColor3f(1.0,0.0,0.0);
        glVertex2f(85.0,-30.6);
        glVertex2f(105.0,-10.0);
        glVertex2f(90.0,-30.0);
    glEnd();
    /* House side */


}

int clr;
void hwindows()
{
     /* Windows */
       glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(92.0,-43.5);
        glVertex2f(92.0,-33.5);
        glVertex2f(98.0,-33.5);
        glVertex2f(98.0,-43.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(112.0,-43.5);
        glVertex2f(112.0,-33.5);
        glVertex2f(118.0,-33.5);
        glVertex2f(118.0,-43.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(86.5,-43.5);
        glVertex2f(86.5,-33.0);
        glVertex2f(88.5,-33.0);
        glVertex2f(88.5,-43.5);
    glEnd();

     /* Windows */
  if(clr==1)
  {
       /* Windows */
       glColor3f(0.941, 1.000, 1.000);
    glBegin(GL_POLYGON);
        glVertex2f(92.0,-43.5);
        glVertex2f(92.0,-33.5);
        glVertex2f(98.0,-33.5);
        glVertex2f(98.0,-43.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(112.0,-43.5);
        glVertex2f(112.0,-33.5);
        glVertex2f(118.0,-33.5);
        glVertex2f(118.0,-43.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(86.5,-43.5);
        glVertex2f(86.5,-33.0);
        glVertex2f(88.5,-33.0);
        glVertex2f(88.5,-43.5);
    glEnd();

    /* Windows */
  }
  if(clr==0)
  {
       /* Windows */
        glColor3f(0.0,0.0,0.0);
      glBegin(GL_POLYGON);
        glVertex2f(92.0,-43.5);
        glVertex2f(92.0,-33.5);
        glVertex2f(98.0,-33.5);
        glVertex2f(98.0,-43.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(112.0,-43.5);
        glVertex2f(112.0,-33.5);
        glVertex2f(118.0,-33.5);
        glVertex2f(118.0,-43.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(86.5,-43.5);
        glVertex2f(86.5,-33.0);
        glVertex2f(88.5,-33.0);
        glVertex2f(88.5,-43.5);
    glEnd();
     /* Windows */
  }
}

void l_loop()
{
    /*outline house side*/
     glBegin(GL_LINE_LOOP); //outline 1
    glLineWidth(0.1);
        glColor3f(0.0,0.0,0.0);
            glVertex2f(85.0,-30.6);
            glVertex2f(90.0,-30.0);
            glVertex2f(90.0,-60.0);
            glVertex2f(85.0,-60.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //outline 2
    glLineWidth(0.1);
        glColor3f(0.0,0.0,0.0);
           glVertex2f(85.0,-30.6);
        glVertex2f(105.0,-10.0);
        glVertex2f(90.0,-30.0);
    glEnd();
    /*outline house side */

    /*outline house triangle top,square base,door*/

     glBegin(GL_LINE_LOOP); //outline square base
    glLineWidth(0.1);
        glColor3f(0.0,0.0,0.0);
            glVertex2f(90.0,-60.0);
        glVertex2f(90.0,-30.0);
        glVertex2f(120.0,-30.0);
        glVertex2f(120.0,-60.0);
    glEnd();

     glBegin(GL_LINE_LOOP); //outline triangle top
    glLineWidth(0.1);
        glColor3f(0.0,0.0,0.0);
          glVertex2f(90.0,-30.0);
        glVertex2f(105.0,-10.0);
        glVertex2f(120.0,-30.0);
    glEnd();

    glBegin(GL_LINE_LOOP); //outline door
    glLineWidth(0.1);
        glColor3f(0.0,0.0,0.0);
         glVertex2f(100.0,-60.0);
        glVertex2f(100.0,-45.0);
        glVertex2f(110.0,-45.0);
        glVertex2f(110.0,-60.0);
    glEnd();

     /*outline house triangle top,square base,door*/

}

void fence()
{
    glBegin(GL_POLYGON);
    glColor3f(0.627, 0.322, 0.176);
        glVertex2f(122.0,-60.0);
        glVertex2f(124.0,-60.0);
        glVertex2f(124.0,-45.0);
        glVertex2f(122.0,-45.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.627, 0.322, 0.176);
        glVertex2f(128.0,-60.0);
        glVertex2f(130.0,-60.0);
        glVertex2f(130.0,-45.0);
        glVertex2f(128.0,-45.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.627, 0.322, 0.176);
        glVertex2f(134.0,-60.0);
        glVertex2f(136.0,-60.0);
        glVertex2f(136.0,-45.0);
        glVertex2f(134.0,-45.0);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.627, 0.322, 0.176);
        glVertex2f(138.0,-60.0);
        glVertex2f(140.0,-60.0);
        glVertex2f(140.0,-45.0);
        glVertex2f(138.0,-45.0);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.627, 0.322, 0.176);
        glVertex2f(144.0,-60.0);
        glVertex2f(146.0,-60.0);
        glVertex2f(146.0,-45.0);
        glVertex2f(144.0,-45.0);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.627, 0.322, 0.176);
        glVertex2f(148.0,-60.0);
        glVertex2f(150.0,-60.0);
        glVertex2f(150.0,-45.0);
        glVertex2f(148.0,-45.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.271, 0.075);
        glVertex2f(120.0,-52.5);
        glVertex2f(120.0,-50.0);
        glVertex2f(150.0,-50.0);
        glVertex2f(150.0,-52.5);
    glEnd();
}

void celestials()
{       glColor3f(0.973, 0.973, 1.000);
        glBegin(GL_POINTS);
            glPointSize(25.85);
            glVertex2f(15.0,80.0);
            glVertex2f(-25.0,60.0);
            glVertex2f(34.0,96.0);
            glVertex2f(-125.0,68.0);
            glVertex2f(142.0,82.0);
            glVertex2f(-45.0,75.0);
            glVertex2f(112.0,64.0);
            glVertex2f(-55.0,58.0);
            glVertex2f(55.0,140.0);
            glVertex2f(-105.0,122.0);
            glVertex2f(95.0,135.0);
            glVertex2f(-115.0,112.0);
            glVertex2f(86.0,105.0);
            glVertex2f(-56.0,126.0);
            glVertex2f(-39.0,40.0);
            glVertex2f(57.0,44.0);
            glVertex2f(-105.7,100.0);
            glVertex2f(-95.0,30.0);
            glVertex2f(-85.0,62.0);
            glVertex2f(30.0,62.0);
            glVertex2f(44.0,81.5);
        glEnd();

    /*moon*/
        glBegin(GL_POLYGON);
        glColor3f(0.973, 0.973, 1.000);
            glVertex2f(15.0,150.0);
            glVertex2f(20.0,143.5);
            glVertex2f(25.0,141.8);
            glVertex2f(30.0,143.5);
            glVertex2f(35.0,150.0);
        glEnd();

}

void aircraft(int x,int y)
{
    glBegin(GL_POLYGON);                //NOSE
    glColor3f(0.863,0.078,0.235);
        glVertex2f(-105.0+x,135.0+y);
        glVertex2f(-115.0+x,140.0+y);
        glVertex2f(-115.0+x,130.0+y);
    glEnd();

    glBegin(GL_POLYGON);                //body
    glColor3f( 0.753,0.753,0.753 );
        glVertex2f(-115.0+x,140.0+y);
        glVertex2f(-136.0+x,142.5+y);
        glVertex2f(-145.0+x,132.0+y);
        glVertex2f(-140.0+x,127.5+y);
        glVertex2f(-115.0+x,130.0+y);
    glEnd();

    glBegin(GL_POLYGON);                //tail
    glColor3f(0.863,0.078,0.235);
        glVertex2f(-136.0+x,142.5+y);
        glVertex2f(-140.0+x,145.0+y);
        glVertex2f(-145.0+x,132.0+y);
    glEnd();

    glBegin(GL_POLYGON);                //exhaust
    glColor3f(1.000,0.271,0.000);
        glVertex2f(-145.0+x,132.0+y);
        glVertex2f(-149.8+x,130.5+y);
        glVertex2f(-140.0+x,127.5+y);
    glEnd();

    glBegin(GL_POLYGON);                //cockpit
    glColor3f(1.000, 1.000, 0.000);
        glVertex2f(-132.0+x,141.5+y);
        glVertex2f(-125.5+x,144.0+y);
        glVertex2f(-115.0+x,140.0+y);
    glEnd();

     /* outline aircraft nose and cockpit */

      glBegin(GL_LINE_LOOP); //outline nose
    glLineWidth(0.1);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-105.0+x,135.0+y);
        glVertex2f(-115.0+x,140.0+y);
        glVertex2f(-115.0+x,130.0+y);
    glEnd();

    glBegin(GL_LINE_LOOP); //outline cockpit
    glLineWidth(0.1);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-132.0+x,141.5+y);
        glVertex2f(-125.5+x,144.0+y);
        glVertex2f(-115.0+x,140.0+y);
    glEnd();


     /* outline aircraft nose and cockpit */

}

void display1(void)
{
    pos+=0.1;
    aircraft(pos,y);
    glutPostRedisplay();
    //glFlush();
    //glutSwapBuffers();
}

void aircraftmov1(void)
{
        pos+=1.4;               //fast-forward
        aircraft(pos,y);
        glutPostRedisplay();
        //glutSwapBuffers();
}

void aircraftmov2(void)
{
        pos-=0.8;               //Rewind
        aircraft(pos,y);
        glutPostRedisplay();
        //glutSwapBuffers();
}

void pillar()
{
     /* Pillar */
            glBegin(GL_POLYGON);
                glColor3f(0.439,0.502,0.565);
                    glVertex2i(0.0,2.0);
                    glVertex2i(-5.0,-60.0);
                    glVertex2i(-3.0,-70.0);
                    glVertex2i(5.0,-70.0);
                    glVertex2i(8.0,-60.0);
            glEnd();
    /* Pillar */

    /*outline for pillar */
        glBegin(GL_LINE_LOOP); //outline p1
        glLineWidth(0.1);
        glColor3f(0.0,0.0,0.0);
                    glVertex2i(0.0,2.0);
                    glVertex2i(-5.0,-60.0);
                    glVertex2i(-3.0,-70.0);
                    glVertex2i(5.0,-70.0);
                    glVertex2i(8.0,-60.0);
        glEnd();

         glBegin(GL_LINE_LOOP); //outline p2
        glLineWidth(0.1);
        glColor3f(0.0,0.0,0.0);
                    glVertex2i(0.0,2.0);
                    glVertex2i(-5.0,-60.0);
                    glVertex2i(-3.0,-70.0);
        glEnd();

          glBegin(GL_LINE_LOOP); //outline p3
        glLineWidth(0.1);
        glColor3f(0.0,0.0,0.0);
                    glVertex2i(0.0,2.0);
                     glVertex2i(5.0,-70.0);
                    glVertex2i(8.0,-60.0);
        glEnd();
}

void chrtr()
{
    int i;
    glColor3f(0.000, 0.000, 0.502);
        glRasterPos2f(-145.0,-135.0);
        for(i=0;s[i]!='\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);   // char s

    glColor3f(0.000, 0.000, 0.502);
        glRasterPos2f(115.0,-135.0);
        for(i=0;s7[i]!='\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s7[i]);  // char s7

    glColor3f(1.000, 0.843, 0.000);
        glRasterPos2f(-149.0,90.0);
        for(i=0;s1[i]!='\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s1[i]);  // char s1

    glColor3f(1.000, 0.843, 0.000);
        glRasterPos2f(-120.0,80.0);
        for(i=0;s2[i]!='\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s2[i]);  // char s2

    glColor3f(0.753, 0.753, 0.753);
        glRasterPos2f(-149.0,50.0);
        for(i=0;s3[i]!='\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s3[i]);  // char s3

     glColor3f(1.000, 1.000, 0.878);
        glRasterPos2f(-120.0,50.0);
        for(i=0;s4[i]!='\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s4[i]);  // char s4

    glColor3f(1.000, 1.000, 0.878);
        glRasterPos2f(-120.0,35.0);
        for(i=0;s5[i]!='\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s5[i]);  // char s5

    glColor3f(0.753, 0.753, 0.753);
        glRasterPos2f(-149.0,15.0);
        for(i=0;s6[i]!='\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s6[i]);  // char s6

    glColor3f(1.000, 1.000, 0.878);
        glRasterPos2f(-100.0,15.0);
        for(i=0;s8[i]!='\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s8[i]);  // char s8


}

void display(void)
{

    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

            pillar();
            celestials();   // stars & moon clipping
            display1();     //aircraft
             grass1();      //grass layout
            grasselev();    //grassland elevation

            drawhouse();    //house function
            l_loop();       //outline
            hwindows();     // house window func
            fence();

            chrtr();    // S print

            glRotatef(theta[0],-1.0,0.0,0.0);      /*rotation of the fan*/
            glRotatef(theta[1],0.0,-1.0,0.0);       /*rotation of the fan*/
            glRotatef(theta[2],0.0,0.0,-1.0);       /*rotation of the fan*/

            fan();

    glutSwapBuffers();
    glFlush();
}

void idle()                         /*speed at start*/
{
    theta[axis]+=2.0;
    if(theta[axis]>360.0)
	  theta[axis]-=360.0;
    glutPostRedisplay();
}

void idle1()					    /*speed at 1st */
{theta[axis]+=4;
    if(theta[axis]>360.0)
	  theta[axis]-=360.0;
    glutPostRedisplay();
}

void idle2()					    /*speed at 2nd */
{theta[axis]+=6;
    if(theta[axis]>360.0)
	  theta[axis]-=360.0;
    glutPostRedisplay();
}

void idle3()					    /*speed at 3rd */
{theta[axis]+=8;
    if(theta[axis]>360.0)
	  theta[axis]-=360.0;
    glutPostRedisplay();
}
void idle4()					    /*speed at 4th */
{theta[axis]+=10;
    if(theta[axis]>360.0)
	  theta[axis]-=360.0;
    glutPostRedisplay();
}
void idle5()					    /*speed at 5th */
{theta[axis]+=12;
    if(theta[axis]>360.0)
	  theta[axis]-=360.0;
    glutPostRedisplay();
}

void keys(unsigned char key,int x,int y) /*keyboard function to implement the fan rotation*/
{
  if(key=='s')  //start speed
	{
	    glutIdleFunc(idle);
    }

  if(key=='1')  //speed-1
  {
      glutIdleFunc(idle1);
  }

  if(key=='2')  //speed-2
  {
      glutIdleFunc(idle2);
  }

  if(key=='3')  //speed-3
  {
      glutIdleFunc(idle3);
  }

 if(key=='4')   //speed-4
  {
      glutIdleFunc(idle4);
  }

 if(key=='5')   //speed-5
  {
      glutIdleFunc(idle5);
  }

  if(key=='q')  //stop fan
  {
      glutIdleFunc(NULL);
      //exit(0);
  }

    /* FOR AIRCRAFT */
    if(key=='f')
    {
        aircraftmov1();
    }

    if(key=='b')
    {
        aircraftmov2();
    }
}

 void demo_menu(int id)     //menu list demo
{
    switch(id)
    {
        case 3:exit(0);
         break;
    }
    glutPostRedisplay();
}

void color1(int id)
{
    switch(id)
    {
        case 1:global=1;
             break;
        case 2:global=2;
             break;
        case 3:global=3;
             break;
        case 4:global=4;
             break;
    }
    glutPostRedisplay();
}

void lit(int id)
{
        switch(id)
        {
            case 1:     clr=1;
                        break;
            case 2:     clr=0;
                        break;
        }
}

void func1(int id)
{
    switch(id)
    {
          case 1:glutIdleFunc(idle);
                  break;
          case 2:glutIdleFunc(NULL);
                 break;
          case 3:glutIdleFunc(idle1);
                 break;
          case 4:glutIdleFunc(idle2);
                 break;
          case 5:glutIdleFunc(idle3);
                 break;
          case 6:glutIdleFunc(idle4);
                 break;
          case 7:glutIdleFunc(idle5);
                 break;
    }
    glutPostRedisplay();
}

void tex2(int id)
{
    switch(id)
    {
        case 1:tex1=1;
             break;
        case 2:tex1=0;
             break;
    }
    glutPostRedisplay();
}

const int TEXDIM = 256;

int main(int argc,char **argv)
{
    printf("A Project by Sumanth BS");
    int color,op,text1,wcolor;
    GLfloat *tex;

      glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

      glutInitWindowPosition(0,0);
      glutInitWindowSize(2400,2600);
      glutCreateWindow("Windmill Env");
      //glutReshapeFunc(myreshape);
      myinit();

    color = glutCreateMenu(color1);
        glutAddMenuEntry("Default",1);
        glutAddMenuEntry("Brown",2);
        glutAddMenuEntry("Red",3);
        glutAddMenuEntry("Blue",4);


      op = glutCreateMenu(func1);
          glutAddMenuEntry("Start",1);
          glutAddMenuEntry("Stop",2);
          glutAddMenuEntry("Speed1",3);
          glutAddMenuEntry("Speed2",4);
          glutAddMenuEntry("Speed3",5);
          glutAddMenuEntry("Speed4",6);
          glutAddMenuEntry("Speed5",7);


      text1 = glutCreateMenu(tex2);
          glutAddMenuEntry("Enable",1);
          glutAddMenuEntry("Disable",2);

      wcolor = glutCreateMenu(lit);
            glutAddMenuEntry("Switch On",1);
            glutAddMenuEntry("Switch Off",2);

      glutCreateMenu(demo_menu);
        glutAddSubMenu("Fan color",color);
        glutAddSubMenu("E/D:Texture",text1);
        glutAddSubMenu("Operations",op);
        glutAddSubMenu("Window lighting",wcolor);
        glutAddMenuEntry("Exit Mainframe",3);
        glutAttachMenu(GLUT_RIGHT_BUTTON);

        glutDisplayFunc(display);
        glutKeyboardFunc(keys);


 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   tex = make_texture(TEXDIM, TEXDIM);
    glTexImage2D(GL_TEXTURE_2D, 0, 1, TEXDIM, TEXDIM, 0, GL_RED, GL_FLOAT, tex);
    free(tex);

 glutMainLoop();
    return 0;
}
