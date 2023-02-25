#include <LiquidCrystal.h>

#define trig_untral1 A1
#define trig_untral2 9
#define trig_untral3 A3
#define trig_untral4 7
#define trig_untral5 5
#define trig_untral6 A5

#define echo_untral1 A0
#define echo_untral2 10
#define echo_untral3 A2
#define echo_untral4 8
#define echo_untral5 6
#define echo_untral6 A4

String data = "";
bool Sensor1Status, Sensor2Status, Sensor3Status, Sensor4Status, Sensor5Status, Sensor6Status;
void setup()
{
    pinMode(trig_untral1, OUTPUT);
    pinMode(trig_untral2, OUTPUT);
    pinMode(trig_untral3, OUTPUT);
    pinMode(trig_untral4, OUTPUT);
    pinMode(trig_untral5, OUTPUT);
    pinMode(trig_untral6, OUTPUT);

    pinMode(echo_untral1, INPUT);
    pinMode(echo_untral2, INPUT);
    pinMode(echo_untral3, INPUT);
    pinMode(echo_untral4, INPUT);
    pinMode(echo_untral5, INPUT);
    pinMode(echo_untral6, INPUT);
    Serial.begin(9600);
}

void loop()
{
    int rangeOfSensor1 = getDistanceFromUltral1();
    int rangeOfSensor2 = getDistanceFromUltral2();
    int rangeOfSensor3 = getDistanceFromUltral3();
    int rangeOfSensor4 = getDistanceFromUltral4();
    int rangeOfSensor5 = getDistanceFromUltral5();
    int rangeOfSensor6 = getDistanceFromUltral6();
  	//printRangeData(rangeOfSensor1, rangeOfSensor2, rangeOfSensor3,
    //                 rangeOfSensor4, rangeOfSensor5, rangeOfSensor6);
    // obstacleDetection and send data
    obstacleDetection(rangeOfSensor1, rangeOfSensor2, rangeOfSensor3,
                      rangeOfSensor4, rangeOfSensor5, rangeOfSensor6);
}

void obstacleDetection(int rangeOfSensor1, int rangeOfSensor2,
                       int rangeOfSensor3, int rangeOfSensor4,
                       int rangeOfSensor5, int rangeOfSensor6)
{

    // detection for 1st sensor
    if (rangeOfSensor1 < 30)
    {
        Sensor1Status = true;
    }
    else
    {
        Sensor1Status = false;
    }
    // detection for 2nd sensor
    if (rangeOfSensor2 < 30)
    {
        Sensor2Status = true;
    }
    else
    {
        Sensor2Status = false;
    }
    // detection for 3rd sensor
    if (rangeOfSensor3 < 30)
    {
        Sensor3Status = true;
    }
    else
    {
        Sensor3Status = false;
    }
    // detection for 4th sensor
    if (rangeOfSensor4 < 30)
    {
        Sensor4Status = true;
    }
    else
    {
        Sensor4Status = false;
    }
    // detection for 5th sensor
    if (rangeOfSensor5 < 30)
    {
        Sensor5Status = true;
    }
    else
    {
        Sensor5Status = false;
    }
    // detection for 6th sensor
    if (rangeOfSensor6 < 30)
    {
        Sensor6Status = true;
    }
    else
    {
        Sensor6Status = false;
    }
	sendData(Sensor1Status,Sensor2Status,Sensor3Status,Sensor4Status,Sensor5Status,Sensor6Status);
}

void sendData(bool a, bool b, bool c, bool d, bool e, bool f) {
  byte data = 0;
  if (a) {
    data |= 1 << 0;
  }
  if (b) {
    data |= 1 << 1;
  }
  if (c) {
    data |= 1 << 2;
  }
  if (d) {
    data |= 1 << 3;
  }
  if (e) {
    data |= 1 << 4;
  }
  if (f) {
    data |= 1 << 5;
  }
	delay(100);
  Serial.write(data);
}

void printRangeData(int a, int b, int c, int d, int e, int f){
  Serial.print(a);
  	Serial.print("-");
  Serial.print(b);
  	Serial.print("-");
  Serial.print(c);
  	Serial.print("-");
  Serial.print(d);
  	Serial.print("-");
  Serial.print(e);
  	Serial.print("-");
  Serial.print(f);
  	Serial.println();
}


// lấy khoảng cách cảm biến đo được từ cảm biến thứ x đến tàu
int getDistanceFromUltral1()
{
    digitalWrite(trig_untral1, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_untral1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_untral1, LOW);

    const unsigned long duration = pulseIn(echo_untral1, HIGH);
    int distance = duration / 29 / 2;
    if (duration != 0)
    {
        return distance;
    }
}

int getDistanceFromUltral2()
{
    digitalWrite(trig_untral2, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_untral2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_untral2, LOW);

    const unsigned long duration = pulseIn(echo_untral2, HIGH);
    int distance = duration / 29 / 2;
    if (duration != 0)
    {
        return distance;
    }
}

int getDistanceFromUltral3()
{
    digitalWrite(trig_untral3, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_untral3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_untral3, LOW);

    const unsigned long duration = pulseIn(echo_untral3, HIGH);
    int distance = duration / 29 / 2;
    if (duration != 0)
    {
        return distance;
    }
}

int getDistanceFromUltral4()
{
    digitalWrite(trig_untral4, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_untral4, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_untral4, LOW);

    const unsigned long duration = pulseIn(echo_untral4, HIGH);
    int distance = duration / 29 / 2;
    if (duration != 0)
    {
        return distance;
    }
}

int getDistanceFromUltral5()
{
    digitalWrite(trig_untral5, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_untral5, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_untral5, LOW);

    const unsigned long duration = pulseIn(echo_untral5, HIGH);
    int distance = duration / 29 / 2;
    if (duration != 0)
    {
        return distance;
    }
}

int getDistanceFromUltral6()
{
    digitalWrite(trig_untral6, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_untral6, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_untral6, LOW);

    const unsigned long duration = pulseIn(echo_untral6, HIGH);
    int distance = duration / 29 / 2;
    if (duration != 0)
    {
        return distance;
    }
}