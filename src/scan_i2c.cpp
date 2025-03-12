 #include <Arduino.h>
 #include <Wire.h>


 #define wire Wire


 void setup(void) {
     Serial.begin(9600);
     while (!Serial) {
 	    delay(500);
     };

 	wire.begin();
     wire.setTimeout(200);

     const uint8_t firstAddr = 1;
 	const uint8_t lastAddr = 0x7F;
 	Serial.println();
 	Serial.print("Interrogating all addresses in range 0x");
 	Serial.print(firstAddr, HEX);
 	Serial.print(" - 0x");
 	Serial.print(lastAddr, HEX);
 	Serial.println(" (inclusive) ...");

 	for (uint8_t addr = firstAddr; addr <= lastAddr; addr++) {
 		TXLED1;

 		delayMicroseconds(50);

 		wire.beginTransmission(addr);
 		uint8_t startResult = wire.endTransmission();

 		if (startResult == 0) {
 			Serial.print("\r### Device found at 0x");
 			Serial.print(addr, HEX);
 			Serial.println("###");
 			Serial.flush();
 		}
 		TXLED0;

 		delay(50);
 	}
    Serial.println("Scan finished");

 }


 void loop(void) {
     ;
 }
