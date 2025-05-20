#include<windows.h>
#include <GL/glut.h>
#include <time.h>
#include <cmath>
#include<cstdlib>
int j=0,r=3;
int k=0,l=0,m=0;
class game{
public:
	int OrthoWid;
	int OrthoHei;
	int WinWid;
	int WinHei;
	int winXPos;
	int winYPos;
	float FieldSizeX;
	float FieldSizeY;
	int delay;
	float PThickness;
	float BallSize;
	float BorderT;
	float MLineT;
	int ScoreL;
	int ScoreR;
	float TextPosX;
	float TextPosY;
	float BallSpeedX;
	float PSpeedY;
	game(){
		WinWid = 700;
		WinHei = 700;
		OrthoWid = 700;
		OrthoHei = 700;
		winXPos = 100;
		winYPos = 100;
		delay = 1;
		PThickness = 10;
		BallSize = 5;
		FieldSizeX = 600;
		FieldSizeY = 400;
		BorderT = 10;
		MLineT = 5;
		ScoreL = 0;
		ScoreR = 0;
		TextPosX = 0;
		TextPosY = FieldSizeY + 10;
		BallSpeedX = 5;
		PSpeedY = 2;
	}
	void start_settings();
	void win();
	void KeyControl();
	void KeyReset();
	void DrawField();
	void DrawScore();
}settings;

class ball{
public:
float x;
float y;
float vx;
float vy;
void move();
void reflection();
void draw();
}ball;

class reflector{
public:
	float x,y;
	float vy;
	float size;
	bool Up, Down, hold;
	reflector(){
	vy = 0;
	y = 0;
	Up = false;
	Down = false;
	hold = false;
	}
	void draw();
	void move();
	void care();
}left,right;

void game::KeyReset(){
left.vy = 0;
right.vy = 0;
}

void game::KeyControl(){
	if((left.Up)&&(!left.Down))left.vy = PSpeedY;
	if((!left.Up)&&(left.Down))left.vy = -PSpeedY;
	if((right.Up)&&(!right.Down))right.vy = PSpeedY;
	if((!right.Up)&&(right.Down))right.vy = -PSpeedY;
}

void game::start_settings(){
left.size = 200;
right.size = 200;
left.x = -510;
right.x = 510;
while(ball.vx == 0)ball.vx = (rand()%3 - 1)*BallSpeedX;
ball.vy = 0;
ball.x = 0;
ball.y = 0;
}

void game::win(){
	if((ScoreL == 6)||(ScoreR == 5)){
		glutTimerFunc(2000,exit,0);
		settings.delay = 10000;
	}
	if(ball.x < left.x + PThickness - BallSpeedX){

		right.hold = true;
		ScoreR++;
		r=1;
	}
	if(ball.x > right.x - PThickness + BallSpeedX){

		left.hold = true;
		ScoreL++;
		r=0;
	}
}

void reflector::care(){
	if(hold){
		ball.vx = 0;
		if(x < 0)ball.x = x + 2*settings.PThickness;
		if(x > 0)ball.x = x - 2*settings.PThickness;
		ball.vy = vy;
		ball.y = y;
	}
}

void game::DrawField(){
//	glColor3f(1,0,0);
//	glVertex2f(-610,-410);
//	        glColor3d(1,1,0);
//	glVertex2f(-610,400);
//	        glColor3d(1,1,1);
//	glVertex2f(600,400);
//	        glColor3d(0,1,1);
//	glVertex2f(600,-410);
    if(l%2==0){
glColor3f((rand()%2),(rand()%2),(rand()%2));
l++;
    }
else if(l%3==0){
        glColor3f((rand()%3),(rand()%3),(rand()%3));
    l++;
}
else{
glColor3f((rand()%5),(rand()%5),(rand()%5));
l++;
}
	glVertex2f(-FieldSizeX - BorderT,-FieldSizeY - BorderT);
	glVertex2f(FieldSizeX + BorderT,-FieldSizeY - BorderT);
	glVertex2f(FieldSizeX + BorderT,-FieldSizeY);
	glVertex2f(-FieldSizeX - BorderT,-FieldSizeY);

	glVertex2f(-FieldSizeX - BorderT,FieldSizeY + BorderT);
	glVertex2f(FieldSizeX + BorderT,FieldSizeY + BorderT);
	glVertex2f(FieldSizeX + BorderT,FieldSizeY);
	glVertex2f(-FieldSizeX - BorderT,FieldSizeY);

	glVertex2f(-FieldSizeX - BorderT,-FieldSizeY - BorderT);
	glVertex2f(-FieldSizeX,-FieldSizeY - BorderT);
	glVertex2f(-FieldSizeX,FieldSizeY + BorderT);
	glVertex2f(-FieldSizeX - BorderT, FieldSizeY + BorderT);

	glVertex2f(FieldSizeX,-FieldSizeY - BorderT);
	glVertex2f(FieldSizeX + BorderT,-FieldSizeY - BorderT);
	glVertex2f(FieldSizeX + BorderT,FieldSizeY + BorderT);
	glVertex2f(FieldSizeX, FieldSizeY + BorderT);

	for(float i = -FieldSizeY; i <= FieldSizeY; i += 4*MLineT){
        j++;
        if(j%2==0)
        glColor3f(1,1,1);
else if(j%3==0)
    glColor3f(1,0,0);
    else if (j%5==0)
    glColor3f(0,1,0);
    else
        glColor3f(0,0,1);
		glVertex2f(-MLineT,i + MLineT);
		glVertex2f(MLineT,i + MLineT);
		glVertex2f(MLineT,i - MLineT);
		glVertex2f(-MLineT,i - MLineT);
	}
}

