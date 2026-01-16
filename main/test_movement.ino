// Motors
#define enA 9
#define enB 10
#define in1 8
#define in2 7
#define in3 6
#define in4 5

void setup() {
  // Motors
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
  // Initialize motor speed (0-255)
  analogWrite(enA, 200); // Motor A speed
  analogWrite(enB, 200); // Motor B speed
 
  Serial.begin(9600);
  Serial.println("Starting motor test...");
}

// Control functions
void moveF() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("FORWARD");
}

void moveB() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("BACKWARD");
}

void moveR() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("TURN RIGHT");
}

void moveL() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("TURN LEFT");
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("STOP");
}

void loop() {
  // Test movement sequence
  Serial.println("=== TEST FORWARD ===");
  moveF();
  delay(2000);
  stop();
  delay(500);
 
  Serial.println("=== TEST BACKWARD ===");
  moveB();
  delay(2000);
  stop();
  delay(500);
 
  Serial.println("=== TEST TURN LEFT ===");
  moveL();
  delay(2000);
  stop();
  delay(500);
 
  Serial.println("=== TEST TURN RIGHT ===");
  moveR();
  delay(2000);
  stop();
  delay(500);
 
  Serial.println("=== COMPLETED 1 TEST CYCLE ===");
  delay(2000);
}
