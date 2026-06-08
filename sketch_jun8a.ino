#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 5
#define RST_PIN 4

#define BUZZER_PIN 15
#define BUTTON_PIN 13

MFRC522 rfid(SS_PIN, RST_PIN);

LiquidCrystal_I2C lcd(0x27, 16, 2);

int totalBill = 0;

// RFID UID -> Product Database
struct Product {
  String uid;
  String name;
  int price;
};

Product products[] = {
  {"D3A1B2C4", "Milk", 50},
  {"A1B2C3D4", "Bread", 30},
  {"11223344", "Rice", 120},
  {"55667788", "Sugar", 60}
};

int numProducts = sizeof(products) / sizeof(products[0]);

void beep()
{
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);
}

String getUID()
{
  String uid = "";

  for (byte i = 0; i < rfid.uid.size; i++)
  {
    if (rfid.uid.uidByte[i] < 0x10)
      uid += "0";

    uid += String(rfid.uid.uidByte[i], HEX);
  }

  uid.toUpperCase();
  return uid;
}

void showTotal()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Total Amount");

  lcd.setCursor(0,1);
  lcd.print("Rs ");
  lcd.print(totalBill);
}

void setup()
{
  Serial.begin(115200);

  SPI.begin();
  rfid.PCD_Init();

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Smart Checkout");

  lcd.setCursor(0,1);
  lcd.print("Scan Item");

  delay(2000);

  showTotal();
}

void loop()
{
  // Reset Bill Button
  if(digitalRead(BUTTON_PIN) == LOW)
  {
    totalBill = 0;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Bill Reset");

    beep();

    delay(1500);

    showTotal();
  }

  // RFID Card Detection
  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  String scannedUID = getUID();

  Serial.print("UID: ");
  Serial.println(scannedUID);

  bool found = false;

  for(int i=0; i<numProducts; i++)
  {
    if(scannedUID == products[i].uid)
    {
      totalBill += products[i].price;

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print(products[i].name);

      lcd.setCursor(0,1);
      lcd.print("Rs ");
      lcd.print(products[i].price);

      beep();

      delay(2000);

      showTotal();

      found = true;
      break;
    }
  }

  if(!found)
  {
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Unknown Item");

    beep();

    delay(1500);

    showTotal();
  }

  rfid.PICC_HaltA();
}