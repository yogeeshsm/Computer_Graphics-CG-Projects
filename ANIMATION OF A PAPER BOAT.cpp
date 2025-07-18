#include<windows.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<GL/glut.h>

int displayFrontScreen = 1;
int idlestateangle =0;
int idlestate1 = 0, idlestate2 = 0, idlestate3 = 0;
int rotateonce =0;
int stage3_mode =0;
static int line_mid = 0.0, line_perp=0.0, turn1 = 0.0, turn2 =0.0;
float z= 0, x1 = 2.828, x2 = -2.828;
int j, depth = 0;
double lookatangle = 0;
int stage =1;
int state1 = 0, state2 = 0, state3= 0;
float valy = -2, valz = 0;
float transvalx = 0, transvaly = 2;
int xanglecount = 0;
int xangle =0;
int world_angles[] = {0,0,0};
int world_angles_true[] = {0,0,0};
float sz=2;
int b0=0,b1=0,b2=0,b3=0,b4=0,b5=0;
int i=0;

float computeZ(float y){
    float temp = 4 - y*y;
    float z = sqrtf(temp);
    return z;
}
void timer(int iunused)
{
    glutPostRedisplay();
    glutTimerFunc(30,timer,0);
}
void secondInit()
{
    glClearColor(0, 1, 0, 0);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, 1, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -15);
}

void triangle1_Stage3(){

    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, 0);
    glVertex3f(-2, 0, 0);
    glVertex3f(0, 2, 0);
    glEnd();

}

void traingle2_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 2, 0);
    glVertex3f(2, 0, 0);

    glEnd();

}

void traingle3_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(2, 0, 0);
    glVertex3f(0, valy, valz);
    glVertex3f(0, 0, 0);
    glEnd();

}

void traingle4_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(0, valy, valz);
    glVertex3f(-2, 0, 0);
    glVertex3f(0, 0, 0);
    glEnd();

}

void coneTriangleOne_Stage3(){

    glBegin(GL_TRIANGLES);
    glVertex3f(-2, 0, 0);
    glVertex3f(-transvalx, transvaly, 0);
    glVertex3f(0, valy, valz);
    glEnd();
}

void coneTriangleTwo_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(2, 0, 0);
    glVertex3f(transvalx, transvaly, 0);
    glVertex3f(0, valy, valz);
    glEnd();
}

void conetraingaleThree_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(-2, 0, 0);
    glVertex3f(-transvalx, transvaly, 0);
    glVertex3f(0, valy, -valz);
    glEnd();
}

void conetraingleFour_Stage3()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(2, 0, 0);
    glVertex3f(transvalx, transvaly, 0);
    glVertex3f(0, valy, -valz);
    glEnd();
}

void coneTriangle1()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(0, -2, z);
    glVertex3f(x2, -2,0);
    glVertex3f(0, 0,0);
    glEnd();
}

void coneTriangle2()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, -2, 0);
    glVertex3f(0, -2, z);
    glVertex3f(0, 0, 0);
    glEnd();
}

void conetraingale3()
{
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(0, -2, -z);
    glVertex3f(x2, -2,0);
    glVertex3f(0, 0,0);
    glEnd();
    glPopMatrix();

}

void conetraingle4()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, -2, 0);
    glVertex3f(0, -2, -z);
    glVertex3f(0, 0, 0);
    glEnd();
}

void drawtraingleone()
{
    if (depth ==1) {
        glColor3ub(63, 81, 181);
        glPushMatrix();
        glBegin(GL_POLYGON);
        glVertex3f(0, 0,-2);
        glVertex3f(-2, 0,0);
        glVertex3f(-2, 2,0);
        glEnd();
        glPopMatrix();

    }else{
    glColor3ub(63, 81, 181);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0,0);
    glVertex3f(-2, 0,0);
    glVertex3f(-2, 2,0);
    glEnd();
    glPopMatrix();
    }
}

void drawtriangletwo()
{
    if (depth ==1) {
        glColor3ub(86, 119, 252);
        glPushMatrix();
        glBegin(GL_POLYGON);
        glVertex3f(0, 0,2);
        glVertex3f(-2, 2,0);
        glVertex3f(0, 2,0);
        glEnd();
        glPopMatrix();
    }else{
    glColor3ub(86, 119, 252);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(0, 0,0);
    glVertex3f(-2, 2,0);
    glVertex3f(0, 2,0);
    glEnd();
    glPopMatrix();
    }
}

void drawtrianglethree()
{
    if (depth ==1) {
        glColor3ub(0, 188, 212);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
        glVertex3f(0, 0,-2);
        glVertex3f(0, 2,0);
        glVertex3f(2, 2,0);
        glEnd();
        glPopMatrix();
    }
    glColor3ub(0, 188, 212);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0,0);
    glVertex3f(0, 2,0);
    glVertex3f(2, 2,0);
    glEnd();
    glPopMatrix();

}

