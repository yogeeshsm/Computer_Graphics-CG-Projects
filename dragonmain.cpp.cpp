#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//#include <GL/gl.h>
#include <GL/glut.h>
//#include <gl/glu.h>
#include <math.h>
#include <iostream>
using namespace std;
GLenum Mouse;

int prevx,prevy;

void v();
GLfloat camx,camy,camz;
unsigned char camera = 'r';
int Width = 1500;
int Height = 1200;
float tick=clock();
//angles of legs and trans
float tl1=0.0f;
float bl1=0.0f;
float tl2=0.0f;
float bl2=0.0f;
float tl3=0.0f;
float bl3=0.0f;
float tl4=0.0f;
float bl4=0.0f;
float tra1=0.0f;
float tra2=0.0f;
float tra3=0.0f;
float tra4=0.0f;
bool start=true;
bool p1=true;
//angles of wings
float wx1=10;
float wx2=0;
float wx3=0;
float wy1=0;
float wy2=0;
float wy3=0;
float wz1=0;
float wz2=0;
float wz3=0;
//speed of wings flapping
float spd=.1;
//flags
int moveflag=0;
int wag=0;
int tailflag=0;
int around=0;
int fly=0;
int mouthopen=0;
int mouthclose=1;
int mouthcount=0;
int fireflag=0;
int firestart=0;
int i = 0;
//angles and translation of torso.
float Ta=0;
float Tx=0;
float Tz=10*10*cos(0.0);
float Ty=0;
//angles of tail swipe
double tangle =0;
double mangle = 0;
double fpositionx = 0;
double fpositiony = 0;
double fpositionz = 0;
double yoffset = 0;
double zoffset = 0;
// Storage For Our Quadratic Objects
GLUquadricObj *quadratic;
//functions for drawing.
void drawTorso();
void drawtail();
void drawtail1();

void drawleg(int num);
void drawNeck();
void drawLeftWing();
void drawRightWing();

void drawleg1(int num);
void drawNeck1();
void drawLeftWing1();
void drawRightWing1();

void mouse(int button,int state,int x,int y);
void drawHead();
void drawHead1();
void drawGround();
void drawToe();
void drawToe1();
//functions for flying
void wingsdown();
void wingsup();
void soar();
void reset();

void v()
{
    glPushMatrix();
    glTranslatef(60,-80,60);
    glColor3f(0.7,0.3,0);
    glutSolidSphere(10,20,10);
    glPopMatrix();


}
void reset()
{
//   anglex=angley=anglez=0.0f;
   //pedalAngle=steering=0.0f;
   Mouse=GLUT_UP;
  // pedalAngle=speed=steering=0.0f;
   camx=camy=0.0f;
   camz=5.0f;
   //xpos=zpos=0.0f;
   //direction=0.0f;
}

void cb_keyboard(unsigned char c, int x, int y) {
  switch (c) {
  case 'q':
    exit (0);
    break;
  case 's':
    camera = 's';
    break;

  case 'l':
    camera = 'l';
    break;
  case 'f':
    camera = 'f';
    break;
  case 'b':
    camera = 'b';
    break;
  case 'a':
    camera = 'a';
    break;
  case 'u':
    camera = 'u';
    break;
  case 'r':
    camera = 'r';
    break;
  case 'c':
    camera = 'c';
    break;
 //walk
  case '1':
      moveflag=1;
      around=1;
    break;
  //use slashing of tail
  case '2':
    tick=clock();
    if(tailflag){
      tailflag=0;
    }
    else{
      tailflag=1;
    }
    break;
  //rotate
  case '3':
    tick=clock();
    if(wag){
      wag=0;
    }
    else{
      wag=1;
    }
    break;

//fly
  case '4':
    tick=clock();
    if(!fly){
      fly=1;
    }else{
        fly=4;
    }

    moveflag=0;
    break;

  case '5':
    tick=clock();

    moveflag=0;
    break;
//open mouth
  case '7':
    tick=clock();
	if(!mouthopen){
	  mouthopen = 1;
	  mouthclose = 0;
    }
    break;

//close mouth
  case '8':
    tick=clock();
    if(!mouthclose){
	  mouthclose = 1;
	  mouthopen = 0;
    }
    break;

//breath fire
  case '9':
    tick=clock();
	fireflag = 1;
  }

  glutPostRedisplay();
}


void cb_display()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45, 1.0, 0.1, 800.0 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( 2, 0, -275.0 );
    switch (camera) {
    case 's':
        glRotatef( 45, 1.0, 0 , 0.0 );
        break;

    case 'l':

        glRotatef( 180, 0, 1 , 0 );
        glTranslatef(0,0,50);
        break;

    case 'f':
        glRotatef( 90, 0.0, 1.0, 0.0 );
        break;
    case 'b':
        glRotatef( -90, 0.0, 1.0, 0.0 );
        break;
    case 'a':
        glRotatef( 90, 1.0, 0.0, 0.0 );
		glTranslatef(0,-80,0);
        break;
    case 'u':
        glRotatef( -90, 1.0, 0.0, 0.0 );
        break;
    case 'r':
        break;
    case 'c':
        //glRotatef( bangle+=45, 1.0, 0.0, 0.0 );
        break;
    }

    glPushMatrix();
    v();
    drawGround();
    glPopMatrix();
    glTranslatef(0.0f,-50.0f,0.0f);
    if(around){
        if(Ta<-360){
            Ta=0;
            Tx=0;
            around=0;
        }
        else{
            Tz=10*10*cos(Ta*3.14/180.0);
            Tx=10*10*sin(Ta*3.14/180.0);
            Ta-=.72;
            if(fly){
                if(fly==3)
                    Ty-=400.0/(360.0/.36)/4.0*spd;
                else if(fly==2) {
                    Ty+=1500.0/(360.0/.36)/4.0*spd;
                }
            }
        }
    }else if(fly==1){
          if(wx1<25){
              wx1+=.4;
              wx2+=.4;
              wx3+=.4;
          }else{
              around=1;
              fly=2;
          }
    }
    if(fly>1){
        if(spd>4)
            spd=4;

        if(fly==2){
            wingsdown();
        }else if(fly==3){
            wingsup();
        }else{
            soar();
        }
    }
    glTranslatef(Tx,Ty,Tz-10*10*cos(0.0));
    glRotatef(Ta,0.0f,1.0f,0.0f);
 glPushMatrix();
    glRotatef(90,0.0f,1.0f,0.0f);

    glPushMatrix();


    drawTorso();
   glPushMatrix();
    drawtail();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(15.0,-7.0,sqrt((9.25)*(9.25)-(7*7)));
    drawleg(1);
    glTranslatef(-30.0,0,0);
    drawleg(2);
    glTranslatef(0,0,-2*sqrt((9.25)*(9.25)-(7*7)));
    drawleg(3);
    glTranslatef(30.0,0,0);
    drawleg(4);
    glPopMatrix();
    glPushMatrix();
    drawNeck();
    glPopMatrix();
	glTranslatef(-10.0,5.0,10.0);
	drawLeftWing();
    glPopMatrix();
	glTranslatef(0.0,0.0,-20.0);
	drawRightWing();
    glPopMatrix();
	drawHead();
	glPopMatrix();
	glPopMatrix();






