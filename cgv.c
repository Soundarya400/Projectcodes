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