#include <Arduino.h>
// Define motor control pins
int motor1Pin1 = 3; // Connect to IN1 on the L298N (Motor A)
int motor1Pin2 = 4; // Connect to IN2 on the L298N (Motor A)
int motor2Pin1 = 5; // Connect to IN3 on the L298N (Motor B)
int motor2Pin2 = 6; // Connect to IN4 on the L298N (Motor B)
int ENA_pin = 2;    // Connect to ENA on the L298N (Motor A)
int ENB_pin = 7;   // Connect to ENB on the L298N (Motor B)

void setup() {
  // Set motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  // Set ENA_pin and ENB_pin as outputs
  pinMode(ENA_pin, OUTPUT);
  pinMode(ENB_pin, OUTPUT);
  
  // Initially, stop both motors
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Test Motor A (forward)
  Serial.println("Testing Motor A (Forward)");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  analogWrite(ENA_pin, 150); // Set Motor A speed using PWM (range: 0-255)
  delay(2000); // Run for 2 seconds
  
  // Stop Motor A
  analogWrite(ENA_pin, 0);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  delay(1000); // Pause for 1 second
  
  // Test Motor A (backward)
  Serial.println("Testing Motor A (Backward)");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  analogWrite(ENA_pin, 150); // Set Motor A speed using PWM (range: 0-255)
  delay(2000); // Run for 2 seconds
  
  // Stop Motor A
  analogWrite(ENA_pin, 0);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  delay(1000); // Pause for 1 second
  
  // Test Motor B (forward)
  Serial.println("Testing Motor B (Forward)");
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(ENB_pin, 150); // Set Motor B speed using PWM (range: 0-255)
  delay(2000); // Run for 2 seconds
  
  // Stop Motor B
  analogWrite(ENB_pin, 0);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(1000); // Pause for 1 second
  
  // Test Motor B (backward)
  Serial.println("Testing Motor B (Backward)");
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(ENB_pin, 150); // Set Motor B speed using PWM (range: 0-255)
  delay(2000); // Run for 2 seconds
  
  // Stop Motor B
  analogWrite(ENB_pin, 0);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(1000); // Pause for 1 second
}
