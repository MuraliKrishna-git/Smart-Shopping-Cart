#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// #define MAX_STR_LEN 20 // Maximum length of each string-
#define MAX_NUM_STRINGS 4 // Maximum number of strings in the array

int selected = 0;
int entered = -1;

int Send = 100;
// char StarMaker = "<";
// int recieved = 0 ;

String myList[MAX_NUM_STRINGS];
int c=0;
int arr[4];

//  int down ;
//  int up ;
//  int enter;
//  int back;

int bob=1;
int A=0,B=0,C=0,D=0;

void displaymenu(void) {

  int down = digitalRead(3);
  int up = digitalRead(2);
  int enter = digitalRead(4);
  int back = digitalRead(5);

  if (up == LOW && down == LOW) {

  };
  if (up == LOW) {
    // if(selected>0){
      selected = selected - 1;
      Serial.println(selected);
      // };
    delay(200);
  };
  if (down == LOW) {
    // if(selected>0){
      selected = selected + 1;
      Serial.println(selected);
      // };
    delay(200);
  };
  if (enter == LOW) {
    entered = selected;
     Serial.println(entered);
     delay(200);
  };
  if (back == LOW) {
    bob=0;
    // entered = -1;
    //  Serial.println(entered);
  };
  const char *options[4] = {
    " Eraser ",
    " Paper Cup ",
    " Water Bottle ",
    " Scrubber "
  };  

  // while(back!=LOW)
  // {
  if (entered == -1) {
    display.clearDisplay();
    display.setTextSize(1.2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Available List"));
    display.println("");
    for (int i = 0; i < 4; i++) {
      if (i == selected) {
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
        display.println(options[i]);
      } else if (i != selected) {
        display.setTextColor(SSD1306_WHITE);
        display.println(options[i]);
      }
    }
  } else if (entered == 0) {
    display.clearDisplay();
    display.setTextSize(1.2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Selected Product"));
    display.println("Rubiks Cube");
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    myList[c]="Rubiks Cube";
    c++;
    // delay(1000);
    A++;
    entered=-1;
    

    // display.println("Dsn Menu system");
  } else if (entered == 1) {
    display.clearDisplay();
    display.setTextSize(1.2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Selected Product"));
    display.println(" Eraser ");
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    myList[c]="Eraser";
    c++;
    // delay(1000);
    B++;
    entered=-1;
    
    // display.println("Dsn Menu system :)");
  }
  else if (entered == 2) {
    display.clearDisplay();
    display.setTextSize(1.2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Selected Product"));
    display.println("Water Bottle");
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    myList[c]="Water Bottle";
    c++;
    // delay(1000);
    entered=-1;
    C++;
    
    // display.println("Dsn Menu system:)");
  } else if (entered == 3) {
    display.clearDisplay();
    display.setTextSize(1.2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Selected Product"));
    display.println("Scrubber");
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    myList[c]="Scrubber";
    c++;
    // delay(1000);
    entered=-1;
    D++;
    
    // display.println("Dsn Menu system:)");
  }
  display.display();
  delay(800);
  // }
  // } else if (entered == 4) {
  //   display.clearDisplay();
  //   display.setTextSize(1);
  //   display.setTextColor(SSD1306_WHITE);
  //   display.setCursor(0, 0);
  //   display.println(F("Dsn menu test"));
  //   display.println("Menu option 5");
  //   display.setTextColor(SSD1306_WHITE);
  //   display.setTextSize(2);
  //   display.println("Dsn Menu system:)");
  // } else if (entered == 5) {
  //   display.clearDisplay();
  //   display.setTextSize(1);
  //   display.setTextColor(SSD1306_WHITE);
  //   display.setCursor(0, 0);
  //   display.println(F("Dsn menu test"));
  //   display.println("Menu option 6");
  //   display.setTextColor(SSD1306_WHITE);
  //   display.setTextSize(2);
  //   display.println("Dsn Menu system:)");
  // } else if (entered == 6) {
  //   display.clearDisplay();
  //   display.setTextSize(1);
  //   display.setTextColor(SSD1306_WHITE);
  //   display.setCursor(0, 0);
  //   display.println(F("Dsn menu test"));
  //   display.println("Menu option 7");
  //   display.setTextColor(SSD1306_WHITE);
  //   display.setTextSize(2);
  //   display.println("Dsn Menu system:)");
  // }

  // display.display();
}

void display_list(void)
{
  for(int i=0;i<4;i++)
  {
    Serial.println(myList[i]);
  }
  
}

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.display();
  delay(2000); // Pause for 2 seconds
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(bob == 1)
  {
    displaymenu();
    // delay(1000);
  }
  display_list();
  delay(100);
  arr[0]=A;
  arr[1]=B;
  arr[2]=C;
  arr[3]=D;
  // int numberToSend = 123; // Example number to send
  // String names[] = {"Alice", "Bob", "Charlie"}; // Example array of names

  // Start bit
  // digitalWrite(TX_PIN, HIGH);
  // delayMicroseconds(1000); // Wait for a short period for synchronization
  
  // Send the number
  // Serial.write(StarMaker);
  Serial.write((uint8_t*)&Send, sizeof(Send));
  for(int i=0;i<4;i++){
  Serial.write((uint8_t*)&arr[i], sizeof(arr));}
  // delay(100);  
  // Serial.write((uint8_t*)&B, sizeof(B));
  // Serial.write((uint8_t*)&C, sizeof(C));
  // Serial.write((uint8_t*)&D, sizeof(D));

  // Serial.println(Send);
  // Serial.println(A);
  // Serial.println(B);
  // Serial.println(C);
  // Serial.println(D);

  // Send the array of names
  for (int i = 0; i<4; i++) {
    Serial.print(arr[i]);}
  //   Serial.write('\0'); // Null terminator to mark the end of each string
  // }
  delay(1000);
  // A=0,B=0,C=0,D=0;
  bob=1;
  c=0;
  entered = -1;
  selected = 0;
}
