
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

GLint keyl,keyr,flag=0;
float  counter=600.0, cnt=-150.0,r1=0.0,g1=1.0,b1=0.0,bc=-260.0;
float r2=0.0,g2=1.0,b2=1.0,r=1.0,g=0.0,b=0.0;
int c=1,d=1;

void  road();
void  grass();
void  grass2();
void  line1();
void  line2();
void  line3();
void  line4();
void  car();
void  truck();
void  bus();
void  sq();
void  text();
void  tc();
void  light();
void  light2();


void *currentfont;


void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *ct;
	glRasterPos3f(x,y,z);

	for(ct=string;*ct!='\0';ct++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*ct);
	}
}

void initOpenGl()
{
    glClearColor(0.2,0.6,0.99,0); //Background Color Blue
    //glClearColor(0.0,0.0,0.0,0); //Background Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,700,0,500);
    glMatrixMode(GL_MODELVIEW);
//    The modelview matrix defines how your objects are transformed (meaning translation,rotation and scaling) in your world coordinate frame

//The projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes.
}

void text()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    drawstring(160,130,0.0,"BUBT BUS");
    glColor3f(1,1,1);
}



void tc()
{//tower
    glLoadIdentity();
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(310,190);
    glVertex2f(310,390);
    glVertex2f(340,390);
    glVertex2f(340,190);
    glEnd();

}

void light()
{
    glLoadIdentity();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(315,330);
    glVertex2f(315,370);
    glVertex2f(335,370);
    glVertex2f(335,330);
    glEnd();
}

void light2()
{
    glLoadIdentity();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(315,330);
    glVertex2f(315,370);
    glVertex2f(335,370);
    glVertex2f(335,330);
    glEnd();
}

void light3()
{
    glLoadIdentity();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(315,280);
    glVertex2f(315,320);
    glVertex2f(335,320);
    glVertex2f(335,280);
    glEnd();
}

void light4()
{
    glLoadIdentity();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(315,280);
    glVertex2f(315,320);
    glVertex2f(335,320);
    glVertex2f(335,280);
    glEnd();
}

void window(int w1,int w2)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(w1,160);
    glVertex2f(w1,185);
    glVertex2f(w2,185);
    glVertex2f(w2,160);
    glEnd();
}

void buswindow(int w1,int w2)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(w1,180);
    glVertex2f(w1,205);
    glVertex2f(w2,205);
    glVertex2f(w2,180);
    glEnd();
}


void wheel(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   for(int i=0;i<360;i++)
   {
       th=i*(3.1416/180);
       glVertex2f(x+20*cos(th),y+20*sin(th));
   }

   glEnd();

}

void road()
{
    glLoadIdentity();
    //1
   // glLoadIdentity — replace the current matrix with the identity matrix
    glColor3f(0.5,0.5,0.5);//gray black road
    glBegin(GL_POLYGON);
    glVertex2f(0,95);
    glVertex2f(0,260);
    glVertex2f(800,260);
    glVertex2f(800,95);
    glEnd();
}

void grass()
{
    //2
    glLoadIdentity();
    glColor3f(0.0,0.5,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,95);
    glVertex2f(800,95);
    glVertex2f(800,0);
    glEnd();
}

void grass2()
{
    //3
    glLoadIdentity();
    glColor3f(0.0,0.5,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0,260);
    glVertex2f(0,300);
    glVertex2f(800,300);
    glVertex2f(800,260);
    glEnd();
}

void line1()
{
    //4
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0,190);
    glVertex2f(150,190);
    glEnd();

}

void line2()
{
    //5
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(200,190);
    glVertex2f(300,190);
    glEnd();

}

void line3()
{
    //6
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(350,190);
    glVertex2f(500,190);
    glEnd();

}

void line4()
{ //7
    glLoadIdentity();
    //glLoadIdentity() function ensures that each time when we enter the projection mode, the matrix will be reset to identity matrix, so that the new viewing parameters are not combined with the previous one
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(550,190);
    glVertex2f(700,190);
    glEnd();

}

void zebra_crossing()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(200,95);
    glVertex2f(200,260);
    glVertex2f(250,260);
    glVertex2f(250,95);
    glEnd();

}


void zebra_crossing1()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(400,95);
    glVertex2f(400,260);
    glVertex2f(450,260);
    glVertex2f(450,95);
    glEnd();

}



