/*
 Name:		DimmerLED.ino
 Created:	5/15/2016 9:40:15 PM
 Author:	NhatHo
*/

const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A1;
const int greenSensorPin = A0;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorVal = 0;
int greenSensorVal = 0;
int blueSensorVal = 0;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600); // Communicate with PC with 9600 bps

	pinMode(greenLEDPin, OUTPUT);
	pinMode(redLEDPin, OUTPUT);
	pinMode(blueLEDPin, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	/*
	* Received signal from photoresistors.
	* The delay is for ADC to process
	*/
	redSensorVal = analogRead(redSensorPin);
	delay(5);
	greenSensorVal = analogRead(greenSensorPin);
	delay(5);
	blueSensorVal = analogRead(blueSensorPin);

	Serial.print("Raw Sensor Values \t Red: ");
	Serial.print(redSensorVal);
	Serial.print("\t Green: ");
	Serial.print(greenSensorVal);
	Serial.print("\t Blue: ");
	Serial.println(blueSensorVal);

	/*
	* Convert 0-1023 range (from photoresistors) to 0-255 range of LED input 
	*/
	redValue = redSensorVal / 4;
	greenValue = greenSensorVal / 4;
	blueValue = blueSensorVal / 4;

	Serial.print("Mapped Sensor Values \t Red: ");
	Serial.print(redValue);
	Serial.print("\t Green: ");
	Serial.print(greenValue);
	Serial.print("\t Blue: ");
	Serial.println(blueValue);

	// Output the converted value to each color input of LED to change its color using Pulse Width Modulation (PWM)
	analogWrite(redLEDPin, redValue);
	analogWrite(blueLEDPin, blueValue);
	analogWrite(greenLEDPin, greenValue);
}
