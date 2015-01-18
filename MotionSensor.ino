#define FULL_LIGHT_DELAY 2000 // ms

const int pirPin = 0;
const int builtInLed = 1;
const int ledPin = 4;

int pwmValue = 0;
float pwmCounter = 0.0;

void setup(){
 pinMode(pirPin, INPUT);
 pinMode(ledPin, OUTPUT);
 pinMode(builtInLed, OUTPUT);
 digitalWrite(ledPin, LOW);

 digitalWrite(builtInLed, HIGH);
 delay(100);
 digitalWrite(builtInLed, LOW);
 delay(100);
 digitalWrite(builtInLed, HIGH);
 delay(100);
 digitalWrite(builtInLed, LOW);
}


void loop(){

  // Have we seen motion?
  if(movementDetected()){
    digitalWrite(builtInLed, HIGH);

    // Increase PWM value until we're at 255 - Also check
    while(pwmCounter < 1.57){

      // pwmValue += 1;
      pwmValue = sin(pwmCounter) * 255.0;
      pwmCounter += 0.01;

      analogWrite(ledPin, pwmValue);
      delay(10);
    }

    // Once we're at 255, stay on for the FULL_LIGHT_DELAY
    delay(FULL_LIGHT_DELAY);

  }else{
    digitalWrite(builtInLed, LOW);

    // Decrease PWM value until we're at 0
    if(pwmCounter > 0){

      if(pwmCounter < 0) pwmCounter = 0;

      // pwmValue -= 1;
      pwmValue = sin(pwmCounter) * 255.0;
      pwmCounter -= 0.01;

      analogWrite(ledPin, pwmValue);
      delay(10);
    }
  }
}

bool movementDetected(){
    if(digitalRead(pirPin) == LOW){
        return true;
    }
    return false;
}
