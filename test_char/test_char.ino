//A variable to hold the level of coolness
int coolFactor = 3;
String test;

void setup() {

  Serial.begin(9600);
  test +='B';
  test +=char(128);

}

void loop() {

  //Send the value of coolFactor to the the Serial port.
  //So we can see it in the serial monitor window
  int b = 0;
  sscanf(&test[1],"%d",&b);
  //for(int i = 0; i < 3; i++)
  //{
  //  b += test[3 - i] * exp(i);
  //}
  Serial.print(char(128));
  Serial.print('\n');
  if(test[1]==char(128))
  {
  Serial.print('A');
  Serial.print('\n');
  }
}

int my_atoi(const char *s)
{
    int sign=1;
    if (*s == '-')
        sign = -1;
    s++;
    int num = 0;
    while(*s)
    {
        num = ((*s)-'0') + num*10;
        s++;
    }
    return num*sign;
}
