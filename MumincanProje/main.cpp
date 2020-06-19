#pragma region Usings
#include"glew.h"
#include"freeglut.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>       
#include <random>
#include <GL/glut.h>
#include <string>
// TODO : HOW TO PREVENT RESHAPE OPENGL 
using namespace std;
#pragma endregion
#pragma region Method Definitions
void key_entry(int key, int x, int y);
void keyPress(unsigned char key, int x, int y);
void display();
void plane();
void setLocation();
void helicopterStraight(int x, int y, float r, float g, float b);
void helicopterReverse(int x, int y, float r, float g, float b);
void helikopter1();
void helikopter2();
void helikopter3();
void helikopter4();
void parametreAl(int heliId);
void isCrashed();
void isWin();
float distance(int x1, int y1, int x2, int y2);
void ScoreText();
void LoseText();
void textShow(std::string text, int x, int y, bool color);
void menuShow();
void infoShow();
void drawButton(int x, int y, string text, int r, int g, int b);
std::default_random_engine generator;
std::uniform_int_distribution<int> hizBulma(1, 5);
std::uniform_int_distribution<int> YonBulma(0, 1);
std::uniform_int_distribution<int> ucakX(25, 431);
std::uniform_int_distribution<int> ucakY(25, 150);
std::uniform_int_distribution<int> renk(0, 100);

#pragma endregion
#pragma region Variables
int planeX, planeY, stop = 0;
int windowSizeWidth = 480;
int windowSizeHeight = 640;
int gameSpeed = 10;
float x1 = 0, x2 = 0, x3 = 0, x4 = 0;
int sagaHareket1 = YonBulma(generator);
int sagaHareket2 = YonBulma(generator);
int sagaHareket3 = YonBulma(generator);
int sagaHareket4 = YonBulma(generator);
float difficulty = 1;
float Speed1, Speed2, Speed3, Speed4;
int reset1 = 1, reset2 = 1, reset3 = 1, reset4 = 1;
int hak = 3;
int hx1, hx2, hx3, hx4, hy1, hy2, hy3, hy4;
int Skor = 0;
float r1, r2, r3, r4, g1, g2, g3, g4, b1, b2, b3, b4;
bool showMenu = true, showHelp = false;
int selectedMenuItem = 1;
#pragma endregion

void display() {
	if (!stop) {
		glMatrixMode(GL_PROJECTION);
		glClear(GL_COLOR_BUFFER_BIT);
		if (showMenu) {
			if (showHelp) {
				infoShow();
			}
			else
			{
				menuShow();
			}
		}
		else {
			plane();
			ScoreText();
			helikopter1();
			helikopter2();
			helikopter3();
			helikopter4();
			isCrashed();
			isWin();
		}
		glFlush();
		glutPostRedisplay();
		glutSwapBuffers();
	}
}

void setLocation() {
	srand(time(NULL));
	planeX = ucakX(generator);
	planeY = ucakY(generator);
}

void menuShow() {
	glColor3f(1, 0, 0);
	int r = 0, g = 1, b = 1, r2 = 0, g2 = 1, b2 = 1;
	textShow("Oyuna Hosgeldin", 170, 450, 1);
	if (selectedMenuItem == 1) {
		r = 0;
		g = 0;
		b = 1;
	}
	drawButton(150, 350, "Basla", r, g, b);
	if (selectedMenuItem == 2) {
		r2 = 0;
		g2 = 0;
		b2 = 1;
	}
	drawButton(150, 250, "Yardim", r2, g2, b2);
}

void drawButton(int x, int y, string text, int r, int g, int b) {
	glColor3f(r, g, b);
	glPointSize(5.0f);
	glLineWidth(5.0f);
	glBegin(GL_QUADS);
	glVertex2f(x - 10, y - 30);
	glVertex2f(x - 10, y + 30);
	glVertex2f(x + 100, y + 30);
	glVertex2f(x + 100, y - 30);
	glEnd();
	textShow(text, x, y, 0);


}

void infoShow() {
	textShow("Oyunda ki gorevin ", 100, 450, 0);
	textShow("ucagi hedeflere carpmadan", 100, 430, 0);
	textShow("oyun alaninin sonuna goturmek", 100, 410, 0);
	textShow("Ucagi ok tuslari ile kontrol edebilirsin", 100, 380, 0);
	textShow("ESC tusu ile oyundan cikabilir,", 100, 360, 0);
	textShow("HOME tusu ile tekrar baslatabilirsin", 100, 340, 0);
	glColor3f(1, 0, 0);
	textShow("Ana ekrana donmek icin ESC bas..", 100, 240, 1);
}

