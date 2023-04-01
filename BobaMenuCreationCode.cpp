//  Created by Samson Batula on 2/23/23.

// Creator: Samson Batula
/******************************************
*
* Official Name:  Samsondeen Batula
*
* Call me: Samson
*
* E-mail:  sobatula@syr.edu
*
* Assignment:  Project 2
*
* Environment/Compiler:  Xcode 14.1
*
* Date submitted:  February 27, 2023
*
* References:  list any references you used or write NONE
 windows.cpp
 menus.cpp
 windowsWMouseClickOptions.cpp
 windowsWKeyboardOptions.cpp
 PixelsToWorldCoords.pptx
 MultipleWindows.pptx
 Menus.pptx
 
 
*
* Interactions:
 Left Click on each radio button and Square button to enable different options
 Right Click on second window screen to open menu for different Boba options
 Press 1-6 on the keyboard to switch between the Menu on Window 1.
 Press 1 to toggle Taro Milk Tea
 Press 2 to toggle PassionFruit Tea
 Press 3 to toggle HoneyDew Milk Tea
 Press 4 to toggle Mango Fruit Tea
 Press 5 to toggle Boba in drink
 Press 6 to toggle No Boba in drink
*
*******************************************/

#include <stdio.h>
#include <cmath>
#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265358979324

using namespace std;


// Globals.
static int id1, id2; // Window identifiers.
static float z1 = -1;
static float z2 = -1;
static int selection = 0;
static int bobaselection = 0;

// taro color default
static float drinkcolordefault[3] = {1.0, 1.0, 1.0};
static float bobadefault[3] = {0.0, 0.0, 0.0};




// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string)
{
   char *c;
   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}
  
// Routine to draw a stroke character string.
void writeStrokeString(void *font, char *string)
{
   char *c;
   for (c = string; *c != '\0'; c++) glutStrokeCharacter(font, *c);
}

void TitleText(void)
{
    // black color
    glColor3f(0.0, 0.0, 0.0);
    
    glRasterPos3f(30.0, 90.0, 0.0);
    writeBitmapString(GLUT_BITMAP_HELVETICA_18, "SAM'S BOBA PALACE");
    
    // black color
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(70.0,0.0,z1);
    glVertex3f(90.0,0.0,z1);
    glEnd();
    
    glFlush();
}

void TaroText(void)
{
    glColor3f(0.0, 0.0, 0.0);
    
    glRasterPos3f(20.0, 78.0, 0.0);
    writeBitmapString(GLUT_BITMAP_HELVETICA_18, "TARO MILK TEA");
    glFlush();
}

void PassionFruitText(void)
{
    glColor3f(0.0, 0.0, 0.0);
    
    glRasterPos3f(20.0, 66.0, 0.0);
    writeBitmapString(GLUT_BITMAP_HELVETICA_18, "PASSION FRUIT TEA");
    glFlush();
}

void HoneyDewText(void)
{
    glColor3f(0.0, 0.0, 0.0);
    
    glRasterPos3f(20.0, 54.0, 0.0);
    writeBitmapString(GLUT_BITMAP_HELVETICA_18, "HONEYDEW MILK TEA");
    glFlush();
}

void MangoText(void)
{
    glColor3f(0.0, 0.0, 0.0);
    
    glRasterPos3f(20.0, 42.0, 0.0);
    writeBitmapString(GLUT_BITMAP_HELVETICA_18, "MANGO FRUIT TEA");
    glFlush();
}

void BOBAText(void)
{
    glColor3f(0.0, 0.0, 0.0);
    
    glRasterPos3f(22.5, 25.0, 0.0);
    writeBitmapString(GLUT_BITMAP_HELVETICA_18, "BOBA");
    glFlush();
}

void NOBOBAText(void)
{
    glColor3f(0.0, 0.0, 0.0);
    
    glRasterPos3f(62.5, 25.0, 0.0);
    writeBitmapString(GLUT_BITMAP_HELVETICA_18, "NO BOBA");
    glFlush();
}

