
// USS = Ultra Sonic Sensor

// 3 USS declaration of variables
// - Front Side
int T_Front = 8;
int E_Front = 9;
// - Left side
int T_Left = 4;
int E_Left = 5;
// - Right side
int T_Right = 2;
int E_Right = 3;
// Decleration for variables of RELAY conected to DC Motors
int LeftWheel = 11;
int RightWheel = 10;

// Different sides USS distance declaration of variables
int Dist_Front, Dist_Left, Dist_Right;

void setup() {
  // Assign variables
  // - Front USS
  pinMode(T_Front, OUTPUT);
  pinMode(E_Front, INPUT);
  // - Left USS
  pinMode(T_Left, OUTPUT);
  pinMode(E_Left, INPUT);
  // - Right USS
  pinMode(T_Right, OUTPUT);
  pinMode(E_Right, INPUT);
  
  // - RELAYS connected to DC Motors
  pinMode(LeftWheel, OUTPUT);
  pinMode(RightWheel, OUTPUT);
  
  // Custom function see line 
  Stop();
}

void loop() {
  // Send signals for Front USS
  digitalWrite(T_Front, LOW);
  delayMicroseconds(2);
  digitalWrite(T_Front, HIGH);
  delayMicroseconds(10);
  digitalWrite(T_Front, LOW);
  // Calculate Front USS distance in cm (metric)
  Dist_Front = pulseIn(E_Front, HIGH)*0.034/2;

  // Send signals for Left USS
  digitalWrite(T_Left, LOW);
  delayMicroseconds(2);
  digitalWrite(T_Left, HIGH);
  delayMicroseconds(10);
  digitalWrite(T_Left, LOW);
  // Calculate Left USS distance in cm (metric)
  Dist_Left = pulseIn(E_Left, HIGH)*0.034/2;
	
  // Send signals for Right USS
  digitalWrite(T_Right, LOW);
  delayMicroseconds(2);
  digitalWrite(T_Right, HIGH);
  delayMicroseconds(10);
  digitalWrite(T_Right, LOW);
  // Calculate Right USS distance in cm (metric)
  Dist_Right = pulseIn(E_Right, HIGH)*0.034/2;
  
  // Decition making for turning with DC Motors
  if (Dist_Front <= 35 && Dist_Front >= 7) {
    Stop();
    if (Dist_Left > Dist_Right) {
      TurnLeft();
    } else {
      TurnRight();
    }
  } else if (Dist_Front <= 7) {
    Stop();
  } else {
    Forward();
  }
  
}

// CUSTOM
// Stop function - switches RELAYs off
void Stop() {
  digitalWrite(LeftWheel, HIGH);
  digitalWrite(RightWheel, HIGH);
}

// Forward function - switches both RELAYs on
void Forward() {
  digitalWrite(LeftWheel, LOW);
  digitalWrite(RightWheel, LOW);
}

// Left function - switches Right RELAY on + Left RELAY off
void TurnLeft() {
  digitalWrite(LeftWheel, HIGH);
  digitalWrite(RightWheel, LOW);
}

// Right function - switches Left RELAY on + Right RELAY off
void TurnRight() {
  digitalWrite(LeftWheel, LOW);
  digitalWrite(RightWheel, HIGH);
}
