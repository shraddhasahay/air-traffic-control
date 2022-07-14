#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>


float red=0.52734375,green=0.8046878,blue=1.0;
GLfloat a=0,b=0,c=0,d=0,e=0; //runway
int goUp=0; //for initial start of plane
int m=0;
int vp=200;
int flag=0;
//stars
void stars()
{

    glPointSize(4.0);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex3f(-250,300,-1);
    glVertex3f(-333,200,-1);
    glVertex3f(-50,390,-1);
    glVertex3f(-160,400,-1);
    glVertex3f(-34,500,-1);
    glVertex3f(100,100,-1);
    glVertex3f(200,200,-1);
    glVertex3f(300,300,-1);
    glVertex3f(500,500,-1);
    glVertex3f(400,400,-1);
    glVertex3f(-500,-500,-1);
    glVertex3f(-100,-100,-1);
    glVertex3f(-200,-200,-1);
    glVertex3f(-300,-300,-1);
    glVertex3f(-500,-350,-1);
    glVertex3f(-400,-400,-1);
    glVertex3f(500,-450,-1);

    glEnd();
}
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

//runway and strips
void runway()
{

        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);//black road
        glVertex3f(-500,-50,-1);
        glVertex3f(-500,-500.0,-1);
        glVertex3f(500.0,-500.0,-1);
        glVertex3f(500.0,-50.0,-1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//white strips on road
        glVertex3f(0.0,-60.0,-1);
        glVertex3f(8.0,-80.0,-1);
        glVertex3f(58.0,-80.0,-1);
        glVertex3f(50.0,-60,-1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex3f(100.0,-60.0,-1);
        glVertex3f(108.0,-80.0,-1);
        glVertex3f(158.0,-80.0,-1);
        glVertex3f(150.0,-60.0,-1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex3f(200.0,-60.0,-1);
        glVertex3f(208.0,-80.0,-1);
        glVertex3f(258.0,-80.0,-1);
        glVertex3f(250.0,-60.0,-1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex3f(300.0,-60.0,-1);
        glVertex3f(308.0,-80.0,-1);
        glVertex3f(358.0,-80.0,-1);
        glVertex3f(350.0,-60.0,-1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex3f(400.0,-60.0,-1);
        glVertex3f(408.0,-80.0,-1);
        glVertex3f(458.0,-80.0,-1);
        glVertex3f(450.0,-60.0,-1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//white strips on road-2 reflected
        glVertex3f(-0.0,-60.0,-1);
        glVertex3f(-8.0,-80.0,-1);
        glVertex3f(-58.0,-80.0,-1);
        glVertex3f(-50.0,-60,-1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex3f(-100.0,-60.0,-1);
        glVertex3f(-108.0,-80.0,-1);
        glVertex3f(-158.0,-80.0,-1);
        glVertex3f(-150.0,-60.0,-1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex3f(-200.0,-60.0,-1);
        glVertex3f(-208.0,-80.0,-1);
        glVertex3f(-258.0,-80.0,-1);
        glVertex3f(-250.0,-60.0,-1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex3f(-300.0,-60.0,-1);
        glVertex3f(-308.0,-80.0,-1);
        glVertex3f(-358.0,-80.0,-1);
        glVertex3f(-350.0,-60.0,-1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(b,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex3f(-400.0,-60.0,-1);
        glVertex3f(-408.0,-80.0,-1);
        glVertex3f(-458.0,-80.0,-1);
        glVertex3f(-450.0,-60.0,-1);
        glEnd();
        glPopMatrix();
        glNewList(1,GL_COMPILE);
        airplane_left();
        glEndList();
}

//start screen
void flying(int i=0,int j=0)
{

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(red,green,blue,0.6);
        stars();
        glLoadIdentity();
        glViewport(0,0,1000,400);
        runway();
        //stationary plane
        glPushMatrix();
        glViewport(250,-40,1000,500);
        glCallList(1);
        glPopMatrix();
        //cloud
        draw_object(300);
        glutSwapBuffers();
        glutPostRedisplay();

}
//to add a plane
void add_plane(int i=0,int j=0,int x=0,int y=0)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(red,green,blue,0.6);
    stars();
    glLoadIdentity();
    glViewport(0,0,1000,400);
    runway();
    //plane 1
     glPushMatrix();
     glViewport(x,y,1000,500);
     glTranslatef(i,j,0);
     glCallList(1);
     glPopMatrix();
         //cloud
    draw_object(125);
   glutSwapBuffers();

}
//to rotate the plane by 180 degrees
void rot_plane(int i=0,int j=0)
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(red,green,blue,0.6);
        stars();
        glLoadIdentity();
        glViewport(0,0,1000,400);
        runway();
        //rotated plane
        glPushMatrix();
        glViewport(0,300,800,300);
        glRotatef(i, j, 1, 0);
        glTranslatef(i,j,0);
        airplane_left();
        glPopMatrix();
        //cloud
        draw_object(300);
        glutSwapBuffers();
        glutPostRedisplay();

}
//delete plane
void del_plane()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(red,green,blue,0.6);
    stars();
    glLoadIdentity();
    glViewport(0,0,1000,400);
    runway();
    draw_object(300);
    glutSwapBuffers();
    glutPostRedisplay();
}

void mov(int f)
{
    //start
   if(f==2)
   {
    int j=0;

    flying();
    goUp=0;

   }
   //add a plane
    if(f==1)
   {
    int j=0;
    if(goUp==0)
    {
         for(int i=0;i<100;i+=5,j+=5)
            {
                delay(0.02);
                add_plane(-i,j,250,-20);
            }
            goUp=1;
    }

        int i=0;
           while(i<=250)
        {
            delay(0.02);
            add_plane(-(i+5),0,-250,100);
            i+=5;
        }
        i=0;
        while(i<=250)
        {
            delay(0.02);
            add_plane(-(i+5),0,250,100);
            i+=5;
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
    goUp=0;
   }
    //display();
    glutPostRedisplay();
}

static void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //start screen plane from current direction of the screen
    if(flag==1)
        {
            mov(flag);
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

    glFlush();
}
//display start screen--credits
void welcomeDisplay()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0,0,0.7);

     glRasterPos3f(-300,400,0);
    char a[]="CMRIT INSTITUTE OF TECHNOLOGY";
    for(int i=0;i<strlen(a);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[i]);


     glRasterPos3f(-300,350,0);
    char b[]="COMPUTER GRAPHICS LAB MINI PROJECT";
    for(int i=0;i<strlen(b);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,b[i]);

    glRasterPos3f(-300,300,0);
    char s[]="PROBLEM STATEMENT:Airplane Flying";
    for(int i=0;i<strlen(s);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);

    glRasterPos3f(-400,140,0);
    char s1[]="PRESENTED BY:";
    for(int i=0;i<strlen(s1);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s1[i]);

      glRasterPos3f(-400,90,0);
    char s2[]="Name:SHRADDHA SAHAY";
    for(int i=0;i<strlen(s2);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s2[i]);

     glRasterPos3f(-400,50,0);
    char s3[]="USN:1CR19CS156";
    for(int i=0;i<strlen(s3);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s3[i]);

          glRasterPos3f(-400,10,0);
    char c[]="Name:SHANU KUMAR";
    for(int i=0;i<strlen(c);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c[i]);


      glRasterPos3f(-400,-30,0);
    char d[]="USN:1CR19CS153";
    for(int i=0;i<strlen(d);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,d[i]);

       glRasterPos3f(200,140,0);
    char s4[]="UNDER GUIDANCE OF";
    for(int i=0;i<strlen(s4);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s4[i]);

      glRasterPos3f(200,90,0);
    char s5[]="Prof. SHIVARAJ V B";
    for(int i=0;i<strlen(s5);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s5[i]);

     glRasterPos3f(200,50,0);
    char s6[]="ASSISTANT PROFESSOR";
    for(int i=0;i<strlen(s6);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s6[i]);

          glRasterPos3f(200,10,0);
    char s7[]="Prof. KARTHEEK G C R ";
    for(int i=0;i<strlen(s7);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s7[i]);


      glRasterPos3f(200,-30,0);
    char s8[]="ASSISTANT PROFESSOR";
    for(int i=0;i<strlen(s8);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s8[i]);

        glRasterPos3f(-400,-150,0);
    char f[]="PRESS d for DAY n for NIGHT";
    for(int i=0;i<strlen(f);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,f[i]);

       glRasterPos3f(-400,-190,0);
    char f1[]="USE RIGHT MOUSE BUTTON FOR MENU";
    for(int i=0;i<strlen(f1);i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,f1[i]);

    glutSwapBuffers();
    glutDisplayFunc(display);
    glutPostRedisplay();
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

   else
     {
       exit(0);
     }
     display();
    glutPostRedisplay();
}
//keyboard function
void keys(unsigned char k,int x,int y)
{
    if(k=='d'||k=='D')
    {
        red=1.0;
        green=0.5;
        blue=0.0;
    }
    if(k=='n'||k=='N')
    {
        red=0.1;
        green=0.0;
        blue=0.1;
    }
    display();
    glutPostRedisplay();
}
/* Program entry point */
int main(int argc, char *argv[])
{
        glutInit(&argc, argv);
        glutInitWindowSize(1000,800);
        glutInitWindowPosition(0,0);
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        glutCreateWindow("AIRPLANE FLYING");
        glutCreateMenu(scan_menu);
        glutAddMenuEntry("Start",1);
        glutAddMenuEntry("Add",2);
        glutAddMenuEntry("Rotate",3);
        glutAddMenuEntry("Delete",4);
        glutAddMenuEntry("Quit",5);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutDisplayFunc(welcomeDisplay);
        glutKeyboardFunc(keys);
        glEnable(GL_DEPTH);
        init();
        glutMainLoop();
        return EXIT_SUCCESS;
}
