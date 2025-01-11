// #include <SPI.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include <MFRC522.h>

// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 64 // OLED display height, in pixels
// #define OLED_RESET 4      // Reset pin # (or -1 if sharing Arduino reset pin)
// #define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// #define UP_BUTTON 2
// #define DOWN_BUTTON 3
// #define SELECT_BUTTON 4
// #define FINISH_BUTTON 5

// #define LINESENSOR1 6
// #define LINESENSOR2 7
// #define MOTOR1A 8
// #define MOTOR1B 9
// #define MOTOR2A 10
// #define MOTOR2B A0
// #define EN A3

// #define RFID_SDA A2
// #define RFID_RST A1

// #define MOTOR_SPEED 200
// #define MINIMUM_TIME_BETWEEN_CARDS 2000
// const char *options[4] = {
//     " Rubiks Cube ",
//     " Eraser ",
//     " Water Bottle ",
//     " Scrubber "
//   }; 

// MFRC522 mfrc522(12, A1);
// long int last_card_read;
// #define COMMANDS_LENGTH 4
// char *Type[4] = {"Stop", "stop", "STOP", "Stop"};
// int Value[4] = {3000, 1000, 0, 5000};

// char *CardID[4] = {"39 5F BB 99", "23 F9 E9 FA", "79 07 38 99", "93 F9 77 C5"};

// const int MAX_ITEMS = 4;
// char myList[MAX_ITEMS][50];
// int numItems = 0;

// int selected = 0;
// int entered = -1;
// int end = 0;

// // char myList[4][50];
// int c=0;

// void setup()
// {
//   pinMode(UP_BUTTON, INPUT_PULLUP);
//   pinMode(DOWN_BUTTON, INPUT_PULLUP);
//   pinMode(SELECT_BUTTON, INPUT_PULLUP);
//   pinMode(FINISH_BUTTON, INPUT_PULLUP);

//   Serial.begin(9600);
//   // display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

//   if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
//   {
//     Serial.println(F("SSD1306 allocation failed"));
//     for (;;)
//        ;// Don't proceed, loop forever
//   }
//   display.clearDisplay();
//   display.drawPixel(10, 10, SSD1306_WHITE);
//   display.display();
//   delay(2000); // Pause for 2 seconds

//   SPI.begin();
//   mfrc522.PCD_Init(RFID_SDA, RFID_RST);
//   pinMode(LINESENSOR1, INPUT);
//   pinMode(LINESENSOR2, INPUT);
//   pinMode(MOTOR1A, OUTPUT);
//   pinMode(MOTOR1B, OUTPUT);
//   pinMode(MOTOR2A, OUTPUT);
//   pinMode(MOTOR2B, OUTPUT);
//   pinMode(EN, OUTPUT);
// }

// void loop()
// {
//   while(end==0)
//   {
//     displayMenu();
//   }
  
//   // Line follower logic
//   if (digitalRead(LINESENSOR1) == LOW && digitalRead(LINESENSOR2) == HIGH)
//   {
//     Forward();
//     Serial.println("FRWD");
//     delay(20);
//   }
//   else if (digitalRead(LINESENSOR1) == HIGH && digitalRead(LINESENSOR2) == LOW)
//   {
//     Left();
//     Serial.println("LFT");
//     delay(20);
//   }
//   else if (digitalRead(LINESENSOR1) == LOW && digitalRead(LINESENSOR2) == LOW)
//   {
//     Right();
//     Serial.println("RT");
//     delay(20);
//   }

//   // RFID tag detection logic
//   if (millis() - last_card_read >= MINIMUM_TIME_BETWEEN_CARDS)
//   {
//     if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
//     {
//       String content = "";
//       for (byte i = 0; i < mfrc522.uid.size; i++)
//       {
//         content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
//         content.concat(String(mfrc522.uid.uidByte[i], HEX));
//       }
//       content.toUpperCase();
//       content = content.substring(1);

//       for (int a = 0; a < COMMANDS_LENGTH; a++)
//       {
//         last_card_read = millis();
//         if (content == CardID[a])
//         {
//           if (Type[a] == "Stop")
//           {
//             Stop();
//             delay(Value[a]);
//           }
//           else if (Type[a] == "stop")
//           {
//             Stop();
//             delay(Value[a]);
//           }
//           else if (Type[a] == "STOP")
//           {
//             Stop();
//             delay(500);
//           }
//           else if (Type[a] == "Ignore")
//           {
//           }
//         }
//       }
//     }
//   }
//   end=0;
//   c=0;
// }