void taroCircle(void)
{
    //TARO black outline circle 1
    if(selection != 1){
        glColor3f(0.0, 0.0, 0.0);
        float angle;
        int i;
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 30; ++i)
        {
            angle = 2 * PI * i / 30;
            glVertex2f(10.0 + cos(angle) * 5.0, 80.0 + sin(angle) * 5.0);
        }
        glEnd();
    }
    else {
        glColor3f(0.0, 0.0, 0.0);
        float angle;
        int i;
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 30; ++i)
        {
            angle = 2 * PI * i / 30;
            glVertex2f(10.0 + cos(angle) * 5.0, 80.0 + sin(angle) * 5.0);
        }
        glEnd();
        
        glColor3f(0.0, 0.0, 0.0);
        float angle2;
        int j;
        glBegin(GL_TRIANGLE_FAN);
        for(j = 0; j < 30; ++j)
        {
            angle2 = 2 * PI * j / 30;
            glVertex2f(10.0 + cos(angle2) * 4.0, 80.0 + sin(angle2) * 4.0);
        }
        glEnd();
        
    }
    glFlush();
}

void passionfruitCircle (void)
{
    if(selection != 2){
        //PASSIONFRUIT black outline circle 2
        glColor3f(0.0, 0.0, 0.0);
        float angle;
        int i;
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 30; ++i)
        {
           angle = 2 * PI * i / 30;
           glVertex2f(10.0 + cos(angle) * 5.0, 68.0 + sin(angle) * 5.0);
        }
        glEnd();
    }
    else{
        glColor3f(0.0, 0.0, 0.0);
        float angle;
        int i;
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 30; ++i)
        {
           angle = 2 * PI * i / 30;
           glVertex2f(10.0 + cos(angle) * 5.0, 68.0 + sin(angle) * 5.0);
        }
        glEnd();
        
        glColor3f(0.0, 0.0, 0.0);
        float angle2;
        int j;
        glBegin(GL_TRIANGLE_FAN);
        for(j = 0; j < 30; ++j)
        {
           angle2 = 2 * PI * j / 30;
           glVertex2f(10.0 + cos(angle2) * 4.0, 68.0 + sin(angle2) * 4.0);
        }
        glEnd();
        
    }
    glFlush();
}

void honeydewCircle (void)
{
    
    if(selection != 3){
        //HONEYDEW black outline circle 3
        glColor3f(0.0, 0.0, 0.0);
        float angle;
        int i;
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 30; ++i)
        {
           angle = 2 * PI * i / 30;
           glVertex2f(10.0 + cos(angle) * 5.0, 56.0 + sin(angle) * 5.0);
        }
        glEnd();
    }
    else{
        //HONEYDEW black outline circle 3
        glColor3f(0.0, 0.0, 0.0);
        float angle;
        int i;
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 30; ++i)
        {
           angle = 2 * PI * i / 30;
           glVertex2f(10.0 + cos(angle) * 5.0, 56.0 + sin(angle) * 5.0);
        }
        glEnd();
        
        //HONEYDEW black outline circle 3
        glColor3f(0.0, 0.0, 0.0);
        float angle2;
        int k;
        glBegin(GL_TRIANGLE_FAN);
        for(k = 0; k < 30; ++k)
        {
           angle2 = 2 * PI * k / 30;
           glVertex2f(10.0 + cos(angle2) * 4.0, 56.0 + sin(angle2) * 4.0);
        }
        glEnd();
    }
    glFlush();
}

