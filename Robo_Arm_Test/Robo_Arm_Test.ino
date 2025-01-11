#include <Servo.h>

int Robo;

#define DATA_PIN 4

// Define the servo objects
Servo microServo1;
Servo microServo2;
Servo microServo3;
Servo mgServo1;
Servo mgServo2;
Servo mgServo3;

// Pin numbers for the servos
int microServoPin1 = 3;
int microServoPin2 = 5;
int microServoPin3 = 6;
int mgServoPin1 = 9;
int mgServoPin2 = 10;
// int mgServoPin3 = 11;

void setup() {
  // Attach the servos to their respective pins
  microServo1.attach(microServoPin1);
  microServo2.attach(microServoPin2);
  microServo3.attach(microServoPin3);
  mgServo1.attach(mgServoPin1);
  mgServo2.attach(mgServoPin2);
  // mgServo2.attach(mgServoPin3);

  mgServo1.write(180);
    mgServo2.write(90);
    // mgServo3.write(180);
  microServo1.write(180);
  microServo2.write(0);
  microServo3.write(0);
  delay(5000);
    
  //   // delay(5000);

  // mgServo1.write(180);
  //   mgServo2.write(90);
  //   mgServo3.write(180);
  //   microServo1.write(90);
  // microServo2.write(0);
  // microServo3.write(90);
  // delay(10000);

  // mgServo1.write(180);
  //   mgServo2.write(90);
  //   mgServo3.write(180);
  //   microServo1.write(90);
  // microServo2.write(0);
  // microServo3.write(180);
  // delay(1000);

  // mgServo1.write(180);
  //   mgServo2.write(90);
  //   mgServo3.write(180);
  //   microServo1.write(180);
  // microServo2.write(0);
  // microServo3.write(180);
  // delay(1000);

  // Serial.readBytes((char*)&Robo, sizeof(int));
  // delay(3000);
  // if(Robo == 107)
  // {

  //   microServo1.write(170);
  //   microServo2.write(90);
  //   microServ
  //   321o3.write(0);
  //   // mgServo1.write(0);
  //   mgServo2.write(10);
  //   mgServo3.write(20);
  //   delay(5000);

        mgServo1.write(180);
      mgServo2.write(180);
    // mgServo3.write(180);
    microServo1.write(180);
    microServo2.write(0);
    microServo3.write(0);
    delay(5000);

      mgServo1.write(180);
    mgServo2.write(120);
    // mgServo3.write(180);
    microServo1.write(180);
    microServo2.write(0);
    microServo3.write(90);
    delay(5000);

      mgServo1.write(180);
    mgServo2.write(120);
    // mgServo3.write(180);
    microServo1.write(180);
    microServo2.write(0);
    microServo3.write(90);
    delay(5000);

      mgServo1.write(180);
    mgServo2.write(120);
    // mgServo3.write(180);
    microServo1.write(90);
    microServo2.write(0);
    microServo3.write(90);
    delay(5000);

      mgServo1.write(120);
    mgServo2.write(120);
    // mgServo3.write(180);
    microServo1.write(90);
    microServo2.write(0);
    microServo3.write(90);
    delay(5000);

      mgServo1.write(120);
    mgServo2.write(120);
    // mgServo3.write(180);
    microServo1.write(180);
    microServo2.write(0);
    microServo3.write(90);
    delay(5000);

      mgServo1.write(120);
    mgServo2.write(120);
    // mgServo3.write(180);
    microServo1.write(180);
    microServo2.write(0);
    microServo3.write(180);
    delay(5000);

      mgServo1.write(180);
    mgServo2.write(120);
    // mgServo3.write(180);33
    
    microServo1.write(180);
    microServo2.write(0);
    microServo3.write(180);
    delay(5000);

      mgServo1.write(180);
    mgServo2.write(120);
    // mgServo3.write(180);
    microServo1.write(180);
    microServo2.write(0);
    microServo3.write(0);
    delay(5000);
  // }
  sendData(100);
}

void loop() {
  // Move each servo to a specific position
  // microServo1.write(200);
  // microServo2.write(110);
  // microServo3.write(0);
  // mgServo1.write(50);
  // mgServo2.write(10);

  // delay(1000); // Wait for a second

  // // Move each servo back to its initial position
  // microServo1.write(170);
  // microServo2.write(110);
  // microServo3.write(0);
  // mgServo1.write(100);
  // mgServo2.write(100);

  // delay(1000); // Wait for a second
}

void sendData(int data) {
  digitalWrite(DATA_PIN, HIGH); // Start bit
  delayMicroseconds(100); // Delay for synchronization
  for (int i = 0; i < 8; i++) {
    digitalWrite(DATA_PIN, bitRead(data, i)); // Send each bit of data
    delayMicroseconds(100); // Delay for synchronization
  }
  digitalWrite(DATA_PIN, LOW); // Stop bit
  delayMicroseconds(100); // Delay for synchronization
}