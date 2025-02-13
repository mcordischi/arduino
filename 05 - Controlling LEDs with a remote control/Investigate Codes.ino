#include <IRremote.h>
const int IR_RECEIVER_PIN = 2;
IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        irrecv.resume();
    }
}