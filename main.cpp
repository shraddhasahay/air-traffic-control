
#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>
int m=0;
void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}
void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}
void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

void draw_object()
{
    int l;
    for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(300, 300, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
//void runwaystrip()
//{
 //glColor3f()
//}
void ground(){
glColor3f(0,0.7,0);
glBegin(GL_POLYGON);
    glVertex3f(-500,0,-1);
    glVertex3f(-400,15,-1);
    glVertex3f(-300,25,-1);
    glVertex3f(-200,35,-1);
    glVertex3f(-100,45,-1);

    glVertex3f(0,55,-1);
    glVertex3f(100,65,-1);
    glVertex3f(200,75,-1);
    glVertex3f(300,85,-1);
    glVertex3f(400,95,-1);
    glVertex3f(500,0,-1);
    glVertex3f(500,-500,-1);
    glVertex3f(0,-500,-1);
    glVertex3f(-500,-500,-1);



    glEnd();
}
void delay(float number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

static void airplane_left()
{
    //glViewport(250,250,200,200);
    //glTranslated(k,j,0);
    //airplane tail
    glBegin(GL_QUAD_STRIP);
        glColor3d(211,211,211);
        glVertex3f(-50,0,-1);
        glColor3d(211,211,211);
        glVertex3f(50,0,-1);
        glColor3d(0,0,1);
        glVertex3f(50,50,-1);
        glColor3d(0,0,1);
        glVertex3f(-50,-50,-1);
    glEnd();
    //airplane body
    glBegin(GL_QUADS);
        glColor3f(0,0,1);
        glVertex3f(-200,-50,-1);
        glColor3f(0,0,1);
        glVertex3f(-50,-50,-1);
        glColor3f(211,211,211);
        glVertex3f(-50,0,-1);
        glColor3f(211,211,211);
        glVertex3f(-200,0,-1);
    glEnd();
    //airplane head
        float i = 0.0f;
        glBegin(GL_TRIANGLE_FAN);
         glColor3f(0.8,0,0);
        glVertex2f(-200, -50); // Center
        for(i = 90; i <= 180; i++)
                glVertex2f(50*cos(M_PI * i / 180.0) -200, 50*sin(M_PI * i / 180.0) - 50);
        glEnd();
    //left wing
    glBegin(GL_QUADS);
        glColor3f(0,0,1);
        glVertex3f(-170,-30,-1);
        glColor3f(0,0,1);
        glVertex3f(-95,-30,-1);
        glColor3f(220,20,60);
        glVertex3f(-65,-65,-1);
        glColor3f(220,20,60);
        glVertex3f(-90,-80,-1);
    glEnd();


}
static void display(int i=0,int j=0)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0.9,0.9,0);
    glLoadIdentity();
      glViewport(0,0,1000,400);
    //glTranslatef(0,0,0);
    ground();
    draw_object();
    glPushMatrix();
    glViewport(250,250,400,200);
    glTranslatef(i,j,0);
    airplane_left();
    glPopMatrix();
    //glTranslatef(i,j,0);


    //glTranslatef(i,j,0);*/
    //glViewport(0,0,500,500);
    //ground();

    glutSwapBuffers();
    glFlush();
}
void mov()
{
    int j=0;
    for(int i=0;i<350;i+=5,j+=5)
    {
        delay(0.5);
        display(-i,0);

    }

}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}
void init()
{
    glMatrixMode(GL_PROJECTION);
    glOrtho(-500,500,-500,500,-500,500);
    glMatrixMode(GL_MODELVIEW);
}
/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("AIR TRAFFIC");
    glutReshapeFunc(resize);
    //glutDisplayFunc(display);
    init();
    glutKeyboardFunc(key);
    glutIdleFunc(mov);
    glClearColor(135,206,250,0.4);
    glutMainLoop();
    return EXIT_SUCCESS;
}