void key_entry(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		if (showMenu) {
			if (selectedMenuItem > 1)
				selectedMenuItem--;
		}
		planeY += gameSpeed;
		if (planeY + 25 > windowSizeHeight) { planeY -= gameSpeed; }
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		if (showMenu) {
			if (selectedMenuItem < 2)
				selectedMenuItem++;
		}
		planeY = planeY - gameSpeed;
		if (planeY - 25 < 0) { planeY += gameSpeed; }
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		planeX = planeX - gameSpeed;
		if (planeX - 25 < 0) { planeX += gameSpeed; }
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		planeX = planeX + gameSpeed;
		if (planeX + 30 > windowSizeWidth) { planeX -= gameSpeed; }
		glutPostRedisplay();
		break;
	case GLUT_KEY_HOME:
		stop = 0;
		display();
		break;
	case GLUT_KEY_F1:
		showHelp = true;
		break;
	}
}

void keyPress(unsigned char key, int x, int y) {
	switch (key) {
	case 13:
		if (selectedMenuItem == 1) {
			showMenu = false;
		}
		if (selectedMenuItem == 2) {
			showHelp = true;
		}
		break;
	case 27:
		showMenu = true;
		showHelp = false;
	}
}

int main(int argc, char** argv){
	setLocation();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(600, 300);//glut penceresinin ekran konumu
	glutInitWindowSize(windowSizeWidth, windowSizeHeight); //glut penceresinin boyutlarý
	glutCreateWindow("Dinamikleþtik Aðam");
	glClearColor(1, 1, 1, 0);
	gluOrtho2D(0, 480, 0.0, 640);
	glutReshapeWindow(480, 640);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPress);
	glutSpecialFunc(key_entry);
	glutMainLoop();
	return 0;
}

void plane() {
	glPointSize(5.0f);
	glLineWidth(5.0f);
	glColor3f(1, 0, 1);
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
}

void helicopterStraight(int x, int y, float r, float g, float b) {
	int direction = 1;
	glColor3f(r, g, b);
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

}

void helicopterReverse(int x, int y, float r, float g, float b) {
	int direction = -1;
	glColor3f(r, g, b);
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
}

void helikopter1() {
	glLoadIdentity();
	if (reset1 == 1) {
		parametreAl(1);
	}
	if (sagaHareket1 == 1) {
		helicopterStraight(25 + x1, 250, r1, g1, b1);
		x1 += Speed1;
		if (25 + x1 > 480) {
			parametreAl(1);
			x1 = 0;
		}
		hx1 = 25 + x1;
	}
	if (sagaHareket1 == 0) {
		helicopterReverse(480 - x1, 250, r1, g1, b1);
		x1 += Speed1;
		if (480 - x1 < 0) {
			parametreAl(1);
			x1 = 0;
		}
		hx1 = 480 - x1;
	}
	hy1 = 255;
}
void helikopter2() {
	if (reset2 == 1) {
		parametreAl(2);
	}
	if (sagaHareket2 == 1) {
		helicopterStraight(25 + x2, 330, r2, g2, b2);
		x2 += Speed2;
		if (25 + x2 > 480) {
			parametreAl(2);
			x2 = 0;
		}
		hx2 = 25 + x2;
	}
	if (sagaHareket2 == 0) {
		helicopterReverse(480 - x2, 330, r2, g2, b2);
		x2 += Speed2;
		if (480 - x2 < 0) {
			parametreAl(2);
			x2 = 0;
		}
		hx2 = 480 - x2;
	}
	hy2 = 335;
}
void helikopter3() {

	if (reset3 == 1) {
		parametreAl(3);
	}
	if (sagaHareket3 == 1) {
		helicopterStraight(25 + x3, 410, r3, g3, b3);
		x3 += Speed3;
		if (25 + x3 > 480) {
			parametreAl(3);
			x3 = 0;
		}
		hx3 = 25 + x3;
	}
	if (sagaHareket3 == 0) {
		helicopterReverse(480 - x3, 410, r3, g3, b3);
		x3 += Speed3;
		if (480 - x3 < 0) {
			parametreAl(3);
			x3 = 0;
		}
		hx3 = 480 - x3;
	}
	hy3 = 415;
}