void mangoCircle(void)
{
    if(selection != 4){
        //MANGO black outline circle 4
        glColor3f(0.0, 0.0, 0.0);
        float angle;
        int i;
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 30; ++i)
        {
           angle = 2 * PI * i / 30;
           glVertex2f(10.0 + cos(angle) * 5.0, 44.0 + sin(angle) * 5.0);
        }
        glEnd();
    }
    else{
        //MANGO black outline circle 4
        glColor3f(0.0, 0.0, 0.0);
        float angle;
        int i;
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 30; ++i)
        {
           angle = 2 * PI * i / 30;
           glVertex2f(10.0 + cos(angle) * 5.0, 44.0 + sin(angle) * 5.0);
        }
        glEnd();
        
        //MANGO black outline circle 4
        glColor3f(0.0, 0.0, 0.0);
        float angle2;
        int k;
        glBegin(GL_TRIANGLE_FAN);
        for(k = 0; k < 30; ++k)
        {
           angle2 = 2 * PI * k / 30;
           glVertex2f(10.0 + cos(angle2) * 4.0, 44.0 + sin(angle2) * 4.0);
        }
        glEnd();
    }
    glFlush();
}
void checkbox(void)
{
    // black color
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    // bottom left (counterclockwise)
    glVertex3f(10.0, 20.0, z1);
    // bottom right
    glVertex3f(20.0, 20.0, z1);
    // top right
    glVertex3f(20.0, 30.0, z1);
    // top left
    glVertex3f(10.0, 30.0, z1);
    glEnd();
    
    // black color
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    // bottom left (counterclockwise)
    glVertex3f(50.0, 20.0, z1);
    // bottom right
    glVertex3f(60.0, 20.0, z1);
    // top right
    glVertex3f(60.0, 30.0, z1);
    // top left
    glVertex3f(50.0, 30.0, z1);
    glEnd();
    glFlush();
}

void bobaex(void)
{
    if(bobaselection == 1){
        // X illusion line for boba or no boba check
        //glLineWidth(5.0f);  // set line width to 5 pixels
        glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0); // set color to red
        glVertex2f(10.0f, 30.0f); // start point of line
        glVertex2f(20.0f, 20.0f); // end point of line
        glEnd();

        // X illusion line for boba or no boba check
       // glLineWidth(5.0f);  // set line width to 5 pixels
        glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0); // set color to red
        glVertex2f(10.0f, 20.0f); // start point of line
        glVertex2f(20.0f, 30.0f); // end point of line
        glEnd();
    }
    glFlush();

}
void nobobaex(void)
{
    if(bobaselection == 2){
        // X illusion line for boba or no boba check
        //glLineWidth(5.0f);  // set line width to 5 pixels
        glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0); // set color to red
        glVertex2f(50.0f, 30.0f); // start point of line
        glVertex2f(60.0f, 20.0f); // end point of line
        glEnd();

        // X illusion line for boba or no boba check
       // glLineWidth(5.0f);  // set line width to 5 pixels
        glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0); // set color to red
        glVertex2f(50.0f, 20.0f); // start point of line
        glVertex2f(60.0f, 30.0f); // end point of line
        glEnd();
    }
    glFlush();

}

// Drawing routine for first window.
void drawScene1(void)
{
   // Choose window.
   glutSetWindow(id1);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    taroCircle();
    passionfruitCircle();
    honeydewCircle();
    mangoCircle();
    checkbox();
    TaroText();
    PassionFruitText();
    HoneyDewText();
    MangoText();
    BOBAText();
    NOBOBAText();
    TitleText();
    bobaex();
    nobobaex();
    
   glFlush();
}

void emptycup(void){
    //black ellipse
    glColor3f(0.0, 0.0, 0.0);
    float angle;
    int i;
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
       angle = 2 * PI * i / 30;
       glVertex2f(40.0 + cos(angle) * 10.0, 65.5 + sin(angle) * 2.0);
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    float angle2;
    int j;
    glBegin(GL_LINE_LOOP);
    for(j = 0; j < 30; ++j)
    {
       angle2 = 2 * PI * j / 30;
       glVertex2f(40.0 + cos(angle2) * 3.0, 65.5 + sin(angle2) * 1.0);
    }
    glEnd();
    
    
    // black color
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    // bottom left (counterclockwise)
    glVertex3f(35.0, 40.0, z2);
    // bottom right
    glVertex3f(45.0, 40.0, z2);
    // top right
    glVertex3f(50.0, 65.0, z2);
    // top left
    glVertex3f(30.0, 65.0, z2);
    glEnd();
    
    // purple color
    // glColor3f(0.5, 0.5, 0.7);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLE_FAN);
    // bottom left (counterclockwise)
    glVertex3f(35.0, 40.2, z2);
    // bottom right
    glVertex3f(45.0, 40.2, z2);
    // top right
    glVertex3f(49.0, 60.0, z2);
    // top left
    glVertex3f(31.0, 60.0, z2);
    glEnd();
    
    // white line to create cup illusion
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0); // set color to red
    glVertex2f(30.0f, 65.0f); // start point of line
    glVertex2f(50.0f, 65.0f); // end point of line
    glEnd();
    
    glFlush();
    
}

