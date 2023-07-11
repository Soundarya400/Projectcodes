#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<stdarg.h>
static double x[10] = { 0 }, x2 = 0.0, r1 = 0.0;
static double yaxis[10] = { -15,-15,-15,-15,-15,-15,-15,-15,-15,-15 };
static double max = 0;
static boolean takeOff = FALSE;
void stroke_output(GLfloat x, GLfloat y, char* format, ...)
{
va_list args;
char buffer[200],*p;
va_start(args, format);
printf(buffer, format, args);
va_end(args);
glPushMatrix();
glTranslatef(-2.5, y, 0);
glScaled(0.003, 0.005,0.005);
for (p = buffer; *p; p++)
glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
glPopMatrix();
} //runway strip void strip(float x1)
{
glPushMatrix();
glRotatef(-65, 0, 1, 0);
glColor3f(1, 1, 1);
glTranslatef(x1, -3.5, 7.8);
glScaled(1, 0.15, 0.1);
AIR TRAFFIC CONTROL 1BI21CS400
Department of CS&E, BIT 2022-23 15
glutSolidCube(1);
glPopMatrix();
}
void drawPlane(float y1)
{
/*********** PLANE CONSTRUCTION *******************/
glPushMatrix();
// Main Body
glPushMatrix();
glScalef(.3, 0.3, 1.5);
if (y1 <= 15)
glColor3f(1, 1.0, 0.5);
if (y1 >= 15)
glColor3f(1, 0.3, 0.5);
glutSolidSphere(2.0, 50, 50);
glPopMatrix();
glPushMatrix();
glTranslatef(0.0, 0.1, -1.8);
glScalef(1.0, 1, 1.5);
glColor3f(0, 0, 1);
glutSolidSphere(0.5, 25, 25);
glPopMatrix();
//Left Fin
glPushMatrix();
glTranslatef(-1.0, 0, 0);
glScalef(1.5, 0.1, 0.5);
glColor3f(0, 0, 0);
glutSolidSphere(1.0, 50, 50);
glPopMatrix();
// Right Fin
glPushMatrix();
AIR TRAFFIC CONTROL 1BI21CS400
Department of CS&E, BIT 2022-23 16
glTranslatef(1.0, 0, 0);
glScalef(1.5, 0.1, 0.5);
glColor3f(0, 0, 0);
glutSolidSphere(1.0, 50, 50);
glPopMatrix(); //right Tail
fin glPushMatrix();
glTranslatef(0.8, 0, 2.4);
glScalef(1.2, 0.1, 0.5);
glColor3f(0.0, 0, 0);
glutSolidSphere(0.4, 50, 50);
glPopMatrix();
//left Tail fin glPushMatrix();
glTranslatef(-0.8, 0, 2.4);
glScalef(1.2, 0.1, 0.5);
glColor3f(0.0, 0, 0);
glutSolidSphere(0.4, 50, 50);
glPopMatrix(); //Top tail fin
glPushMatrix();
glTranslatef(0, 0.5, 2.4);
glScalef(0.1, 1.1, 0.5);
glColor3f(0.0, 0, 0);
glutSolidSphere(0.4, 50, 50);
glPopMatrix(); // Blades
glPushMatrix();
glRotatef(x2, 0.0, 0.0, 1.0);
glPushMatrix();
glTranslatef(0, 0.0, -3.0);
glScalef(1.5, 0.2, 0.1);
glColor3f(0.0, 0, 0);
glutSolidSphere(0.3, 50, 50);
glPopMatrix();
AIR TRAFFIC CONTROL 1BI21CS400
Department of CS&E, BIT 2022-23 17
//blades glPushMatrix();
glRotatef(90, 0.0, 0.0, 1.0);
glTranslatef(0, 0.0, -3.0);
glScalef(1.5, 0.2, 0.1);
glColor3f(0.0, 0, 0);
glutSolidSphere(0.3, 50, 50);
glPopMatrix();
glPopMatrix();
/* Blased End */
/* Wheels */ //Front
glPushMatrix();
glTranslatef(0.0, -0.8, -1.5);
glRotatef(90, 0.0, 1, 0);
glScaled(0.3, 0.3, 0.3);
glutSolidTorus(0.18, 0.5, 25, 25);
glColor3f(1, 1, 1);
glutSolidTorus(0.2, 0.1, 25, 25);
glPopMatrix();
glPushMatrix();
}
void animate(float y1, float x1) {
// Plane Transition
glPushMatrix();
//Move the Plane towards rotating zone
if (y1 <= -2)
{
glTranslatef(5.5 + y1, 3, 0);
glRotatef(-90, 0, 1, 0);
}
// Move the Plane towards 2nd runwat
if (takeOff) if (y1 >= 15) {
glRotatef(140, 0, 1, 0); 