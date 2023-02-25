#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo myservo;
int pos = 0;

void setup()
{

    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(13, OUTPUT);

    pinMode(8, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);

    myservo.attach(A0);
    // tắt trạng thái quay lúc khởi động barie
    myservo.write(0);

    lcd.begin(30, 2);
    // Print a message to the LCD.
    lcd.print("TRANG THAI:");
    Serial.begin(9600);
}

int stop = 1;
void getLevel(int level, int check)
{

    if (level == 0)
    {
        // in ra màn hình lcd
        lcd.setCursor(0, 16);
        lcd.print("HE THONG READY    ");
        // lcd.print("he thong san sang ");
        Serial.println("He Thong san sang");
        if (stop == 1)
        {
            // xoay ngược barie 90 độ
            myservo.write(0);
            stop = 0;
        }
    }
    else
    {
        if (level == 1)
        {
            lcd.setCursor(0, 16);
            if (check > 0)
            {
                lcd.print("TAU SAP DEN    ");
                Serial.println("TAU SAP DEN");
            }
            else
            {
                lcd.print("TAU DI XA     ");
                Serial.println("TAU DI XA");
            }
            // Nếu barier đang mở thì lúc này được đóng lại
            if (stop == 0)
            {
                // xoay ngược barie 90 độ
                myservo.write(90);
                stop = 1;
            }
        }
        else
        {
            if (level == 2)
            {
                lcd.setCursor(0, 16);
                if (check > 0)
                {
                    lcd.print("TAU DEN GAN    ");
                    Serial.println("TAU DEN GAN ");
                    // cho den nhay
                    digitalWrite(10, 1);
                    digitalWrite(9, 0);
                    delay(100);
                    digitalWrite(10, 0);
                    digitalWrite(9, 1);
                    delay(100);
                }
                else
                {
                    lcd.print("TAU SAP DI QUA     ");
                    Serial.println("TAU SAP DI QUA");
                }
            }
            else
            {
                if (level < 6)
                {
                    lcd.setCursor(0, 16);
                    lcd.print("TAU DANG DI QUA ");
                    Serial.println("TAU DANG DI QUA");
                    if (check > 0)
                    {
                        // b
                        tone(A0, 256, 500);
                        delay(10);
                        noTone(13);
                        delay(5);
                        // nhay den
                        digitalWrite(10, 1);
                        digitalWrite(9, 0);
                        delay(100);
                        digitalWrite(10, 0);
                        digitalWrite(9, 2);
                        delay(100);
                    }
                }
                else
                {
                    lcd.setCursor(0, 16);
                    lcd.print("TAU DANG DI QUA ");
                    Serial.println("TAU DANG DI QUA");
                    digitalWrite(10, 0);
                    digitalWrite(9, 0);
                }
            }
        }
    }
}

void testDevice()
{

    int bt1 = digitalRead(8);
    int bt2 = digitalRead(7);
    int bt3 = digitalRead(6);

    // Xử lí test thiết bị

    if (bt1 == 0)
    {
        Serial.println("testLEd#");
        digitalWrite(9, HIGH);
        delay(500);
        digitalWrite(9, LOW);
        delay(500);
    }

    if (bt2 == 0)
    {
        Serial.println("testServo#");
        myservo.write(90);
        delay(500);
        myservo.write(0);
        delay(500);
    }
    if (bt3 == 0)
    {
        Serial.println("test13#");
        digitalWrite(13, HIGH);
        delay(500);
        digitalWrite(13, LOW);
        delay(500);
    }
}

int lastLoc = 0;
int currentLoc = 0;
int lastRecord = 0;

void loop()
{

    testDevice();
    receiveDataAndProcess();
}

void receiveDataAndProcess()
{

    if (Serial.available() > 0)
    {
        int location = 0;
        byte data = Serial.read();
        bool sensor1 = (data & (1 << 0)) != 0;
        bool sensor2 = (data & (1 << 1)) != 0;
        bool sensor3 = (data & (1 << 2)) != 0;
        bool sensor4 = (data & (1 << 3)) != 0;
        bool sensor5 = (data & (1 << 4)) != 0;
        bool sensor6 = (data & (1 << 5)) != 0;
        // Do something with the received data

        if (sensor1)
            location += 1;
        if (sensor2)
            location += 1;
        if (sensor3)
            location += 1;
        if (sensor4)
            location += 1;
        if (sensor5)
            location += 1;
        if (sensor6)
            location += 1;

        currentLoc = location;

        if (currentLoc - lastLoc != 0)
        {
            lastRecord = currentLoc - lastLoc;
        }

        getLevel(location, lastRecord);
        lastLoc = location;

        Serial.println(location);
        delay(5);
    }
}
