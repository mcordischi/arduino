const int soundSensor = 2; // Digital Pin of the sound sensor
const int micPin = A0; //Analog Pin of the sound sensor
const int relayPin = 7; // Relay Pin
const int motorTime = 2000; // Time in milliseconds (2 seg)
int threshold = 400; // Adjust based on the environment

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Motor apagado al inicio
  Serial.begin(9600);
}

void loop() {
  int micValue = analogRead(micPin);
  Serial.println(micValue);
  
  if (micValue > threshold) { 
    digitalWrite(relayPin, HIGH); // Enciende el motor
    delay(motorTime); // Mantiene el motor encendido por 5 segundos
    digitalWrite(relayPin, LOW); // Apaga el motor
    delay(motorTime); // Mantiene el motor encendido por 5 segundos
  }
}