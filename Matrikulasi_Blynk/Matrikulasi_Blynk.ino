#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6c93au1kM"
#define BLYNK_TEMPLATE_NAME "Tertanam"

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define LED_PIN LED_BUILTIN
bool ledState = false;
bool ledStateUpdated = true;
uint32_t tUpdate = 0;
#define DHTPIN D6  // Pemilihan Pin D2 dan pendeklarasian variabel
#define DHTTYPE DHT11 

char auth[] = "9sE4MidQJqHFnkqYUD591eWYkRmrOLSQ"; // masukkan kode autentikasi disini
char ssid[] = "ZTE_5G_qUbUL2"; //nama wifi
char pass[] = "XuDJDK65"; //password

BlynkTimer timer;
float t;
float h; 
DHT dht(DHTPIN, DHTTYPE);
void setup(){ //Pengaturan Variabel
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
}

void loop(){ //Perulangan Program
  Blynk.run();
  timer.run();
}

void sendSensor(){ //Pengaturan Variabel Sensor dan Virtual Pin
  h = dht.readHumidity();
  t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("KELEMBAPAN: "); Serial.println(h);
  Serial.print("SUHU      : "); Serial.println(t);
  Blynk.virtualWrite(V4, t);
  Blynk.virtualWrite(V5, h);
//  Blynk.virtualWrite(V3, t);
//  Blynk.virtualWrite(V4, h);
}
 

 
