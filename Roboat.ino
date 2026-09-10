// ===== IR SENSOR PINS =====
#define LEFT_IR 32
#define RIGHT_IR 33

// ===== L298N MOTOR DRIVER =====
#define IN1 26
#define IN2 27
#define IN3 14
#define IN4 25

void forward()
{
  // Left motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void leftTurn()
{
  // Left motor STOP
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Right motor FORWARD
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void rightTurn()
{
  // Left motor FORWARD
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor STOP
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopRobot()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup()
{
  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopRobot();

  Serial.begin(115200);
}

void loop()
{
  int leftSensor = digitalRead(LEFT_IR);
  int rightSensor = digitalRead(RIGHT_IR);

  Serial.print("Left = ");
  Serial.print(leftSensor);

  Serial.print("   Right = ");
  Serial.println(rightSensor);

  // WHITE + WHITE → STRAIGHT
  if (leftSensor == 1 && rightSensor == 1)
  {
    forward();
  }

  // BLACK + WHITE → LEFT
  else if (leftSensor == 0 && rightSensor == 1)
  {
    leftTurn();
  }

  // WHITE + BLACK → RIGHT
  else if (leftSensor == 1 && rightSensor == 0)
  {
    rightTurn();
  }

  // BLACK + BLACK → STOP
  else
  {
    stopRobot();
  }

  delay(20);
}