void taro(void)
{
    if(selection == 1){
        //black ellipse
        glColor3f(0.0, 0.0, 0.0);
        float angle;
        int i;
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 30; ++i)
        {
           angle = 2 * PI * i / 30;
           glVertex2f(40.0 + cos(angle) * 10.0, 65.5 + sin(angle) * 2.0);
        }
        glEnd();
        
        glColor3f(0.0, 0.0, 0.0);
        float angle2;
        int j;
        glBegin(GL_LINE_LOOP);
        for(j = 0; j < 30; ++j)
        {
           angle2 = 2 * PI * j / 30;
           glVertex2f(40.0 + cos(angle2) * 3.0, 65.5 + sin(angle2) * 1.0);
        }
        glEnd();
        
        
        // black color
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
        // bottom left (counterclockwise)
        glVertex3f(35.0, 40.0, z2);
        // bottom right
        glVertex3f(45.0, 40.0, z2);
        // top right
        glVertex3f(50.0, 65.0, z2);
        // top left
        glVertex3f(30.0, 65.0, z2);
        glEnd();
        
        // purple color
        // glColor3f(0.5, 0.5, 0.7);
        glColor3fv(drinkcolordefault);
        glBegin(GL_TRIANGLE_FAN);
        // bottom left (counterclockwise)
        glVertex3f(35.0, 40.2, z2);
        // bottom right
        glVertex3f(45.0, 40.2, z2);
        // top right
        glVertex3f(49.0, 60.0, z2);
        // top left
        glVertex3f(31.0, 60.0, z2);
        glEnd();
        
        // white line to create cup illusion
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0); // set color to red
        glVertex2f(30.0f, 65.0f); // start point of line
        glVertex2f(50.0f, 65.0f); // end point of line
        glEnd();
    }
    glFlush();
}

void passionfruit(void)
{
    if(selection == 2){
        //black ellipse
        glColor3f(0.0, 0.0, 0.0);
        float angle;
        int i;
        glBegin(GL_LINE_LOOP);
        for(i = 0; i < 30; ++i)
        {
           angle = 2 * PI * i / 30;
           glVertex2f(40.0 + cos(angle) * 10.0, 65.5 + sin(angle) * 2.0);
        }
        glEnd();
        
        
        // black color
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
        // bottom left (counterclockwise)
        glVertex3f(35.0, 40.0, z2);
        // bottom right
        glVertex3f(45.0, 40.0, z2);
        // top right
        glVertex3f(50.0, 65.0, z2);
        // top left
        glVertex3f(30.0, 65.0, z2);
        glEnd();
        
        // passionfruit color
        //glColor3f(1.0, 0.4, 0.6);
        glColor3fv(drinkcolordefault);
        glBegin(GL_TRIANGLE_FAN);
        // bottom left (counterclockwise)
        glVertex3f(35.0, 40.2, z2);
        // bottom right
        glVertex3f(45.0, 40.2, z2);
        // top right
        glVertex3f(49.0, 60.0, z2);
        // top left
        glVertex3f(31.0, 60.0, z2);
        glEnd();
        
        // white line to create cup illusion
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0); // set color to red
        glVertex2f(30.0f, 65.0f); // start point of line
        glVertex2f(50.0f, 65.0f); // end point of line
        glEnd();
    }
    glFlush();
}