// void displayMenu()
// {
//   int up = digitalRead(UP_BUTTON);
//   int down = digitalRead(DOWN_BUTTON);
//   int select = digitalRead(SELECT_BUTTON);
//   int finish = digitalRead(FINISH_BUTTON);

//   if (up == LOW)
//   {
//     selected = selected - 1;
//     delay(200);
//   }
//   if (down == LOW)
//   {
//     selected = selected + 1;
//     delay(200);
//   }
//   if (select == LOW)
//   {
//     entered = selected;
//     delay(200);
//   }
//   if (finish == LOW)
//   {
//     // Start the line follower logic
//     end=1;
//   }

//   if(entered == -1)
//   {
//     display.clearDisplay();
//     display.setTextSize(1);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(0, 0);
//     display.println(F("Available List"));
//     display.println("");
//     for (int i = 0; i < MAX_ITEMS; i++)
//     {
//       if (i == selected)
//       {
//         display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
//         display.println(options[i]);
//       }
//       else
//       {
//         display.setTextColor(SSD1306_WHITE);
//         display.println(options[i]);
//       }
//     }
//   }
//   else if (entered == 0) {
//     display.clearDisplay();
//     display.setTextSize(1);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(0, 0);
//     display.println(F("Selected Product"));
//     display.println("Rubiks Cube");
//     display.setTextColor(SSD1306_WHITE);
//     display.setTextSize(2);
//     strcpy(myList[c], "Rubiks Cube");
//     c++;
//     entered=-1;
//   } 
//   else if (entered == 1) {
//     display.clearDisplay();
//     display.setTextSize(1);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(0, 0);
//     display.println(F("Selected Product"));
//     display.println(" Eraser ");
//     display.setTextColor(SSD1306_WHITE);
//     display.setTextSize(2);
//     strcpy(myList[c], "Eraser");
//     c++;
//     entered=-1;
//   }
//   else if (entered == 2) {
//     display.clearDisplay();
//     display.setTextSize(1);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(0, 0);
//     display.println(F("Selected Product"));
//     display.println("Water Bottle");
//     display.setTextColor(SSD1306_WHITE);
//     display.setTextSize(2);
//     strcpy(myList[c], "Water Bottle");
//     c++;
//     entered=-1;
//   } 
//   else if (entered == 3) {
//     display.clearDisplay();
//     display.setTextSize(1);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(0, 0);
//     display.println(F("Selected Product"));
//     display.println("Scrubber");
//     display.setTextColor(SSD1306_WHITE);
//     display.setTextSize(2);
//     strcpy(myList[c], "Scrubber");
//     c++;
//     entered=-1;
//   }
//   display.display();
//   delay(2000);
// }

// void Forward()
// {
//   digitalWrite(MOTOR1A, HIGH);
//   digitalWrite(MOTOR1B, LOW);

//   analogWrite(EN, MOTOR_SPEED);

//   digitalWrite(MOTOR2A, HIGH);
//   digitalWrite(MOTOR2B, LOW);

//   analogWrite(EN, MOTOR_SPEED);
// }

// void Left()
// {
//   digitalWrite(MOTOR1A, LOW);
//   digitalWrite(MOTOR1B, HIGH);

//   analogWrite(EN, MOTOR_SPEED);

//   digitalWrite(MOTOR2A, LOW);
//   digitalWrite(MOTOR2B, HIGH);

//   analogWrite(EN, MOTOR_SPEED);
// }

// void Right()
// {
//   digitalWrite(MOTOR1A, HIGH);
//   digitalWrite(MOTOR1B, LOW);

//   analogWrite(EN, MOTOR_SPEED);

//   digitalWrite(MOTOR2A, LOW);
//   digitalWrite(MOTOR2B, HIGH);

//   analogWrite(EN, MOTOR_SPEED);
// }

// void Stop()
// {
//   digitalWrite(MOTOR1A, LOW);
//   digitalWrite(MOTOR1B, LOW);

//   digitalWrite(MOTOR2A, LOW);
//   digitalWrite(MOTOR2B, LOW);
// }


























// #include <SPI.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include <MFRC522.h>

// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 64 // OLED display height, in pixels
// #define OLED_RESET -1      // Reset pin # (or -1 if sharing Arduino reset pin)
// #define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// #define UP_BUTTON 2
// #define DOWN_BUTTON 3
// #define SELECT_BUTTON 4
// #define FINISH_BUTTON 5

// #define LINESENSOR1 6
// #define LINESENSOR2 7
// #define MOTOR1A 8
// #define MOTOR1B 9
// #define MOTOR2A 10
// #define MOTOR2B A0
// #define EN A3

