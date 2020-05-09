#pragma region Usings
#include"glew.h"
#include"freeglut.h"
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include <stdio.h>
#include <time.h>       
#include <random>

using namespace std;
#pragma endregion
#pragma region Method Definitions
void key_entry(int key, int x, int y);
void display();
void plane();
void setLocation();
void helicopterStraight(int x, int y);
void helicopterReverse(int x, int y);
void helikopter1();
void helikopter2();
void helikopter3();
void parametreAl(int heliId);
void isCrashed();
std::default_random_engine generator;
std::uniform_int_distribution<int> hizBulma(1, 6);
std::uniform_int_distribution<int> YonBulma(0, 1);
#pragma endregion
#pragma region Variables
int planeX, planeY;
int windowSizeWidth = 480;
int windowSizeHeight = 640;
int gameSpeed = 10;
float x1 = 0, x2 = 0, x3 = 0;
int sagaHareket1 = YonBulma(generator);;
int sagaHareket2 = YonBulma(generator);;
int sagaHareket3= YonBulma(generator);;
int difficulty = 1;
float Speed1, Speed2, Speed3;
int reset1 = 1, reset2 = 1, reset3 = 1;
int hak = 3;
int hx1, hx2, hx3, hy1, hy2, hy3;
#pragma endregion
/*
class Heli {
public:
	int x,y,isDirectionRight,extra;
	float Speed;

	Heli(int layer, int difficulty) {
		srand(time(NULL));
		isDirectionRight = rand() % 2;
		if (isDirectionRight == 0) { x = 25; }
		else { x = windowSizeWidth - 25; }
		if (layer == 1) { y = 300; }
		if (layer == 2) { y = 400; }
		if (layer == 3) { y = 500; }
		Speed = rand() % 7 + 1;
		Speed = Speed * 0, 1 + difficulty;
		helicopterUret();
	}
	void helicopterUret() {
		int direction = 1;
		glColor3f(0, 0, 1);
		glPointSize(2.0f);
		glLineWidth(2.0f);
		if (isDirectionRight == 1) {
#pragma region gövde
			glBegin(GL_POLYGON); //1
			glVertex2f((x - 5) * direction, y + 10);
			glVertex2f((x + 15) * direction, y + 10);
			glVertex2f((x + 25) * direction, y);
			glVertex2f((x + 25) * direction, y - 10);
			glVertex2f((x - 5) * direction, y - 10);
			glEnd();
#pragma endregion
#pragma region kuyruk
			glBegin(GL_LINES); //2
			glVertex2f((x - 5) * direction, y);
			glVertex2f((x - 20) * direction, y);
			glEnd();

			glBegin(GL_LINES); //3
			glVertex2f((x - 25) * direction, y + 5);
			glVertex2f((x - 15) * direction, y - 5);
			glEnd();

			glBegin(GL_LINES); //5  
			glVertex2f((x - 25) * direction, y - 5);
			glVertex2f((x - 15) * direction, y + 5);
			glEnd();
#pragma endregion
#pragma region Pervane
			glBegin(GL_LINES); //6  
			glVertex2f((x + 5) * direction, y + 10);
			glVertex2f((x + 5) * direction, y + 20);
			glEnd();
			glBegin(GL_LINES); //7  
			glVertex2f((x - 15) * direction, y + 25);
			glVertex2f((x + 25) * direction, y + 15);
			glEnd();
			glBegin(GL_LINES); //8  
			glVertex2f((x - 15) * direction, y + 15);
			glVertex2f((x + 25) * direction, y + 25);
			glEnd();
#pragma endregion
#pragma region Ayak
			glBegin(GL_LINES); //5  
			glVertex2f((x + 5) * direction, y - 10);
			glVertex2f((x + 5) * direction, y - 15);
			glEnd();
			glBegin(GL_LINES); //5  
			glVertex2f((x + 20) * direction, y - 10);
			glVertex2f((x + 20) * direction, y - 15);
			glEnd();
			glBegin(GL_LINES); //5  
			glVertex2f((x - 10) * direction, y - 15);
			glVertex2f((x + 25) * direction, y - 15);
			glEnd();
			glBegin(GL_LINES); //5  
			glVertex2f((x - 10) * direction, y - 15);
			glVertex2f((x - 10) * direction, y - 10);
			glEnd();
#pragma endregion
		}
		if (isDirectionRight == 0) {
#pragma region gövde
			glBegin(GL_POLYGON); //1
			glVertex2f(((x - 5) * direction) + 2 * x, y + 10);
			glVertex2f(((x + 15) * direction) + 2 * x, y + 10);
			glVertex2f(((x + 25) * direction) + 2 * x, y);
			glVertex2f(((x + 25) * direction) + 2 * x, y - 10);
			glVertex2f(((x - 5) * direction) + 2 * x, y - 10);
			glEnd();
#pragma endregion
#pragma region kuyruk
			glBegin(GL_LINES); //2
			glVertex2f(((x - 5) * direction) + 2 * x, y);
			glVertex2f(((x - 20) * direction) + 2 * x, y);
			glEnd();

			glBegin(GL_LINES); //3
			glVertex2f(((x - 25) * direction) + 2 * x, y + 5);
			glVertex2f(((x - 15) * direction) + 2 * x, y - 5);
			glEnd();

			glBegin(GL_LINES); //5  
			glVertex2f(((x - 25) * direction) + 2 * x, y - 5);
			glVertex2f(((x - 15) * direction) + 2 * x, y + 5);
			glEnd();
#pragma endregion
#pragma region Pervane
			glBegin(GL_LINES); //6  
			glVertex2f(((x + 5) * direction) + 2 * x, y + 10);
			glVertex2f(((x + 5) * direction) + 2 * x, y + 20);
			glEnd();
			glBegin(GL_LINES); //7  
			glVertex2f(((x - 15) * direction) + 2 * x, y + 25);
			glVertex2f(((x + 25) * direction) + 2 * x, y + 15);
			glEnd();
			glBegin(GL_LINES); //8  
			glVertex2f(((x - 15) * direction) + 2 * x, y + 15);
			glVertex2f(((x + 25) * direction) + 2 * x, y + 25);
			glEnd();
#pragma endregion
#pragma region Ayak
			glBegin(GL_LINES); //5  
			glVertex2f(((x + 5) * direction) + 2 * x, y - 10);
			glVertex2f(((x + 5) * direction) + 2 * x, y - 15);
			glEnd();
			glBegin(GL_LINES); //5  
			glVertex2f(((x + 20) * direction) + 2 * x, y - 10);
			glVertex2f(((x + 20) * direction) + 2 * x, y - 15);
			glEnd();
			glBegin(GL_LINES); //5  
			glVertex2f(((x - 10) * direction) + 2 * x, y - 15);
			glVertex2f(((x + 25) * direction) + 2 * x, y - 15);
			glEnd();
			glBegin(GL_LINES); //5  
			glVertex2f(((x - 10) * direction) + 2 * x, y - 15);
			glVertex2f(((x - 10) * direction) + 2 * x, y - 10);
			glEnd();
#pragma endregion
		}
		glFlush();
	}
};
*/


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	plane(); 
	helikopter1();
	helikopter2();
	helikopter3();
	isCrashed();
	glutPostRedisplay();
	glutSwapBuffers();
}