void honeydew(void)
{
    //black ellipse
    glColor3f(0.0, 0.0, 0.0);
    float angle;
    int i;
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
       angle = 2 * PI * i / 30;
       glVertex2f(40.0 + cos(angle) * 10.0, 65.5 + sin(angle) * 2.0);
    }
    glEnd();
    
    
    // black color
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    // bottom left (counterclockwise)
    glVertex3f(35.0, 40.0, z2);
    // bottom right
    glVertex3f(45.0, 40.0, z2);
    // top right
    glVertex3f(50.0, 65.0, z2);
    // top left
    glVertex3f(30.0, 65.0, z2);
    glEnd();
    
    // honeydew color
    //glColor3f(0.94, 1.0, 0.94);
    glColor3fv(drinkcolordefault);
    glBegin(GL_TRIANGLE_FAN);
    // bottom left (counterclockwise)
    glVertex3f(35.0, 40.2, z2);
    // bottom right
    glVertex3f(45.0, 40.2, z2);
    // top right
    glVertex3f(49.0, 60.0, z2);
    // top left
    glVertex3f(31.0, 60.0, z2);
    glEnd();
    
    // white line to create cup illusion
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0); // set color to red
    glVertex2f(30.0f, 65.0f); // start point of line
    glVertex2f(50.0f, 65.0f); // end point of line
    glEnd();
    
    glFlush();
}

void mango(void)
{
    //black ellipse
    glColor3f(0.0, 0.0, 0.0);
    float angle;
    int i;
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 30; ++i)
    {
       angle = 2 * PI * i / 30;
       glVertex2f(40.0 + cos(angle) * 10.0, 65.5 + sin(angle) * 2.0);
    }
    glEnd();
    
    
    // black color
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    // bottom left (counterclockwise)
    glVertex3f(35.0, 40.0, z2);
    // bottom right
    glVertex3f(45.0, 40.0, z2);
    // top right
    glVertex3f(50.0, 65.0, z2);
    // top left
    glVertex3f(30.0, 65.0, z2);
    glEnd();
    
    // mango color
    //glColor3f(1.0, 0.65, 0.0);
    glColor3fv(drinkcolordefault);
    glBegin(GL_TRIANGLE_FAN);
    // bottom left (counterclockwise)
    glVertex3f(35.0, 40.2, z2);
    // bottom right
    glVertex3f(45.0, 40.2, z2);
    // top right
    glVertex3f(49.0, 60.0, z2);
    // top left
    glVertex3f(31.0, 60.0, z2);
    glEnd();
    
    // white line to create cup illusion
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0); // set color to red
    glVertex2f(30.0f, 65.0f); // start point of line
    glVertex2f(50.0f, 65.0f); // end point of line
    glEnd();
    
    glFlush();
}

