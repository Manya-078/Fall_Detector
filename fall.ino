#include <WiFi.h>
#include <MPU6050.h>
#include <Wire.h>
MPU6050 mpu;
#define buzzer 4

void setup()
{

  Wire.begin(2, 15); // SDA to GPIO 2, SCL to GPIO 15

  // Initialize MPU6050
  mpu.initialize();
  Serial.begin(115200);

  Serial.println(mpu.testConnection()  ? "MPU6050 connection successful" : "MPU6050 connection failed");
  pinMode(buzzer, OUTPUT);
  delay(10);


}
float prevAccX=0;
float prevAccY=0;
float prevAccZ=0;
const int sampleInterval = 100;
void loop(){
  int16_t ax, ay, az;

  mpu.getAcceleration(&ax, &ay, &az);
  float acceleration_mg_x = ax / 9.8;
  float acceleration_mg_y = ay / 9.8;
  float acceleration_mg_z = az / 9.8;
  float jerkX = (acceleration_mg_x - prevAccX) / (sampleInterval / 1000.0);
  float jerkY = (acceleration_mg_y - prevAccY) / (sampleInterval / 1000.0);
  float jerkZ = (acceleration_mg_z - prevAccZ) / (sampleInterval / 1000.0);
  prevAccX = acceleration_mg_x;
  prevAccY = acceleration_mg_y;
  prevAccZ = acceleration_mg_z;

    


    //  magnitude of jerk
  float jerkMagnitude = sqrt(jerkX * jerkX + jerkY * jerkY + jerkZ * jerkZ);
  Serial.println(jerkMagnitude);
    
  if (jerkMagnitude > 25000)
  {
      // Fall detected
    Serial.println("Fall detected!");

    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);

  }
}