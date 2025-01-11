#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 9
#define RST_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

const int MAX_CARDS = 3; // Maximum number of cards to store
const int CARD_LENGTH = 11; // Length of the card ID

String cardIDs[MAX_CARDS]; // Array to store card IDs
int numCards = 0; // Number of cards stored

void setup() {
  Serial.begin(9600); // Initialize serial communication
  SPI.begin(); // Initialize SPI bus
  mfrc522.PCD_Init(); // Initialize MFRC522

  Serial.println("Scan your RFID card...");
}

void loop() {
  // Look for new cards
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Get the UID of the card
    String rfidString = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      rfidString += String(mfrc522.uid.uidByte[i], HEX);
      rfidString.toUpperCase(); // Convert to uppercase
      if (i < mfrc522.uid.size - 1) {
        rfidString += " "; // Add space between bytes
      }
    }

    // Check if the card ID is already stored
    if (!isCardStored(rfidString)) {
      // Store the card ID in the array
      if (numCards < MAX_CARDS) {
        cardIDs[numCards] = rfidString;
        numCards++;
        Serial.println("Card ID stored successfully.");Serial.println(rfidString);
      } else {
        Serial.println("Maximum number of cards reached.");
      }
    } else {
      Serial.println("Card ID already stored.");
      Serial.println(rfidString);
    }

    // Halt until card is removed
    mfrc522.PICC_HaltA();
    // Stop encryption on PCD
    mfrc522.PCD_StopCrypto1();
  }
  // else{
  //   Serial.println("RFID Prob");
  // }
}

bool isCardStored(String cardID) {
  // Check if the card ID is already stored in the array
  for (int i = 0; i < numCards; i++) {
    if (cardIDs[i] == cardID) {
      return true;
    }
  }
  return false;
}
