
#define GREEN_RIGHT 2
#define GREEN_LEFT 7
#define GREEN_TOP 9
#define GREEN_BOTTOM 5
#define RED_RIGHT 3
#define RED_LEFT 6
#define RED_TOP 8
#define RED_BOTTOM 4

void red()
{
	digitalWrite(RED_RIGHT, HIGH);
    digitalWrite(GREEN_RIGHT, LOW); 
  
  	digitalWrite(RED_LEFT, HIGH);
    digitalWrite(GREEN_LEFT, LOW); 
  
  	digitalWrite(RED_TOP, HIGH);
    digitalWrite(GREEN_TOP, LOW); 
  
  	digitalWrite(RED_BOTTOM, HIGH);
    digitalWrite(GREEN_BOTTOM, LOW); 
}

void green(int side_green, int side_red)
{
  	red();
	digitalWrite(side_green, HIGH);
    digitalWrite(side_red, LOW); 
}

void setup()
{
  pinMode(GREEN_LEFT, OUTPUT);
  pinMode(GREEN_RIGHT, OUTPUT);
  pinMode(GREEN_TOP, OUTPUT);
  pinMode(GREEN_BOTTOM, OUTPUT);
  pinMode(RED_RIGHT, OUTPUT);
  pinMode(RED_LEFT, OUTPUT);
  pinMode(RED_TOP, OUTPUT);
  pinMode(RED_BOTTOM, OUTPUT);
}

void loop()
{
  while(true)
  {
    bool changed = false;
    unsigned long now = millis();
    while(millis() < now + 5000)
    {
      if(!changed)
      {
        green(GREEN_TOP, RED_TOP);
        changed = true;
      }
    }
    changed = false;
    now = millis();
    while(millis() < now + 2000)
    {
      red();
    }
    now = millis();
    while(millis() < now + 5000)
    {
      if(!changed)
      {
        green(GREEN_RIGHT, RED_RIGHT);
        changed = true;
      }
    }
    changed = false;
    now = millis();
    while(millis() < now + 2000)
    {
      red();
    }
    now = millis();
    while(millis() < now + 5000)
    {
      if(!changed)
      {
        green(GREEN_BOTTOM, RED_BOTTOM);
        changed = true;
      }
    }
    changed = false;
    now = millis();
    while(millis() < now + 2000)
    {
      red();
    }
    now = millis();
    while(millis() < now + 5000)
    {
      if(!changed)
      {
        green(GREEN_LEFT, RED_LEFT);
        changed = true;
      }
    }
    now = millis();
    while(millis() < now + 2000)
    {
      red();
    }
  }
}