//    drawTorso();
   glPushMatrix();
  //  drawtail();
    drawtail1();
   glPopMatrix();
   glPushMatrix();
   glTranslatef(0.0,-7.0,52);
    drawleg1(1);
    //glTranslatef(-30.0,0,0);
  //  drawleg(2);

    glTranslatef(0,0,-2*sqrt((9.25)*(9.25)-(7*7)));
    drawleg1(3);
    //glTranslatef(30.0,0,0);
    //drawleg(4);
    glPopMatrix();
    glPushMatrix();
    drawNeck1();
    glPopMatrix();
	glTranslatef(-10.0,5.0,10.0);
drawLeftWing1();
    glPopMatrix();
	glTranslatef(0.0,0.0,-20.0);
	drawRightWing1();
    glPopMatrix();
	drawHead1();
	glPopMatrix();
	glPopMatrix();
	   gluLookAt(camx,camy,camz,  camx,0.0,0.0,  0.0,1.0,0.0);

    glutSwapBuffers();
    GLenum error = glGetError();
    if(error != GL_NO_ERROR)
        printf("ERROR: %s\n", gluErrorString(error));
}

void mouse(int button,int state,int x,int y)
{
   switch(button)
   {
      case GLUT_LEFT_BUTTON:
         if(state==GLUT_DOWN)
         {
            Mouse=GLUT_DOWN;
            prevx=x;
            prevy=y;
         }
         if(state==GLUT_UP)
         {
            Mouse=GLUT_UP;
         }
         break;
      case GLUT_RIGHT_BUTTON:
         /*   DO NOTHING   */
         break;
   }
   glutPostRedisplay();
}


void drawGround(){
    glTranslatef(0.0f,-100.0f,0.0f);
    glColor3f(139.0/255.0,69.0/255.0,19.0/255.0);
    glBegin(GL_QUADS);
	glVertex3f( -200.0f, 0.0f, 200.0f);
	glVertex3f(-200.0f,0.0f, -600.0f);
	glVertex3f( 200.0f,0.0f, -600.0f);
    glVertex3f( 200.0f,0.0f, 200.0f);
    glEnd();
}


void drawNeck1()
{
    double val0,val1, angle;
    double slice=0;
    double a=0.02;
    double b=-0.4;
    double c=7;
    glPushMatrix();
    glColor3f(0,0.5,1);
    glTranslatef(-5.0f,2.0f,45.0f);
    glScaled(1,1.7,1);
    glRotated(300,0,0,1);
    val0=7;
    angle=0;
    glRotatef(-90,0.0f,1.0f,0.0f);
    for(slice=1.0;slice<11;slice++){
        val1=a*slice*slice+b*slice+c;
        angle+=.2;
        glPushMatrix();
        gluCylinder(quadratic,val0,val1,1.4,36,36);
        glRotatef(-3,1.0f,0.0f,0.0f);
        glTranslatef(0.0f,0.0f,1.0f);
        val0=val1;
    }
    for(slice=1.0;slice<21;slice++){
        angle+=.1;
        glPushMatrix();
        gluCylinder(quadratic,5,5,1.3,36,36);
        glRotatef(-3+angle,1.0f,0.0f,0.0f);
        glTranslatef(0.0f,0.0f,1.0f);
        val0=val1;
    }
    for(slice=1.0;slice<41;slice++){
        glPopMatrix();
        glPopMatrix();
    }
    glPushMatrix();
    glTranslatef(-8,55,45);
    glutSolidSphere(6.8,10,10);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0.5,0);
    glTranslatef(-2.9,0,45);
    glutSolidSphere(15,10,10);
    glColor3f(02,0.5,0);
    glTranslatef(-3,10,0);
    glutSolidSphere(12,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0, 45);
glRotatef(90,0,1,0);
    glutSolidCone(10,50,10,10);
    glColor3f(0,1,01);
    glTranslatef(0,0,51);
     glBegin(GL_TRIANGLES);
	glVertex3f( 0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f,-3.0f, -3.0f);
	glVertex3f( 0.0f,3.0f, -3.0f);
    glEnd();
    glColor3f(1,0,0);

glPopMatrix();

glColor3f(1,0,0);

        glPopMatrix();

}

void drawtail1()
{
    double val0,val1;
    double slice=0;
    double a=1.0/3200.0;
    double b=-9.0/80.0;
    double c=7;
glColor3f(1,0,0);
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-45.0f,1.0f,3.0f);
    val0=7;
    for(slice=1.0;slice<10;slice++){
        val1=a*slice*slice+b*slice+c;
        glPushMatrix();
    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(80,0,10);
       //gluCylinder(quadratic,val0,val1,0,36,36);

       // glutSolidCone(5,10,10,10);
        glPopMatrix();
     //glPopMatrix();

        if(tailflag==1){
            if(tangle<2){
                tangle+=.0025;
            }
            else{
                tailflag=2;
                Sleep(200);
            }
        }else if(tailflag&&tangle>0){
             tangle-=.025;
        }else if(tailflag!=0){
              Sleep(10);
              tangle=0;
              tailflag=0;
        }
        if(wag==1){
            if(tangle<2){
                tangle+=.005;
            }
            else{
                wag=2;
            }
        }else if(wag==2&&tangle>-2){
             tangle-=.005;
        }else if(wag){
            wag=1;
        }
        if(!wag)
            glRotatef(-tangle,1.0f,1.0f,0.0f);
        else
            glRotatef(-tangle,0.0f,1.0f,0.0f);
        glTranslatef(0.0f,0.0f,1.0f);
        val0=val1;
    }
    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
	glVertex3f( 0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f,-3.0f, -3.0f);
	glVertex3f( 0.0f,3.0f, -3.0f);
    glEnd();
    glPopMatrix();
    for(slice=1.0;slice<81;slice++){
        glPopMatrix();
    }
    glPopMatrix();
}

