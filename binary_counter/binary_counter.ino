
const int LEDCOUNT = 6;
const int LED[] = {0, 1, 2, 3, 4, 5};

byte count = 0;

void setup()
{
  for (int i = 0; i < LEDCOUNT; i++)
  {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop()
{
  byte b = 0;
  for (int i = 0; i < LEDCOUNT; i++)
  {
    digitalWrite(LED[i], bitRead(count, i));
  }
  if (count >= 59)
  {
    count = 0;
  }
  else
  {
    count++;
  }
  
  delay(1000);
}