// #define RFID_SDA A2
// #define RFID_RST -1

// #define MOTOR_SPEED 200
// #define MINIMUM_TIME_BETWEEN_CARDS 2000
// const char *options[4] = {
//     " Rubiks Cube ",
//     " Eraser ",
//     " Water Bottle ",
//     " Scrubber "
//   }; 

// MFRC522 mfrc522(12, A1);
// long int last_card_read;
// #define COMMANDS_LENGTH 4
// char *Type[4] = {"Stop", "stop", "STOP", "Stop"};
// int Value[4] = {3000, 1000, 0, 5000};

// char *CardID[4] = {"39 5F BB 99", "23 F9 E9 FA", "79 07 38 99", "93 F9 77 C5"};

// const int MAX_ITEMS = 4;
// char myList[MAX_ITEMS][50];
// int numItems = 0;

// int selected = 0;
// int entered = -1;
// int end = 0;

// // char myList[4][50];
// int c=0;

// void setup()
// {
//   pinMode(UP_BUTTON, INPUT_PULLUP);
//   pinMode(DOWN_BUTTON, INPUT_PULLUP);
//   pinMode(SELECT_BUTTON, INPUT_PULLUP);
//   pinMode(FINISH_BUTTON, INPUT_PULLUP);

//   Serial.begin(9600);

//   if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
//   {
//     Serial.println(F("SSD1306 allocation failed"));
//     for (;;); // Don't proceed, loop forever
//   }
//   display.clearDisplay();
//   display.drawPixel(10, 10, SSD1306_WHITE);
//   display.display();
//   delay(2000); // Pause for 2 seconds

//   SPI.begin();
//   mfrc522.PCD_Init(RFID_SDA, RFID_RST);
//   pinMode(LINESENSOR1, INPUT);
//   pinMode(LINESENSOR2, INPUT);
//   pinMode(MOTOR1A, OUTPUT);
//   pinMode(MOTOR1B, OUTPUT);
//   pinMode(MOTOR2A, OUTPUT);
//   pinMode(MOTOR2B, OUTPUT);
//   pinMode(EN, OUTPUT);
// }

// void loop()
// {
//   displayMenu();

//   // Line follower logic
//   if (digitalRead(LINESENSOR1) == LOW && digitalRead(LINESENSOR2) == HIGH)
//   {
//     Forward();
//     Serial.println("FRWD");
//     delay(20);
//   }
//   else if (digitalRead(LINESENSOR1) == HIGH && digitalRead(LINESENSOR2) == LOW)
//   {
//     Left();
//     Serial.println("LFT");
//     delay(20);
//   }
//   else if (digitalRead(LINESENSOR1) == LOW && digitalRead(LINESENSOR2) == LOW)
//   {
//     Right();
//     Serial.println("RT");
//     delay(20);
//   }

//   // RFID tag detection logic
//   if (millis() - last_card_read >= MINIMUM_TIME_BETWEEN_CARDS)
//   {
//     if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
//     {
//       String content = "";
//       for (byte i = 0; i < mfrc522.uid.size; i++)
//       {
//         content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
//         content.concat(String(mfrc522.uid.uidByte[i], HEX));
//       }
//       content.toUpperCase();
//       content = content.substring(1);

//       for (int a = 0; a < COMMANDS_LENGTH; a++)
//       {
//         last_card_read = millis();
//         if (content == CardID[a])
//         {
//           if (Type[a] == "Stop")
//           {
//             Stop();
//             delay(Value[a]);
//           }
//           else if (Type[a] == "stop")
//           {
//             Stop();
//             delay(Value[a]);
//           }
//           else if (Type[a] == "STOP")
//           {
//             Stop();
//             delay(500);
//           }
//           else if (Type[a] == "Ignore")
//           {
//           }
//         }
//       }
//     }
//   }
// }

// void displayMenu()
// {
//   int up = digitalRead(UP_BUTTON);
//   int down = digitalRead(DOWN_BUTTON);
//   int select = digitalRead(SELECT_BUTTON);
//   int finish = digitalRead(FINISH_BUTTON);

//   if (up == LOW)
//   {
//     selected = selected - 1;
//     delay(200);
//   }
//   if (down == LOW)
//   {
//     selected = selected + 1;
//     delay(200);
//   }
//   if (select == LOW)
//   {
//     entered = selected;
//     delay(200);
//   }
//   if (finish == LOW)
//   {
//     // Start the line follower logic
//     end=1;
//   }

