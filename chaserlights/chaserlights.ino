int time = 250;
int A = 0;
int B = 1;
int C = 4;
int D = 3;


void setup()
{
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
}

void off()
{
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
}

void on(int a, int b)
{
  off();
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  delay(time);
}

void loop()
{
  on(A, B);
  on(A, C);
  on(A, D);
  on(B, A);
  on(B, C);
  on(B, D);
  on(C, A);
  on(C, B);
  on(C, D);
  on(D, A);
  on(D, B);
  on(D, C);  
}
