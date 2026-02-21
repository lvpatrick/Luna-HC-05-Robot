// Motors
#define enA 9
#define enB 10
#define in1 8
#define in2 7
#define in3 6
#define in4 5

// HC-05/HC-06 direct connection
// HC-05/HC-06 TX -> Arduino RX (pin 0)
// HC-05/HC-06 RX -> Arduino TX (pin 1)

// Speed control (0-255)
int motorSpeed = 150; // Default speed
char command;

void setup() {
  // Motors
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Set initial motor speeds
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
  
  // Serial for Bluetooth communication (HC-05/HC-06)
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    
    switch(command) {
      case 'F': case 'f': moveF(); break;
      case 'B': case 'b': moveB(); break;
      case 'R': case 'r': moveR(); break;
      case 'L': case 'l': moveL(); break;
      case 'S': case 's': stop(); break;
      
      // Speed control
      case '0': setSpeed(0); break;
      case '1': setSpeed(80); break;
      case '2': setSpeed(150); break;
      case '3': setSpeed(200); break;
      case '4': setSpeed(255); break;
    }
  }
}

void setSpeed(int speed) {
  motorSpeed = speed;
  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
}

// Control functions
void moveF() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveB() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveR() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveL() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
