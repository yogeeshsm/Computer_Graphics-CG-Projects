#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>

//Function initialization
void drawBall(void);
void drawBanners(void);
void changeBallPosition(void);
void drawRedBox(int);
void drawOrangeBox(int);
void drawBlueBox(int);
void printText(void);
void generateObstacles(void);
void checkCollision(void);
void displayScore(void);
void startScreen(void);
void display2();
void startScreen1(void);
void startScreen2(void);


//Global variable declaration
float ballSpeed = -13.0;
float ballDeltaY = 0.0;
float boxDeltaX = 0.0;
float boxSpeed = 10.0;
float boxXPos = 500.0;
float ballYPos = 400.0;
float ballRadius = 25.0;
float boxYPos = 400.0;
int life=3;

struct ballPointFront
{
	float x,y;
}ballFront;

struct ballPointUp
{
	float x,y;
}ballUp;

struct ballPointDown
{
	float x,y;
}ballDown;

struct boxPointsUp
{
	float x1,y1,x2,y2;
}boxUp;

struct boxPointsDown
{
	float x1,y1,x2,y2;
}boxDown;

struct boxPointsFront
{
	float x1,y1,x2,y2;
}boxFront;

int score = 0;
int randNum = 0;
int randNum1=0;
bool flag = false;
bool flag1=false;
bool endGame = false;
bool firstScreen = true;
bool level2=false;

void startScreen1()
{

    drawBanners();
    	int x = 230;
	int y = 400;
    char line16[15]="level1";
    	glRasterPos2f(x,y);

	int len = (int) strlen(line16);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line16[i]);
}
void display1()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	if(firstScreen == true)
		startScreen();
	else {
		if(endGame == false && life!=0)
		{
		    startScreen1();
			drawBanners();

			drawBall();

			changeBallPosition();

			generateObstacles();

			printText();

		}
   else

                displayScore();
		//glutSwapBuffers();
	}
}

void generateObstacles()
{
	if(flag == false)
	{
		randNum = rand() % 8;
		flag = true;
	}
	if(flag1 == false)
	{
		randNum1 = rand() % 20;
		flag1 = true;
	}

	if(score<5)
		{
		    drawRedBox(randNum);
		}
   else if(score>=5)
    {
        level2=true;
        drawRedBox(randNum);
        drawBlueBox(randNum1);
    }
}

void drawRedBox(int i)
{
	if(flag == true)
	{
		if(i == 0)	boxYPos = 150;
		if(i == 1)	boxYPos = 200;
		if(i == 2)	boxYPos = 250;
		if(i == 3)	boxYPos = 300;
		if(i == 4)	boxYPos = 350;
		if(i == 5)	boxYPos = 400;
		if(i == 6)	boxYPos = 450;
		if(i == 7)	boxYPos = 500;
	}

	//1x1 box - RED
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);
		glVertex2f(650-boxDeltaX,boxYPos);
		glVertex2f(600-boxDeltaX,boxYPos);
		glVertex2f(600-boxDeltaX,boxYPos-50);
		glVertex2f(650-boxDeltaX,boxYPos-50);
	glEnd();

	//Top-right
	boxUp.x1 = 650 - boxDeltaX;
	boxUp.y1 = boxYPos;

	//Top-left
	boxUp.x2 = 600 - boxDeltaX;
	boxUp.y2 = boxYPos;

	//Bottom-right
	boxDown.x1 = 650 - boxDeltaX;
	boxDown.y1 = boxYPos - 50;

	//Bottom-left
	boxDown.x2 = 600 - boxDeltaX;
	boxDown.y2 = boxYPos - 50;

	//Top-left
	boxFront.x1 = 600 - boxDeltaX;
	boxFront.y1 = boxYPos;

	//Bottom-left
	boxFront.x2 = 600 - boxDeltaX;
	boxFront.y2 = boxYPos - 50;

	checkCollision();

	boxDeltaX += boxSpeed;

	if(600-boxDeltaX+50.0 <= 0)
	{
		flag = false;
		boxDeltaX = 0.0;
	}
}

