#if defined(linux) || defined(_WIN32)
#include <GL/glut.h>    /*Для Linux и Windows*/
#else
#include <GLUT/GLUT.h>  /*Для Mac OS*/
#endif

void reshape(int w, int h);
void display();
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL lesson 6");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();

	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-20, 20, -20, 20, -20, 20);
	gluPerspective(50, 1, 1, 30);
	gluLookAt(5, 5, 10, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1, 1, 1, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(-15,0,0);
	glVertex3f(15,0,0);

	glVertex3f(0,-15, 0);
	glVertex3f(0,15, 0);

	glVertex3f(0,0,-15);
	glVertex3f(0,0,15);
	glEnd();


	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(3, 100, 100);
	glColor3f(0.0, 1.0, 1.0);
	glutWireSphere(5, 100, 100);
	glColor3f(0.3, 0.3, 0.7);
	glutWireCube(6);
	//glutWireTeapot(4);


	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
	if ((key == '=') || (key == '+')) {
		glMatrixMode(GL_MODELVIEW);
		glScaled(1.2, 1.2, 1.2);
		display();
	}
	if ((key == '-') || (key == '_')) {
		glMatrixMode(GL_MODELVIEW);
		glScaled(0.8, 0.8, 0.8);
		display();
	}
	if (key == 127) {
		glMatrixMode(GL_MODELVIEW);
		glRotated(5, 0, 0, 1);
		display();
	}
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(0, 1, 0);
		display();
		break;
	case GLUT_KEY_DOWN:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(0, -1, 0);
		display();
		break;
	case GLUT_KEY_LEFT:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(-1, 0, 0);
		display();
		break;
	case GLUT_KEY_RIGHT:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(1, 0, 0);
		display();
		break;
	case GLUT_KEY_HOME:
		glMatrixMode(GL_MODELVIEW);
		glRotated(5,1,0,0);
		display();
		break;
	case GLUT_KEY_END:
		glMatrixMode(GL_MODELVIEW);
		glRotated(5, 0, 1, 0);
		display();
		break;
	case GLUT_KEY_PAGE_UP:
		glMatrixMode(GL_MODELVIEW);
		glRotated(-5, 1, 1, 1);
		display();
		break;
	case GLUT_KEY_PAGE_DOWN:
		glMatrixMode(GL_MODELVIEW);
		glRotated(5, 1, 1, 1);
		display();
		break;
	}
}
