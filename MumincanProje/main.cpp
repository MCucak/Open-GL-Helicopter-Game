#pragma region Usings
#include"glew.h"
#include"freeglut.h"
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include <stdio.h>
#include <time.h>       

using namespace std;
#pragma endregion

#pragma region Method Definitions
void key_entry(int key, int x, int y);
void display();
void plane();
void setLocation();
void helicopterStraight(int x, int y);
void helicopterReverse(int x, int y);
void gameManagement();

#pragma endregion

#pragma region Variables
int planeX, planeY;
int windowSizeWidht = 480;
int windowSizeHeight = 640;
int gameSpeed = 10;
float helikopter1X=300, helikopter1Y=400, helikopter2X=200, helikopter2Y=400;

#pragma endregion

void gameManagement() {
	


}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	plane();
	gameManagement();
	helicopterStraight(helikopter1X, helikopter1Y);
	helicopterReverse(helikopter2X, helikopter2Y);
	helikopter1X += 0.04;	
	glutPostRedisplay();
	glutSwapBuffers();
}

class Heli {
public:
	int Id;
	int Yon;
	int Hýz;
	int Renk;

	Heli() {


	}
	void helicopterUret(int x, int y, int yon) {
		int direction = 1;
		glColor3f(0, 0, 1);
		glPointSize(2.0f);
		glLineWidth(2.0f);
		if (yon == 1) {
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
		if (yon == -1) {
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
		if (planeX + 30 > windowSizeWidht) { planeX -= gameSpeed; }
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
	glutInitWindowSize(windowSizeWidht, windowSizeHeight); //glut penceresinin boyutlarý
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