void drawOrangeBox(int i)
{
	if(flag == true)
	{
		if(i == 0)	boxYPos = 150;
		if(i == 1)	boxYPos = 200;
		if(i == 2)	boxYPos = 250;
		if(i == 3)	boxYPos = 300;
		if(i == 4)	boxYPos = 350;
		if(i == 5)	boxYPos = 400;
		if(i == 6)	boxYPos = 450;
		if(i == 7)	boxYPos = 500;
	}

	//1x2 box - ORANGE
	glColor3f(1.0,0.5,0.0);
	glBegin(GL_QUADS);
		glVertex2f(600-boxDeltaX,boxYPos-100);
		glVertex2f(650-boxDeltaX,boxYPos-100);
		glVertex2f(650-boxDeltaX,boxYPos);
		glVertex2f(600-boxDeltaX,boxYPos);
	glEnd();

	//Top-right
	boxUp.x1 = 650 - boxDeltaX;
	boxUp.y1 = boxYPos;

	//Top-left
	boxUp.x2 = 600 - boxDeltaX;
	boxUp.y2 = boxYPos;

	//Bottom-right
	boxDown.x1 = 650 - boxDeltaX;
	boxDown.y1 = boxYPos - 50;

	//Bottom-left
	boxDown.x2 = 600 - boxDeltaX;
	boxDown.y2 = boxYPos - 50;

	//Top-left
	boxFront.x1 = 600 - boxDeltaX;
	boxFront.y1 = boxYPos;

	//Bottom-left
	boxFront.x2 = 600 - boxDeltaX;
	boxFront.y2 = boxYPos - 50;

	checkCollision();

	boxDeltaX += boxSpeed;

	if(600-boxDeltaX+50.0 <= 0)
	{
		flag = false;
		boxDeltaX = 0.0;
	}
}

void drawBlueBox(int i)
{

   if(flag == true)
	{
		if(i == 0)	boxYPos = 150;
		if(i == 1)	boxYPos = 200;
		if(i == 2)	boxYPos = 250;
		if(i == 3)	boxYPos = 300;
		if(i == 4)	boxYPos = 350;
		if(i == 5)	boxYPos = 400;
		if(i == 6)	boxYPos = 450;
		if(i == 7)	boxYPos = 500;
	}

	//1x1 box - RED
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_QUADS);
		glVertex2f(650-boxDeltaX,boxYPos);
		glVertex2f(600-boxDeltaX,boxYPos);
		glVertex2f(600-boxDeltaX,boxYPos-50);
		glVertex2f(650-boxDeltaX,boxYPos-50);
	glEnd();

	//Top-right
	boxUp.x1 = 650 - boxDeltaX;
	boxUp.y1 = boxYPos;

	//Top-left
	boxUp.x2 = 600 - boxDeltaX;
	boxUp.y2 = boxYPos;

	//Bottom-right
	boxDown.x1 = 650 - boxDeltaX;
	boxDown.y1 = boxYPos - 50;

	//Bottom-left
	boxDown.x2 = 600 - boxDeltaX;
	boxDown.y2 = boxYPos - 50;

	//Top-left
	boxFront.x1 = 600 - boxDeltaX;
	boxFront.y1 = boxYPos;

	//Bottom-left
	boxFront.x2 = 600 - boxDeltaX;
	boxFront.y2 = boxYPos - 50;

	checkCollision();

	boxDeltaX += boxSpeed;

	if(600-boxDeltaX+50.0 <= 0)
	{
		flag = false;
		boxDeltaX = 0.0;
	}
}


void checkCollision()
{


        if(boxUp.x2 <= 100 && boxUp.x1 >= 50)
        {
            //Check for ball front collision
            for(float i=boxFront.y1;i>=boxFront.y2;i--)
            {
                if(ballUp.x == i && ((ballUp.y >= boxDown.y1) && (boxDown.y1 >= ballDown.y)))
                    life--;
            }
        }
        if(boxDown.x2 <= 100 && boxUp.x1 >= 50){

            for(float i=boxDown.x2;i<=boxDown.x1;i++)
            {
                     if(ballUp.x == i && ((ballUp.y >= boxDown.y1) && (boxDown.y1 >= ballDown.y)))
                     life--;
            }

            for(float i=boxUp.x2;i<=boxUp.x1;i++)
            {
                        if(ballDown.x == i && ((ballDown.y <= boxUp.y1) && (boxUp.y1 <= ballDown.y)))
                        life--;
            }
             if(life==0)
            endGame = true;

        }
}

