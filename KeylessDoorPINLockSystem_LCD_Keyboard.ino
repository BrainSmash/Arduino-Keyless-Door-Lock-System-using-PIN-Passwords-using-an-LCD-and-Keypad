/*
* ********************************************************************************************
* ******************************* BRAIN SMASH ************************************************ 
* ************************* AUTHOR: DAEDALUS   8/2019 ****************************************
* **************** Visit us at: youtube.com/UC022nDDmdzDHkUT1hl_vHMg *************************
* ************************* Github.com/BrainSmash ********************************************
* You may use or modify this code for any and all of your projects whitout any restrictions
* If you use any fragment of this code we will be happy if you could send us a message ;)
* Brain Smash nor the Author are hold responsible for any misuse partially or complete of this code 
*/

/*
 * Keyless Door Pin Lock System
 * 
 * This Sketch allows the End user to create a PIN Lock System
 * the access is granted when the correct 4 character PIN
 * is entered, when the correct password is typed the text
 * "You shall pass" is displayed.
 * If the wrong paasword is entered the access is denied and the text
 * "You shall not pass" is displayed.
 * 
 * The libraries LiquidCrystal.h & Keypad.h are needed to run the sketch 
 * LiquidCrystal.h is installed by default with the installation of the Arduino IDE
 * Keypad.h can be found on the Github page of this code and shall be placed inside the folder:
 * C:\...\Documents\Arduino\Libraries
 * 
 * StartText()
 * This method clears the screen and displays the 
 * lock_text variable in the first row of the LCD.
 * 
 * Reset()
 * This method resets the LCD by cleaning it and calling StartText()
 * as well as cleaning the variables key_entered, entered_passwd & reset.
 * 
 * PasswdEntered(bool enter)
 * This method displays the access_granted_text variable if the pin entered
 * is the same as the stablished correct pin,
 * otherwise it displays access_denied_text variable to let the user know it entered 
 * the wrong pin, it also calls StartText() after the conditional statements.
 * 
 * KeysEntered()
 * This method read the quantity of characters that have been entered and
 * to protect the privacy of the pin password it replaces the current key entered
 * by a "*" (asterisk) character after a small delay.
 * 
 * KeyAction(char key)
 * This method determines the action to be taken upon certain characters entered
 * if the character is either "*" or "#" it performs a certain action, 
 * reset for the former and enter for the latter, any other character entered that is a number
 * gets to be displayed on the LCD.
 */
#include <Keypad.h>
#include <LiquidCrystal.h>

const int rs = 3, en = 2, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String lock_text = "Enter password",
       access_granted_text = "YouShallPass!",
       access_denied_text = "YouShallNotPass!",
       psswd = "1402",
       entered_psswd = "";

bool reset = false, enter = false;
int key_entered = 0, key_delay_time = 300, passwd_delay_time = 2500;

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 12, 11}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  lcd.begin(16, 2);

  StartText();
}

void loop() {
  
  KeysEntered();

  char key = keypad.getKey();

  KeyAction(key);
}

void StartText() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(lock_text);
}

void Reset(bool reset) {
  if (reset) {
    StartText();
    lcd.setCursor(0, 1);
  }
  key_entered = 0;
  entered_psswd = "";
  reset = false;
}

void PasswdEntered(bool enter) {
  if (enter) {
    if (entered_psswd.equals(psswd)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(access_granted_text);
      
    } else if (!entered_psswd.equals(psswd)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(access_denied_text);
    }
    
    delay(passwd_delay_time);
    StartText();
    key_entered = 0;
    entered_psswd = "";
    enter = false;
  }
}

void KeysEntered() {
  
  if (key_entered == 0) {
    lcd.setCursor(0, 1);
    
  } else if (key_entered == 1) {
    lcd.setCursor(0, 1);
    delay(key_delay_time);
    lcd.print('*');
    lcd.setCursor(1, 1);
    
  }  else if (key_entered == 2) {
    lcd.setCursor(1, 1);
    delay(key_delay_time);
    lcd.print('*');
    lcd.setCursor(2, 1);
    
  }  else if (key_entered == 3) {
    lcd.setCursor(2, 1);
    delay(key_delay_time);
    lcd.print('*');
    lcd.setCursor(3, 1);
    
  } else if (key_entered == 4) {
    lcd.setCursor(3, 1);
    delay(key_delay_time);
    lcd.print('*');
    lcd.setCursor(3, 1);
  }
}

void KeyAction(char key){

    if (key) {
    if (key == '*') {
      reset = true;
      Reset(reset);
    
    } else if (key == '#') {
      enter = true;
      PasswdEntered(enter);
      
    } else {
      if (key_entered <= 3) {
        lcd.print(key);
        key_entered += 1;
        entered_psswd += key;
      }
    }
  }
}