void helikopter4() {

	if (reset4 == 1) {
		parametreAl(4);
	}
	if (sagaHareket4 == 1) {
		helicopterStraight(25 + x4, 490, r4, g4, b4);
		x4 += Speed4;
		if (25 + x4 > 480) {
			parametreAl(4);
			x4 = 0;
		}
		hx4 = 25 + x4;
	}
	if (sagaHareket4 == 0) {
		helicopterReverse(480 - x4, 490, r4, g4, b4);
		x4 += Speed4;
		if (480 - x4 < 0) {
			parametreAl(4);
			x4 = 0;
		}
		hx4 = 480 - x4;
	}
	hy4 = 495;
}

void parametreAl(int heliId) {
	if (heliId == 1) {
		sagaHareket1 = YonBulma(generator);
		Speed1 = hizBulma(generator);
		Speed1 = Speed1 * 0.01 + difficulty * 0.02;
		reset1 = 0;
		r1 = renk(generator) * 0.01;
		g1 = renk(generator) * 0.01;
		b1 = renk(generator) * 0.01;
	}

	if (heliId == 2) {
		sagaHareket2 = YonBulma(generator);
		Speed2 = hizBulma(generator);
		Speed2 = Speed2 * 0.01 + difficulty * 0.02;
		reset2 = 0;
		r2 = renk(generator) * 0.01;
		g2 = renk(generator) * 0.01;
		b2 = renk(generator) * 0.01;

	}

	if (heliId == 3) {
		sagaHareket3 = YonBulma(generator);
		Speed3 = hizBulma(generator);
		Speed3 = Speed3 * 0.01 + difficulty * 0.02;
		reset3 = 0;
		r3 = renk(generator) * 0.01;
		g3 = renk(generator) * 0.01;
		b3 = renk(generator) * 0.01;
	}

	if (heliId == 4) {
		sagaHareket4 = YonBulma(generator);
		Speed4 = hizBulma(generator);
		Speed4 = Speed4 * 0.01 + difficulty * 0.02;
		reset4 = 0;
		r4 = renk(generator) * 0.01;
		g4 = renk(generator) * 0.01;
		b4 = renk(generator) * 0.01;
	}
}

void isCrashed() {
	int isCrashedPlane = 0;
	int H1D = distance(planeX, planeY, hx1, hy1);
	if (H1D < 46) { isCrashedPlane = 1; }
	int H2D = distance(planeX, planeY, hx2, hy2);
	if (H2D < 46) { isCrashedPlane = 1; }
	int H3D = distance(planeX, planeY, hx3, hy3);
	if (H3D < 46) { isCrashedPlane = 1; }
	int H4D = distance(planeX, planeY, hx4, hy4);
	if (H4D < 46) { isCrashedPlane = 1; }
	glColor3f(0, 0, 0);
	glPointSize(1.0f);

	if (isCrashedPlane == 1) {
		setLocation();
		isCrashedPlane = 0;
		hak -= 1;

		if (hak == 0) {
			LoseText();
			stop = 1;
			Skor = 0;
			hak = 3;
			difficulty = 0;
		}
	}
}

void isWin() {
	if (planeY > 600) {
		difficulty += 1;
		Skor += 10;
		setLocation();
	}
}

float distance(int x1, int y1, int x2, int y2) {

	float xDis = abs(x1 - x2);
	float yDis = abs(y1 - y2);
	float zDis = xDis * xDis + yDis * yDis;

	return sqrt(zDis);

}

void ScoreText()
{
	string skorText = "Skor : " + to_string(Skor);
	string heartText = "Hak : " + to_string(hak);

	textShow(skorText, 320, 620, 0);
	textShow(heartText, 400, 620, 0);
}

void textShow(std::string text, int x, int y, bool color) {
	std::string shownText = text;
	std::string& shownTextPointer = shownText;
	if (color == 0) {
		glColor3f(0, 0, 0);
	}
	glRasterPos2i(x, y);
	for (int i = 0; i < shownText.size(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, shownTextPointer[i]);
	}
}

void LoseText()
{
	string skorText = "Kaybettin! Puan : " + to_string(Skor);
	string againText = "YENIDEN BASLAMAK ICIN 'HOME' TUSUNA BAS..";

	textShow(skorText, 150, 150, 0);
	textShow(againText, 20, 100, 0);
}