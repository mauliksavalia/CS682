//Use constants for the relay pins in case you need to change these later
const int elev_relay1 = 3;   //Arduino pin that triggers relay #1
const int elev_relay2 = 2;   //Arduino pin that triggers relay #2
const int elev_relay3 = 5;   //Arduino pin that triggers relay #1
const int elev_relay4 = 4;   //Arduino pin that triggers relay #2
const int first_relay1 = 7;   //Arduino pin that triggers relay #1
const int first_relay2 = 6;   //Arduino pin that triggers relay #2
const int second_relay1 = 9;   //Arduino pin that triggers relay #1
const int second_relay2 = 8;   //Arduino pin that triggers relay #2
const int third_relay1 = 11;   //Arduino pin that triggers relay #1
const int third_relay2 = 10;   //Arduino pin that triggers relay #2
const int fourth_relay1 = 12;   //Arduino pin that triggers relay #1
const int fourth_relay2 = 13;   //Arduino pin that triggers relay #2
// const int fifth_relay1 = 12;   //Arduino pin that triggers relay #1
// const int fifth_relay2 = 13;   //Arduino pin that triggers relay #2

void setup() {
  //Set pinMode to OUTPUT for the two relay pins
  pinMode(elev_relay1, OUTPUT);
  pinMode(elev_relay2, OUTPUT);
  pinMode(elev_relay3, OUTPUT);
  pinMode(elev_relay4, OUTPUT);
  pinMode(first_relay1, OUTPUT);
  pinMode(first_relay2, OUTPUT);
  pinMode(second_relay1, OUTPUT);
  pinMode(second_relay2, OUTPUT);
  pinMode(third_relay1, OUTPUT);
  pinMode(third_relay2, OUTPUT);
  pinMode(fourth_relay1, OUTPUT);
  pinMode(fourth_relay2, OUTPUT);
  // pinMode(fifth_relay1, OUTPUT);
  // pinMode(fifth_relay2, OUTPUT);

batterySwap();
//batteryReset();
//firstPush();
//firstStop();
//firstRetract();
//elevatorUp();
//elevatorDown();
//delay(10500);
//elevatorStop();
//secondRetract();
//secondPush();
//secondRetract();
//thirdPush();
//thirdRetract();
//fourthPush();
//fourthRetract();
//platformReset();
}
void platformReset() {
elevatorUp();
firstRetract();
secondRetract();
thirdRetract();  
fourthRetract();
}
void batteryReset() {

elevatorDown();
delay(21000);

elevatorStop();

thirdPush();
delay(21000);

thirdStop();

thirdRetract();
delay(21000);

thirdStop();

elevatorUp();
delay(10800);

elevatorStop();

fourthPush();
delay(21000);

fourthStop();

fourthRetract();
delay(21000);

fourthStop();

elevatorUp();
delay(10400);

elevatorStop();

}

void batterySwap() {
elevatorDown();
delay(22000);

elevatorStop();

firstPush();
delay(21000);

firstStop();

firstRetract();
delay(21000);

firstStop();

elevatorUp();
delay(10800);

elevatorStop();

secondPush();
delay(21000);

secondStop();

secondRetract();
delay(21000);

secondStop();

elevatorUp();
delay(11150);

elevatorStop();

}

void elevatorUp() {
    digitalWrite(elev_relay1, HIGH);
    digitalWrite(elev_relay2, LOW);
    digitalWrite(elev_relay3, HIGH);
    digitalWrite(elev_relay4, LOW);
}

void elevatorDown() {
    digitalWrite(elev_relay1, LOW);
    digitalWrite(elev_relay2, HIGH);
    digitalWrite(elev_relay3, LOW);
    digitalWrite(elev_relay4, HIGH);
}

void elevatorStop() {
    digitalWrite(elev_relay1, LOW);
    digitalWrite(elev_relay2, LOW);
    digitalWrite(elev_relay3, LOW);
    digitalWrite(elev_relay4, LOW);
}

void firstPush() {
    digitalWrite(first_relay1, HIGH);
    digitalWrite(first_relay2, LOW);
}

void firstRetract() {
    digitalWrite(first_relay1, LOW);
    digitalWrite(first_relay2, HIGH);
}

void firstStop() {
    digitalWrite(first_relay1, LOW);
    digitalWrite(first_relay2, LOW);
}

void secondPush() {
    digitalWrite(second_relay1, HIGH);
    digitalWrite(second_relay2, LOW);
}

void secondRetract() {
    digitalWrite(second_relay1, LOW);
    digitalWrite(second_relay2, HIGH);
}

void secondStop() {
    digitalWrite(second_relay1, LOW);
    digitalWrite(second_relay2, LOW);
}
void thirdPush() {
    digitalWrite(third_relay1, HIGH);
    digitalWrite(third_relay2, LOW);
}

void thirdRetract() {
    digitalWrite(third_relay1, LOW);
    digitalWrite(third_relay2, HIGH);
}

void thirdStop() {
    digitalWrite(third_relay1, LOW);
    digitalWrite(third_relay2, LOW);
}

void fourthPush() {
    digitalWrite(fourth_relay1, HIGH);
    digitalWrite(fourth_relay2, LOW);
}

void fourthRetract() {
    digitalWrite(fourth_relay1, LOW);
    digitalWrite(fourth_relay2, HIGH);
}

void fourthStop() {
    digitalWrite(fourth_relay1, LOW);
    digitalWrite(fourth_relay2, LOW);
}

 void loop() {

 }








