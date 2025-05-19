#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
void train();
void redrawcar();
float bi=50,c=0.2;

int boat=0;

void myinit()
{
	glClearColor(0.0,0.8,0.9,1.0);
	glColor3f(0.0,1.0,0.0);
	glPointSize(6.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,900.0,0.0,700.0);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);


/*	redrawcar();
    train();
	glMatrixMode(GL_MODELVIEW);
glLoadIdentity();*/
//MOUNTAIN
glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.8);
	glVertex2i(180,310);
	glVertex2i(350,325);
    glVertex2i(270,366);

glEnd();

glBegin(GL_POLYGON);
glColor3f(0.9,0.9,0.9);
	glVertex2i(280,313);
	glVertex2i(470,325);
    glVertex2i(390,366);

glEnd();

glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.8);
	glVertex2i(440,313);
	glVertex2i(570,325);
    glVertex2i(490,346);

glEnd();
glBegin(GL_POLYGON);
glColor3f(0.9,0.9,0.9);
	glVertex2i(540,313);
	glVertex2i(670,325);
    glVertex2i(590,360);

glEnd();


//lt
glBegin(GL_POLYGON);
glColor3f(0.0,1.0,0.0);
	glVertex2i(1,295);
	glVertex2i(645,310);
    glVertex2i(699,276);
	glVertex2i(740,320);
	glVertex2i(420,330);
glEnd();



//water
	glBegin(GL_POLYGON);
glColor3f(0.6,0.7,1.0);
	glVertex2i(1,295);
	glVertex2i(1,0);
    glVertex2i(900,0);
	glVertex2i(900,150);
    glVertex2i(645,310);

    glEnd();
//hill
	glBegin(GL_POLYGON);
   glColor3f(1.0,0.8,0.5);
	glVertex2i(699,276);
	glVertex2i(805,440);
    glVertex2i(900,440);
	glVertex2i(900,150);
  //  glVertex2i(645,310);
glEnd();


//TREE on the bridge
	glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,0.0);
	glVertex2i(800,450);
	glVertex2i(850,450);
    glVertex2i(825,530);
	glEnd();



	redrawcar();
    train();
	glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
//TREE outside bridge
	glBegin(GL_POLYGON);
   glColor3f(1.0,0.0,0.0);
	glVertex2i(860,465);
	glVertex2i(860,430);
	glVertex2i(865,430);
	glVertex2i(865,465);
   glEnd();


	glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,0.0);
	glVertex2i(845,450);
	glVertex2i(880,450);
    glVertex2i(863,530);
	glEnd();

		glBegin(GL_POLYGON);
   glColor3f(1.0,0.0,0.0);
	glVertex2i(890,465);
	glVertex2i(890,430);
	glVertex2i(895,430);
	glVertex2i(895,465);
   glEnd();


	glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,0.0);
	glVertex2i(865,450);
	glVertex2i(910,450);
    glVertex2i(900,580);
	glEnd();

//tree behind mountain
//m1
   glBegin(GL_POLYGON);
   glColor3f(1.0,0.0,0.0);
	glVertex2i(312,310);
	glVertex2i(312,333);
	glVertex2i(309,333);
	glVertex2i(309,310);
   glEnd();


	glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,0.0);
	glVertex2i(290,330);
	glVertex2i(330,330);
    glVertex2i(310,380);
	glEnd();

//m2


		glBegin(GL_POLYGON);
   glColor3f(1.0,0.0,0.0);
	glVertex2i(547,313);
	glVertex2i(547,336);
	glVertex2i(550,336);
	glVertex2i(550,313);
   glEnd();


	glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,0.0);
	glVertex2i(530,330);
	glVertex2i(570,330);
    glVertex2i(550,380);
	glEnd();

//m3

		glBegin(GL_POLYGON);
   glColor3f(1.0,0.0,0.0);
	glVertex2i(703,313);
	glVertex2i(703,336);
	glVertex2i(706,336);
	glVertex2i(706,313);
   glEnd();


	glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,0.0);
	glVertex2i(685,330);
	glVertex2i(725,330);
    glVertex2i(705,380);
	glEnd();

	//1
	glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.8);
	glVertex2i(1,480);
	glVertex2i(1,410);
glVertex2i(850,390);
	glVertex2i(850,460);
	glEnd();
//2
	glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(30,480);
	glVertex2i(30,400);
glVertex2i(45,400);
	glVertex2i(45,480);
	glEnd();
//3
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(1,485);
	glVertex2i(1,480);
glVertex2i(850,460);
	glVertex2i(850,465);
	glEnd();

