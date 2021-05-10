
// Motor A pin setup
int IN_1 = 27;
int IN_2 = 26;
int EN_A = 14;

// PWM setup
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 50;

void setup() {
 // Motor pins
pinMode(IN_1, OUTPUT);
pinMode(IN_2, OUTPUT);
pinMode(EN_A, OUTPUT);

 // PWM setup
ledcSetup(pwmChannel, freq, resolution);

// attach the channel to the GPIO to be controlled
ledcAttachPin(EN_A, pwmChannel);

Serial.begin(115200);
}

void loop() {
  // Move DC motor forward with increasing speed
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  while (dutyCycle <= 255){
    ledcWrite(pwmChannel, dutyCycle);   
    Serial.print("Forward with duty cycle: ");
    Serial.println(dutyCycle);
    dutyCycle = dutyCycle + 5;
    delay(500);
  }
  dutyCycle = 50;

}