void drawtrianglefour()
{

    if (depth ==1) {
        glColor3ub(3, 169, 15);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
        glVertex3f(0, 0,-2);
        glVertex3f(2, 2,0);
        glVertex3f(2, 0,0);
        glEnd();
        glPopMatrix();
    }
    glColor3ub(3, 169, 15);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0,0);
    glVertex3f(2, 2,0);
    glVertex3f(2, 0,0);
    glEnd();
    glPopMatrix();

}

void drawsquareone(int flag)
{
    if (flag ==2) {
        glPushMatrix();
        drawtraingleone();
        glPushMatrix();
        glRotatef(turn1, -1, 1, 0);
        drawtriangletwo();
        glPopMatrix();
        glPopMatrix();
    }
    else{
    glPushMatrix();
    drawtraingleone();
    drawtriangletwo();
    glPopMatrix();
    }
}

void drawsquaretwo(int flag)
{
    if (flag ==1) {
        glPushMatrix();
        glPushMatrix();
        glRotatef(turn1, 1, 1, 0);
        drawtrianglethree();
        glPopMatrix();
        drawtrianglefour();
        glPopMatrix();

    }
    else{
        glPushMatrix();
        drawtrianglethree();
        drawtrianglefour();
        glPopMatrix();
    }

}

void drawrectangletop(int flag)
{
    if (flag ==1) {
        glPushMatrix();
        glPushMatrix();
        glRotatef(turn1, 1, 1, 0);
        drawsquareone(0);
        glPopMatrix();
        drawsquaretwo(1);
        glPopMatrix();
    }
    else if(flag == 2){
        glPushMatrix();
        drawsquareone(2);
        glPushMatrix();
        glRotatef(turn1, -1, 1, 0);
        drawsquaretwo(0);
        glPopMatrix();
        glPopMatrix();

    }
    else{
    glPushMatrix();
    drawsquareone(0);
        glPushMatrix();
    drawsquaretwo(0);
        glPopMatrix();
    glPopMatrix();
    }
}

void drawrectanglebottom(int flag)
{
    if (flag ==2) {
        glPushMatrix();
        glTranslated(-2, 0,0);
        drawsquaretwo(0);
        glTranslated(4, 0, 0);
        drawsquareone(2);
        glPopMatrix();
    }
    else if (flag ==1) {
        glPushMatrix();
        glTranslated(-2, 0,0);
        drawsquaretwo(1);
        glTranslated(4, 0, 0);
        drawsquareone(0);
        glPopMatrix();
    }
    else{
        glPushMatrix();
        glTranslated(-2, 0,0);
        drawsquaretwo(0);
        glTranslated(4, 0, 0);
        drawsquareone(0);
        glPopMatrix();
    }
}
void displayStage3()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0.0,1.0,0.0,1.0);
    glColor3f(1.0, 1.0, 1.0);
    if (stage3_mode == 1) {
    }
    if (!rotateonce) {
    }
    glPushMatrix();
    triangle1_Stage3();
    traingle2_Stage3();
    glPushMatrix();
    glRotated(180, 0, 1, 0);
    glColor3ub(86, 119, 252);
    traingle3_Stage3();
    traingle4_Stage3();
    glPopMatrix();
    glColor3f(1, 1, 1);
    traingle3_Stage3();
    traingle4_Stage3();
    glColor3ub(86, 119, 252);
    coneTriangleOne_Stage3();
    coneTriangleTwo_Stage3();
    conetraingaleThree_Stage3();
    conetraingleFour_Stage3();
    glPopMatrix();
}