void bubbles (void)
{
    if(bobaselection != 1){
        
    }
    else{
        glColor3fv(bobadefault);
        float angle1;
        int j;
        glBegin(GL_TRIANGLE_FAN);
        for(j = 0; j < 30; ++j)
        {
            angle1 = 2 * PI * j / 30;
            glVertex2f(36.0 + cos(angle1) * 1.0, 41 + sin(angle1) * 1.0);
        }
        glEnd();
        
        glColor3fv(bobadefault);
        float angle2;
        int i;
        glBegin(GL_TRIANGLE_FAN);
        for(i = 0; i < 30; ++i)
        {
            angle2 = 2 * PI * i / 30;
            glVertex2f(38.0 + cos(angle2) * 1.0, 41 + sin(angle2) * 1.0);
        }
        glEnd();
        
        glColor3fv(bobadefault);
        float angle3;
        int k;
        glBegin(GL_TRIANGLE_FAN);
        for(k = 0; k < 30; ++k)
        {
            angle3 = 2 * PI * k / 30;
            glVertex2f(40.0 + cos(angle3) * 1.0, 41 + sin(angle3) * 1.0);
        }
        glEnd();
        
        glColor3fv(bobadefault);
        float angle4;
        int l;
        glBegin(GL_TRIANGLE_FAN);
        for(l = 0; l < 30; ++l)
        {
            angle4 = 2 * PI * l / 30;
            glVertex2f(42.0 + cos(angle4) * 1.0, 41 + sin(angle4) * 1.0);
        }
        glEnd();
        
        glColor3fv(bobadefault);
        float angle5;
        int o;
        glBegin(GL_TRIANGLE_FAN);
        for(o = 0; o < 30; ++o)
        {
            angle5 = 2 * PI * o / 30;
            glVertex2f(44.0 + cos(angle5) * 1.0, 41 + sin(angle5) * 1.0);
        }
        glEnd();
        
        glColor3fv(bobadefault);
        float angle6;
        int p;
        glBegin(GL_TRIANGLE_FAN);
        for(p = 0; p < 30; ++p)
        {
            angle6 = 2 * PI * p / 30;
            glVertex2f(35.6 + cos(angle6) * 1.0, 43 + sin(angle6) * 1.0);
        }
        glEnd();
        
        glColor3fv(bobadefault);
        float angle7;
        int m;
        glBegin(GL_TRIANGLE_FAN);
        for(m = 0; m < 30; ++m)
        {
            angle7 = 2 * PI * m / 30;
            glVertex2f(37.5 + cos(angle7) * 1.0, 43 + sin(angle7) * 1.0);
        }
        glEnd();
        
        glColor3fv(bobadefault);
        float angle8;
        int n;
        glBegin(GL_TRIANGLE_FAN);
        for(n = 0; n < 30; ++n)
        {
            angle8 = 2 * PI * n / 30;
            glVertex2f(39.4 + cos(angle8) * 1.0, 43 + sin(angle8) * 1.0);
        }
        glEnd();
        
        glColor3fv(bobadefault);
        float angle9;
        int b;
        glBegin(GL_TRIANGLE_FAN);
        for(b = 0; b < 30; ++b)
        {
            angle9 = 2 * PI * b / 30;
            glVertex2f(41.3 + cos(angle9) * 1.0, 43 + sin(angle9) * 1.0);
        }
        glEnd();
        
        glColor3fv(bobadefault);
        float angle;
        int h;
        glBegin(GL_TRIANGLE_FAN);
        for(h = 0; h < 30; ++h)
        {
            angle = 2 * PI * h / 30;
            glVertex2f(43.2 + cos(angle) * 1.0, 43 + sin(angle) * 1.0);
        }
        glEnd();
        
        glColor3fv(bobadefault);
        float anglex;
        int y;
        glBegin(GL_TRIANGLE_FAN);
        for(y = 0; y < 30; ++y)
        {
            anglex = 2 * PI * y / 30;
            glVertex2f(44.8 + cos(anglex) * 1.0, 43 + sin(anglex) * 1.0);
        }
        glEnd();
    }
    glFlush();
}


// Drawing routine for second window.
void drawScene2(void)
{
    // Choose window.
    glutSetWindow(id2);
    
    glClear(GL_COLOR_BUFFER_BIT);
    // cup is empty to begin with
    emptycup();
    
    if(selection == 1){
        taro();
    }
    
    if(selection == 2){
        passionfruit();
    }

    if(selection == 3){
        honeydew();
    }

    if(selection == 4){
        mango();
    }
    
    if(bobaselection == 1){
        bubbles();
    }
    
    glFlush();
    }


