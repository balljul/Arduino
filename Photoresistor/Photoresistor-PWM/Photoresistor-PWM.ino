
// Im Setup definiere ich einen analogen Input (zum Einlesen des Photoresistors) und einen digitalen Output(zum ein/ausschalten der Leuchtiode)

void setup(){
	pinMode(A5, INPUT);
  pinMode(3, OUTPUT);
}

// im loop lese ich zuerst den photowiederstand ein und wandle den eingelesenen Wert in den wertebereich 0 bis 255 um.
// Danach gebe ich mit analogWrite am pin3 ein PWM Signal aus. 
void loop(){

  int measuredLight = analogRead(A5);
  int lightLevel = map(measuredLight, 26, 923, 0, 255);
  
  analogWrite(3, lightLevel);

}
  