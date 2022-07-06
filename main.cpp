#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<string.h>

int m=0;
int vp=200;
int flag=0;
//cloud
void draw_pixel(GLint cx, GLint cy)
{
    //glColor3f(1,0,0);
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

void draw_object(int h)
{
    int l;
    for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,h,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,h,l);
		draw_circle(225+m,h,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,h,l);
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
void ground(){
glColor3f(0.1,0.1,0.1);
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

    //runway-strip1
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(-420,-450,-1);
    glVertex3f(-450,-420,-1);
    glVertex3f(-380,-350,-1);
    glVertex3f(-350,-380,-1);
    glEnd();
    //runway-strip2
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(-320,-350,-1);
    glVertex3f(-350,-320,-1);
    glVertex3f(-280,-250,-1);
    glVertex3f(-250,-280,-1);
    glEnd();
    //runway-strip3
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(-220,-250,-1);
    glVertex3f(-250,-220,-1);
    glVertex3f(-180,-150,-1);
    glVertex3f(-150,-180,-1);
    glEnd();
    //runway-strip4
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(-120,-150,-1);
    glVertex3f(-150,-120,-1);
    glVertex3f(-80,-50,-1);
    glVertex3f(-50,-80,-1);
    glEnd();
    //second row- strip1
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(420,-450,-1);
    glVertex3f(450,-420,-1);
    glVertex3f(380,-350,-1);
    glVertex3f(350,-380,-1);
    glEnd();
    //second row-strip2
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(320,-350,-1);
    glVertex3f(350,-320,-1);
    glVertex3f(280,-250,-1);
    glVertex3f(250,-280,-1);
    glEnd();
    //second row-strip3
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(220,-250,-1);
    glVertex3f(250,-220,-1);
    glVertex3f(180,-150,-1);
    glVertex3f(150,-180,-1);
    glEnd();
    //second row-strip4
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(120,-150,-1);
    glVertex3f(150,-120,-1);
    glVertex3f(80,-50,-1);
    glVertex3f(50,-80,-1);
    glEnd();

    //airplane on ground

    airplane_left();
    glTranslatef(-200,-200,0);
    airplane_left();

    glRotatef(180, 0, 1, 0);
    glTranslatef(-200,100,0);
    airplane_left();
    glTranslatef(-200,-200,0);
    airplane_left();


}

//start screen
void flying(int i=0,int j=0)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glClearColor(0.0,0,0.7,0.6);
    glLoadIdentity();
    glViewport(0,0,1000,400);
    ground();
    //plane 1
    glPushMatrix();
    glViewport(500,100,800,800);
    glTranslatef(i,j,0);
    airplane_left();
    glPopMatrix();
         //cloud
    draw_object(125);

   glutSwapBuffers();
    //glFlush();
    glutPostRedisplay();

}
//to add a plane
void add_plane(int i=0,int j=0)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glClearColor(0.0,0,0.7,0.6);
    glLoadIdentity();
    glViewport(0,0,1000,400);
    ground();
    //plane 1
    glPushMatrix();
    glViewport(0,vp,800,300);
    glTranslatef(i,j,0);
    airplane_left();
    glPopMatrix();
         //cloud
    draw_object(125);

   glutSwapBuffers();
    //glFlush();
    glutPostRedisplay();
}
//to rotate the plane by 180 degrees
void rot_plane(int i=0,int j=0)
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0,0,0.7,0.6);
        glLoadIdentity();
        glViewport(0,0,1000,400);
        ground();
        //rotated plane
        glPushMatrix();
        glViewport(0,300,800,300);
        glRotatef(180, 0, 1, 0);
        glTranslatef(i,j,0);
        airplane_left();
        glPopMatrix();
        //cloud
        draw_object(300);
        glutSwapBuffers();

}
void del_plane()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0,0.7,0.6);
    glLoadIdentity();
    glViewport(0,0,1000,400);
    ground();
    draw_object(300);
    glutSwapBuffers();
}

void mov(int f)
{
    //start
   if(f==1)
   {
    int j=0;
    for(int i=0;i<350;i+=5,j+=5)
    {
        delay(0.01);
        flying(-i,0);
    }
   }
   //add a plane
    else if(f==2)
   {
    int j=0;
    for(int i=0;i<350;i+=5,j+=5)
    {
        delay(0.01);
        add_plane(-i,0);
    }
   }
   //rotate
   else if(f==3)
   {
    int j=0;
    for(int i=0;i<350;i+=5,j+=5)
    {
        delay(0.01);
        rot_plane(-i,0);
    }
   }

}
void renderbitmap(float x,float y,void *font,char *string){
    char *c;
    glRasterPos3f(x,y,-1);
    for(c=string;*c!='\0';c++){
        glutBitmapCharacter(font,*c);
    }
}
void displayText( float x, float y,float z, int r, int g, int b, const char *string ) {
int j = strlen( string );

glColor3f( r, g, b );
glRasterPos3f( x, y,z );
for( int i = 0; i < j; i++ ) {
glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
}
}
static void display()
{
     //glClearColor(135,206,250,0.4);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //start screen plane from current direction of the screen
    if(flag==1)
        {
           // glPushMatrix();
            mov(flag);
            //airplane_left();
            //glPopMatrix();
        }
     // add a plane
   if(flag==2)
    {
        vp=vp+100;
        mov(flag);
    }
    //rotate plane--enter from other side of screen
    if(flag==3)
    {
       mov(flag);
    }
    //delete plane
    if(flag==4)
    {
        del_plane();
    }
    //credits
    if(flag==5)
    {
       glDisable(GL_TEXTURE_2D); //added this
glMatrixMode(GL_PROJECTION);
glPushMatrix();
glLoadIdentity();
gluOrtho2D(0.0, 1000, 0.0, 800);
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glLoadIdentity();
glRasterPos2i(10, 10);
char s[] = "Some text";
void * font = GLUT_BITMAP_9_BY_15;
for (char *t =s; *t!='\0';t++)
{
  char c = *t;
  glColor3d(1.0, 0.0, 0.0);
  glutBitmapCharacter(font, c);
}
glMatrixMode(GL_PROJECTION); //swapped this with...
glPopMatrix();
glMatrixMode(GL_MODELVIEW); //...this
glPopMatrix();
//added this
glEnable(GL_TEXTURE_2D);
    }

    glFlush();
}
void init()
{
    glMatrixMode(GL_PROJECTION);
    glOrtho(-500,500,-500,500,-500,500);
    glMatrixMode(GL_MODELVIEW);

}
void scan_menu(int id)
{

  if(id==1)
   {
     flag=1;
   }
   else if(id==2)
   {
     flag=2;
   }
   else if(id==3)
   {
       flag=3;
   }
   else if(id==4)
   {
     flag=4;
   }
   else if(id==5)
   {
     flag=5;
   }
   else
     {
       exit(0);
     }
     display();
    glutPostRedisplay();
}
/* Program entry point */
int main(int argc, char *argv[])
{
        glutInit(&argc, argv);
        glutInitWindowSize(1000,800);
        glutInitWindowPosition(10,10);
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        glutCreateWindow("AIRPLANE FLYING");

        glutCreateMenu(scan_menu);
        glutAddMenuEntry("Start",1);
        glutAddMenuEntry("Add",2);
        glutAddMenuEntry("Rotate",3);
        glutAddMenuEntry("Delete",4);
        glutAddMenuEntry("Credits",5);
        glutAddMenuEntry("Quit",6);

        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutDisplayFunc(display);
        //glClearColor(135,206,250,0.4);
        glEnable(GL_DEPTH);
        init();
        glutMainLoop();
        return EXIT_SUCCESS;
}
