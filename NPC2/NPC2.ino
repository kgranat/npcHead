#include <TVout.h>
#include <fontALL.h>
#include "schematic.h"
#include "eye.h"
#include "TVOlogo.h"

TVout TV;

int zOff = 150;
int xOff = 0;
int yOff = 0;
int cSize = 50;
int view_plane = 64;
float angle = PI/60;

int motorPosition; 
int motorDirection;

const int stepPin = 3; 
const int dirPin = 4; 
//
//float cube3d[8][3] = {
//  {xOff - cSize,yOff + cSize,zOff - cSize},
//  {xOff + cSize,yOff + cSize,zOff - cSize},
//  {xOff - cSize,yOff - cSize,zOff - cSize},
//  {xOff + cSize,yOff - cSize,zOff - cSize},
//  {xOff - cSize,yOff + cSize,zOff + cSize},
//  {xOff + cSize,yOff + cSize,zOff + cSize},
//  {xOff - cSize,yOff - cSize,zOff + cSize},
//  {xOff + cSize,yOff - cSize,zOff + cSize}
//};
//unsigned char cube2d[8][2];
//

void setup() {
  TV.begin(NTSC,120,96);
  TV.select_font(font6x8);

  
  // Sets the two pins as Outputs for the stepper
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);


  middleEye();
  scanEyeLeft();
  scanEyeRight();
  scanEyeLeft();
  scanEyeRight();
  
  intro();
}

void loop() {


  TV.bitmap(0,0,schematic);
  TV.delay(10000);
  TV.clear_screen();

  


  


  
  randomSeed(analogRead(0));
  //generateCube();

}


//void generateCube(){
//  for(int i = 0; i < 5; i++)
//  {
//    int rsteps = random(10,60);
//    switch(random(6)) {
//      case 0:
//        for (int i = 0; i < rsteps; i++) {
//          zrotate(angle);
//          printcube();
//        }
//        break;
//      case 1:
//        for (int i = 0; i < rsteps; i++) {
//          zrotate(2*PI - angle);
//          printcube();
//        }
//        break;
//      case 2:
//        for (int i = 0; i < rsteps; i++) {
//          xrotate(angle);
//          printcube();
//        }
//        break;
//      case 3:
//        for (int i = 0; i < rsteps; i++) {
//          xrotate(2*PI - angle);
//          printcube();
//        }
//        break;
//      case 4:
//        for (int i = 0; i < rsteps; i++) {
//          yrotate(angle);
//          printcube();
//        }
//        break;
//      case 5:
//        for (int i = 0; i < rsteps; i++) {
//          yrotate(2*PI - angle);
//          printcube();
//        }
//        break;
//    }
//
//
//
//  }
//
//
//}


void middleEye()
{
  TV.bitmap(0,0,eye);
}
void scanEyeLeft()
{
 


dirRight();
    for (int i = 0; i > -40; i--)
  {
    TV.bitmap(i,0,eye);

    stepMove();
  }

dirLeft();
  for (int i = -40; i < 0; i++)
  {
    TV.bitmap(i,0,eye);

    stepMove();

    
  }


}

void scanEyeRight()
{
 
  //TV.bitmap(50,0,schematic, 0 , 100, 100);
dirLeft();
  for (int i = 0; i < 40; i++)
  {
    TV.bitmap(i,0,eye);
    stepMove();
    
  }

dirRight();
    for (int i = 40; i > 0; i--)
  {
    TV.bitmap(i,0,eye);
    stepMove();
  }



}

void dirLeft()
{
  digitalWrite(dirPin,HIGH); //Enables the motor to move in a particular direction
}

void dirRight()
{
   digitalWrite(dirPin,LOW); //Enables the motor to move in a particular direction
}

void stepMove()
{
      
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
}