void drawleg1(int num)
{
glPushMatrix();
glColor3f(0,1,0);
    if(around==0){
        moveflag=0;
        tl1=0.0f;
        bl1=0.0f;
        tl2=0.0f;
        bl2=0.0f;
        tl3=0.0f;
        bl3=0.0f;
        tl4=0.0f;
        bl4=0.0f;
        tra1=0.0f;
        tra2=0.0f;
        tra3=0.0f;
        tra4=0.0f;
        start=true;
        p1=true;
    }
    if(moveflag==1){
        if(tl1>-30&&p1){
            tl1-=.3;
            bl1+=.3;
            tl2-=.3;
            bl2+=.3;
            bl3+=.15;
            bl4+=.15;
            if(!start){
                tra3-=.3/30.0*5.0;
                tra4-=.3/30.0*5.0;
            }
        }else if(tra1<5){
            p1=false;
            tl1+=.3;
            bl1-=.3;
            tl2+=.3;
            bl2-=.3;
            bl3-=.15;
            bl4-=.15;
            tra1+=.3/30.0*5.0;
            tra2+=.3/30.0*5.0;
       }else{
           moveflag=2;
           p1=true;
       }
    }else if(moveflag==2){
        if(tl3>-30&&p1){
            tl3-=.3;
            bl3+=.3;
            tl4-=.3;
            bl4+=.3;
            bl1+=.15;
            bl2+=.15;
            tra1-=.3/30.0*5.0;
            tra2-=.3/30.0*5.0;
        }else if(tra3<5){
            p1=false;
            tl3+=.3;
            bl3-=.3;
            tl4+=.3;
            bl4-=.3;
            bl1-=.15;
            bl2-=.15;
            tra3+=.3/30.0*5.0;
            tra4+=.3/30.0*5.0;
            start=false;
        }else{
            p1=true;
            moveflag=1;
        }
    }

    glPushMatrix();
    if(num==1){
        glTranslatef(tra1,0,0);
        glRotatef(tl1,0,0,1);
    }
    else if (num==2){
        glTranslatef(tra2,0,0);
        glRotatef(tl2,0,0,1);
    }
    else if (num==3){
        glTranslatef(tra3,0,0);
        glRotatef(tl3,0,0,1);
    }
    else if (num==4){
        glTranslatef(tra4,0,0);
        glRotatef(tl4,0,0,1);
    }
    glColor3f(0,0,0);
    glutSolidSphere(2.5, 10, 10);
    glTranslatef(0,-1.25,0);
    glPushMatrix();
    glRotatef(90,1.0f,0.0f,0.0f);
    glColor3f(.7,0,0);
    gluCylinder(quadratic,2.5,1.25,10,15,15);
    glRotatef(-90,1.0f,0.0f,0.0f);
    glTranslatef(0,-10,0);
    glColor3f(0,0,0);
    if(num==1)
        glRotatef(bl1,0,0,1);
    else if (num==2)
        glRotatef(bl2,0,0,1);
    else if (num==3)
        glRotatef(bl3,0,0,1);
    else if (num==4)
        glRotatef(bl4,0,0,1);
    glutSolidSphere(1.5, 10, 10);
    glPushMatrix();
    glColor3f(.7,0,0);
    glRotatef(90,1.0f,0.0f,0.0f);
    gluCylinder(quadratic,1.25,0.5,6.5,15,15);
    glTranslatef(0,0,6.5);
    if(num==1)
        glRotatef(-bl1,0,0,1);
    else if (num==2)
        glRotatef(-bl2,0,0,1);
    else if (num==3)
        glRotatef(-bl3,0,0,1);
    else if (num==4)
        glRotatef(-bl4,0,0,1);

    gluCylinder(quadratic,2,2.5,3.5,4,4);
    glPushMatrix();    //draw Toes
    glRotatef(-90,0,0,1);
    glRotatef(90,0,1,0);
    glTranslatef(-1.25,-3.5,1.25);
    glColor3f(0,0,0);
    drawToe();
    glTranslatef(-0.1,0,-1);
    drawToe();
    glTranslatef(-0.1,0,-1);
    drawToe();
    glTranslatef(0.1,0,-1);
    drawToe();
    glTranslatef(0.1,0,-1);
    drawToe();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}


void drawtail()
{
    double val0,val1;
    double slice=0;
    double a=1.0/3200.0;
    double b=-9.0/80.0;
    double c=7;
    glPushMatrix();
    glColor3f(0,1,0);
    glTranslatef(0.0f,0.0f,30.0f);
    val0=7;
    for(slice=1.0;slice<81;slice++){
        val1=a*slice*slice+b*slice+c;
        glPushMatrix();
        gluCylinder(quadratic,val0,val1,1,36,36);
        if(tailflag==1){
            if(tangle<2){
                tangle+=.0025;
            }
            else{
                tailflag=2;
                Sleep(200);
            }
        }else if(tailflag&&tangle>0){
             tangle-=.025;
        }else if(tailflag!=0){
              Sleep(10);
              tangle=0;
              tailflag=0;
        }
        if(wag==1){
            if(tangle<2){
                tangle+=.005;
            }
            else{
                wag=2;
            }
        }else if(wag==2&&tangle>-2){
             tangle-=.005;
        }else if(wag){
            wag=1;
        }
        if(!wag)
            glRotatef(-tangle,1.0f,1.0f,0.0f);
        else
            glRotatef(-tangle,0.0f,1.0f,0.0f);
        glTranslatef(0.0f,0.0f,1.0f);
        val0=val1;
    }
    glPushMatrix();
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLES);
	glVertex3f( 0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f,-3.0f, -3.0f);
	glVertex3f( 0.0f,3.0f, -3.0f);
    glEnd();
    glPopMatrix();
    for(slice=1.0;slice<81;slice++){
        glPopMatrix();
    }
    glPopMatrix();
}


void drawTorso(){
    double val0,val1;
    double slice=0;
    double a=-1.0/300.0;
    double b=0;
    double c=10;
    glColor3f(2,0.5,0);


    glPushMatrix();
    val0=10;
    for(slice=1.0;slice<31;slice++){
        val1=a*slice*slice+b*slice+c;
        gluCylinder(quadratic,val0,val1,1,36,36);
        glTranslatef(0.0f,0.0f,1.0f);

        val0=val1;
    }

    glPopMatrix();
    glPushMatrix();
    val0=10;

    glRotatef(180,0.0f,1.0f,0.0f);
    for(slice=0.0;slice<30;slice++){
        val1=a*slice*slice+b*slice+c;
        gluCylinder(quadratic,val0,val1,1.0f,36,36);
        glTranslatef(0.0f,0.0f,1.0f);
        val0=val1;

    }


    glPopMatrix();
}
/*
void cb_display()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45, 1.0, 0.1, 800.0 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( 2, 0, -275.0 );
    switch (camera) {
    case 's':
        glRotatef( 45, 1.0, 0 , 0.0 );
        break;
    case 'f':
        glRotatef( 90, 0.0, 1.0, 0.0 );
        break;
    case 'b':
        glRotatef( -90, 0.0, 1.0, 0.0 );
        break;
    case 'a':
        glRotatef( 90, 1.0, 0.0, 0.0 );
		glTranslatef(0,-80,0);
        break;
    case 'u':
        glRotatef( -90, 1.0, 0.0, 0.0 );
        break;
    case 'r':
        break;
    case 'c':
        //glRotatef( bangle+=45, 1.0, 0.0, 0.0 );
        break;
    }

    glPushMatrix();
    drawGround();
    glPopMatrix();
    glTranslatef(0.0f,-50.0f,0.0f);
    if(around){
        if(Ta<-360){
            Ta=0;
            Tx=0;
            around=0;
        }
        else{
            Tz=10*10*cos(Ta*3.14/180.0);
            Tx=10*10*sin(Ta*3.14/180.0);
            Ta-=.72;
            if(fly){
                if(fly==3)
                    Ty-=400.0/(360.0/.36)/4.0*spd;
                else if(fly==2) {
                    Ty+=1500.0/(360.0/.36)/4.0*spd;
                }
            }
        }
    }else if(fly==1){
          if(wx1<25){
              wx1+=.4;
              wx2+=.4;
              wx3+=.4;
          }else{
              around=1;
              fly=2;
          }
    }
    if(fly>1){
        if(spd>4)
            spd=4;

        if(fly==2){
            wingsdown();
        }else if(fly==3){
            wingsup();
        }else{
            soar();
        }
    }
    glTranslatef(Tx,Ty,Tz-10*10*cos(0.0));
    glRotatef(Ta,0.0f,1.0f,0.0f);
 glPushMatrix();
    glRotatef(90,0.0f,1.0f,0.0f);
    drawTorso();
   glPushMatrix();
    drawtail();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(15.0,-7.0,sqrt((9.25)*(9.25)-(7*7)));
    drawleg(1);
    glTranslatef(-30.0,0,0);
    drawleg(2);
    glTranslatef(0,0,-2*sqrt((9.25)*(9.25)-(7*7)));
    drawleg(3);
    glTranslatef(30.0,0,0);
    drawleg(4);
    glPopMatrix();
    glPushMatrix();
    drawNeck();
    glPopMatrix();
	glTranslatef(-10.0,5.0,10.0);
	drawLeftWing();
    glPopMatrix();
	glTranslatef(0.0,0.0,-20.0);
	drawRightWing();
    glPopMatrix();
	drawHead();
	glPopMatrix();
	glPopMatrix();
	   gluLookAt(camx,camy,camz,  camx,0.0,0.0,  0.0,1.0,0.0);

    glutSwapBuffers();
    GLenum error = glGetError();
    if(error != GL_NO_ERROR)
        printf("ERROR: %s\n", gluErrorString(error));

}
*/


