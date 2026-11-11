
const int buttonPin = 2;
const int ledPin = 3;

int mode = 0;
int lastButton = HIGH;

bool ledState = HIGH;
unsigned long timer = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, HIGH);
}

void loop() {
  int button = digitalRead(buttonPin);

  if (button == LOW && lastButton == HIGH) {
    mode++;

    if (mode > 3) {
      mode = 0;
    }

    ledState = HIGH;
    digitalWrite(ledPin, HIGH);
    timer = millis();

    delay(50);
  }

  lastButton = button;

  if (mode == 0) {
    digitalWrite(ledPin, HIGH);
  }

  else {
    int speed;

    if (mode == 1) {
      speed = 1000;
    }
    else if (mode == 2) {
      speed = 500;
    }
    else {
      speed = 200;
    }

    if (millis() - timer >= speed) {
      timer = millis();
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
  }
}