void startScreen()
{
	drawBanners();
	char line1[50] = "INSTRUCTIONS";
	char line2[100] = "1.Press down the left mouse button to slow down the diamond ball";
	char line3[100] = "2.Press down the right mouse button to fasten the diamond ball";
	char line4[50] = "   and release to resume normal speed";
	char line5[75] = "3.Avoid collision between diamond ball and obstacle";
	char line6[50] = "4.The score increases when the ball reaches";
	char line7[50] = "  the top/bottom edge of the screen";
    char line8[50] = "5. After score 5, you reach level 2";
    char line9[50]="6. You have 3 lives ";
    char line10[70]="7. After reaching a score of 20 the game will end";
	char line11[70] = "PRESS LEFT MOUSE BUTTON TO CONTINUE. ALL THE BEST!!";

	char title[25] = "COLLISION GAME";
	char names[20] = "- Anusha and Sunand";

	int x = 230;
	int y = 400;

	glRasterPos2f(x,y);

	int len = (int) strlen(line1);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line1[i]);


	x = 40;
	y = 350;
	glRasterPos2f(x,y);

	len = (int) strlen(line2);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line2[i]);

	x = 40;
	y = 320;
	glRasterPos2f(x,y);

	len = (int) strlen(line3);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line3[i]);

	x = 40;
	y = 290;
	glRasterPos2f(x,y);

	len = (int) strlen(line4);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line4[i]);

	x = 40;
	y = 260;
	glRasterPos2f(x,y);

	len = (int) strlen(line5);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line5[i]);


	x = 40;
	y = 230;
	glRasterPos2f(x,y);

	len = (int) strlen(line6);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line6[i]);

	x = 40;
	y = 200;
	glRasterPos2f(x,y);

	len = (int) strlen(line7);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line7[i]);

    x = 40;
	y = 170;
	glRasterPos2f(x,y);

	len = (int) strlen(line8);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line8[i]);

	x = 40;
	y = 140;
	glRasterPos2f(x,y);

	len = (int) strlen(line9);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line9[i]);

		x = 40;
	y = 110;
	glRasterPos2f(x,y);

	len = (int) strlen(line10);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line10[i]);

			x = 40;
	y = 80;
	glRasterPos2f(x,y);

	len = (int) strlen(line11);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line11[i]);

	x = 250;
	y = 500;
	glRasterPos2f(x,y);

	len = (int) strlen(title);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,title[i]);


	x = 400;
	y = 480;
	glRasterPos2f(x,y);


	len = (int) strlen(names);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,names[i]);


}

void displayScore()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1,0.1,0.1,0.9);
	glColor3f(	0.412, 0.412, 0.412);
	glBegin(GL_QUADS);
		glVertex2f(0.0,0.0);
		glVertex2f(0.0,600.0);
		glVertex2f(600.0,600.0);
		glVertex2f(600.0,0.0);
	glEnd();

	glColor3f(0.502, 0.000, 0.000);
	char string[4] = "   ";
	itoa(score,string,10);
	int x = 200;
	int y = 300;
	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x,y);
	char txt[100] = "Your score is ";
	strcat(txt, string);
	//get the length of the string to display
	int len = (int) strlen(txt);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,txt[i]);
}

void changeBallPosition()
{
	//Check if banner is reached
	if((ballYPos+ballDeltaY-ballRadius) <= 60.0 || (ballYPos+ballDeltaY+ballRadius) >= 530.0)
	{
		ballSpeed = -ballSpeed;
		score++;
	}
	ballDeltaY += ballSpeed;
}

void drawBanners()
{
	//Guide Lines
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_LINES);

		//Horizontal guide lines
		glVertex2f(0.0,100.0);
		glVertex2f(600.0,100.0);

		glVertex2f(0.0,150.0);
		glVertex2f(600.0,150.0);

		glVertex2f(0.0,200.0);
		glVertex2f(600.0,200.0);

		glVertex2f(0.0,250.0);
		glVertex2f(600.0,250.0);

		glVertex2f(0.0,300.0);
		glVertex2f(600.0,300.0);

		glVertex2f(0.0,350.0);
		glVertex2f(600.0,350.0);

		glVertex2f(0.0,400.0);
		glVertex2f(600.0,400.0);

		glVertex2f(0.0,450.0);
		glVertex2f(600.0,450.0);

		glVertex2f(0.0,500.0);
		glVertex2f(600.0,500.0);

		//Vertical gudie lines
		glVertex2f(100.0,50.0);
		glVertex2f(100.0,550.0);

		glVertex2f(50.0,50.0);
		glVertex2f(50.0,550.0);
	glEnd();

	//Top Banner
	glColor3f(0.66,0.0,0.33);
	glBegin(GL_QUADS);
		glVertex2f(0.0,600.0);
		glVertex2f(600.0,600.0);
		glVertex2f(600.,530.0);//550
		glVertex2f(0.0,530.0);//550
	glEnd();
	//Bottom Banner
	glColor3f(0.66,0.0,0.33);
	glBegin(GL_QUADS);
		glVertex2f(0.0,0.0);
		glVertex2f(600.0,0.0);
		glVertex2f(600.0,60.0);//50
		glVertex2f(0.0,60.0);//50
	glEnd();

}