void setLocation() {
	srand(time(NULL));
	planeX = rand() % 431 + 25;
	planeY = rand() % 150 + 25;
	printf("planeX %d \n", planeX);
	printf("planeY %d \n", planeY);

}

void key_entry(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_UP:
		planeY += gameSpeed;
		if (planeY + 25 > windowSizeHeight) { planeY -= gameSpeed; }
		printf("GLUT_KEY_UP %d \n", planeY);
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		planeY = planeY - gameSpeed;
		if (planeY - 25 < 0) { planeY += gameSpeed; }
		printf("GLUT_KEY_DOWN %d \n", planeY);
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		planeX = planeX - gameSpeed;
		if (planeX - 25 < 0) { planeX += gameSpeed; }
		printf("GLUT_KEY_LEFT %d \n", planeX);
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		planeX = planeX + gameSpeed;
		if (planeX + 30 > windowSizeWidth) { planeX -= gameSpeed; }
		printf("GLUT_KEY_RIGHT %d \n", planeX);
		glutPostRedisplay();
		break;
	case GLUT_KEY_HOME:
		exit(0);
		break;
	}


}

int main(int argc, char** argv)
{
	setLocation();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(600, 300);//glut penceresinin ekran konumu
	glutInitWindowSize(windowSizeWidth, windowSizeHeight); //glut penceresinin boyutlarý
	glutCreateWindow("Dinamikleþtik Aðam");
	glClearColor(1, 1, 1, 0);
	gluOrtho2D(0, 480, 0.0, 640);
	glutDisplayFunc(display);
	glutSpecialFunc(key_entry);
	glutMainLoop();

	return 0;
}

