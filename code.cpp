// C++ code
//LEFT SIDE:
//green - pin 11
//red - pin 10
//
//RIGHT SIDE:
//green - pin 5
//red - pin 6

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

	
void loop()
{
  while(true)
  {
    int now = millis();
  	while(millis() < now + 4000) // LEFT - GREEN, RIGHT - RED
    {
    	digitalWrite(11, HIGH);
      	digitalWrite(10, LOW);
      
      	digitalWrite(5, LOW);
      	digitalWrite(6, HIGH);
    }
  	while(millis() < now + 6000) //BREAK
    {
    	digitalWrite(11, LOW);
      	digitalWrite(10, HIGH);
      
      	digitalWrite(5, LOW);
      	digitalWrite(6, HIGH);
    }
  	while(millis() < now + 10000)//LEFT - RED, RIGHT - GREEN
    {
    	digitalWrite(11, LOW);
      	digitalWrite(10, HIGH);
      
      	digitalWrite(5, HIGH);
      	digitalWrite(6, LOW);
    }
  	while(millis() < now + 12000)//BREAK
    {
    	digitalWrite(11, LOW);
      	digitalWrite(10, HIGH);
      
      	digitalWrite(5, LOW);
      	digitalWrite(6, HIGH);
    }
  }
}