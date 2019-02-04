#include <Servo.h>
#include <SoftwareSerial.h>
#include <ShiftRegister74HC595.h>
#include <QList.h>

/*--------------------- Back IR -------------------------*/

unsigned int sensorValues[8]={0,0,0,0,0,0,0,0};
static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5,A6,A7};

float sum;
float w_sum;
float pos;

/*--------------------- Front IR ------------------------*/

unsigned int sensor2Values[8]={0,0,0,0,0,0,0,0};
static const uint8_t sensor2Pins[] = {38,36,34,32,30,28,26,24};

float sum2;
float w_sum2;
float pos2;

/*--------------------- line Follow variables ---------------*/

float Kp=30; //40
float Kd=20000;    //20000 for dahsed line follow
float Ki=0;
float PID;
float error=0;
float last_error=0;
float tot_error=0;

int ref_speed=160;
int D0_count=0;

/********************** ColorSensor ********************/

#define s0 43   
#define s1 44 
#define s2 46   
#define s3 45 
#define out 47
   
// values
int red = 0;  
int green = 0;  
int blue = 0;

int redSum = 0;  
int greenSum = 0;  
int blueSum = 0;


/********************** Bluetooth **********************/

#define Rx 11
#define Tx 10

SoftwareSerial BTserial(Rx, Tx); // RX, TX


/********************* SSD *************************/

ShiftRegister74HC595 sr (4, 23, 25, 27); 

int value,digit1,digit2,digit3,digit4; 
uint8_t  numberB[] = {B11000000, //0
                      B11111001, //1 
                      B10100100, //2
                      B10110000, //3 
                      B10011001, //4
                      B10010010, //5
                      B10000011, //6
                      B11111000, //7
                      B10000000, //8
                      B10011000, //9
                      B01000000, //0.
                      B01111001, //1. 
                      B00100100, //2.
                      B00110000, //3.
                      B00011001, //4.
                      B00010010, //5.
                      B00000011, //6.
                      B01111000, //7.
                      B00000000, //8.
                      B00011000 //9.
                     };
                     
/********************* Buzzer ***********************/

//const int buzzer = 22; //buzzer to arduino pin 9


/*--------------------- Motors -------------------------------*/

#define MOTLA 2
#define MOTLB 3
#define MOTLEN 4
#define MOTLPWM 5

#define MOTRA 6
#define MOTRB 7
#define MOTREN 8
#define MOTRPWM 9

/***********************LED*********************/

#define R 48
#define G 49
#define B 50

/*********************** Servos *********************/

Servo ServoR;
Servo ServoL;
Servo ServoRs;
Servo ServoLs;
Servo ServoTLid;
Servo ServoRtube;
Servo ServoGtube;
Servo ServoBtube;
Servo ServoTray;


/*************battery voltage reading *************/

#define VoltageBat A8

/************State Pin ***********************/
  
  int ROUND;
  #define State 51
  
 /********************** Robot State ****************/

 int RState=0;
 QList<int> path;
int dCount=0;
String shortPath;

/************************ Heading *********/
int init_State =0;



void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);
  pinMode(A7,INPUT);
  //Front IR
  pinMode(38,INPUT);
  pinMode(36,INPUT);
  pinMode(34,INPUT);
  pinMode(32,INPUT);
  pinMode(30,INPUT);
  pinMode(28,INPUT);
  pinMode(26,INPUT);
  pinMode(24,INPUT);
  //MOTORS
  pinMode(MOTLA,OUTPUT);
  pinMode(MOTLB,OUTPUT);
  pinMode(MOTLEN,OUTPUT);
  pinMode(MOTLPWM,OUTPUT);

  pinMode(MOTRA,OUTPUT);
  pinMode(MOTRB,OUTPUT);
  pinMode(MOTREN,OUTPUT);
  pinMode(MOTRPWM,OUTPUT);
  //LED
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  //Buzzer
  //pinMode(Sig,OUTPUT);
  
  ServoR.attach(31);
  ServoL.attach(29);
  ServoRs.attach(35);
  ServoLs.attach(33);
  ServoTLid.attach(37);
  ServoRtube.attach(39);
  ServoGtube.attach(40);
  ServoBtube.attach(41);
  ServoTray.attach(42);

  //bring arm to top at start

  ServoR.write(140);
  ServoL.write(33);
  ServoRtube.write(10);
  ServoGtube.write(10);
   ServoBtube.write(10);
  ServoTray.write(82);
  ServoTLid.write(30);
  ServoRs.write(90);
  ServoLs.write(90);
    pinMode(s0,OUTPUT);
    pinMode(s1,OUTPUT);
    pinMode(s2,OUTPUT);
    pinMode(s3,OUTPUT);  
    pinMode(out,INPUT);

    digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);
  
      pinMode(24,INPUT);
    

  /*******************************/

  /*    Fill code with initial Servo angles */

  /*******************************/
 
   pinMode(VoltageBat, INPUT);
   pinMode(State,INPUT);
   Serial.begin(9600);
   //BTserial.begin(9600);
   //BTserial.write("api dinanawa");
   //BTserial.print(12);

    delay(1000);
    ROUND=digitalRead(State);

    
}

void loop() {
  
 if(ROUND == LOW){

    R_1();
    
  }else{

    round2();

    }
    
    
  
}
    
