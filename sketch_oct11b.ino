#include<Keypad.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(5,4,3,2,A4,A5);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char Keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0,A1,11,10};
byte colPins[COLS] = {9,8,7,6};
int LCDCol = 0;
int LCDRow = 0;

Keypad keypad = Keypad(makeKeymap(Keys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16 ,2);
  lcd.setCursor(LCDCol,LCDRow);
  
}

void loop()
{
  char key =keypad.getKey();
  if (key)
  {
    Serial.println(key);

    if(LCDCol>15)
    {
      ++LCDRow;
      
      if(LCDRow>1)
      {LCDRow=0; LCDCol=0; lcd.clear();}

      LCDCol=0;
    }
    lcd.setCursor (LCDCol, LCDRow);
    
    lcd.print(key);
    
    ++LCDCol;
  }
}