void drawNeck(){
    double val0,val1, angle;
    double slice=0;
    double a=0.02;
    double b=-0.4;
    double c=7;
    glPushMatrix();
    glColor3f(0.85,1,0);
    glTranslatef(-30.0f,0.0f,0.0f);
    val0=7;
    angle=0;
    glRotatef(-90,0.0f,1.0f,0.0f);
    for(slice=1.0;slice<11;slice++){
        val1=a*slice*slice+b*slice+c;
        angle+=.2;
        glPushMatrix();
        gluCylinder(quadratic,val0,val1,1.4,36,36);
        glRotatef(-3,1.0f,0.0f,0.0f);
        glTranslatef(0.0f,0.0f,1.0f);
        val0=val1;
    }
    for(slice=1.0;slice<21;slice++){
        angle+=.1;
        glPushMatrix();
        gluCylinder(quadratic,5,5,1.3,36,36);
        glRotatef(-3+angle,1.0f,0.0f,0.0f);
        glTranslatef(0.0f,0.0f,1.0f);
        val0=val1;
    }
    for(slice=1.0;slice<41;slice++){
        glPopMatrix();
        glPopMatrix();
    }
        glPopMatrix();
}


void drawleg(int num)
{
    if(around==0){
        moveflag=0;
        tl1=0.0f;
        bl1=0.0f;
        tl2=0.0f;
        bl2=0.0f;
        tl3=0.0f;
        bl3=0.0f;
        tl4=0.0f;
        bl4=0.0f;
        tra1=0.0f;
        tra2=0.0f;
        tra3=0.0f;
        tra4=0.0f;
        start=true;
        p1=true;
    }
    if(moveflag==1){
        if(tl1>-30&&p1){
            tl1-=.3;
            bl1+=.3;
            tl2-=.3;
            bl2+=.3;
            bl3+=.15;
            bl4+=.15;
            if(!start){
                tra3-=.3/30.0*5.0;
                tra4-=.3/30.0*5.0;
            }
        }else if(tra1<5){
            p1=false;
            tl1+=.3;
            bl1-=.3;
            tl2+=.3;
            bl2-=.3;
            bl3-=.15;
            bl4-=.15;
            tra1+=.3/30.0*5.0;
            tra2+=.3/30.0*5.0;
       }else{
           moveflag=2;
           p1=true;
       }
    }else if(moveflag==2){
        if(tl3>-30&&p1){
            tl3-=.3;
            bl3+=.3;
            tl4-=.3;
            bl4+=.3;
            bl1+=.15;
            bl2+=.15;
            tra1-=.3/30.0*5.0;
            tra2-=.3/30.0*5.0;
        }else if(tra3<5){
            p1=false;
            tl3+=.3;
            bl3-=.3;
            tl4+=.3;
            bl4-=.3;
            bl1-=.15;
            bl2-=.15;
            tra3+=.3/30.0*5.0;
            tra4+=.3/30.0*5.0;
            start=false;
        }else{
            p1=true;
            moveflag=1;
        }
    }

    glPushMatrix();
    if(num==1){
        glTranslatef(tra1,0,0);
        glRotatef(tl1,0,0,1);
    }
    else if (num==2){
        glTranslatef(tra2,0,0);
        glRotatef(tl2,0,0,1);
    }
    else if (num==3){
        glTranslatef(tra3,0,0);
        glRotatef(tl3,0,0,1);
    }
    else if (num==4){
        glTranslatef(tra4,0,0);
        glRotatef(tl4,0,0,1);
    }
    glColor3f(0,1,0);
    glutSolidSphere(2.5, 10, 10);
    glTranslatef(0,-1.25,0);
    glPushMatrix();
    glRotatef(90,1.0f,0.0f,0.0f);
    glColor3f(.7,01,0);
    gluCylinder(quadratic,2.5,1.25,10,15,15);
    glRotatef(-90,1.0f,0.0f,0.0f);
    glTranslatef(0,-10,0);
    glColor3f(2.5,0.5,0.5);
    if(num==1)
        glRotatef(bl1,0,0,1);
    else if (num==2)
        glRotatef(bl2,0,0,1);
    else if (num==3)
        glRotatef(bl3,0,0,1);
    else if (num==4)
        glRotatef(bl4,0,0,1);
    glutSolidSphere(1.5, 10, 10);
    glPushMatrix();
    glColor3f(.7,01,0);
    glRotatef(90,1.0f,0.0f,0.0f);
    gluCylinder(quadratic,1.25,0.5,6.5,15,15);
    glTranslatef(0,0,6.5);
    if(num==1)
        glRotatef(-bl1,0,0,1);
    else if (num==2)
        glRotatef(-bl2,0,0,1);
    else if (num==3)
        glRotatef(-bl3,0,0,1);
    else if (num==4)
        glRotatef(-bl4,0,0,1);
    gluCylinder(quadratic,0.5,2.5,3.5,4,4);
    glPushMatrix();    //draw Toes
    glRotatef(-90,0,0,1);
    glRotatef(90,0,1,0);
    glTranslatef(-1.25,-3.5,1.25);
    glColor3f(0,0,0);
    drawToe();
    glTranslatef(-0.1,0,-1);
    drawToe();
    glTranslatef(-0.1,0,-1);
    drawToe();
    glTranslatef(0.1,0,-1);
    drawToe();
    glTranslatef(0.1,0,-1);
    drawToe();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}



void drawToe(){
    glBegin(GL_QUADS);
    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( -2.0f,0.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 1.5f);
    glVertex3f( -2.0f,0.0f, 1.5f);
    glVertex3f( 0.0f, 0.0f, 1.5f);
    glEnd();
}




