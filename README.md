# Arduino-Keyless-Door-Lock-System-using-PIN-Passwords-using-an-LCD-and-Keypad
Sketch that allows the End user to create a PIN Lock System in Arduino with an LCD and Keypad

********************************************************************************************

******************************* BRAIN SMASH ************************************************ 

************************* AUTHOR: DAEDALUS   8/2019 ****************************************

**************** Visit us at: youtube.com/UC022nDDmdzDHkUT1hl_vHMg *************************

************************* Github.com/BrainSmash ********************************************

You may use or modify this code for any and all of your projects whitout any restrictions
If you use any fragment of this code we will be happy if you could send us a message ;)
Brain Smash nor the Author are hold responsible for any misuse partially or complete of this code 

Keyless Door Pin Lock System

This Sketch allows the End user to create a PIN Lock System
the access is granted when the correct 4 character PIN
is entered, when the correct password is typed the text
"You shall pass" is displayed.
If the wrong paasword is entered the access is denied and the text
"You shall not pass" is displayed.
 
The libraries LiquidCrystal.h & Keypad.h are needed to run the sketch 
LiquidCrystal.h is installed by default with the installation of the Arduino IDE
Keypad.h can be found on the Github page of this code and shall be placed inside the folder:
C:\...\Documents\Arduino\Libraries
  
StartText()
This method clears the screen and displays the 
lock_text variable in the first row of the LCD.
  
Reset()
This method resets the LCD by cleaning it and calling StartText()
as well as cleaning the variables key_entered, entered_passwd & reset.
  
PasswdEntered(bool enter)
This method displays the access_granted_text variable if the pin entered
is the same as the stablished correct pin,
otherwise it displays access_denied_text variable to let the user know it entered 
the wrong pin, it also calls StartText() after the conditional statements.
  
KeysEntered()
This method read the quantity of characters that have been entered and
to protect the privacy of the pin password it replaces the current key entered
by a "*" (asterisk) character after a small delay.
  
KeyAction(char key)
This method determines the action to be taken upon certain characters entered
if the character is either "*" or "#" it performs a certain action, 
reset for the former and enter for the latter, any other character entered that is a number
gets to be displayed on the LCD.
