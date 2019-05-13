int buttonPin = 8;

int ledPins[7] = {5, 6, 7, 9, 10, 11, 12};

int patterns[6][7] = {
  {0, 0, 0, 1, 0, 0, 0}, //One
  {0, 0, 0, 0, 1, 0, 0}, //Two
  {0, 0, 0, 0, 0, 1, 0}, //Three
  {0, 0, 0, 0, 0, 0, 1}, //Four
  {0, 0, 1, 0, 0, 0, 0}, //Five
  {0, 1, 0, 0, 0, 0, 0}, //Six
  };

void setup() {
  for(int i = 0; i < ledPins; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
    }
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
  }

void loop() {
if(digitalRead(buttonPin)){
  roll();
  delay(100);
  }


}

 void show(int rndNum) {
  for(int i = 0; i < ledPins; i++){
    digitalWrite(ledPins[i], patterns[rndNum][i]);
    delay(200);
    }
  }

void roll() {
  int rndNum = 0;
  Serial.println(rndNum);
  rndNum = random(0, 6);
  Serial.println(rndNum);
  delay(500);
  show(rndNum);
  delay(500);
    }


