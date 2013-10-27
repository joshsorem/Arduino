

const int LED = 0; //0;
const int SENSOR = 1; //2;
const int DEBUG = 4;

byte brightness0 = 128;
byte brightnessMin = 128;
byte brightnessMax = 255;
char stepMin = -40;
char stepMax = 40;

void setup()
{
  for(byte i = 0; i < 5; i++)
  {
    pinMode(i, INPUT_PULLUP);
  }
//  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);
  pinMode(DEBUG, OUTPUT);
  
  // Initialize the random number generator to be a bit more random.
  randomSeed(analogRead(3));
}

void loop()
{
  int sensorvalue = analogRead(SENSOR);
  
  digitalWrite(DEBUG, LOW);
  
//  Serial.println(sensorvalue);
  if(sensorvalue > 250)
  {
    if (sensorvalue > 750)
    {
      digitalWrite(DEBUG, HIGH);
    }  
    // Set a new brightness which differs from the old brightness by a random
    // number between stepMin and stepMax and where the new brightness is 
    // constrained to be between brightnessMin and brightnessMax.
    brightness0 = constrain(brightness0 + random(stepMin, stepMax), brightnessMin, brightnessMax);
    analogWrite(LED, brightness0);

    delay(40);
  }
  else
  {
    digitalWrite(LED, 0);
    delay(10000);
  }
}