void drawLeftWing(){
   glPushMatrix();
   glRotatef(-wx1,1,0,0);
   glColor3f(0,01,0);
   glutSolidSphere(2, 10, 10);
   glColor3f(0,01,0);
   glBegin(GL_POLYGON);
   glVertex3f( 0.0f, 0.0f, 0.0f);
   glVertex3f( 40.0f, 0.0f, 16.0f);
   glVertex3f( 0.0f, 0.0f, 16.0f);
   glEnd();
   glColor3f(01,01,0);
   glTranslatef(0,0,1);
   gluCylinder(quadratic,1.5,1.5,15,36,36);
   glColor3f(0,01,0);
   glTranslatef(0,0,15);
   glRotatef(-wx2,1,0,0);
   glutSolidSphere(2, 10, 10);
   glColor3f(01,01,0);
   glBegin(GL_POLYGON);
   glVertex3f( 0.0f, 0.0f, 0.0f);
   glVertex3f( 40.0f, 0.0f, 0.0f);
   glVertex3f( 40.0f, 0.0f, 31.0f);
   glVertex3f( 0.0f, 0.0f, 31.0f);
   glEnd();
   glColor3f(0,01,0);
   glRotatef(90,0.0,1.0,0.0);
   gluCylinder(quadratic,.2,.2,40,36,36);
   glRotatef(270,0.0,1.0,0.0);
   glTranslatef(0,0,0);
   gluCylinder(quadratic,1.5,1.5,30,36,36);
   glColor3f(01,01,0);
   glTranslatef(0,0,30);
   glRotatef(-wx3,1,0,0);
   glutSolidSphere(2, 10, 10);
   glColor3f(0,01,0);
   glBegin(GL_POLYGON);
   glVertex3f( 0.0f, 0.0f, 0.0f);
   glVertex3f( 40.0f, 0.0f, 0.0f);
   glVertex3f( 0.0f, 0.0f, 62.0f);
   glEnd();
   glColor3f(1,01,0);
   glRotatef(90,0.0,1.0,0.0);
   gluCylinder(quadratic,0.2,0.2,40 ,36,36);
   glRotatef(270,0.0,1.0,0.0);
   glTranslatef(0,0,1);
   gluCylinder(quadratic,1.5,1.5,60,36,36);
   glColor3f(0,0,0);
   glTranslatef(0,0,60.5);
   glutSolidSphere(1.5, 10, 10);
}
void drawRightWing()
{
   glPushMatrix();
   glRotatef(wx1,1,0,0);
   glColor3f(0,1,0);
   glutSolidSphere(2, 10, 10);
   glColor3f(0,1,0);
   glBegin(GL_POLYGON);
   glVertex3f( 0.0f, 0.0f, 0.0f);
   glVertex3f( 40.0f, 0.0f, -17.0f);
   glVertex3f( 0.0f, 0.0f, -17.0f);
   glEnd();
   glColor3f(1,1,0);
   glTranslatef(0,0,-16);
   gluCylinder(quadratic,1.5,1.5,15,36,36);
   glColor3f(0,1,0);
   glTranslatef(0,0,-1);
   glRotatef(wx2,1,0,0);
   glutSolidSphere(2, 10, 10);
   glColor3f(1,1,0);
   glBegin(GL_POLYGON);
   glVertex3f( 0.0f, 0.0f, 0.0f);
   glVertex3f( 40.0f, 0.0f, 0.0f);
   glVertex3f( 40.0f, 0.0f, -32.0f);
   glVertex3f( 0.0f, 0.0f, -32.0f);
   glEnd();
   glColor3f(0,01,0);
   glRotatef(90,0.0,1.0,0.0);
   gluCylinder(quadratic,.2,.2,40,36,36);
   glRotatef(270,0.0,1.0,0.0);
   glTranslatef(0,0,-31);
   gluCylinder(quadratic,1.5,1.5,30,36,36);
   glColor3f(0,0,0);
   glTranslatef(0,0,-1);
   glRotatef(wx3,1,0,0);
   glutSolidSphere(2, 10, 10);
   glColor3f(0,1,0);
   glBegin(GL_POLYGON);
   glVertex3f( 0.0f, 0.0f, 0.0f);
   glVertex3f( 40.0f, 0.0f, 0.0f);
   glVertex3f( 0.0f, 0.0f, -63.0f);
   glEnd();
   glColor3f(01,01,0);
   glRotatef(90,0.0,1.0,0.0);
   gluCylinder(quadratic,0.2,0.2,40 ,36,36);
   glRotatef(270,0.0,1.0,0.0);
   glTranslatef(0,0,-61);
   gluCylinder(quadratic,1.5,1.5,60,36,36);
   glColor3f(0,0,0);
   glTranslatef(0,0,-.5);
   glutSolidSphere(1.5, 10, 10);
}





void drawLeftWing1()
{
    glPushMatrix();





    glPushMatrix();
    //glColor3f(0,1,0);
    glTranslatef(0,40,33);


    glutSolidSphere(2,10,10);
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-1,-1,-2);
glBegin(GL_QUADS);

    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( -2.0f,0.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 1.5f);
    glVertex3f( -2.0f,0.0f, 1.5f);
    glVertex3f( 0.0f, 0.0f, 1.5f);
    glEnd();
     glTranslatef(-1,0,1);
glBegin(GL_QUADS);

    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( -2.0f,0.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 1.5f);
    glVertex3f( -2.0f,0.0f, 1.5f);
    glVertex3f( 0.0f, 0.0f, 1.5f);
    glEnd();
     glTranslatef(0,0,1);
glBegin(GL_QUADS);

    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( -2.0f,0.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 1.5f);
    glVertex3f( -2.0f,0.0f, 1.5f);
    glVertex3f( 0.0f, 0.0f, 1.5f);
    glEnd();
     glTranslatef(0,0,2.5);
glBegin(GL_QUADS);

    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( -2.0f,0.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 1.5f);
    glVertex3f( -2.0f,0.0f, 1.5f);
    glVertex3f( 0.0f, 0.0f, 1.5f);
    glEnd();
         glTranslatef(0,0,1);
glBegin(GL_QUADS);

    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( -2.0f,0.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 1.5f);
    glVertex3f( -2.0f,0.0f, 1.5f);
    glVertex3f( 0.0f, 0.0f, 1.5f);
    glEnd();
         glTranslatef(0,0,1);
glBegin(GL_QUADS);

    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( -2.0f,0.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 0.0f);
    glVertex3f( 0.75f, 3.0f, 1.5f);
    glVertex3f( -2.0f,0.0f, 1.5f);
    glVertex3f( 0.0f, 0.0f, 1.5f);
    glEnd();
    glPopMatrix();
glColor3f(1,0,0);
    glTranslatef(0,0,4.5);

    glutSolidSphere(2,10,10);

    glPopMatrix();

    glTranslatef(4,-10,40);
   glPushMatrix();
   glRotatef(-wx1-80,1,0,0);