void plane() {
	glColor3f(0, 0, 1);
	glPointSize(5.0f);
	glLineWidth(5.0f);
	glBegin(GL_LINES); //1
	glVertex2f(planeX, planeY + 25);
	glVertex2f(planeX, planeY - 25);
	glEnd();
	glBegin(GL_LINES); //2
	glVertex2f(planeX - 25, planeY + 10);
	glVertex2f(planeX + 25, planeY + 10);
	glEnd();
	glBegin(GL_LINES); //3
	glVertex2f(planeX - 10, planeY - 20);
	glVertex2f(planeX + 10, planeY - 20);
	glEnd();
	glFlush();
}

void helicopterStraight(int x, int y) {
	int direction = 1;
	glColor3f(0, 0, 1);
	glPointSize(2.0f);
	glLineWidth(2.0f);
#pragma region gövde
	glBegin(GL_POLYGON); //1
	glVertex2f((x - 5) * direction, y + 10);
	glVertex2f((x + 15) * direction, y + 10);
	glVertex2f((x + 25) * direction, y);
	glVertex2f((x + 25) * direction, y - 10);
	glVertex2f((x - 5) * direction, y - 10);
	glEnd();
#pragma endregion

#pragma region kuyruk
	glBegin(GL_LINES); //2
	glVertex2f((x - 5) * direction, y);
	glVertex2f((x - 20) * direction, y);
	glEnd();

	glBegin(GL_LINES); //3
	glVertex2f((x - 25) * direction, y + 5);
	glVertex2f((x - 15) * direction, y - 5);
	glEnd();

	glBegin(GL_LINES); //5  
	glVertex2f((x - 25) * direction, y - 5);
	glVertex2f((x - 15) * direction, y + 5);
	glEnd();
#pragma endregion

#pragma region Pervane
	glBegin(GL_LINES); //6  
	glVertex2f((x + 5) * direction, y + 10);
	glVertex2f((x + 5) * direction, y + 20);
	glEnd();
	glBegin(GL_LINES); //7  
	glVertex2f((x - 15) * direction, y + 25);
	glVertex2f((x + 25) * direction, y + 15);
	glEnd();
	glBegin(GL_LINES); //8  
	glVertex2f((x - 15) * direction, y + 15);
	glVertex2f((x + 25) * direction, y + 25);
	glEnd();
#pragma endregion

#pragma region Ayak
	glBegin(GL_LINES); //5  
	glVertex2f((x + 5) * direction, y - 10);
	glVertex2f((x + 5) * direction, y - 15);
	glEnd();
	glBegin(GL_LINES); //5  
	glVertex2f((x + 20) * direction, y - 10);
	glVertex2f((x + 20) * direction, y - 15);
	glEnd();
	glBegin(GL_LINES); //5  
	glVertex2f((x - 10) * direction, y - 15);
	glVertex2f((x + 25) * direction, y - 15);
	glEnd();
	glBegin(GL_LINES); //5  
	glVertex2f((x - 10) * direction, y - 15);
	glVertex2f((x - 10) * direction, y - 10);
	glEnd();
#pragma endregion
	glFlush();
}