//shadow
	glBegin(GL_POLYGON);
glColor3f(0.7,0.7,0.7);
	glVertex2i(1,410);
	glVertex2i(1,390);
glVertex2i(850,388);
	glVertex2i(850,390);
	glEnd();

	//4
	glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(130,477);
	glVertex2i(130,407);
glVertex2i(145,407);
	glVertex2i(145,477);
	glEnd();
	//5

	glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(230,475);
	glVertex2i(230,404);
glVertex2i(245,404);
	glVertex2i(245,475);
	glEnd();
//6
	glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(330,472);
	glVertex2i(330,402);
glVertex2i(345,402);
	glVertex2i(345,472);
	glEnd();
//7

glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(430,470);
	glVertex2i(430,400);
glVertex2i(445,400);
	glVertex2i(445,470);
	glEnd();

//8

glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(530,468);
	glVertex2i(530,397);
    glVertex2i(545,397);
	glVertex2i(545,468);
	glEnd();

//9
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(630,466);
	glVertex2i(630,394);
    glVertex2i(645,394);
	glVertex2i(645,466);
	glEnd();
//10
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(730,464);
	glVertex2i(730,392);
    glVertex2i(745,392);
	glVertex2i(745,464);
	glEnd();

//11
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(830,462);
	glVertex2i(830,390);
    glVertex2i(845,390);
	glVertex2i(845,462);
	glEnd();

//PILLER1
//p1
	glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(70,390);
	glVertex2i(70,380);
glVertex2i(100,380);
	glVertex2i(100,390);
	glEnd();


	glBegin(GL_POLYGON);
glColor3f(0.7,0.7,0.7);
	glVertex2i(60,380);
	glVertex2i(60,200);
glVertex2i(110,200);
	glVertex2i(110,380);
	glEnd();


	glBegin(GL_POLYGON);
glColor3f(0.6,0.6,0.6);
	glVertex2i(55,380);
	glVertex2i(55,370);
glVertex2i(115,370);
	glVertex2i(115,380);
	glEnd();

//2

glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(150,408);
	glVertex2i(150,398);
glVertex2i(180,398);
	glVertex2i(180,408);
	glEnd();

	glBegin(GL_POLYGON);
glColor3f(0.7,0.7,0.7);
	glVertex2i(140,398);
	glVertex2i(140,185);
glVertex2i(190,185);
	glVertex2i(190,398);
	glEnd();

	glBegin(GL_POLYGON);
glColor3f(0.6,0.6,0.6);
	glVertex2i(135,398);
	glVertex2i(135,388);
glVertex2i(195,388);
	glVertex2i(195,398);
	glEnd();
//3
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
	glVertex2i(350,390);
	glVertex2i(350,380);
glVertex2i(380,380);
	glVertex2i(380,390);
	glEnd();

	glBegin(GL_POLYGON);
glColor3f(0.7,0.7,0.7);
	glVertex2i(340,380);
	glVertex2i(340,200);
glVertex2i(390,200);
	glVertex2i(390,380);
	glEnd();

	glBegin(GL_POLYGON);
glColor3f(0.6,0.6,0.6);
	glVertex2i(335,380);
	glVertex2i(335,370);
glVertex2i(395,370);
	glVertex2i(395,380);
	glEnd();


//4
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
glVertex2i(440,399);
	glVertex2i(440,388);
glVertex2i(470,388);
	glVertex2i(470,398);
	glEnd();

	glBegin(GL_POLYGON);
glColor3f(0.7,0.7,0.7);
	glVertex2i(430,389);
	glVertex2i(430,180);
glVertex2i(480,180);
	glVertex2i(480,389);
	glEnd();

	glBegin(GL_POLYGON);
glColor3f(0.6,0.6,0.6);
	glVertex2i(425,389);
	glVertex2i(425,379);
glVertex2i(485,379);
	glVertex2i(485,389);
	glEnd();


//5
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
glVertex2i(640,388);
	glVertex2i(640,378);
glVertex2i(670,378);
	glVertex2i(670,388);
	glEnd();

	glBegin(GL_POLYGON);
glColor3f(0.7,0.7,0.7);
	glVertex2i(630,378);
	glVertex2i(630,190);
    glVertex2i(680,190);
	glVertex2i(680,378);
	glEnd();

	glBegin(GL_POLYGON);
glColor3f(0.6,0.6,0.6);
	glVertex2i(625,378);
	glVertex2i(625,368);
glVertex2i(685,368);
	glVertex2i(685,378);
	glEnd();
