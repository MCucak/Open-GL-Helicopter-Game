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
void helicopter(int x, int y);

#pragma endregion

#pragma region Variables
int planeX, planeY;
int windowSizeWidht = 480;
int windowSizeHeight = 640;
int gameSpeed = 10;

#pragma endregion


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	plane();
	helicopter(50,70);
	glutPostRedisplay();
	glutSwapBuffers();
}

void setLocation() {
	srand(time(NULL));
	planeX = rand() % 431 + 25;
	planeY = rand() % 150 + 25;
}

void key_entry(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_UP:
		planeY+=gameSpeed;
		if (planeY + 25 > windowSizeHeight) { planeY -= gameSpeed; }
		printf("GLUT_KEY_UP %d \n",planeY);
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
	printf("planeX %d \n", planeX);
	printf("planeY %d \n", planeY);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(600, 300);//glut penceresinin ekran konumu
	glutInitWindowSize(windowSizeWidht, windowSizeHeight); //glut penceresinin boyutlarý
	glutCreateWindow("Dinamikleþtik Aðam");
	glClearColor(1,1,1,0);
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
	glVertex2f(planeX-25, planeY + 10);
	glVertex2f(planeX+25, planeY + 10);
	glEnd();
	glBegin(GL_LINES); //3
	glVertex2f(planeX - 10, planeY - 20);
	glVertex2f(planeX + 10, planeY - 20);
	glEnd();
	glFlush();

}

void helicopter(int x, int y) {

	glColor3f(0, 0, 1);
	glPointSize(5.0f);
	glLineWidth(5.0f);
	glBegin(GL_LINES); //1
	glVertex2f(planeX + 100, planeY - 50);
	glVertex2f(planeX + 100, planeY - 50);
	glEnd();
	glFlush();


}