glRotatef(-90,0,0,1);
   glColor3f(0,0,0);
  // glutSolidSphere(2, 10, 10);
   glColor3f(0,0,1);
   glBegin(GL_POLYGON);
   glVertex3f( 7.0f, 0.0f, 0.0f);
   glVertex3f( 20.0f, 0.0f, 17.0f);
   glVertex3f( 0.0f, 0.0f, 17.0f);
   glEnd();
   glColor3f(1,0,0);
   glTranslatef(0,0,1);
  // gluCylinder(quadratic,1.5,1.5,15,36,36);
   glColor3f(0,0,0);
   glTranslatef(0,0,15);
   glRotatef(-wx2,1,0,0);
   glutSolidSphere(2, 10, 10);
   glColor3f(0,0,1);
   glBegin(GL_POLYGON);
   glVertex3f( 0.0f, 0.0f, 0.0f);
   glVertex3f( 20.0f, 0.0f, 0.0f);
   glVertex3f( 20.0f, 0.0f, 31.0f);
   glVertex3f( 0.0f, 0.0f, 31.0f);
   glEnd();
   glColor3f(1,0,0);
   glRotatef(90,0.0,1.0,0.0);
   gluCylinder(quadratic,.2,.2,20,36,36);
   glRotatef(270,0.0,1.0,0.0);
   glTranslatef(0,0,1);
   gluCylinder(quadratic,1.5,1.5,30,36,36);
   glColor3f(0,0,0);
   glTranslatef(0,0,30);
   glRotatef(-wx3,1,0,0);
   glutSolidSphere(2, 10, 10);
   glColor3f(0,0,1);
   glBegin(GL_POLYGON);
   glVertex3f( 0.0f, 0.0f, 0.0f);
   glVertex3f( 20.0f, 0.0f, 0.0f);
   glVertex3f( 7.0f, 0.0f, 17.0f);
   glEnd();
   glColor3f(1,0,0);
   glRotatef(90,0.0,1.0,0.0);
   gluCylinder(quadratic,0.2,0.2,20 ,36,36);
   glRotatef(270,0.0,1.0,0.0);
   glTranslatef(0,0,1);
  // gluCylinder(quadratic,1.5,1.5,60,36,36);
   glColor3f(0,0,0);
   glTranslatef(0,0,60.5);
  // glutSolidSphere(1.5, 10, 10);
   glPopMatrix();
}
void drawRightWing1()
{
   glPushMatrix();
   glTranslatef(4,-10,50);
   glPushMatrix();

   glRotatef(wx1+80,1,0,0);
   glRotatef(-90,0,0,1);
   glColor3f(0,0,0);
   //glutSolidSphere(2, 10, 10);
   glColor3f(0,0,1);
   glBegin(GL_POLYGON);
   glVertex3f( 7.0f, 0.0f, 0.0f);
   glVertex3f( 20.0f, 0.0f, -17.0f);
   glVertex3f( 0.0f, 0.0f, -17.0f);
   glEnd();
   glColor3f(1,0,0);
   glTranslatef(0,0,-16);
  // gluCylinder(quadratic,1.5,1.5,0,36,36);

   glColor3f(0,0,0);
   glTranslatef(0,0,-1);
   glRotatef(wx2,1,0,0);
   glutSolidSphere(2, 10, 10);
   glColor3f(0,0,1);
   glBegin(GL_POLYGON);
   glVertex3f( 0.0f, 0.0f, 0.0f);
   glVertex3f( 20.0f, 0.0f, 0.0f);
   glVertex3f( 20.0f, 0.0f, -32.0f);
   glVertex3f( 0.0f, 0.0f, -32.0f);
   glEnd();
   glColor3f(1,0,0);
   glRotatef(90,0.0,1.0,0.0);
   gluCylinder(quadratic,.2,.2,20,36,36);
   glRotatef(270,0.0,1.0,0.0);
   glTranslatef(0,0,-31);
   gluCylinder(quadratic,1.5,1.5,30,36,36); //beech wala
   glColor3f(0,0,0);
   glTranslatef(0,0,-1);
   glRotatef(wx3,1,0,0);
   glutSolidSphere(2, 10, 10);
   glColor3f(0,0,1);
   glBegin(GL_POLYGON);
   glVertex3f( 0.0f, 0.0f, 0.0f);
   glVertex3f( 20.0f, 0.0f, 0.0f);
   glVertex3f( 7.0f, 0.0f, -15.0f);
   glEnd();
   glColor3f(1,0,0);
   glRotatef(90,0.0,1.0,0.0);
   gluCylinder(quadratic,0.2,0.2,20 ,36,36);
   glRotatef(270,0.0,1.0,0.0);
   glTranslatef(0,0,-61);
   //gluCylinder(quadratic,1.5,1.5,60,36,36);
   glColor3f(0,0,0);
   glTranslatef(0,0,-.5);
  // glutSolidSphere(1.5, 10, 10);


    glPopMatrix();
}


void wingsdown()
{
            wx1-=spd*2;
            wx2-=spd*2;
            wx3-=spd*2;
            if(spd<2)
                spd+=.1;
            if(wx1<=-5){
                fly=3;
                spd+=.1;
                wx1=-5;
                wx2=-5;
                wx3=-5;
            }
}


void wingsup()
{
    wx1+=spd;
    wx2+=spd;
    wx3+=spd;
    if(wx1>=25){
        fly=2;
        spd+=.1;
        wx1=25;
        wx2=25;
        wx3=25;
    }
}

void soar()
{
    if(wx1<0){
        wx1+=.2;
        wx2+=.2;
        wx3+=.2;
        if(wx1>-.01){
            wx1=0;
        }
    }else if(wx1>0){
        if(wx1<.01){
            wx1=0;
        }
        wx1-=.5;
        wx2-=.5;
        wx3-=.5;
    }else if(Ty>.5){
        wx1=0;
        wx2=0;
        wx3=0;
        around=1;
        Ty-=103.85966/(360.0/.36);

    }else{
        Ty=0;
        fly=0;
        around=0;
    }
}

