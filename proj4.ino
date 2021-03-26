#include <Stepper.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <HTTPClient.h>
#define USE_SERIAL Serial

const int stepsPerRevolution = 128;  

int in1 = 14;
int in2 = 27;
int in3 = 26;
int in4 = 25;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, in1, in3, in2, in4);


Servo myservo;  // create servo object to control a servo

int servoPin = 15; // Servo motor pin


const char *ssid_Router     = "YOUR_ROUTER_NAME"; //Enter the router name
const char *password_Router = "YOUR_ROUTER_PASSWORD"; //Enter the router password

String address= "http://165.227.76.232:3000/ebv2109/running";

void setup() {
  myservo.setPeriodHertz(50);           // standard 50 hz servo
  myservo.attach(servoPin, 500, 2500);  // attaches the servo on servoPin to the servo object
  
  USE_SERIAL.begin(115200);
  WiFi.begin(ssid_Router, password_Router);
  USE_SERIAL.println(String("Connecting to ")+ssid_Router);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    USE_SERIAL.print(".");
  }
  USE_SERIAL.println("\nConnected, IP address: ");
  USE_SERIAL.println(WiFi.localIP());
  USE_SERIAL.println("Setup End");
}

void loop() {
  if((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    http.begin(address);
 
    int httpCode = http.GET(); // start connection and send HTTP header
    if (httpCode == HTTP_CODE_OK) { 
        String response = http.getString();
        if (response.equals("false")) {
            // Do not run sculpture, perhaps sleep for a couple seconds
            delay(2000);
        }
        else if(response.equals("true")) {
            // Run sculpture
            myStepper.setSpeed(120);         
                       
            myservo.write(10);                          //E
            delay(200);
            myservo.write(0);
            //delay(500);
            
            myStepper.step(stepsPerRevolution);         //D
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);
            //delay(500);
            
            myStepper.step(stepsPerRevolution);         //C
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);
            //delay(500);
            
            myStepper.step(-stepsPerRevolution);        //D
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);
            //delay(500);
            
            myStepper.step(-stepsPerRevolution);        //E
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);
            
            delay(250);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            delay(250);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            myStepper.step(stepsPerRevolution);       //D
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);
            
            delay(250);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            delay(250);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            myStepper.step(-stepsPerRevolution);      //E
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);
            
            delay(250);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            delay(250);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            delay(600);                  
            myservo.write(10);                          //E
            delay(200);
            myservo.write(0);
            
            myStepper.step(stepsPerRevolution);         //D
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);
            
            myStepper.step(stepsPerRevolution);         //C
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);
            
            myStepper.step(-stepsPerRevolution);        //D
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);
            //delay(500);
            
            myStepper.step(-stepsPerRevolution);        //E
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);
            
            delay(250);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            delay(250);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            delay(250);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            myStepper.step(stepsPerRevolution);         //D
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            delay(250);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            myStepper.step(-stepsPerRevolution);        //E
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            myStepper.step(stepsPerRevolution);         //D
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            myStepper.step(stepsPerRevolution);         //C
            delay(200);
            myservo.write(10);
            delay(200);
            myservo.write(0);

            myStepper.step(-(2*stepsPerRevolution));
        }
        USE_SERIAL.println("Response was: " + response);
    } else {
        USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
    delay(500); // sleep for half of a second
  }
}