// Initialization routine for first window.
void setup1(void)
{
   // Black background.
   glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Initialization routine for second window.
void setup2(void)
{
   // white background
   glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Reshape routine for first window.
void resize1(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // Non-square aspect ratio squashes the square.
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Reshape routine for second window.
void resize2(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Keyboard input processing routine shared by both windows.
void keyInput(unsigned char key, int x, int y)
{
   switch(key)
   {
      case 27:
         exit(0);
         break;
       case '1':
               selection = 1
               taro();
               drinkcolordefault[0] = 0.5; drinkcolordefault[1] = 0.5; drinkcolordefault[2] = 0.7;

               cout << "1 was pressed on the keyboard" << endl;
               glutSetWindow(id1);
               glutPostRedisplay();
               glutSetWindow(id2);
               glutPostRedisplay();
           break;
       case '2':
               selection = 2;
               passionfruit();
               drinkcolordefault[0] = 1.0; drinkcolordefault[1] = 0.4; drinkcolordefault[2] = 0.6;

               cout << "2 was pressed on the keyboard" << endl;
               glutSetWindow(id1);
               glutPostRedisplay();
               glutSetWindow(id2);
               glutPostRedisplay();

           break;
       case '3':
               selection = 3;
               honeydew();
               drinkcolordefault[0] = 0.94; drinkcolordefault[1] = 1.0; drinkcolordefault[2] = 0.94;

               cout << "3 was pressed on the keyboard" << endl;
               glutSetWindow(id1);
               glutPostRedisplay();
               glutSetWindow(id2);
               glutPostRedisplay();
           break;
       case '4':
               selection = 4;
               mango();
               drinkcolordefault[0] = 1.0; drinkcolordefault[1] = 0.65; drinkcolordefault[2] = 0;

               cout << "4 was pressed on the keyboard" << endl;
               glutSetWindow(id1);
               glutPostRedisplay();
               glutSetWindow(id2);
               glutPostRedisplay();
           break;
       case '5':
        
               bobaselection = 1;
               cout << "(BOBA) 5 was pressed on the keyboard" << endl;
               bubbles();
               bobaex();
               glutSetWindow(id1);
               glutPostRedisplay();
               glutSetWindow(id2);
               glutPostRedisplay();
        
           break;
       case '6':
        
               bobaselection = 2;
               cout << "(NOBOBA) 6 was pressed on the keyboard" << endl;
               bubbles();
               nobobaex();
               glutSetWindow(id1);
               glutPostRedisplay();
               glutSetWindow(id2);
               glutPostRedisplay();
        
           break;
      
      default:
         break;
   }
}

// Mouse callback routine.
void radioMouseControl(int button, int state, int x, int y)
{
    int xWorld, yWorld;
    xWorld = x * 1.0/5;
    yWorld = (500-y) * 1.0/5;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
       
        if (yWorld>=75 && yWorld<=85 && xWorld>=5 && xWorld<=15)
        {
            drinkcolordefault[0] = 0.5; drinkcolordefault[1] = 0.5; drinkcolordefault[2] = 0.7;
            cout<< "in taro box" << endl;
            selection = 1;
            
        }
        else if(yWorld>=60 && yWorld<=70 && xWorld>=5 && xWorld<=15)
        {
            drinkcolordefault[0] = 1.0; drinkcolordefault[1] = 0.4; drinkcolordefault[2] = 0.6;
            cout<< "in passionfruit box" << endl;
            selection = 2;
        }
        else if(yWorld>=50 && yWorld<=59 && xWorld>=5 && xWorld<=15)
        {
            drinkcolordefault[0] = 0.94; drinkcolordefault[1] = 1.0; drinkcolordefault[2] = 0.94;
            cout<< "in honeydew box" << endl;
            selection = 3;
        }
        else if(yWorld>=39 && yWorld<=49 && xWorld>=5 && xWorld<=15)
        {
            drinkcolordefault[0] = 1.0; drinkcolordefault[1] = 0.65; drinkcolordefault[2] = 0;
            cout<< "in mango box" << endl;
            selection = 4;
        }
        
        // checked boxes
        if(yWorld>=20 && yWorld<=30 && xWorld>=10 && xWorld<=20){
            cout<< "in boba selection box" << endl;
            bobaselection = 1;
        }
        else if(yWorld>=20 && yWorld<=30 && xWorld>=50 && xWorld<=60)
        {
            cout<< "in No boba selection box" << endl;
            bobaselection = 2;
        }
        
        glutSetWindow(id1);
        glutPostRedisplay();
        glutSetWindow(id2);
        glutPostRedisplay();
    }
}

// The top menu callback function.
void top_menu(int id)
{
   if (id==1) exit(0);
}

// The sub-menu callback function.
void drinktype_menu(int id)
{
   if (id==2)
   {
       drinkcolordefault[0] = 0.5; drinkcolordefault[1] = 0.5; drinkcolordefault[2] = 0.7;
   }
   if (id==3)
   {
       drinkcolordefault[0] = 1.0; drinkcolordefault[1] = 0.4; drinkcolordefault[2] = 0.6;
   }
   if (id==4)
   {
       drinkcolordefault[0] = 0.94; drinkcolordefault[1] = 1.0; drinkcolordefault[2] = 0.94;
   }
   if (id==5)
   {
       drinkcolordefault[0] = 1.0; drinkcolordefault[1] = 0.65; drinkcolordefault[2] = 0;
   }
    
   glutPostRedisplay();
}
// SUB-SUB MENU
void boba_menu(int id)
{
   if (id==6)
   {
       bobaselection = 1;
   }
    
   if (id==7)
   {
       bobaselection = 2;
   }
    
   glutPostRedisplay();
}

// Routine to make the menu.
void makeMenu(void)
{
   // The sub-menu is created first (because it should be visible when the top
   // menu is created): its callback function is registered and menu entries added.
    int sub_menu;
    int subsub_menu;
    
    // create subsub menu
    subsub_menu = glutCreateMenu(boba_menu);
    glutAddMenuEntry("Boba", 6);
    glutAddMenuEntry("No Boba", 7);
   
   sub_menu = glutCreateMenu(drinktype_menu);
   glutAddSubMenu("Boba Options", subsub_menu);
   glutAddMenuEntry("Taro Milk Tea", 2);
   glutAddMenuEntry("Passion Fruit Tea",3);
   glutAddMenuEntry("HoneyDew Milk Tea",4);
   glutAddMenuEntry("Mango Fruit Tea",5);

   // The top menu is created: its callback function is registered and menu entries,
   // including a submenu, added.
   glutCreateMenu(top_menu);
   glutAddSubMenu("Drinks", sub_menu);
   glutAddMenuEntry("Quit",1);
    
   // The menu is attached to a mouse button.
   glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
   cout << "Interaction:" << endl;
   cout << "Left Click on each radio button and Square button to enable different options" << endl
        << "Right Click on second window screen to open menu for different Boba options" << endl
        << "Press 1-6 on the keyboard to switch between the Menu on Window 1." << endl
        << "Press 1 to toggle Taro Milk Tea" << endl
        << "Press 2 to toggle PassionFruit Tea" << endl
        << "Press 3 to toggle HoneyDew Milk Tea" << endl
        << "Press 4 to toggle Mango Fruit Tea" << endl
        << "Press 5 to toggle Boba in drink" << endl
        << "Press 6 to toggle No Boba in drink" << endl;
    
}

// Main routine.
int main(int argc, char **argv)
{
    printInteraction();
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   
   // First top-level window definition.
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);

   // Create the first window and return id.
   id1 = glutCreateWindow("windows.cpp - window 1");

   // Initialization, display, and other routines of the first window.
   setup1();
   glutDisplayFunc(drawScene1);
   glutReshapeFunc(resize1);
   glutKeyboardFunc(keyInput); // Routine is shared by both windows.
   glutMouseFunc(radioMouseControl);
   makeMenu();

   
   // Second top-level window definition.
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(900, 100);
   
   // Create the second window and return id.
   id2 = glutCreateWindow("windows.cpp - window 2");

   // Initialization, display, and other routines of the second window.
   setup2();
   glutDisplayFunc(drawScene2);
   glutReshapeFunc(resize2);
   glutKeyboardFunc(keyInput); // Routine is shared by both windows.
   makeMenu();

   glutMainLoop();

   return 0;
}
