#define PIR_input 9  
#define LED_output 13                      // LED can be replaced with an alarm
void setup()
{
  Serial.begin(9600);
  pinMode(PIR_input, INPUT);
  pinMode(LED_output, OUTPUT);
}
void loop()
{
  int temp;
  while(1)
  {
   temp=digitalRead(PIR_input);            //read the sensor value and then activate the GSM module along with the alarm.
   if(temp)
   {
    digitalWrite(LED_output,HIGH);        //alarm activation
    Serial.println("ATDXXXXXXXXXX;");     //replace XXXXXXXXXX with the 10 digit mobile number on which you want to send an alert via call.
   // SendAlertMsg                         // Uncomment this line to send a text msg instead of call !!
     delay(30000);                         // delay to allow the gsm (sim 900) module to make a call(set it according to the requirement).
   }
   else
   {
    digitalWrite(LED_output,LOW);
    delay(100);
   }
  }
}
void SendAlertMsg()
{
 Serial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
 delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); //replace XXXXXXXXXX with the 10 digit mobile number on which you want to send an alert via msg.
 delay(1000);
 Serial.println("Place your alert text here");// The SMS text you want to send
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