void helicopterReverse(int x, int y) {
	int direction = -1;
	glColor3f(0, 0, 1);
	glPointSize(2.0f);
	glLineWidth(2.0f);
#pragma region gövde
	glBegin(GL_POLYGON); //1
	glVertex2f(((x - 5) * direction) + 2 * x, y + 10);
	glVertex2f(((x + 15) * direction) + 2 * x, y + 10);
	glVertex2f(((x + 25) * direction) + 2 * x, y);
	glVertex2f(((x + 25) * direction) + 2 * x, y - 10);
	glVertex2f(((x - 5) * direction) + 2 * x, y - 10);
	glEnd();
#pragma endregion
#pragma region kuyruk
	glBegin(GL_LINES); //2
	glVertex2f(((x - 5) * direction) + 2 * x, y);
	glVertex2f(((x - 20) * direction) + 2 * x, y);
	glEnd();

	glBegin(GL_LINES); //3
	glVertex2f(((x - 25) * direction) + 2 * x, y + 5);
	glVertex2f(((x - 15) * direction) + 2 * x, y - 5);
	glEnd();

	glBegin(GL_LINES); //5  
	glVertex2f(((x - 25) * direction) + 2 * x, y - 5);
	glVertex2f(((x - 15) * direction) + 2 * x, y + 5);
	glEnd();
#pragma endregion
#pragma region Pervane
	glBegin(GL_LINES); //6  
	glVertex2f(((x + 5) * direction) + 2 * x, y + 10);
	glVertex2f(((x + 5) * direction) + 2 * x, y + 20);
	glEnd();
	glBegin(GL_LINES); //7  
	glVertex2f(((x - 15) * direction) + 2 * x, y + 25);
	glVertex2f(((x + 25) * direction) + 2 * x, y + 15);
	glEnd();
	glBegin(GL_LINES); //8  
	glVertex2f(((x - 15) * direction) + 2 * x, y + 15);
	glVertex2f(((x + 25) * direction) + 2 * x, y + 25);
	glEnd();
#pragma endregion
#pragma region Ayak
	glBegin(GL_LINES); //5  
	glVertex2f(((x + 5) * direction) + 2 * x, y - 10);
	glVertex2f(((x + 5) * direction) + 2 * x, y - 15);
	glEnd();
	glBegin(GL_LINES); //5  
	glVertex2f(((x + 20) * direction) + 2 * x, y - 10);
	glVertex2f(((x + 20) * direction) + 2 * x, y - 15);
	glEnd();
	glBegin(GL_LINES); //5  
	glVertex2f(((x - 10) * direction) + 2 * x, y - 15);
	glVertex2f(((x + 25) * direction) + 2 * x, y - 15);
	glEnd();
	glBegin(GL_LINES); //5  
	glVertex2f(((x - 10) * direction) + 2 * x, y - 15);
	glVertex2f(((x - 10) * direction) + 2 * x, y - 10);
	glEnd();
#pragma endregion
	glFlush();
}

void helikopter1(){
	if(reset1==1){
		parametreAl(1); 
	}
	if (sagaHareket1 == 1) {
		helicopterStraight(25+x1, 300);
		x1 += Speed1;
		if (25 + x1 > 480) {
			parametreAl(1);
			x1 = 0;
		}
	}
	if (sagaHareket1 == 0) {
		helicopterReverse(480 - x1, 300);
		x1 += Speed1;
		if (480-x1 < 0) {
			parametreAl(1);
			x1 = 0;
		}
	}
	hy1 = 300;
}
void helikopter2(){
	if (reset2 == 1) {
		parametreAl(2);
	}
	if (sagaHareket2 == 1) {
		helicopterStraight(25+x2, 400);
		x2 += Speed2;
		if (25 + x2 > 480) {
			parametreAl(2);
			x2 = 0;
		}
	}
	if (sagaHareket2 == 0) {
		helicopterReverse(480 - x2, 400);
		x2 += Speed2;
		if (480 - x2 < 0) {
			parametreAl(2);
			x2 = 0;
		}
	}
}
void helikopter3(){

	if (reset3 == 1) {
		parametreAl(3);
	}
	if (sagaHareket3 == 1) {
		helicopterStraight(25 + x3, 500);
		x3 += Speed3;
		if (25 + x3 > 480) {
			parametreAl(3);
			x3 = 0;
		}
	}
	if (sagaHareket3 == 0) {
		helicopterReverse(480 - x3, 500);
		x3 += Speed3;
		if (480 - x3 < 0) {
			parametreAl(3);
			x3 = 0;
		}
	}
}
void parametreAl(int heliId) {
	if (heliId == 1) {
		srand(time(NULL));
		sagaHareket1= rand() % 2;
		if(sagaHareket2 == 1){}
		Speed1 = hizBulma(generator);
		Speed1 = Speed1 * 0.01 + difficulty * 0, 2;
		reset1 = 0;
	}
	if (heliId == 2) {
		srand(time(NULL));
		sagaHareket2 = rand() % 2;
		Speed2 = hizBulma(generator);
		Speed2 = Speed2 * 0.01 + difficulty * 0, 2;
		reset2 = 0;
	}
	if (heliId == 3) {
		srand(time(NULL));
		sagaHareket1 = rand() % 2;
		Speed3 = hizBulma(generator);
		Speed3 = Speed3 * 0.01 + difficulty * 0, 2;
		reset3 = 0;
	}
}

void isCrashed() {

}