void zebra_line1()
{
    //4
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(200,230);
    glVertex2f(250,230);
    glVertex2f(250,225);
    glVertex2f(200,225);
    glEnd();

}
void zebra_line2()
{
    //4
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(200,200);
    glVertex2f(250,200);
    glVertex2f(250,195);
    glVertex2f(200,195);
    glEnd();

}
void zebra_line3()
{
    //4
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(200,170);
    glVertex2f(250,170);
    glVertex2f(250,165);
    glVertex2f(200,165);
    glEnd();

}
void zebra_line4()
{
    //4
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(200,140);
    glVertex2f(250,140);
    glVertex2f(250,135);
    glVertex2f(200,135);
    glEnd();

}
void zebra_line5()
{
    //4
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(200,115);
    glVertex2f(250,115);
    glVertex2f(250,110);
    glVertex2f(200,110);
    glEnd();

}

void zebra_line6()
{
    //4
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(400,230);
    glVertex2f(450,230);
    glVertex2f(450,225);
    glVertex2f(400,225);
    glEnd();

}
void zebra_line7()
{
    //4
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(400,200);
    glVertex2f(450,200);
    glVertex2f(450,195);
    glVertex2f(400,195);
    glEnd();

}
void zebra_line8()
{
    //4
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(400,170);
    glVertex2f(450,170);
    glVertex2f(450,165);
    glVertex2f(400,165);
    glEnd();

}
void zebra_line9()
{
    //4
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(400,140);
    glVertex2f(450,140);
    glVertex2f(450,135);
    glVertex2f(400,135);
    glEnd();

}
void zebra_line10()
{
    //4
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(400,115);
    glVertex2f(450,115);
    glVertex2f(450,110);
    glVertex2f(400,110);
    glEnd();

}

