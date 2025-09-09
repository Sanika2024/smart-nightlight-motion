// Smart Street Lighting with Slide Switch (Arduino Tinkercad)

// Pin definitions
const int SWITCH_PIN = 4;   // Slide switch for Day/Night
const int PIR_PIN = 2;      // PIR motion sensor
const int LED1 = 3;         // LED (PWM pin)
const int LED2 = 5;         // LED (PWM pin)
const int LED3 = 6;         // LED (PWM pin)

// Parameters
int dimDuty = 60;               // LED brightness in dim mode (0-255)
unsigned long holdMs = 5000;    // Time LEDs stay bright after motion (5 sec)

// Tracking
unsigned long lastMotionMs = 0;
unsigned long lastPrintMs = 0;

void setup() {
  pinMode(SWITCH_PIN, INPUT);   // Slide switch
  pinMode(PIR_PIN, INPUT);      // PIR sensor
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.begin(9600);
  Serial.println("---- Smart Lighting with Slide Switch ----");
}

// Function to set brightness to all LEDs
void setAll(int duty) {
  analogWrite(LED1, duty);
  analogWrite(LED2, duty);
  analogWrite(LED3, duty);
}

void loop() {
  unsigned long now = millis();

  // Read switch (HIGH = Night, LOW = Day)
  bool isNight = digitalRead(SWITCH_PIN);

  // Read PIR motion sensor
  bool motion = digitalRead(PIR_PIN);

  // Update last motion time if detected
  if (motion) {
    lastMotionMs = now;
  }

  // Time since last motion
  unsigned long timeSinceMotion = now - lastMotionMs;

  // LED control
  int duty;
  if (!isNight) {
    duty = 0;  // Day mode → LEDs OFF
  } else {
    if (timeSinceMotion < holdMs) {
      duty = 255; // Night + recent motion → FULL brightness
    } else {
      duty = dimDuty; // Night + no motion → DIM mode
    }
  }

  // Apply brightness
  setAll(duty);

  // Debug info every 2 sec
  if (now - lastPrintMs > 2000) {
    lastPrintMs = now;
    Serial.print("Switch="); Serial.print(isNight ? "NIGHT" : "DAY");
    Serial.print(" | Motion="); Serial.print(motion ? "YES" : "NO");
    Serial.print(" | TimeSinceMotion="); Serial.print(timeSinceMotion / 1000); Serial.print("s");
    Serial.print(" | LED Brightness="); Serial.println(duty);
    lastPrintMs = now;
  }

  delay(100);
}
