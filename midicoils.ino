/*  analogWrite(coil1, velocity) - Writes an analog value (PWM wave) to a pin. Can be used to light a LED at varying brightnesses or drive a motor at various speeds
The Coils are connected to TIP120*/

MIDI_CREATE_DEFAULT_INSTANCE();

#include <Wire.h>
#include <MIDI.h>

const int coil1 =  3;
const int coil2 =  5;

void HandleNoteOn (byte channel, byte number, byte velocity) { 
  if (number == 36) {
  analogWrite(coil1, velocity); // Writes an analog value (PWM wave) to a pin. Can be used to light a LED at varying brightnesses or drive a motor at various speeds
  delay(30);
  analogWrite(coil1, LOW); 
  }
 if (number == 37) {
  analogWrite(coil2, velocity);
  delay(10);
  analogWrite(coil2, LOW);
  } 
}   
void setup()
{
    pinMode(coil1, OUTPUT);
    pinMode(coil2, OUTPUT);
                    
    MIDI.begin(MIDI_CHANNEL_OMNI);
    MIDI.turnThruOff();
    Serial.begin(115200);
    MIDI.setHandleNoteOn(HandleNoteOn);
}
    
void loop()
{
        MIDI.read(); 
}