void drawHead(){
   glPushMatrix();
   glColor3f(2.0,0.5,0);
   glTranslatef(-50,10,10);
   glTranslatef(3,0,0);
   glutSolidSphere(5,10,10);
   glTranslatef(-3,0,0);
   //back of head
   glBegin(GL_POLYGON);
      glVertex3f(6.0f,5.0f,6.0f);
      glVertex3f(6.0f,5.0f,-6.0f);
      glVertex3f(6.0f,-6.0f,-6.0f);
      glVertex3f(6.0f,-6.0f,6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(6.0f,5.0f,6.0f);
      glVertex3f(0.0f,5.0f,6.0f);
      glVertex3f(0.0f,5.0f,-6.0f);
      glVertex3f(6.0f,5.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(6.0f,-6.0f,6.0f);
      glVertex3f(0.0f,-6.0f,6.0f);
      glVertex3f(0.0f,-6.0f,-6.0f);
      glVertex3f(6.0f,-6.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(6.0f,5.0f,6.0f);
      glVertex3f(0.0f,5.0f,6.0f);
      glVertex3f(0.0f,-6.0f,6.0f);
      glVertex3f(6.0f,-6.0f,6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(6.0f,5.0f,-6.0f);
      glVertex3f(0.0f,5.0f,-6.0f);
      glVertex3f(0.0f,-6.0f,-6.0f);
      glVertex3f(6.0f,-6.0f,-6.0f);
   glEnd();
   //top of jaw
   //glColor3f(0,0,1);
   glTranslatef(0,-3,0);
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,6.0f);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
      glVertex3f(0.0f,1.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,-6.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
      glVertex3f(-13.0f,4.0f,-4.0f);
      glVertex3f(0.0f,8.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,6.0f);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,4.0f,4.0f);
      glVertex3f(0.0f,8.0f,6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,8.0f,6.0f);
      glVertex3f(-13.0f,4.0f,4.0f);
      glVertex3f(-13.0f,4.0f,-4.0f);
      glVertex3f(0.0f,8.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,4.0f,4.0f);
      glVertex3f(-13.0f,4.0f,-4.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
   glEnd();
    //eyes
    glPushMatrix();
    glColor3f(2,0,0);
    glTranslatef(0,1,0);
    glTranslatef(0,7,5.65);
    glColor3f(1,1,1);
    glutSolidSphere(2,20,20);
    glTranslatef(-2,0,0);
    glColor3f(0,0,1);
    glutSolidSphere(.5,10,10);
    glTranslatef(0,0,-11);
    glutSolidSphere(.5,10,10);
    glColor3f(1,1,1);
    glTranslatef(2,0,0);
    glutSolidSphere(2,20,20);
    glPopMatrix();
   //bottom of jaw

   if(mouthopen){
	   if(mouthcount<180){
          mangle+=.25;
		  mouthcount++;
	   }
   }
   if(mouthclose){
	   if(mouthcount>0){
	      mangle-=.25;
		  mouthcount--;
	   }
   }
   glRotatef(mangle,0.0f,0.0f,1.0f);
   glTranslatef(1,0,0);
   glColor3f(2,0.5,0);
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,6.0f);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
      glVertex3f(0.0f,1.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,-3.0f,6.0f);
      glVertex3f(-13.0f,-1.0f,4.0f);
      glVertex3f(-13.0f,-1.0f,-4.0f);
      glVertex3f(0.0f,-3.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,-1.0f,4.0f);
      glVertex3f(-13.0f,-1.0f,-4.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,6.0f);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,-1.0f,4.0f);
      glVertex3f(0.0f,-3.0f,6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,-6.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
      glVertex3f(-13.0f,-1.0f,-4.0f);
      glVertex3f(0.0f,-3.0f,-6.0f);
   glEnd();
   glRotatef(-mangle,0.0f,0.0f,1.0f);
   if(fireflag){
      fireflag = 0;
	  firestart = 1;
   }
   if(firestart == 1){
      glColor3f(1.0,0,0);
	  fpositionx +=.25;
	  fpositiony +=.1;
	  glTranslatef(-fpositionx,-fpositiony,0.0);
      glutSolidSphere(3,10,10);
	  fpositionz+=.01;
	  yoffset += .005;
      glColor3f(1.0,0.62,0);
	  for(i = 0; i<10; i++){
		 zoffset = fpositionz * i;
	     glTranslatef(0,0,fpositionz + zoffset);
	     glutSolidSphere(1,10,10);
	     glTranslatef(0,0,-fpositionz*2 - zoffset*2);
	     glutSolidSphere(1,10,10);
		 glTranslatef(0,0,fpositionz + zoffset);
	  }
	  glTranslatef(0,yoffset,0);
      glColor3f(1,1 ,0);
	  glutSolidSphere(1,10,10);
	  for(i = 0; i<8; i++){
         zoffset = fpositionz * i;
		 glTranslatef(0,0,fpositionz + zoffset);
	     glutSolidSphere(.5,10,10);
	     glTranslatef(0,0,-fpositionz*2 - zoffset*2);
	     glutSolidSphere(.5,10,10);
		 glTranslatef(0,0,fpositionz + zoffset);
	  }
	  glTranslatef(0,-yoffset*2,0);
	  glutSolidSphere(.5,10,10);
	  for(i = 0; i<8; i++){
         zoffset = fpositionz * i;
		 glTranslatef(0,0,fpositionz + zoffset);
	     glutSolidSphere(.5,10,10);
	     glTranslatef(0,0,-fpositionz*2 - zoffset*2);
	     glutSolidSphere(.5,10,10);
		 glTranslatef(0,0,fpositionz + zoffset);
	  }
	  glTranslatef(0,yoffset,0);
	  glTranslatef(0,yoffset*2,0);
	  glutSolidSphere(.5,10,10);
	  for(i = 0; i<6; i++){
         zoffset = fpositionz * i;
		 glTranslatef(0,0,fpositionz + zoffset);
	     glutSolidSphere(.5,10,10);
	     glTranslatef(0,0,-fpositionz*2 - zoffset*2);
	     glutSolidSphere(.5,10,10);
		 glTranslatef(0,0,fpositionz + zoffset);
	  }
	  glTranslatef(0,-yoffset*2*2,0);
	  glutSolidSphere(.5,10,10);
	  for(i = 0; i<6; i++){
         zoffset = fpositionz * i;
		 glTranslatef(0,0,fpositionz + zoffset);
	     glutSolidSphere(.5,10,10);
	     glTranslatef(0,0,-fpositionz*2 - zoffset*2);
	     glutSolidSphere(.5,10,10);
		 glTranslatef(0,0,fpositionz + zoffset);
	  }
	  glTranslatef(0,yoffset*2,0);
   }
   if(fpositionx>40){
      fpositionx = 0;
      fpositiony = 0;
      fpositionz = 0;
	  firestart = 0;
	  yoffset = 0;
	  zoffset = 0;
   }

}



void drawHead1(){
   glPushMatrix();
   glColor3f(1.0,0,0);
   glTranslatef(-5,50,55);
   glTranslatef(3,0,0);
   glutSolidSphere(1.5,10,10);
   glTranslatef(-3,0,0);
   //back of head
     glBegin(GL_POLYGON);
      glVertex3f(6.0f,1.0f,6.0f);
      glVertex3f(6.0f,1.0f,-6.0f);
      glVertex3f(6.0f,-1.0f,-6.0f);
      glVertex3f(6.0f,-1.0f,6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(6.0f,5.0f,6.0f);
      glVertex3f(0.0f,5.0f,6.0f);
      glVertex3f(0.0f,5.0f,-6.0f);
      glVertex3f(6.0f,5.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(6.0f,-6.0f,6.0f);
      glVertex3f(0.0f,-6.0f,6.0f);
      glVertex3f(0.0f,-6.0f,-6.0f);
      glVertex3f(6.0f,-6.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(6.0f,5.0f,6.0f);
      glVertex3f(0.0f,5.0f,6.0f);
      glVertex3f(0.0f,-6.0f,6.0f);
      glVertex3f(6.0f,-6.0f,6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(6.0f,5.0f,-6.0f);
      glVertex3f(0.0f,5.0f,-6.0f);
      glVertex3f(0.0f,-6.0f,-6.0f);
      glVertex3f(6.0f,-6.0f,-6.0f);
   glEnd();
   //top of jaw
   glTranslatef(0,-3,0);
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,6.0f);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
      glVertex3f(0.0f,1.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,-6.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
      glVertex3f(-13.0f,4.0f,-4.0f);
      glVertex3f(0.0f,8.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,6.0f);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,4.0f,4.0f);
      glVertex3f(0.0f,8.0f,6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,8.0f,6.0f);
      glVertex3f(-13.0f,4.0f,4.0f);
      glVertex3f(-13.0f,4.0f,-4.0f);
      glVertex3f(0.0f,8.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,4.0f,4.0f);
      glVertex3f(-13.0f,4.0f,-4.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
   glEnd();
    //eyes
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(0,1,0);
    glTranslatef(0,7,5.65);
    glColor3f(1,1,1);
    glutSolidSphere(2,20,20);
    glTranslatef(-2,0,0);
    glColor3f(0,0,1);
    glutSolidSphere(.5,10,10);
    glTranslatef(0,0,-11);
    glutSolidSphere(.5,10,10);
    glColor3f(1,1,1);
    glTranslatef(2,0,0);
    glutSolidSphere(2,20,20);
    glPopMatrix();
   //bottom of jaw
   if(mouthopen){
	   if(mouthcount<180){
          mangle+=.25;
		  mouthcount++;
	   }
   }
   if(mouthclose){
	   if(mouthcount>0){
	      mangle-=.25;
		  mouthcount--;
	   }
   }
   glRotatef(mangle,0.0f,0.0f,1.0f);
   glTranslatef(1,0,0);
   glColor3f(1,0,0);
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,6.0f);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
      glVertex3f(0.0f,1.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,-3.0f,6.0f);
      glVertex3f(-13.0f,-1.0f,4.0f);
      glVertex3f(-13.0f,-1.0f,-4.0f);
      glVertex3f(0.0f,-3.0f,-6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,-1.0f,4.0f);
      glVertex3f(-13.0f,-1.0f,-4.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,6.0f);
      glVertex3f(-13.0f,1.0f,4.0f);
      glVertex3f(-13.0f,-1.0f,4.0f);
      glVertex3f(0.0f,-3.0f,6.0f);
   glEnd();
   glBegin(GL_POLYGON);
      glVertex3f(0.0f,1.0f,-6.0f);
      glVertex3f(-13.0f,1.0f,-4.0f);
      glVertex3f(-13.0f,-1.0f,-4.0f);
      glVertex3f(0.0f,-3.0f,-6.0f);
   glEnd();
   glRotatef(-mangle,0.0f,0.0f,1.0f);
   if(fireflag){
      fireflag = 0;
	  firestart = 1;
   }
   if(firestart == 1){
      glColor3f(1.0,0,0);
	  fpositionx +=.25;
	  fpositiony +=.1;
	  glTranslatef(-fpositionx,-fpositiony,0.0);
      glutSolidSphere(3,10,10);
	  fpositionz+=.01;
	  yoffset += .005;
      glColor3f(1.0,0.62,0);
	  for(i = 0; i<10; i++){
		 zoffset = fpositionz * i;
	     glTranslatef(0,0,fpositionz + zoffset);
	     glutSolidSphere(1,10,10);
	     glTranslatef(0,0,-fpositionz*2 - zoffset*2);
	     glutSolidSphere(1,10,10);
		 glTranslatef(0,0,fpositionz + zoffset);
	  }
	  glTranslatef(0,yoffset,0);
      glColor3f(1,1 ,0);
	  glutSolidSphere(1,10,10);
	  for(i = 0; i<8; i++){
         zoffset = fpositionz * i;
		 glTranslatef(0,0,fpositionz + zoffset);
	     glutSolidSphere(.5,10,10);
	     glTranslatef(0,0,-fpositionz*2 - zoffset*2);
	     glutSolidSphere(.5,10,10);
		 glTranslatef(0,0,fpositionz + zoffset);
	  }
	  glTranslatef(0,-yoffset*2,0);
	  glutSolidSphere(.5,10,10);
	  for(i = 0; i<8; i++){
         zoffset = fpositionz * i;
		 glTranslatef(0,0,fpositionz + zoffset);
	     glutSolidSphere(.5,10,10);
	     glTranslatef(0,0,-fpositionz*2 - zoffset*2);
	     glutSolidSphere(.5,10,10);
		 glTranslatef(0,0,fpositionz + zoffset);
	  }
	  glTranslatef(0,yoffset,0);
	  glTranslatef(0,yoffset*2,0);
	  glutSolidSphere(.5,10,10);
	  for(i = 0; i<6; i++){
         zoffset = fpositionz * i;
		 glTranslatef(0,0,fpositionz + zoffset);
	     glutSolidSphere(.5,10,10);
	     glTranslatef(0,0,-fpositionz*2 - zoffset*2);
	     glutSolidSphere(.5,10,10);
		 glTranslatef(0,0,fpositionz + zoffset);
	  }
	  glTranslatef(0,-yoffset*2*2,0);
	  glutSolidSphere(.5,10,10);
	  for(i = 0; i<6; i++){
         zoffset = fpositionz * i;
		 glTranslatef(0,0,fpositionz + zoffset);
	     glutSolidSphere(.5,10,10);
	     glTranslatef(0,0,-fpositionz*2 - zoffset*2);
	     glutSolidSphere(.5,10,10);
		 glTranslatef(0,0,fpositionz + zoffset);
	  }
	  glTranslatef(0,yoffset*2,0);
   }
   if(fpositionx>40){
      fpositionx = 0;
      fpositiony = 0;
      fpositionz = 0;
	  firestart = 0;
	  yoffset = 0;
	  zoffset = 0;
   }


}

void cb_reshape(int w, int h)
{
   Width = w;
   Height = h;
   glViewport(0, 0, w, h);

}

void cb_idle() {
   glutPostRedisplay();
}

int main(int argc, char **argv)
{
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE );
  glutInitWindowSize( Width, Height );
  glutCreateWindow( "Dragon" );
  glViewport( 0, 0, Width, Height );
  glEnable( GL_DEPTH_TEST );
  glEnable( GL_NORMALIZE );
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  GLfloat ambient[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffuse[] = {0.9, 0.9, 0.9, 1.0};
  GLfloat specular[] = {0.4, 0.4, 0.4, 1.0};
  GLfloat position0[] = {1.0, 1.0, 1.0, 0.0};
  quadratic=gluNewQuadric();
  gluQuadricDrawStyle(quadratic, GLU_FILL);
  glLightfv( GL_LIGHT0, GL_POSITION, position0 );
  glLightfv( GL_LIGHT0, GL_AMBIENT, ambient );
  glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
  glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
  GLfloat position1[] = {-1.0, -1.0, -1.0, 0.0};
  glLightfv( GL_LIGHT1, GL_POSITION, position1 );
  glClearColor(173.0/255,216.0/255,230.0/255, 0.8);
  glLightfv( GL_LIGHT1, GL_AMBIENT, ambient );
  glLightfv( GL_LIGHT1, GL_DIFFUSE, diffuse );
  glLightfv( GL_LIGHT1, GL_SPECULAR, specular );
  glEnable( GL_LIGHTING );
  glEnable( GL_LIGHT0 );
  glEnable( GL_LIGHT1 );
  glEnable( GL_COLOR_MATERIAL );
glutDisplayFunc( cb_display );

 // glutDisplayFunc( cb_display1 );
  glutKeyboardFunc( cb_keyboard );
  glutIdleFunc( cb_idle );
  reset();
  glutMouseFunc(mouse);
  glutReshapeFunc( cb_reshape );
  glutFullScreen();
  glutMainLoop();
  return 0;
}

