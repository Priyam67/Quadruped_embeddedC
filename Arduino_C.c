#include <Servo.h>

// Define servo objects for each joint of the 4 legs
Servo leg1_hip, leg1_knee, leg1_ankle;
Servo leg2_hip, leg2_knee, leg2_ankle;
Servo leg3_hip, leg3_knee, leg3_ankle;
Servo leg4_hip, leg4_knee, leg4_ankle;

// Human detection flag
bool humanDetected = false;

// Function to move all legs with given angles
void moveLegs(int hipAngle, int kneeAngle, int ankleAngle) {
  leg1_hip.write(hipAngle);   leg1_knee.write(kneeAngle);   leg1_ankle.write(ankleAngle);
  leg2_hip.write(hipAngle);   leg2_knee.write(kneeAngle);   leg2_ankle.write(ankleAngle);
  leg3_hip.write(hipAngle);   leg3_knee.write(kneeAngle);   leg3_ankle.write(ankleAngle);
  leg4_hip.write(hipAngle);   leg4_knee.write(kneeAngle);   leg4_ankle.write(ankleAngle);
  delay(500);
}

// Setup function
void setup() {
  Serial.begin(115200); // Begin serial communication

  // Attach servos to corresponding pins
  leg1_hip.attach(2);   leg1_knee.attach(3);   leg1_ankle.attach(4);
  leg2_hip.attach(5);   leg2_knee.attach(6);   leg2_ankle.attach(7);
  leg3_hip.attach(8);   leg3_knee.attach(11);  leg3_ankle.attach(12);
  leg4_hip.attach(13);  leg4_knee.attach(A0);  leg4_ankle.attach(A1);

  Serial.println("Quadruped robot initialized...");
}

// Loop function
void loop() {
  // Check for serial input from camera module
  if (Serial.available()) {
    String input = Serial.readString();
    if (input.indexOf("HUMAN_DETECTED") != -1) {
      humanDetected = true;
    }
  }

  // Respond based on human detection
  if (humanDetected) {
    Serial.println("Human detected! Alerting and pausing...");
    // Stop movement or trigger alert system
    delay(5000);  // Simulated pause for rescue team
    humanDetected = false; // Reset for next detection
  } else {
    Serial.println("No human detected. Walking...");
    // Simulated walking gait
    moveLegs(30, 60, 90);
    moveLegs(60, 30, 90);
  }
}