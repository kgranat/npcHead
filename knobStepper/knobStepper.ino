/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
// Defines pins numbers
const int stepPin = 3;
const int dirPin = 4; 

int customDelay,customDelayMapped; // Defines variables
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
 
  digitalWrite(dirPin,HIGH); //Enables the motor to move in a particular direction
}
int speedRead;
void loop() 
{
  speedRead = analogRead(A0);

  if(speedRead > 524)
  {
    speedRead =   speedRead - (2 * (speedRead - 512));   
  }




  
  customDelayMapped = speedUp(speedRead); // Gets custom delay values from the custom speedUp function
  
  // Makes pules with custom delay, depending on the Potentiometer, from which the speed of the motor depends
  if(analogRead(A0) < 500)
  {
    speedRead = analogRead(A0);
    digitalWrite(dirPin,LOW); //Enables the motor to move in a particular direction
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(customDelayMapped);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(customDelayMapped);
    
    
  }
  else if(analogRead(A0) > 524)
  {
    
    speedRead = analogRead(A0);
    digitalWrite(dirPin,HIGH); //Enables the motor to move in a particular direction
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(customDelayMapped);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(customDelayMapped);
      
  }
  else
  {
    
  }
}
// Function for reading the Potentiometer
int speedUp(int speedRead) {
  //int customDelay = analogRead(A0); // Reads the potentiometer
  int newCustom = map(speedRead, 0, 500, 300,4000); // Convrests the read values of the potentiometer from 0 to 1023 into desireded delay values (300 to 4000)
  return newCustom;  
}
