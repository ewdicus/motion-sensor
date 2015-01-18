#define FULL_LIGHT_DELAY 2000 // ms

const int pirPin = 0;
const int ledPin = 1;

int pwmValue = 0;
float pwmCounter = 0.0;

void setup(){
 Serial.begin(9600);
 pinMode(pirPin, INPUT);
 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW);
}


void loop(){

  // Have we seen motion?
  if(movementDetected()){
    // Increase PWM value until we're at 255
    while(pwmValue < 255){
        pwmValue += 1;
        analogWrite(ledPin, pwmValue);
        delay(1);
    }

    // Once we're at 255, stay on for the FULL_LIGHT_DELAY
    delay(FULL_LIGHT_DELAY);

  }else{
    // Decrease PWM value until we're at 0
    if(pwmValue > 0){
        pwmValue -= 1;
        analogWrite(ledPin, pwmValue);
        delay(1);
    }
  }

  // if(pirVal == LOW){ // Yes - Fade to high
  //   digitalWrite(ledPin, HIGH);
  //   // while(pwmValue < 255){

  //   //   pwmValue = sin(pwmCounter) * 255;
  //   //   pwmCounter += 0.01;

  //   //   analogWrite(ledPin, pwmValue);
  //   //   delay(1);
  //   // }

  //   // Stay on for a bit
  //   delay(2000);

  // }else{ // No
  //   digitalWrite(ledPin, LOW);
  //   // If we're on fade to low
  //   // if(pwmValue > 0){
  //   //   pwmValue = sin(pwmCounter) * 255;
  //   //   pwmCounter -= 0.01;
  //   //   analogWrite(ledPin, pwmValue);
  //   //   delay(1);
  //   // }
  // }
}

bool movementDetected(){
    if(digitalRead(pirPin) == LOW){
        return true;
    }
    return false;
}
