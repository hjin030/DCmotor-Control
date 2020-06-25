#include <AccelStepper.h>
#define MotorInterfaceType 4

char serialData;
int inByte = 0;
AccelStepper stepper = AccelStepper(MotorInterfaceType, 8, 9, 10, 11);
void setup() {

 
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  stepper.setMaxSpeed(1000);
  //establishContact();
}
void loop() {


    //when pressed somthing 
    if(Serial.available() > 0){
      //inByte = Serial.read();
      //read the value of serial.write from python as char instead of numbers due to b' ' it was hard to read it in arduino ide
      char serialData = Serial.read();
    
      //when pressed, motor runs clockwise 
      if(serialData == 'b'){
            stepper.setCurrentPosition(0);
               
            while (stepper.currentPosition() != -200)  {
                   
                    stepper.setSpeed(-200);
                    stepper.runSpeed();
        
             }
            delay(1000);      
                // Reset the position to 0:
            stepper.setCurrentPosition(0);
      }
      //when pressed motor runs anti-clockwise 
      if(serialData == 'a'){

             // Set the current position to 0:
            stepper.setCurrentPosition(0);
           
            while (stepper.currentPosition() != 200)  {
              stepper.setSpeed(200);
              stepper.runSpeed();
            }
            delay(1000);
            // Reset the position to 0:
            stepper.setCurrentPosition(0);
        
      }
    }
    delay(500);
  
}

//This function was just used for a test
void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}
