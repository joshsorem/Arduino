/*
  Candle
  Turns on an LED after a one- to five-second delay and then flickers
  it in a manner which mimics the flame of a candle.  When a certain
  pin goes HIGH, the LED turns off after a one- to five-second delay.
  The only way to turn the candle back on would be by cycling the
  power. 
  
  Circuit
  ------------------------------------------------
  LED connected between pin 9 and ground.
  BUTTON connected between pin 2 and +5V.
  10K resistor connected between pin 2 and ground.
  
*/

const int LED0 = 9;  // 0 for ATTiny45
const int BUTTON0 = 2;  // Need to pull this down with a 10K resistor.

byte brightness0 = 128;
byte brightnessMin = 128;
byte brightnessMax = 255;
char stepMin = -40;
char stepMax = 40;

unsigned int powerDownTime = 0;
unsigned long buttonPressTime = 0;
boolean isOff = false;

void setup()
{
  pinMode(LED0, OUTPUT);
  pinMode(BUTTON0, INPUT);
  
  // Initialize the random number generator to be a bit more random.
  randomSeed(analogRead(0));
  
  // Set the power-down time to some random number between one- and
  // five-seconds.
  powerDownTime = random(1000,5000);
  
  // We want the loop to start a few moments after the device powers
  // on so that, when multiple identical devices are present, they
  // all don't light up at exactly the same time.
  delay(random(1000, 5000));
}

void loop()
{
  // The only time we'll be doing anything of note in this sketch is when
  // the isOff variable is set to false.  The reason for this is that we
  // want the candle to flicker as long as the circuit is on and we want
  // it to stop a few seconds after a certain button is pressed (or other
  // type of switch is "thrown").
  if (!isOff)
  {
    // Set a new brightness which differs from the old brightness by a random
    // number between stepMin and stepMax and where the new brightness is 
    // constrained to be between brightnessMin and brightnessMax.
    brightness0 = constrain(brightness0 + random(stepMin, stepMax), brightnessMin, brightnessMax);
    analogWrite(LED0, brightness0);
    
    // Here we're checking to see if the button was ever pressed.
    if (buttonPressTime == 0)
    {
      // If it hasn't ever been pressed, we'll check the signal pin to
      // see if it's gone HIGH.
      if (digitalRead(BUTTON0) == HIGH)
      {
        // If so, we'll take now to be the time the button was pressed and
        // never check for a button press again (since buttonPressTime
        // will now be greater than zero).
        // Possible edge case - if this circuit runs for longer than 50 days,
        // millis() might return a number which has overflowed and gone back 
        // to zero.  I don't plan on running this for more than a few hours
        // at a time so I'm ignoring that for now.
        buttonPressTime = millis();
      }
    }
    else if (millis() - buttonPressTime > powerDownTime)
    {
      // Since the button was pressed at some point, let's see if the amount
      // of time elapsed since then is more than our powerDownTime.  If so,
      // we'll need to set the candle to "off" and turn off the LED.
      isOff = true;
      analogWrite(LED0, 0);
    }    
  }

  delay(40);
}

