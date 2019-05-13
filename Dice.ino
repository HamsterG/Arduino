
int buttonPin = 8;
int blank = 6;
int ledPins[7] = {5, 6, 7, 9, 10, 11, 12};

int patterns[7][7] = {
  {0, 0, 0, 1, 0, 0, 0}, //One
  {0, 0, 1, 0, 0, 0, 1}, //Two
  {0, 1, 0, 1, 0, 0, 1}, //Three
  {0, 1, 1, 0, 1, 0, 1}, //Four
  {0, 1, 1, 1, 1, 1, 0}, //Five
  {1, 1, 1, 0, 1, 1, 1}, //Six
  {0, 0, 0, 0, 0, 0, 0} //Blank
  };

void setup() {
  for(int i = 0; i < ledPins; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
    }
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
    randomSeed(analogRead(0));
  }

void loop() {
if(digitalRead(buttonPin)) {
  roll();
  delay(250);
  }

}

void roll() {
  int result = 4;
  result = random(0, 6);
  delay(500);
  show(result);
  delay(500);
  }

void show(int result) {
 for(int i = 0; i < 7; i++) {
  digitalWrite(ledPins[i], patterns[result][i]);
  } 
 }