void intro() {
unsigned char w,l,wb;
  int index;
  w = pgm_read_byte(TVOlogo);
  l = pgm_read_byte(TVOlogo+1);
  if (w&7)
    wb = w/8 + 1;
  else
    wb = w/8;
  index = wb*(l-1) + 2;
  for ( unsigned char i = 1; i < l; i++ ) {
    TV.bitmap((TV.hres() - w)/2,0,TVOlogo,index,w,i);
    index-= wb;
    TV.delay(50);
  }
  for (unsigned char i = 0; i < (TV.vres() - l)/2; i++) {
    TV.bitmap((TV.hres() - w)/2,i,TVOlogo);
    TV.delay(50);
  }
  TV.delay(3000);
  TV.clear_screen();
}

//void printcube() {
//  //calculate 2d points
//  for(byte i = 0; i < 8; i++) {
//    cube2d[i][0] = (unsigned char)((cube3d[i][0] * view_plane / cube3d[i][2]) + (TV.hres()/2));
//    cube2d[i][1] = (unsigned char)((cube3d[i][1] * view_plane / cube3d[i][2]) + (TV.vres()/2));
//  }
//  TV.delay_frame(1);
//  TV.clear_screen();
//  draw_cube();
//}

//void zrotate(float q) {
//  float tx,ty,temp;
//  for(byte i = 0; i < 8; i++) {
//    tx = cube3d[i][0] - xOff;
//    ty = cube3d[i][1] - yOff;
//    temp = tx * cos(q) - ty * sin(q);
//    ty = tx * sin(q) + ty * cos(q);
//    tx = temp;
//    cube3d[i][0] = tx + xOff;
//    cube3d[i][1] = ty + yOff;
//  }
//}
//
//void yrotate(float q) {
//  float tx,tz,temp;
//  for(byte i = 0; i < 8; i++) {
//    tx = cube3d[i][0] - xOff;
//    tz = cube3d[i][2] - zOff;
//    temp = tz * cos(q) - tx * sin(q);
//    tx = tz * sin(q) + tx * cos(q);
//    tz = temp;
//    cube3d[i][0] = tx + xOff;
//    cube3d[i][2] = tz + zOff;
//  }
//}
//
//void xrotate(float q) {
//  float ty,tz,temp;
//  for(byte i = 0; i < 8; i++) {
//    ty = cube3d[i][1] - yOff;
//    tz = cube3d[i][2] - zOff;
//    temp = ty * cos(q) - tz * sin(q);
//    tz = ty * sin(q) + tz * cos(q);
//    ty = temp;
//    cube3d[i][1] = ty + yOff;
//    cube3d[i][2] = tz + zOff;
//  }
//}

//void draw_cube() {
//  TV.draw_line(cube2d[0][0],cube2d[0][1],cube2d[1][0],cube2d[1][1],WHITE);
//  TV.draw_line(cube2d[0][0],cube2d[0][1],cube2d[2][0],cube2d[2][1],WHITE);
//  TV.draw_line(cube2d[0][0],cube2d[0][1],cube2d[4][0],cube2d[4][1],WHITE);
//  TV.draw_line(cube2d[1][0],cube2d[1][1],cube2d[5][0],cube2d[5][1],WHITE);
//  TV.draw_line(cube2d[1][0],cube2d[1][1],cube2d[3][0],cube2d[3][1],WHITE);
//  TV.draw_line(cube2d[2][0],cube2d[2][1],cube2d[6][0],cube2d[6][1],WHITE);
//  TV.draw_line(cube2d[2][0],cube2d[2][1],cube2d[3][0],cube2d[3][1],WHITE);
//  TV.draw_line(cube2d[4][0],cube2d[4][1],cube2d[6][0],cube2d[6][1],WHITE);
//  TV.draw_line(cube2d[4][0],cube2d[4][1],cube2d[5][0],cube2d[5][1],WHITE);
//  TV.draw_line(cube2d[7][0],cube2d[7][1],cube2d[6][0],cube2d[6][1],WHITE);
//  TV.draw_line(cube2d[7][0],cube2d[7][1],cube2d[3][0],cube2d[3][1],WHITE);
//  TV.draw_line(cube2d[7][0],cube2d[7][1],cube2d[5][0],cube2d[5][1],WHITE);
//}