void boy(float a, float b){

 glBegin(GL_POLYGON);//head
 glColor3f(1, 1, 1);


 glVertex2f(20 + a, 230 + b);//head 1st co-ordinate(-x+y)
 glVertex2f(20.3 + a, 231 + b);
 glVertex2f(20.7+ a, 232 + b);
 glVertex2f(21+ a, 233 + b);
 glVertex2f(21.3 + a, 234 + b);
 glVertex2f(21.7 + a, 235 + b);
 glVertex2f(22.3+ a, 236 + b);
 glVertex2f(22.7 + a, 236.5 + b);
 glVertex2f(23 + a, 237 + b);
 glVertex2f(23.5 + a, 237.3 + b);
 glVertex2f(24 + a, 237.7 + b);
 glVertex2f(24.5 + a, 238+ b);
 glVertex2f(25 + a, 238.3 + b);
 glVertex2f(26 + a, 238.7 + b);
 glVertex2f(27 + a, 239 + b);
 glVertex2f(28 + a, 239.3 + b);
 glVertex2f(29 + a, 239.7 + b);
 glVertex2f(30 + a, 240 + b);

 glVertex2f(31 + a, 239.7 + b);//head 2nd co-ordinate(+x+y)
 glVertex2f(32 + a, 239.5 + b);
 glVertex2f(33 + a, 239.3 + b);
 glVertex2f(33.5 + a, 239 + b);
 glVertex2f(34 + a, 238.7 + b);
 glVertex2f(34.5 + a, 238.3+ b);
 glVertex2f(34.7 + a, 238 + b);
 glVertex2f(34.9 + a, 237.7 + b);
 glVertex2f(35 + a, 237.5 + b);
 glVertex2f(35.2 + a, 237.4 + b);
 glVertex2f(35.3 + a, 237.3 + b);
 glVertex2f(35.5 + a, 237.1 + b);
 glVertex2f(35.7 + a, 237 + b);
 glVertex2f(35.9 + a, 236.9 + b);
 glVertex2f(36 + a, 236.7 + b);
 glVertex2f(36.3 + a, 236.3 + b);
 glVertex2f(36.7+ a, 236 + b);
 glVertex2f(37 + a, 235.7 + b);
 glVertex2f(37.3 + a, 235.3+ b);
 glVertex2f(37.7 + a, 235 + b);
 glVertex2f(38 + a, 234.5 + b);
 glVertex2f(38.3 + a, 234+ b);
 glVertex2f(38.7 + a, 233.5 + b);
 glVertex2f(39 + a, 233 + b);
 glVertex2f(39.3 + a, 232+ b);
 glVertex2f(39.7 + a, 231 + b);
 glVertex2f(40 + a, 230+ b);


 glVertex2f(39.7 + a, 229 + b);//head 3rd co-ordinate(+x-y)
 glVertex2f(39.3 + a, 228 + b);
 glVertex2f(39 + a, 227 + b);
 glVertex2f(38.7 + a, 226.5 + b);
 glVertex2f(38.3 + a, 226 + b);
 glVertex2f(38 + a, 225.5 + b);
 glVertex2f(37.7 + a, 225 + b);
 glVertex2f(37.3 + a, 224.5 + b);
 glVertex2f(37 + a, 224 + b);
 glVertex2f(36.7 + a, 223.7 + b);
 glVertex2f(36 + a, 223.3 + b);
 glVertex2f(35.7 + a, 223  + b);
 glVertex2f(35.3 + a, 222.7 + b);
 glVertex2f(35 + a, 222.3 + b);
 glVertex2f(34.5 + a, 222 + b);
 glVertex2f(34 + a, 221.7 + b);
 glVertex2f(33.5 + a, 221.3 + b);
 glVertex2f(33 + a, 221 + b);
 glVertex2f(32 + a, 220.7 + b);
 glVertex2f(31 + a, 220.3 + b);
 glVertex2f(30 + a, 220 + b);

 glVertex2f(29 + a, 220.3 + b);//head 4th co-ordinate(-x-y)
 glVertex2f(28 + a, 220.7 + b);
 glVertex2f(27.5 + a, 221 + b);
 glVertex2f(27 + a, 221.3 + b);
 glVertex2f(26.5 + a, 221.7 + b);
 glVertex2f(26 + a, 222 + b);
 glVertex2f(25.5 + a, 222.3 + b);
 glVertex2f(25 + a, 222.7 + b);
 glVertex2f(24.5 + a, 223 + b);
 glVertex2f(24 + a, 223.3 + b);
 glVertex2f(23.7 + a, 223.5 + b);
 glVertex2f(23.3 + a, 224 + b);
 glVertex2f(23 + a, 224.5 + b);
 glVertex2f(22.7 + a, 225 + b);
 glVertex2f(22.3 + a, 225.5 + b);
 glVertex2f(22 + a, 226 + b);
 glVertex2f(21.7 + a, 226.5 + b);
 glVertex2f(21.3 + a, 227 + b);
 glVertex2f(21 + a, 227.5 + b);
 glVertex2f(20.7 + a, 228 + b);
 glVertex2f(20.3 + a, 229 + b);
 glVertex2f(20 + a, 230 + b);
 glEnd();

 glBegin(GL_POLYGON);//left eye
 glColor3f(0, 0, 0);
 glVertex2f(25 + a, 228 + b);
 glVertex2f(23 + a, 230 + b);
 glVertex2f(25 + a, 232 + b);
 glVertex2f(27 + a, 230 + b);
 glEnd();

 glBegin(GL_POLYGON);//right eye
 glColor3f(0, 0, 0);
 glVertex2f(35 + a, 228 + b);
 glVertex2f(33 + a, 230 + b);
 glVertex2f(35 + a, 232 + b);
 glVertex2f(37 + a, 230 + b);
 glEnd();

 glBegin(GL_LINE_STRIP);//mouth
 glColor3f(0, 0, 0);
 glVertex2f(28 + a, 228 + b);
 glVertex2f(30 + a, 225 + b);
 glVertex2f(32 + a, 228 + b);
 glEnd();


 glBegin(GL_POLYGON);//body
 glColor3f(.73, .36, .36);
 glVertex2f(18 + a, 215 + b);
 glVertex2f(25 + a, 220 + b);
 glVertex2f(35 + a, 220 + b);
 glVertex2f(42 + a, 215 + b);
 glVertex2f(42 + a, 180 + b);
 glVertex2f(18 + a, 180 + b);
 glEnd();

 glBegin(GL_POLYGON);//left leg
 glColor3f(1, 1, 1);
 glVertex2f(20 + a, 180 + b);
 glVertex2f(25 + a, 180 + b);
 glVertex2f(25 + a, 160 + b);
 glVertex2f(20 + a, 160 + b);
 glEnd();

 glBegin(GL_POLYGON);//right leg
 glColor3f(1, 1, 1);
 glVertex2f(35 + a, 180 + b);
 glVertex2f(40 + a, 180 + b);
 glVertex2f(40 + a, 160 + b);
 glVertex2f(35 + a, 160 + b);
 glEnd();


 glBegin(GL_LINES);//left hand
 glColor3f(1, 1, 1);
 glVertex2f(18 + a, 210 + b);
 glVertex2f(12 + a, 205 + b);
 glVertex2f(12 + a, 205 + b);
 glVertex2f(12 + a, 195 + b);
 glEnd();

 glBegin(GL_LINES);//right hand
 glColor3f(1, 1, 1);
 glVertex2f(42 + a, 210 + b);
 glVertex2f(50 + a, 200 + b);
 glEnd();



}



