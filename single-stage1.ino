// Using a MOSFET to switch on the coil

const int buttonPin = 2;
const int mosfetPin = 9;

bool lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(mosfetPin, OUTPUT);

  digitalWrite(mosfetPin, LOW);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // Detect button press
  if (lastButtonState == HIGH && buttonState == LOW) {

    digitalWrite(mosfetPin, HIGH);

    // Keep MOSFET on for n ms
    delayMicroseconds(5000);

    digitalWrite(mosfetPin, LOW);
  }

  lastButtonState = buttonState;
}