void displayStage1(){
    glPushMatrix();//origin at 0,0 at this point;first push; make changes and pop returns here
    if (turn2 ==1) {
        glRotatef(45, 0, 0, 1);
    }
    glPushMatrix();//push for rotate about xaxis;
    glRotatef(line_perp, 1, 0, 0);
    //top-left quadrant
    glPushMatrix();//push to draw the topleft;context = rotateabout x
    glTranslated(-2, 2, 0);
    drawrectangletop(state3);
    glTranslated(0, -2, 0);
    drawrectanglebottom(state3);
    //end
    glPopMatrix();//translation back to rotation about x
    glPopMatrix();//backto origin;
    //bottom-left quadrant
    glPushMatrix();//push to bottom -left
    glTranslated(-2, -2, 0);
    glRotatef(180, 0, 0, 1);
    glPushMatrix();
    drawrectangletop(2);
    glTranslated(0, -2, 0);
    drawrectanglebottom(2);
    //end
    glPopMatrix();//back to origin
    glPopMatrix();
    glPushMatrix();//push to change state for rotation ;all the stuff inside this context will by rotated by y =0.
    glRotatef(line_mid, 0, 1, 0);//rotate the entire right side
    glPushMatrix();//push to add rotate about x
    glRotatef(line_perp, 1, 0, 0);//rotation about x
    glPushMatrix();//current context, rotate; push to topright
    //top-right quadrant
    glTranslated(2, 2, 0);
    drawrectangletop(2);
    glTranslated(0, -2, 0);
    drawrectanglebottom(2);
    //end
    glPopMatrix();//back to rotation about x
    glPopMatrix();//back to roaton right
    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    glTranslated(-4, 4, 0);
    //bottom-right quadrant
    glPushMatrix();//rotate, add translaton for bottom quad
    glTranslated(2, -2, 0);
    drawrectangletop(1);
    glTranslated(0, -2, 0);
    drawrectanglebottom(1);
    //end
    glPopMatrix();//return to rotate
    glPopMatrix();

    glPopMatrix();//rotate context over;context back t origin
    glPopMatrix();//extra context buffer
}
void displayStage2(int p)
{
    glClearColor(0.0,1.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3ub(86, 119, 252);
    coneTriangle1();
    coneTriangle2();
    coneTriangle1();
    coneTriangle2();
    conetraingale3();
    conetraingle4();
    conetraingale3();
    conetraingle4();
    glPopMatrix();
    if(p==1)
    {
    glClearColor(0.0,1.0,0.0,1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(1.0, 1.0, 1.0);
    if (stage3_mode == 1) {
    }
    if (!rotateonce) {
    }
    glClearColor(0.0,1.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    triangle1_Stage3();
    traingle2_Stage3();
    glPushMatrix();
    glRotated(180, 0, 1, 0);
    glColor3ub(86, 119, 252);
    traingle3_Stage3();
    traingle4_Stage3();
    glPopMatrix();
    glColor3f(1, 1, 1);
    traingle3_Stage3();
    traingle4_Stage3();
    glColor3ub(86, 119, 252);
    coneTriangleOne_Stage3();
    coneTriangleTwo_Stage3();
    conetraingaleThree_Stage3();
    conetraingleFour_Stage3();
    glPopMatrix();
    }
}


void rotateWorld(int mode)
{
    if (mode ==1) {
        glRotatef(world_angles[0], world_angles_true[0], 0, 0);
        glRotatef(world_angles[1], 0, world_angles_true[1], 0);
        glRotatef(world_angles[2], 0, 0, world_angles_true[2]);
    }
}
void display()
{

    glClearColor(0.0,1.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        if (displayFrontScreen==1) {
        displayFrontScreen=0;
    }
    displayStage1();

        if(stage3_mode == 1)
        {
            rotateWorld(stage3_mode);
        }

   if(b0==0)
  {
        line_mid = (line_mid + 1);
        if(line_mid>179){
       b0=1;
       state1=1;
        }
        else{state3=1;}
  }
    if(b0==1 && b1==0)
  {
    line_perp = (line_perp + 1);
    if (line_perp >180)
        {
            b1=1;
            state2=1;
        }
    else {state3=1;}
  }
  if(state3>0)
  {
    if(b1==1 && b2==0)
    {
        turn1 = (turn1 + 1);
        if(turn1>180)
            {
                b2=1;
                stage=2;
            }
    }
  }
    if(stage==2)
    {
        if(b2==1 && b3==0 && x1>0)
        {

//stage3_mode=0;
                z=z+0.2;
                x1=x1-0.2;
                x2=x2+0.2;
                line_perp = (line_perp + 3);
                    if (line_perp >170) {
                        state2 = 1;
                        //b3=1;
                    }
                    if (state1 &&state2) {
                        state3 = 1;
                    }
        }
            else
        {
            b3=1;
        }
        Sleep(200);
        displayStage2(b3);
    }
    if(b3==1 && b4==0 && valy<=0.8)
    {
                valy +=.2;
                valz = computeZ(valy);
                transvalx += .2;
                transvaly+= .007;
                displayStage3();
                Sleep(200);
                 valy +=.2;
                valz = computeZ(valy);
                transvalx += .2;
                transvaly+= .007;
                displayStage3();
                Sleep(200);
                 valy +=.2;
                valz = computeZ(valy);
                transvalx += .2;
                transvaly+= .007;
                displayStage3();
                Sleep(200);
    }
    glutSwapBuffers();
}


void keys(unsigned char key, int x, int y)
{
    switch(key){
            case 'i':
                stage3_mode = 1;
                world_angles_true[0] = 1;
                world_angles[0] += 1;
                glutPostRedisplay();
                break;
            case 'j':
                        stage3_mode = 1;
                world_angles_true[1] = 1;
                world_angles[1] += 1;
                glutPostRedisplay();
                break;
            case 'k':
                        stage3_mode = 1;
                world_angles_true[2] = 1;
                world_angles[2] += 1;
                glutPostRedisplay();
                break;
            case 'z':
            secondInit();
            glutPostRedisplay();
            glFlush();
            break;
             default: stage3_mode = 0;
                break;

    }
}

void reshape(int w,int h)
{
    glViewport(0, 0, GLsizei(w), GLsizei(h));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -15);
}
int main(int argc,char **argv)
{
    printf("\n\n\t\t\t    *********  ORIGAMI 3D ANIMATION  *********\n");
    printf("             \n\t\t\t\t ANIMATION OF A PAPER BOAT\n");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t MADE BY---\n");
    printf("\t\t\t\t\t RASHI MALPANI(1DT14CS077) \n \t\t\t\t\t REVATHI VEMPRALA(1DT14CS080)\n");
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(640,640);
    glutCreateWindow("origami");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keys);
    timer(0);
    glutMainLoop();
}