void drawBall()
{
	/*
	//Circular Ball
	glColor3f(0.0,1.0,0.498);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(75, ballYPos + ballDeltaY); // center of circle
		for(int i = 0; i <= 2000;i++)
			//X pos + rad*cos(angle),Y pos + rad*sin(angle)
			glVertex2f(75 + (25 * cos(i *  2.0 * PI / 2000)), (ballYPos+ballDeltaY) + (25 * sin(i * 2.0 * PI / 2000)));
	glEnd();*/


	//Diamond Ball
	glColor3f(0.0,1.0,0.3);
	glBegin(GL_QUADS);
		glVertex2f(75, ballYPos + ballDeltaY + 25);
		glVertex2f(100, ballYPos + ballDeltaY);
		glVertex2f(75, ballYPos + ballDeltaY - 25);
		glVertex2f(50, ballYPos + ballDeltaY);
	glEnd();

	//Ball Front
	ballFront.x = 90;
	ballFront.y = ballYPos + ballDeltaY;

	//Ball Up
	ballUp.x = 75;
	ballUp.y = ballYPos + ballDeltaY + 25;

	//Ball Down
	ballDown.x = 75;
	ballDown.y = ballYPos + ballDeltaY - 25;
}

void mouse(int btn,int state,int x,int y)
{

	if(firstScreen == true && btn == GLUT_LEFT_BUTTON)
		firstScreen = false;

	//Slow down the ball
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ((ballYPos+ballDeltaY) > 100 && (ballYPos+ballDeltaY) < 500))
	{
		if(ballSpeed == 13.0)
			ballSpeed = 5.0;
		if(ballSpeed == -13.0)
			ballSpeed = -5.0;
	}
	//Speed up the ball
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if(ballSpeed == 5.0)
			ballSpeed = 13.0;
		if(ballSpeed == -5.0)
			ballSpeed = -13.0;
	}
	//fasten the ball
	if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && ((ballYPos+ballDeltaY) > 100 && (ballYPos+ballDeltaY) < 500))
	{
		if(ballSpeed == 13.0)
			ballSpeed = 25.0;
		if(ballSpeed == -13.0)
			ballSpeed = -25.0;
	}
	//Speed up the ball
	if(btn == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		if(ballSpeed == 25.0)
			ballSpeed = 13.0;
		if(ballSpeed == -5.0)
			ballSpeed = -25.0;
	}
}
void printText()
{
	char string[4] = "   ";
	itoa(score,string,10);
	int x = 550;
	int y = 570;
	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x,y);
	//get the length of the string to display
	int len = (int) strlen(string);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
}

void Timer(int i)
{
	glutPostRedisplay();
	glutTimerFunc(60,Timer,0);
}

void startScreen2()
{

    drawBanners();
    	int x = 230;
	int y = 400;
    char line15[15]="level2";
    	glRasterPos2f(x,y);

	int len = (int) strlen(line15);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,line15[i]);
}
void display2()
{


	if(firstScreen == false && endGame==false && life!=0)
		{
		    startScreen2();

			drawBanners();

			drawBall();

			changeBallPosition();

			generateObstacles();

			printText();

		}
        else
            if(life==0)
                displayScore();
	}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

   if(level2==false)
        display1();
    else
        display2();
        //glutSwapBuffers();
  glutSwapBuffers();
}

void mykey(unsigned char key,int x,int y)
{

    if(key == 'q' or key == 'Q' )
        exit(0);
}


int main(int argc,char **argv)
{
	printf("Press ANY key to start\n");
	getch();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(600,600);
	glutCreateWindow("Collision Game");
	glutDisplayFunc(display);
	glClearColor(0.1,0.1,0.1,0.9); //Background Color GREY
	//glClearColor(1.0,1.0,1.0,1.0); //Background Color WHITE
	gluOrtho2D(0.0,600.0,0.0,600.0);
	glutKeyboardFunc(mykey);
	glutMouseFunc(mouse);
	Timer(0);
	glutMainLoop();
}