//   if(entered == -1)
//   {
//     display.clearDisplay();
//     display.setTextSize(1);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(0, 0);
//     display.println(F("Available List"));
//     display.println("");
//     for (int i = 0; i < MAX_ITEMS; i++)
//     {
//       if (i == selected)
//       {
//         display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
//         display.println(options[i]);
//       }
//       else
//       {
//         display.setTextColor(SSD1306_WHITE);
//         display.println(options[i]);
//       }
//     }
//   }
//   else if (entered == 0) {
//     display.clearDisplay();
//     display.setTextSize(1);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(0, 0);
//     display.println(F("Selected Product"));
//     display.println("Rubiks Cube");
//     display.setTextColor(SSD1306_WHITE);
//     display.setTextSize(2);
//     strcpy(myList[c], "Rubiks Cube");
//     c++;
//     entered=-1;
//   } 
//   else if (entered == 1) {
//     display.clearDisplay();
//     display.setTextSize(1);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(0, 0);
//     display.println(F("Selected Product"));
//     display.println(" Eraser ");
//     display.setTextColor(SSD1306_WHITE);
//     display.setTextSize(2);
//     strcpy(myList[c], "Eraser");
//     c++;
//     entered=-1;
//   }
//   else if (entered == 2) {
//     display.clearDisplay();
//     display.setTextSize(1);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(0, 0);
//     display.println(F("Selected Product"));
//     display.println("Water Bottle");
//     display.setTextColor(SSD1306_WHITE);
//     display.setTextSize(2);
//     strcpy(myList[c], "Water Bottle");
//     c++;
//     entered=-1;
//   } 
//   else if (entered == 3) {
//     display.clearDisplay();
//     display.setTextSize(1);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(0, 0);
//     display.println(F("Selected Product"));
//     display.println("Scrubber");
//     display.setTextColor(SSD1306_WHITE);
//     display.setTextSize(2);
//     strcpy(myList[c], "Scrubber");
//     c++;
//     entered=-1;
//   }
//   display.display();
//   delay(2000);
// }

// void Forward()
// {
//   digitalWrite(MOTOR1A, HIGH);
//   digitalWrite(MOTOR1B, LOW);

//   analogWrite(EN, MOTOR_SPEED);

//   digitalWrite(MOTOR2A, HIGH);
//   digitalWrite(MOTOR2B, LOW);

//   analogWrite(EN, MOTOR_SPEED);
// }

// void Left()
// {
//   digitalWrite(MOTOR1A, LOW);
//   digitalWrite(MOTOR1B, HIGH);

//   analogWrite(EN, MOTOR_SPEED);

//   digitalWrite(MOTOR2A, LOW);
//   digitalWrite(MOTOR2B, HIGH);

//   analogWrite(EN, MOTOR_SPEED);
// }

// void Right()
// {
//   digitalWrite(MOTOR1A, HIGH);
//   digitalWrite(MOTOR1B, LOW);

//   analogWrite(EN, MOTOR_SPEED);

//   digitalWrite(MOTOR2A, LOW);
//   digitalWrite(MOTOR2B, HIGH);

//   analogWrite(EN, MOTOR_SPEED);
// }

// void Stop()
// {
//   digitalWrite(MOTOR1A, LOW);
//   digitalWrite(MOTOR1B, LOW);

//   digitalWrite(MOTOR2A, LOW);
//   digitalWrite(MOTOR2B, LOW);
// }













#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MFRC522.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 4      // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define UP_BUTTON 2
#define DOWN_BUTTON 3
#define SELECT_BUTTON 4
#define FINISH_BUTTON 5

#define LINESENSOR1 6
#define LINESENSOR2 7
#define MOTOR1A 8
#define MOTOR1B 9
#define MOTOR2A 10
#define MOTOR2B A0
#define EN A3

#define RFID_SDA A2
#define RFID_RST A1

#define MOTOR_SPEED 200
#define MINIMUM_TIME_BETWEEN_CARDS 2000
const char *options[4] = {
    " Rubiks Cube ",
    " Eraser ",
    " Water Bottle ",
    " Scrubber "
  }; 

MFRC522 mfrc522(12, A1);
long int last_card_read;
#define COMMANDS_LENGTH 4
char *Type[4] = {"Stop", "stop", "STOP", "Stop"};
int Value[4] = {3000, 1000, 0, 5000};

char *CardID[4] = {"39 5F BB 99", "23 F9 E9 FA", "79 07 38 99", "93 F9 77 C5"};

const int MAX_ITEMS = 4;
char myList[MAX_ITEMS][50];
int numItems = 0;