void game::DrawScore(){
    if(r==3)
            glColor3f(1,1,1);
    if(r==0)
        glColor3f(1,0,0);
    else
    glColor3f(1.0,1.0,1.0);
	glRasterPos2f(TextPosX -350, TextPosY + 20);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'P');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'A');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Y');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '1');
	if(r==0)
        glColor3f(0,1,0);
	else
	glColor3f(0,0,1);
	glRasterPos2f(TextPosX -50, TextPosY + 20);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0' + ScoreL);
	if(r==1)
        glColor3f(0,1,0);
	else
	glColor3f(0,0,1);
	glRasterPos2f(TextPosX + 30, TextPosY + 20);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0' + ScoreR);
	if(r==1)
        glColor3f(1,0,0);
	else
	glColor3f(1,1,1);
	glRasterPos2f(TextPosX +250, TextPosY + 20);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'P');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'A');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Y');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '2');
	if(ScoreL >= 5){
            glColor3f(0,1,0);
		glRasterPos2f(TextPosX - 350, TextPosY + 50);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'I');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');
	}
	if(ScoreR >= 5){
	    glColor3f(0,1,0);
		glRasterPos2f(TextPosX + 270, TextPosY + 50);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'I');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');
	}
}

void reflector::move(){
	y += vy;
	if(y < -settings.FieldSizeY + size/2){
		y = -settings.FieldSizeY + size/2;
		vy = 0;
	}
	if(y > settings.FieldSizeY - size/2){
		y = settings.FieldSizeY - size/2;
		vy = 0;
	}
}

void reflector::draw(){
    glBegin(GL_QUADS);
    if(m%2==0){
glColor3f(1,0,0);
m++;
    }
else if(l%3==0){
        glColor3f(0,1,0);
    m++;
}
else{
glColor3f(1,1,1);
m++;
}
glVertex3f(x + settings.PThickness,y + size/2,0);
glVertex3f(x + settings.PThickness,y - size/2,0);
glVertex3f(x - settings.PThickness,y - size/2,0);
glVertex3f(x - settings.PThickness,y + size/2,0);
glEnd();
}

void ball::reflection(){
if((y <= -settings.FieldSizeY)||(y >= settings.FieldSizeY))vy = -vy;
if((x <= left.x+settings.PThickness)&&(fabs(double(y - left.y)) <= left.size/2 + fabs(vy))){
	vx = -vx;
	vy += left.vy;
	m++;
}
if((x >= right.x-settings.PThickness)&&(fabs(double(y - right.y)) <= right.size/2 + fabs(vy))){
	vx = -vx;
	vy += right.vy;
	m++;
}
}

void ball::draw()
{
    if(k%2==0){
glColor3f(1,1,1);
k++;
    }
else if(k%3==0){
        glColor3f(1,0,0);
    k++;
}
else{
glColor3f(0,1,0);
k++;
}
glVertex2f(x+settings.BallSize,y+settings.BallSize);
glVertex2f(x+settings.BallSize,y-settings.BallSize);
glVertex2f(x-settings.BallSize,y-settings.BallSize);
glVertex2f(x-settings.BallSize,y+settings.BallSize);

}

void ball::move(){
	x += vx;
	y += vy;
}

void keyboard(unsigned char key, int x,int y){
	switch(key){
	case 'q' :
		left.Up = true;
		break;
	case 'a' :
		left.Down = true;
		break;
	case 'z' :
		if(left.hold){
			left.hold = false;
			ball.vx = settings.BallSpeedX;
		}
		break;
	case 'p' :
		right.Up = true;
		break;
	case 'l' :
		right.Down = true;
		break;
	case 'm' :
		if(right.hold){
			right.hold = false;
			ball.vx = -settings.BallSpeedX;
		break;
		}
	}
}

void keyboardUp(unsigned char key, int x,int y){
	switch(key){
	case 'q' :
		left.Up = false;
		break;
	case 'a' :
		left.Down = false;
		break;
	case 'p' :
		right.Up = false;
		break;
	case 'l' :
		right.Down = false;
		break;
	}
}

void Timer (int value){
	settings.win();
	settings.KeyControl();
	left.move();
	right.move();
	ball.move();
	ball.reflection();
	left.care();
	right.care();
	settings.KeyReset();
	glutPostRedisplay();
	glutTimerFunc(settings.delay,Timer,0);
}

void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
    settings.DrawField();
		ball.draw();
	glEnd();
	left.draw();
	right.draw();
	settings.DrawScore();
	glutSwapBuffers();
}

int main (int argc, char ** argv){
	srand(time(NULL));
	settings.start_settings();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Paddle Smash");
	glutDisplayFunc(draw);
	glutTimerFunc(settings.delay,Timer,0);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glClearColor(0,0,0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-700,700,-700,700);
	glutMainLoop();
	return(0);
}