//6
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
glVertex2i(750,394);
	glVertex2i(750,384);
glVertex2i(780,384);
	glVertex2i(780,394);
	glEnd();

	glBegin(GL_POLYGON);
glColor3f(0.7,0.7,0.7);
	glVertex2i(740,384);
	glVertex2i(740,170);
glVertex2i(790,170);
	glVertex2i(790,384);
	glEnd();

	glBegin(GL_POLYGON);
glColor3f(0.6,0.6,0.6);
	glVertex2i(735,384);
	glVertex2i(735,374);
glVertex2i(795,374);
	glVertex2i(795,384);
	glEnd();

//RECT
	glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.8);
	glVertex2i(190,190);
	glVertex2i(180,185);

glVertex2i(380,70);
	glVertex2i(400,80);
	glEnd();
//RE2
	glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.8);
	glVertex2i(400,80);
	glVertex2i(380,70);

glVertex2i(470,1);
	glVertex2i(490,1);
	glEnd();
//land
	glBegin(GL_POLYGON);
glColor3f(0.0,1.0,0.0);
	glVertex2i(0,210);
	glVertex2i(0,0);
    glVertex2i(470,0);
	glVertex2i(380,70);
	glVertex2i(180,185);
	glEnd();



    glutSwapBuffers();

	glFlush();
}
void train()
{
	glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glTranslated(100.0,100.0,0.0);
glMatrixMode(GL_MODELVIEW);
glRotated(-0.2,0.0,0.0,1.0);
glMatrixMode(GL_MODELVIEW);


glTranslated(-100.0,-100.0,0.0);


	//1
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,0.8);
	glVertex2i(930+bi,510);
	glVertex2i(930+bi,470);
    glVertex2i(1050+bi,470);
	glVertex2i(1050+bi,510);
	glEnd();

	//2
	glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
	glVertex2i(930+bi,500);
	glVertex2i(930+bi,483);
    glVertex2i(1050+bi,483);
	glVertex2i(1050+bi,500);
	glEnd();

	//3
	glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
	glVertex2i(930+bi,520);
    glVertex2i(930+bi,510);
    glVertex2i(1050+bi,510);
    glVertex2i(1050+bi,520);
	glEnd();


	//4
	glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
	glVertex2i(940+bi,540);
    glVertex2i(930+bi,520);
    glVertex2i(1050+bi,520);
    glVertex2i(1040+bi,540);
	glEnd();


	//5
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(945+bi,535);
    glVertex2i(937+bi,520);
    glVertex2i(960+bi,520);
    glVertex2i(960+bi,535);
	glEnd();



	//6
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1025+bi,535);
    glVertex2i(1025+bi,520);
    glVertex2i(1043+bi,520);
    glVertex2i(1038+bi,535);
	glEnd();

//7
	glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
	glVertex2i(970+bi,535);
    glVertex2i(970+bi,525);
    glVertex2i(990+bi,525);
    glVertex2i(990+bi,535);
	glEnd();

	//8
	glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
	glVertex2i(995+bi,535);
    glVertex2i(995+bi,525);
    glVertex2i(1015+bi,525);
    glVertex2i(1015+bi,535);
	glEnd();
//9
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2i(925+bi,510);
	glVertex2i(925+bi,478);
    glVertex2i(930+bi,480);
	glVertex2i(930+bi,508);
	glEnd();
//10
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2i(948+bi,550);
    glVertex2i(948+bi,540);
    glVertex2i(958+bi,540);
    glVertex2i(958+bi,550);
	glEnd();
//11
	glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
	glVertex2i(953+bi,565);
    glVertex2i(935+bi,550);
    glVertex2i(970+bi,550);

	glEnd();

	//12
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2i(1050+bi,505);
	glVertex2i(1050+bi,478);
    glVertex2i(1055+bi,475);
	glVertex2i(1055+bi,507);
	glEnd();
//START BOX1
	//1
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2i(1055+bi,507);
	glVertex2i(1055+bi,474);
    glVertex2i(1060+bi,480);
	glVertex2i(1060+bi,503);
	glEnd();

	//2
	glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,0.8);
	glVertex2i(1060+bi,510);
	glVertex2i(1060+bi,470);
    glVertex2i(1190+bi,470);
	glVertex2i(1190+bi,510);
	glEnd();
    //3
	glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
	glVertex2i(1060+bi,500);
	glVertex2i(1060+bi,483);
    glVertex2i(1190+bi,483);
	glVertex2i(1190+bi,500);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
	glVertex2i(1060+bi,530);
    glVertex2i(1060+bi,510);
    glVertex2i(1190+bi,510);
    glVertex2i(1190+bi,530);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
	glVertex2i(1063+bi,540);
    glVertex2i(1060+bi,530);
    glVertex2i(1190+bi,530);
    glVertex2i(1187+bi,540);
	glEnd();