int selected = 0;

void setup()
{
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);
  pinMode(SELECT_BUTTON, INPUT_PULLUP);
  pinMode(FINISH_BUTTON, INPUT_PULLUP);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.display();
  delay(2000); // Pause for 2 seconds

  SPI.begin();
  mfrc522.PCD_Init(RFID_SDA, RFID_RST);
  pinMode(LINESENSOR1, INPUT);
  pinMode(LINESENSOR2, INPUT);
  pinMode(MOTOR1A, OUTPUT);
  pinMode(MOTOR1B, OUTPUT);
  pinMode(MOTOR2A, OUTPUT);
  pinMode(MOTOR2B, OUTPUT);
  pinMode(EN, OUTPUT);
}

void loop()
{
  displayMenu();

  // Line follower logic
  if (digitalRead(LINESENSOR1) == LOW && digitalRead(LINESENSOR2) == HIGH)
  {
    Forward();
    Serial.println("FRWD");
    delay(20);
  }
  else if (digitalRead(LINESENSOR1) == HIGH && digitalRead(LINESENSOR2) == LOW)
  {
    Left();
    Serial.println("LFT");
    delay(20);
  }
  else if (digitalRead(LINESENSOR1) == LOW && digitalRead(LINESENSOR2) == LOW)
  {
    Right();
    Serial.println("RT");
    delay(20);
  }

  // RFID tag detection logic
  if (millis() - last_card_read >= MINIMUM_TIME_BETWEEN_CARDS)
  {
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
    {
      String content = "";
      for (byte i = 0; i < mfrc522.uid.size; i++)
      {
        content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
      }
      content.toUpperCase();
      content = content.substring(1);

      for (int a = 0; a < COMMANDS_LENGTH; a++)
      {
        last_card_read = millis();
        if (content == CardID[a])
        {
          if (Type[a] == "Stop")
          {
            Stop();
            delay(Value[a]);
          }
          else if (Type[a] == "stop")
          {
            Stop();
            delay(Value[a]);
          }
          else if (Type[a] == "STOP")
          {
            Stop();
            delay(500);
          }
          else if (Type[a] == "Ignore")
          {
          }
        }
      }
    }
  }
}

void displayMenu()
{
  int up = digitalRead(UP_BUTTON);
  int down = digitalRead(DOWN_BUTTON);
  int select = digitalRead(SELECT_BUTTON);
  int finish = digitalRead(FINISH_BUTTON);

  if (up == LOW)
  {
    selected = max(0, selected - 1);
    delay(200);
  }
  if (down == LOW)
  {
    selected = min(MAX_ITEMS - 1, selected + 1);
    delay(200);
  }
  if (select == LOW)
  {
    if (numItems < MAX_ITEMS)
    {
      strcpy(myList[numItems], options[selected]);
      numItems++;
    }
    delay(200);
  }
  if (finish == LOW)
  {
    // Start the line follower logic
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Available List"));
  display.println("");
  for (int i = 0; i < MAX_ITEMS; i++)
  {
    if (i == selected)
    {
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      display.println(options[i]);
    }
    else
    {
      display.setTextColor(SSD1306_WHITE);
      display.println(options[i]);
    }
  }
  display.display();
}

void Forward()
{
  digitalWrite(MOTOR1A, HIGH);
  digitalWrite(MOTOR1B, LOW);

  analogWrite(EN, MOTOR_SPEED);

  digitalWrite(MOTOR2A, HIGH);
  digitalWrite(MOTOR2B, LOW);

  analogWrite(EN, MOTOR_SPEED);
}

void Left()
{
  digitalWrite(MOTOR1A, LOW);
  digitalWrite(MOTOR1B, HIGH);

  analogWrite(EN, MOTOR_SPEED);

  digitalWrite(MOTOR2A, LOW);
  digitalWrite(MOTOR2B, HIGH);

  analogWrite(EN, MOTOR_SPEED);
}

void Right()
{
  digitalWrite(MOTOR1A, HIGH);
  digitalWrite(MOTOR1B, LOW);

  analogWrite(EN, MOTOR_SPEED);

  digitalWrite(MOTOR2A, LOW);
  digitalWrite(MOTOR2B, HIGH);

  analogWrite(EN, MOTOR_SPEED);
}

void Stop()
{
  digitalWrite(MOTOR1A, LOW);
  digitalWrite(MOTOR1B, LOW);

  digitalWrite(MOTOR2A, LOW);
  digitalWrite(MOTOR2B, LOW);
}
