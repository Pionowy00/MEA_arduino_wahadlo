#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

Adafruit_LiquidCrystal lcd_1(0);

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','#','/'}
};

byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {6, 7, 8, 9};

String text = "";

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int num1 = 0;
int num2 = 0;
int result = 0;

char operation = ' ';

bool calculated = false;
bool newNumber = false;

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
}

void loop()
{
  char customKey = customKeypad.getKey();

  if (customKey)
  {
    if (customKey >= '0' && customKey <= '9')
    {
      if (calculated)
      {
        text = "";
        calculated = false;
        lcd_1.clear();
      }

      if (newNumber)
      {
        lcd_1.setCursor(0, 0);
        lcd_1.print("                ");
        newNumber = false;
      }

      if (text.length() < 16)
      {
        text += customKey;
        lcd_1.setCursor(16 - text.length(), 0);
        lcd_1.print(text);
      }
    }

    else if (customKey == 'C')
    {
      text = "";
      num1 = 0;
      num2 = 0;
      result = 0;
      operation = ' ';

      calculated = false;
      newNumber = false;

      lcd_1.clear();
    }

    else if (customKey == '+' || customKey == '-' || customKey == '*' || customKey == '/')
    {
      if (text != "" && operation == ' ')
      {
        num1 = text.toInt();
        text = "";
        operation = customKey;
        newNumber = true;

        lcd_1.setCursor(15, 1);
        lcd_1.print(customKey);
      }
    }

    else if (customKey == '#')
    {
      if (text != "" && operation != ' ')
      {
        num2 = text.toInt();

        lcd_1.clear();

        if (operation == '/' && num2 == 0)
        {
          lcd_1.setCursor(0, 0);
          lcd_1.print("DIVISION BY ZERO");

          lcd_1.setCursor(0, 1);
          lcd_1.print("NOT ALLOWED");
        }
        else
        {
          switch (operation)
          {
            case '+':
              result = num1 + num2;
              break;

            case '-':
              result = num1 - num2;
              break;

            case '*':
              result = num1 * num2;
              break;

            case '/':
              result = num1 / num2;
              break;
          }

          lcd_1.setCursor(0, 0);
          lcd_1.print(result);
        }

        text = "";
        operation = ' ';
        calculated = true;
        newNumber = false;
      }
    }
  }
}
