//--------------------------------
//------------ TOUCH -------------
//--------------------------------
// TOUCH GRID CONFIGURATION (here is a 24x24 sensors grid)
#define  ROWS  6
#define  COLS  6

int pinRows[] = {2, 3, 4, 5, 6, 7}; // sorties digitales
int pinCols[] = {0, 1, 2, 3, 4 , 5};  // entrées analogiques

void setup() {
  Serial.begin(9600);  // for serial (to computer)

  // toutes les lignes en LOW
  for (int i = 0; i < COLS; i++) {
    pinMode(pinRows[i], OUTPUT);
    digitalWrite(pinRows[i], LOW);
  }
}

void loop() {
  //--------------------------------
  //------------ TOUCH -------------
  //--------------------------------
  // Scan each column
  for (int i = 0; i < COLS; i++) {
    digitalWrite(pinRows[i], HIGH);

    // Write row reference on serial (zCCxAAAxAAAxAAAxAAA...xAAAq)
    Serial.print("z");
    Serial.print(i);

    // Read electric potential on each points (rows) of the current columns
    for (int j = 0; j < ROWS; j++) {
      Serial.print("x"); // "x" used as separator
      Serial.print(analogRead(pinCols[j]));
    }
    Serial.println("");

    // Set column pin in high-impedance state
    digitalWrite(pinRows[i], LOW);
  }
}
