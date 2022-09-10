
int T_Front = 8;
int E_Front = 9;
int T_Left = 4;
int E_Left = 5;
int T_Right = 2;
int E_Right = 3;
int LeftWheel = 11;
int RightWheel = 10;

int Dist_Front, Dist_Left, Dist_Right;

void setup() {
  pinMode(T_Front, OUTPUT);
  pinMode(E_Front, INPUT);
  pinMode(T_Left, OUTPUT);
  pinMode(E_Left, INPUT);
  pinMode(T_Right, OUTPUT);
  pinMode(E_Right, INPUT);
  
  pinMode(LeftWheel, OUTPUT);
  pinMode(RightWheel, OUTPUT);

  Stop();
}

void loop() {
  digitalWrite(T_Front, LOW);
  delayMicroseconds(2);
  digitalWrite(T_Front, HIGH);
  delayMicroseconds(10);
  digitalWrite(T_Front, LOW);
  Dist_Front = pulseIn(E_Front, HIGH)*0.034/2;

  digitalWrite(T_Left, LOW);
  delayMicroseconds(2);
  digitalWrite(T_Left, HIGH);
  delayMicroseconds(10);
  digitalWrite(T_Left, LOW);
  Dist_Left = pulseIn(E_Left, HIGH)*0.034/2;

  digitalWrite(T_Right, LOW);
  delayMicroseconds(2);
  digitalWrite(T_Right, HIGH);
  delayMicroseconds(10);
  digitalWrite(T_Right, LOW);
  Dist_Right = pulseIn(E_Right, HIGH)*0.034/2;
  
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

void Stop() {
  digitalWrite(LeftWheel, HIGH);
  digitalWrite(RightWheel, HIGH);
}

void Forward() {
  digitalWrite(LeftWheel, LOW);
  digitalWrite(RightWheel, LOW);
}

void TurnLeft() {
  digitalWrite(LeftWheel, HIGH);
  digitalWrite(RightWheel, LOW);
}

void TurnRight() {
  digitalWrite(LeftWheel, LOW);
  digitalWrite(RightWheel, HIGH);
}