void tree1(float x1, float y1)
{
    float x2 = x1+40,y2=y1, x3=x1+20,y3=y1+50;
    glColor3ub(11, 70, 11);
    glBegin(GL_TRIANGLES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2d(x1+10.5, y1);
        glVertex2d(x1, y1-40);
        glVertex2d(x2, y1-40);
        glVertex2d(x2-10.5, y1);

        glVertex2d(x1+10.5, y1-40);
        glVertex2d(x1, y1-80);
        glVertex2d(x2, y1-80);
        glVertex2d(x2-10.5, y1-40);
        glColor3ub(68, 43, 2);
        glVertex2d(x1+10.5, y1-80);
        glVertex2d(x1+10, y1-140);
        glVertex2d(x2-10, y1-140);
        glVertex2d(x2-10.5, y1-80);


    glEnd();


}

void car()
{

   //Bottom Part
   glLoadIdentity();
   counter=counter-0.05;
   glColor3f(r1,g1,b1);
   glTranslated(counter,80,0.0);
   //glTranslated can change path or shift car under green then on road
   if(counter<-1000.00)
   {

       c++;
       counter=700.0;
       if(c%2==0)
       {
           r1=1.0;
           g1=0.0;
           b1=0.0;

       }
       else if(c%3==0)
       {
           r1=0.0;
           g1=2.0+c;
           b1=1.0+c;
       }
       else if(c%5==0)
       {
           r1=1.0;
           g1=1.0;
           b1=0.0;
       }
       else
       {
           r1=0.0;
           g1=1.0;
           b1=0.0;
       }

   }
   glScaled(0.5,0.5,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(100,160);
   glVertex2f(450,160);
   glVertex2f(450,100);
   glEnd();

   //Top Part
   glBegin(GL_POLYGON);
   glVertex2f(150,160);
   glVertex2f(200,200);
   glVertex2f(400,200);
   glVertex2f(450,160);

   glEnd();


   window(200,270);
   window(280,330);
   window(340,390);
   wheel(200,100);
   wheel(380,100);


}

void truck()
{

   //Bottom Part

   glLoadIdentity();
   glColor3f(r2,g2,b2);
   cnt=cnt+0.04;
   if(cnt>1300.00)
   {
       cnt=-250.0;
       d++;
       if(d%2==0)
       {
           r2=r2+d;
           g2=0.0;
           b2=1.0;

       }
       else if(d%3==0)
       {
           r2=0.0;
           g2=3.0+d;
           b2=5.0+d;
       }
       else if(d%5==0)
       {
           r2=5.0;
           g2=0.0;
           b2=1.0;
       }
       else
       {
           r2=0.0;
           g2=1.0;
           b2=0.0;
       }

   }
   glTranslated(cnt,200,0.0);
   glScaled(0.4,0.4,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(100,160);
   glVertex2f(450,160);
   glVertex2f(450,100);
   glEnd();

   //Top Part
   glBegin(GL_POLYGON);
   glVertex2f(350,160);
   glVertex2f(350,200);
   glVertex2f(400,200);
   glVertex2f(450,160);

   glEnd();

   window(365,400);
   wheel(200,100);
   wheel(380,100);

}

void sq()
{
   glBegin(GL_POLYGON);
   glColor3f(0.9,0.2,0.1);
   glVertex2f(100,120);
   glVertex2f(100,170);
   glVertex2f(470,170);
   glVertex2f(470,120);
   glEnd();

}

void bus()
{

   glLoadIdentity();
   bc=bc+0.05;
   glColor3f(1.0,1.0,1.0);
   glTranslated(bc,180,0.0);
   if(bc>1300.00)
   {
       bc=-260.0;

   }
   glScaled(0.4,0.4,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(100,220);
   glVertex2f(470,220);
   glVertex2f(470,100);
   glEnd();

   buswindow(110,160);
   buswindow(170,220);
   buswindow(230,270);
   buswindow(280,330);
   buswindow(340,390);
   buswindow(400,450);
   wheel(200,100);
   wheel(380,100);

}

void display()
{

  glClear(GL_COLOR_BUFFER_BIT);
  //Push and pop matrix for separating circle object from Background

  road();
  zebra_crossing();
  zebra_crossing1();
  zebra_line1();
  zebra_line2();
  zebra_line3();
  zebra_line4();
  zebra_line5();
  zebra_line6();
  zebra_line7();
  zebra_line8();
  zebra_line9();
  zebra_line10();
  grass();
  grass2();
  line1();
  line2();
  line3();
  line4();
  car();
  truck();
  bus();
  sq();
  text();
  tc();
  light();
  light3();
  tree1(20,430);
  tree1(50,430);
  tree1(80,430);
  tree1(650,430);
  tree1(620,430);
  tree1(590,430);
  boy(200,-150);

  if(counter<-25)
  {
     light4();
  }
  if(bc>420 && cnt>420)
  {
      light2();
  }



  glutSwapBuffers();
  glFlush();


}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Animated Road Crossing Alert System");
    initOpenGl();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