//W1
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1065+bi,535);
    glVertex2i(1065+bi,520);
    glVertex2i(1085+bi,520);
    glVertex2i(1085+bi,535);
	glEnd();

//W2
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1090+bi,535);
    glVertex2i(1090+bi,520);
    glVertex2i(1110+bi,520);
    glVertex2i(1110+bi,535);
	glEnd();
//W3
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1115+bi,535);
    glVertex2i(1115+bi,520);
    glVertex2i(1135+bi,520);
    glVertex2i(1135+bi,535);
	glEnd();
//W4
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1140+bi,535);
    glVertex2i(1140+bi,520);
    glVertex2i(1160+bi,520);
    glVertex2i(1160+bi,535);
	glEnd();

//W5
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1175+bi,535);
    glVertex2i(1175+bi,518);
    glVertex2i(1185+bi,518);
    glVertex2i(1185+bi,535);
	glEnd();

//CHAIN

	 glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2i(1190+bi,505);
	glVertex2i(1190+bi,478);
    glVertex2i(1195+bi,475);
	glVertex2i(1195+bi,507);
	glEnd();
//box2

	glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2i(1195+bi,507);
	glVertex2i(1195+bi,474);
    glVertex2i(1200+bi,480);
	glVertex2i(1200+bi,503);
	glEnd();

 //2
	glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,0.8);
	glVertex2i(1200+bi,513);
	glVertex2i(1200+bi,468);
    glVertex2i(1330+bi,466);
	glVertex2i(1330+bi,513);
	glEnd();

//3
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
	glVertex2i(1200+bi,500);
	glVertex2i(1200+bi,483);
    glVertex2i(1330+bi,483);
	glVertex2i(1330+bi,500);
	glEnd();

//4
	glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
	glVertex2i(1200+bi,530);
    glVertex2i(1200+bi,510);
    glVertex2i(1330+bi,510);
    glVertex2i(1330+bi,530);
	glEnd();

//5
	glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
	glVertex2i(1203+bi,540);
    glVertex2i(1200+bi,530);
    glVertex2i(1330+bi,530);
    glVertex2i(1327+bi,540);
	glEnd();


//W1
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1205+bi,535);
    glVertex2i(1205+bi,520);
    glVertex2i(1225+bi,520);
    glVertex2i(1225+bi,535);
	glEnd();

//W2
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1230+bi,535);
    glVertex2i(1230+bi,520);
    glVertex2i(1250+bi,520);
    glVertex2i(1250+bi,535);
	glEnd();

//W3
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1255+bi,535);
    glVertex2i(1255+bi,520);
    glVertex2i(1275+bi,520);
    glVertex2i(1275+bi,535);
    glEnd();

//W4

	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1280+bi,535);
    glVertex2i(1280+bi,520);
    glVertex2i(1300+bi,520);
    glVertex2i(1300+bi,535);
	glEnd();



//W5
	glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
	glVertex2i(1315+bi,535);
    glVertex2i(1315+bi,516);
    glVertex2i(1325+bi,516);
    glVertex2i(1325+bi,535);
	glEnd();

//CHAIN

	 glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2i(1330+bi,505);
	glVertex2i(1330+bi,478);
    glVertex2i(1335+bi,475);
	glVertex2i(1335+bi,507);
	glEnd();

}

void redrawcar()
{	if(boat==0)
	{
		if(bi>-1400)
		{

			bi-=c;
			glutPostRedisplay();
		}
		else
		{	bi=bi+2400;
		glutPostRedisplay();
		}
	}
}
  void menu(int val)
  {
       switch(val)
       {
                  case 1 :if(c==0)
                        c=0.2;
                        else
                        c-=0.1;
                        break;
                  case 2 :if(c==0)
                        c=0.2;
                        else
                        c+=0.1;
                        break;
                  case 3 :c=0;
                  break;
                  case 4 :exit(0);
                  break;
    }
}



int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,700);
    glutCreateWindow("Train crossing on the bridge");
    glutCreateMenu(menu);
    glutAddMenuEntry("slow",1);
	glutAddMenuEntry("fast",2);
	glutAddMenuEntry("stop",3);
    glutAddMenuEntry("Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);

myinit();

	glutMainLoop();
}
