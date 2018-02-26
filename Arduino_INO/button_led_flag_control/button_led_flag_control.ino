boolean butt_flag = 0;
boolean butt;
boolean led_flag = 0;
unsigned long last_press;
int btn = 3;
int led = 4;
void setup() {
  // put your setup code here, to run once:
pinMode(btn, INPUT_PULLUP); //button is here
pinMode(led, OUTPUT); //led is here
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
butt = !digitalRead(btn); // read current button position

if (butt == 1 && butt_flag == 0 && millis() - last_press > 100) {
  butt_flag = 1;
  Serial.println("Button Pressed");
  led_flag = !led_flag;
  digitalWrite(4, led_flag);
  last_press = millis();
}
if(butt == 0 && butt_flag == 1) {
  butt_flag = 0;
  Serial.println("Button Released");
}
}
