// C++ code
//

// Im Setup definiere ich einen analogen Input (zum Einlesen des Photoresistors) und einen digitalen Output(zum ein/ausschalten der Leuchtiode)

void setup(){
	pinMode(A5, INPUT);
  pinMode(4, OUTPUT);
	Serial.begin(9600);
}

// im loop lese ich zuerst den photowiederstand ein und wandle den eingelesenen Wert in den wertebereich -10 bis 10 um.
// dann gebe ich mir den Wert auf dem Serien Monitor aus 
// Als letztes schaue ich ob der Wert (das Lichtlevel) über 0 liegt oder darunter.
// Wenn er höher als 0 ist wird die Leuchtiode eingeschalten sonst nicht.
void loop(){

  int measuredLight = analogRead(A5);
  int lightLevel = map(measuredLight, 26, 923, -10, 10);
  
  
  Serial.print("Light Level: ");
  Serial.println(lightLevel);
  
  
  if(lightLevel >= 0){
    digitalWrite(4, LOW);
  }
  else if(lightLevel < 0){
  	digitalWrite(4,HIGH);
  }


}
  