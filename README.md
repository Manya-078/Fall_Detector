# Fall_Detector
** Description:**
A compact, wearable Fall Detection System designed using ESP32, MPU6050 (Accelerometer + Gyroscope), and a Buzzer, built with the Arduino IDE. This device detects sudden falls or abnormal motion patterns and triggers an immediate alert via a buzzer to notify nearby individuals.

**🔧 Hardware Components:**

ESP32 Development Board
MPU6050 Accelerometer + Gyroscope Module
Active Buzzer
Jumper Wires
Breadboard (Optional for prototyping)
Display

**Software:**
Arduino IDE
Wire Library
MPU6050 Library

**📊 How It Works:**
The MPU6050 continuously monitors acceleration and angular velocity.
The ESP32 reads these values and compares them against preset fall-detection thresholds.
If a sudden, sharp change in motion (like a fall) is detected:
The buzzer is triggered.
Future versions can include notifications via Bluetooth, Wi-Fi, or mobile apps.

**📈 Future Enhancements:**
📲 Mobile app integration for remote alerts
🌐 Wi-Fi/Bluetooth-based emergency notifications
🔋 Battery management and power-saving features
📡 GPS module for location tracking in case of a fall

**📷 Project Demo:**
(https://drive.google.com/file/d/17A7WRr7LCSn77SUgE9N23FKthG12fCNU/view?usp=drivesdk )

**🔌 Connection Diagram (Text-based)**
**MPU6050 to ESP32**
VCC → 3.3V
GND → GND
SDA → GPIO 21
SCL → GPIO 22
**Buzzer to ESP32**
Positive (+) → GPIO 18
Negative (–) → GND

**🛠️ How to Set It Up**
1. Connect the Components:
2. Use jumper wires to make the above connections on a breadboard or directly to the ESP32’s header pins.
3. Install Libraries in Arduino IDE:
4. Open Arduino IDE
5. Go to Sketch → Include Library → Manage Libraries…
6. Search for MPU6050 and install it
7. Also install Wire.h if not already installed (usually preinstalled)
   
**Upload the Code:**
1. Connect your ESP32 to your PC via USB
2. Select the correct board from Tools → Board → ESP32 Dev Module
3. Select the correct port under Tools → Port
4. Upload your fall detection code 

**Test the System:**
Open Serial Monitor to view accelerometer values.
Shake or tilt the module to simulate a fall.
If the values exceed your set threshold, the buzzer will trigger.

**⚡ Pro Tip:**
👉 The MPU6050 is sensitive to voltage. Always connect its VCC to 3.3V on the ESP32.
👉 If you connect it to 5V, it may get damaged since ESP32 is a 3.3V logic device.
















