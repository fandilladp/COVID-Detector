//dibuat oleh Fandilla dimas prayoga
#include <dht.h>
dht DHT;

#define DHT11_PIN 7

int suara = 9;               //untuk modul suara
int led = 8;                //untuk pin led
long durasi, jarak;        // membuat variabel durasi dan jarak
char incominng_value = 0; //koneksi


void setup(){
Serial.begin(9600);
pinMode(suara, OUTPUT);
pinMode(led, OUTPUT); 
}

void loop(){

//sensor suhu
int chk = DHT.read11(DHT11_PIN);
int suhu = DHT.temperature ;
 if(suhu  >= 35){
     digitalWrite(led, HIGH);
      if(suhu >= 38){
          digitalWrite(suara, HIGH);
          digitalWrite(led, LOW);
          delay(300);  
          digitalWrite(led, HIGH);
          delay(300);  
          
        }else{
          digitalWrite(suara, LOW);
          
        }
 }else{
  digitalWrite(led, LOW);
 }
 
  //apk
 Serial.write(suhu);
  delay(2000);
}
