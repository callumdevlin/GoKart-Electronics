volatile unsigned int count = 0;
unsigned long next = 250;
unsigned int temp = 0;

const int radius = 10;

unsigned int rps = 0;
unsigned int fph = 0;
unsigned int mph = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(2), magnet_detect, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis()>=next){
    temp = count;
    rps = temp * 4;
    fph = 2 * 3.14159 * radius * rps * 60;
    mph = fph / 5280;
    Serial.print(mph);Serial.println("mph");
    count -= temp;
    next += 250;
  }
}

void magnet_detect()
{
  count++;
}