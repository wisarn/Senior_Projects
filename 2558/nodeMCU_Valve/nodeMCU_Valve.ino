#include <ESP8266WiFi.h>

#define Switches1 D1 //กำหนดขาที่ต่อ สวิก ให้น้ำ เป็นขา D1
#define LED2 D2 // เปิดไฟเมื่อ d1ไม่ทำงาน
#define Switches2 D3 // สวิต ให้ยา เป็นขา3
#define LED4 D4 // เปิดไฟเมื่อ d3 ไม่ทำงาน
#define LED3 D5 // ไฟ led กระพิบตลอดเวลาเมื่อมีการทำงาน
//const char* ssid = "Arduino Yun-90A2DAF0523C"; //กำหนด SSID (อย่าลืมแก้เป็นของตัวเอง)
const char* ssid = "Most Banhan";
 const char* password = "mosbanhan"; //กำหนด Password(อย่าลืมแก้เป็นของตัวเอง)
unsigned char status1_led = 0; //กำหนดตัวแปร ที่เก็บค่าสถานะของ LED
 unsigned char status2_led = 0;
 WiFiServer server(8081); //กำหนดใช้งาน TCP Server ที่ Port 80

void setup() {
 Serial.begin(115200); //เปิดใช้ Serial
 pinMode(Switches1, OUTPUT); //กำหนด Pin ที่ต่อกับ LED เป็น Output
 pinMode(Switches2, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED4, OUTPUT);
 pinMode(LED3, OUTPUT);
 Serial.println();
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password); //เชื่อมต่อกับ AP
 while (WiFi.status() != WL_CONNECTED) //รอการเชื่อมต่อ
{
delay(500);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected"); //แสดงข้อความเชื่อมต่อสำเร็จ 
server.begin(); //เปิด TCP Server
 Serial.println("Server started");
 Serial.println(WiFi.localIP()); // แสดงหมายเลข IP ของ Server
 }

void loop() {
 WiFiClient client = server.available(); //รอรับ การเชื่อมต่อจาก Client
 Serial.println(WiFi.localIP());
 delay(1000);

// status of valve
 if (status1_led==0) {
 digitalWrite(Switches1,HIGH); 
 digitalWrite(LED2,LOW);
 } 
 else {
 digitalWrite(LED2,HIGH); 
 digitalWrite(Switches1,LOW); 
 } 
 if (status2_led==0) {
 digitalWrite(Switches2,HIGH); 
 digitalWrite(LED4,LOW);
 } 
 else {
 digitalWrite(LED4,HIGH); 
 digitalWrite(Switches2,LOW); 
 } 

// running status 
 digitalWrite(LED3,HIGH);
 delay(500);
 digitalWrite(LED3,LOW);

if (!client) { //ถ้าไม่มี Client เข้ามาให้เริ่มกับไปวน loop รอรับใหม่
return;
 }

Serial.println("new client");
 while(!client.available())
 {
 Serial.println(WiFi.localIP());
 delay(1000);

}
 String req = client.readStringUntil('\r'); //อ่านค่าที่ได้รับจากclient จากข้อมูลแรกถึง ‘\r’ 
Serial.println(req); //แสดงค่าที่ได้รับทาง Serial
 client.flush();
 if (req.indexOf("/a0") != -1) //ตรวจสอบว่า data ที่เข้ามามีข้อความ”/ledoff”

{
status1_led=0; //ถ้ามีให้กำหนดค่า ในตัวแปรใน status_led=0
digitalWrite(Switches1,HIGH); //ให้ LED ดับ
digitalWrite(LED2,LOW); 
 Serial.println("LED OFF");
 }
 else if(req.indexOf("/a1") != -1) //ตรวจสอบว่า data ที่เข้ามามีข้อความ”/ledon”

{
status1_led=1; //ถ้ามีให้กำหนดค่า ในตัวแปรใน status_led=1
 digitalWrite(LED2,HIGH); //ให้ LED ติด
digitalWrite(Switches1,LOW); 
 Serial.println("LED ON");
 } 
 if (req.indexOf("/b0") != -1) //ตรวจสอบว่า data ที่เข้ามามีข้อความ”/ledoff”

{
status2_led=0; //ถ้ามีให้กำหนดค่า ในตัวแปรใน status_led=0
 digitalWrite(Switches2,HIGH); //ให้ LED ดับ
digitalWrite(LED4,LOW); 
 Serial.println("LED OFF");
 }
 else if(req.indexOf("/b1") != -1) //ตรวจสอบว่า data ที่เข้ามามีข้อความ”/ledon”

{
status2_led=1; //ถ้ามีให้กำหนดค่า ในตัวแปรใน status_led=1
 digitalWrite(LED4,HIGH); //ให้ LED ติด
digitalWrite(Switches2,LOW); 
 Serial.println("LED ON");
 } 
 //เก็บ Code HTML ลงในตัวแปรสตริง web
 String web = "HTTP/1.1 OK\r\nContent-Type: text/html\r\n\r\n";
 web += "<html>\r\n";
 web += "<body>\r\n";
 web += "<h1>LED Status</h1>\r\n";
 web += "<p>\r\n";
 if(status1_led==1) // ตรวจเช็คสถานะของ LED ว่า On หรือ Off
 web += "Vavle On\r\n";
 else
 web += "Vavle Off\r\n";
 web += "</p>\r\n";
 web += "</body>\r\n";
 web += "</html>\r\n";
 client.print(web); //ส่ง HTML Code ไปยัง client

 }

