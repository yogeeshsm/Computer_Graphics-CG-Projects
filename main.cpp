//headers
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
//globals
GLuint image1,image2,image3;
float imagerot1,imagerot2,imagerot3,imageSpeed = 0.1;
char ch='1';
int imageFlag = 1;
//other functions and main
void display(void);
//wavefront .obj loader code begins
void loadObj(char *fname1, char * fname2, char* fname3)
{
    FILE *fp;
    int read,flag=4;
    GLfloat x1, y1, z1, x2, y2, z2, x3, y3, z3;
    char ch;
    float ambient[]={0.0f,1.0f,1.0f,1.0f};
    float diffuse[]={0.5f,0.5f,0.5f,1.0f};
    float specular[]={0.7f,0.7f,0.7f,1.0f};
    float shine[]={500.0};
    glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,shine);
    float lightIntensity[]={0.5f,0.5f,0.5f,0.0f};
    float lightPosition[]={100.0f,100.0f,100.0f,0.0f};
    glLightfv(GL_LIGHT0,GL_POSITION,lightPosition);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
//Image 1
    image1=glGenLists(1);
    fp=fopen(fname1,"r");
    if (!fp)
    {
        printf("can't open file %s\n", fname1);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(image1, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_TRIANGLE_STRIP);
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x1,&y1,&z1);
            if(read==4 && ch=='v' && z1>5)
            {
                glVertex3f(x1,y1,z1/2);
            }
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
//Image 2
    image2=glGenLists(1);
    fp=fopen(fname2,"r");
    if (!fp)
    {
        printf("can't open file %s\n", fname2);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(image2, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_TRIANGLE_STRIP);
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x2,&y2,&z2);
            if(read==4 && ch=='v' && z2>5)
            {
                glVertex3f(x2,y2,z2/2);
            }
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
//Image 3
    image3=glGenLists(1);
    fp=fopen(fname3,"r");
    if (!fp)
    {
        printf("can't open file %s\n", fname3);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(image3, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_TRIANGLE_STRIP);
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x3,&y3,&z3);
            if(read==4 && ch=='v' && z3>5)
            {
                glVertex3f(x3,y3,z3/2);
            }
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);


}
//wavefront .obj loader code ends here

//If Window Size is changed this function manages that event.
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (80, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}

//Function to Change Images Based on Mouse Clicks
void mouseFunc(int btn, int state, int x, int y)
{
        //Move to Next Model
        if(state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON)
        {
            imageFlag = imageFlag + 1;
            if(imageFlag>3)
                imageFlag -= 3;
        }
        //Move to Previous Model
        if(state == GLUT_DOWN && btn == GLUT_RIGHT_BUTTON)
        {
            imageFlag = imageFlag - 1;
            if(imageFlag<1)
                imageFlag += 3;
        }
        glutPostRedisplay();
}

//Keyboard Function to Increase and Decrease Rotation Speed of the Models
void keyboardFunc(unsigned char key, int x, int y)
{
    switch(key)
    {
        case '+':
            imageSpeed+=0.1;
            if(imageSpeed > 2.0)
                imageSpeed = 2.0;
            break;
        case '-':
            imageSpeed-=0.1;
            if(imageSpeed < 0.0)
                imageSpeed = 0.0;
            break;
    }
    glutPostRedisplay();
}

//To draw Image 1
void draw1()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glRotatef(imagerot1,0,1,0);
    glCallList(image1);

    imagerot1=imagerot1+imageSpeed;
    if(imagerot1>360)imagerot1=imagerot1-360;
}

//To draw Image 2
void draw2()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glRotatef(imagerot2,0,1,0);
    glCallList(image2);

    imagerot2=imagerot2+imageSpeed;
    if(imagerot2>360)imagerot2=imagerot2-360;
}

//To draw Image 3
void draw3()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glRotatef(imagerot3,0,1,0);
    glCallList(image3);

    imagerot3=imagerot3+imageSpeed;
    if(imagerot3>360)imagerot3=imagerot3-360;
}

//Display Function
void display(void)
{
    glClearColor (1.0,1.0,1.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-105);
    glScalef(0.4,0.4,0.4);
    switch(imageFlag)
    {
        case 1:
            draw1();
            break;
        case 2:
            draw2();
            break;
        case 3:
            draw3();
            break;
    }

    glutSwapBuffers(); //swap the buffers
}

//Main Function
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800,450);
    glutInitWindowPosition(20,20);
    glutCreateWindow("OBJ -> 3D");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMouseFunc(mouseFunc);
    glutKeyboardFunc(keyboardFunc);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_LIGHT0);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);    // Enable smooth shading
    glEnable(GL_NORMALIZE);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);        //Removes the back part of the rendered model
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    loadObj("F:/CGProject/buddha1.stl.obj", "F:/CGProject/shiva.stl.obj", "F:/CGProject/jesus.stl.obj");
    glutMainLoop();
    return 0;
}
