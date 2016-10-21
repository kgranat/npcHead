/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
// Defines pins numbers
const int stepPin = 3;
const int dirPin = 4; 

int customDelay,customDelayMapped; // Defines variables

 int microStepMod = 16;
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(dirPin,HIGH); //Enables the motor to move in a particular direction
}
int speedRead;
void loop() 
{


    digitalWrite(dirPin,HIGH); //Enables the motor to move in a particular direction
    for (int i = 0; i < microStepMod * 40; i++)
    {
    digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
    }
    digitalWrite(13, LOW);

    delay(1000);

    digitalWrite(dirPin,LOW); //Enables the motor to move in a particular direction

    for (int i = 0; i < microStepMod * 40; i++)
    {
    digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
    }
    digitalWrite(13, HIGH);
    
    delay(1000);

}


