/*****************  NEEDED TO MAKE NODEMCU WORK ***************************/
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ESP8266_RAW_PIN_ORDER

/******************  LIBRARY SECTION *************************************/

#include <FastLED.h>        //https://github.com/FastLED/FastLED
#include <SimpleTimer.h>    //https://github.com/thehookup/Simple-Timer-Library
#include <PubSubClient.h>   //https://github.com/knolleary/pubsubclient
#include <ESP8266WiFi.h>    //if you get an error here you need to install the ESP8266 board manager 
#include <ESP8266mDNS.h>    //if you get an error here you need to install the ESP8266 board manager 
#include <ArduinoOTA.h>     //ArduinoOTA is now included with the ArduinoIDE

/*****************  START USER CONFIG SECTION *********************************/
 
#define USER_SSID                 "YOUR_WIRELESS_SSID"
#define USER_PASSWORD             "YOUR_WIRELESS_PW"
#define USER_MQTT_SERVER          "YOUR_MQTT_SERVER_ADDRESS"
#define USER_MQTT_PORT            1883
#define USER_MQTT_USERNAME        "YOUR_MQTT_USERNAME"
#define USER_MQTT_PASSWORD        "YOUR_MQTT_PASSWORD"
#define USER_MQTT_CLIENT_NAME     "LightMCU"           // Used to define MQTT topics, MQTT Client ID, and ArduinoOTA


#define ZONEONE                         1                   //ZONEONE is pin D1, 1 = zone used 0 = zone unused
#define FIRSTZONE_SECTIONS              1                   //Number of roof sections setup below
#define FIRSTZONE_LEDS                  300                 //Number of LEDS in this zone 
#define FIRSTZONE_COLOR_ORDER           GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR 

#define ZONETWO                         1                   //ZONETWO is pin D2, 1 = zone used 0 = zone unused
#define SECONDZONE_SECTIONS             3                   //Number of roof sections setup below
#define SECONDZONE_LEDS                 389                 //Number of LEDS in this zone 
#define SECONDZONE_COLOR_ORDER          GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR 

#define ZONETHREE                       1                   //ZONETHREE is pin D3, 1 = zone used 0 = zone unused
#define THIRDZONE_SECTIONS              1                   //Number of roof sections setup below
#define THIRDZONE_LEDS                  300                 //Number of LEDS in this zone 
#define THIRDZONE_COLOR_ORDER           GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR 

#define ZONEFOUR                        1                   //ZONEFOUR is pin D5, 1 = zone used 0 = zone unused
#define FOURTHZONE_SECTIONS             1                   //Number of roof sections setup below
#define FOURTHZONE_LEDS                 300                 //Number of LEDS in this zone 
#define FOURTHZONE_COLOR_ORDER          GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR 

#define ZONEFIVE                        1                   //ZONEFIVE is pin D6, 1 = zone used 0 = zone unused
#define FIFTHZONE_SECTIONS              1                   //Number of roof sections setup below
#define FIFTHZONE_LEDS                  300                 //Number of LEDS in this zone 
#define FIFTHZONE_COLOR_ORDER           GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR

#define ZONESIX                         1                   //ZONESIX is pin D7, 1 = zone used 0 = zone unused
#define SIXTHZONE_SECTIONS              1                   //Number of roof sections setup below
#define SIXTHZONE_LEDS                  300                 //Number of LEDS in this zone 
#define SIXTHZONE_COLOR_ORDER           GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR 

/*****************************    ZONEONE ROOF SETUP    *************************************/
/*****************************    ZONEONE ROOF SETUP    *************************************/

#if  FIRSTZONE_SECTIONS >= 1        
#define ZONEONE_SECTION1_START            0           //starting LED for this zone
#define ZONEONE_SECTION1_END              100         //ending LED for this zone
#define ZONEONE_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 2
#define ZONEONE_SECTION2_START            0           //starting LED for this zone
#define ZONEONE_SECTION2_END              100         //ending LED for this zone
#define ZONEONE_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 3
#define ZONEONE_SECTION3_START            0           //starting LED for this zone
#define ZONEONE_SECTION3_END              100         //ending LED for this zone
#define ZONEONE_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 4
#define ZONEONE_SECTION4_START            0           //starting LED for this zone
#define ZONEONE_SECTION4_END              100         //ending LED for this zone
#define ZONEONE_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 5
#define ZONEONE_SECTION5_START            0           //starting LED for this zone
#define ZONEONE_SECTION5_END              100         //ending LED for this zone
#define ZONEONE_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 6
#define ZONEONE_SECTION6_START            0           //starting LED for this zone
#define ZONEONE_SECTION6_END              100         //ending LED for this zone
#define ZONEONE_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 7
#define ZONEONE_SECTION7_START            0          //starting LED for this zone
#define ZONEONE_SECTION7_END              100        //ending LED for this zone
#define ZONEONE_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 8
#define ZONEONE_SECTION8_START            0          //starting LED for this zone
#define ZONEONE_SECTION8_END              100        //ending LED for this zone
#define ZONEONE_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 9
#define ZONEONE_SECTION9_START            0          //starting LED for this zone
#define ZONEONE_SECTION9_END              100        //ending LED for this zone
#define ZONEONE_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

/*****************************    ZONETWO ROOF SETUP    *************************************/
/*****************************    ZONETWO ROOF SETUP    *************************************/

#if  SECONDZONE_SECTIONS >= 1        
#define ZONETWO_SECTION1_START            0           //starting LED for this zone
#define ZONETWO_SECTION1_END              44         //ending LED for this zone
#define ZONETWO_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 2
#define ZONETWO_SECTION2_START            44           //starting LED for this zone
#define ZONETWO_SECTION2_END              87         //ending LED for this zone
#define ZONETWO_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 3
#define ZONETWO_SECTION3_START            88           //starting LED for this zone
#define ZONETWO_SECTION3_END              94         //ending LED for this zone
#define ZONETWO_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 4
#define ZONETWO_SECTION4_START            95           //starting LED for this zone
#define ZONETWO_SECTION4_END              182         //ending LED for this zone
#define ZONETWO_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 5
#define ZONETWO_SECTION5_START            183           //starting LED for this zone
#define ZONETWO_SECTION5_END              189         //ending LED for this zone
#define ZONETWO_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 6
#define ZONETWO_SECTION6_START            190           //starting LED for this zone
#define ZONETWO_SECTION6_END              286         //ending LED for this zone
#define ZONETWO_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 7
#define ZONETWO_SECTION7_START            287          //starting LED for this zone
#define ZONETWO_SECTION7_END              382        //ending LED for this zone
#define ZONETWO_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 8
#define ZONETWO_SECTION8_START            0          //starting LED for this zone
#define ZONETWO_SECTION8_END              100        //ending LED for this zone
#define ZONETWO_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 9
#define ZONETWO_SECTION9_START            0          //starting LED for this zone
#define ZONETWO_SECTION9_END              100        //ending LED for this zone
#define ZONETWO_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif


/*****************************    ZONETHREE ROOF SETUP    *************************************/
/*****************************    ZONETHREE ROOF SETUP    *************************************/

#if  THIRDZONE_SECTIONS >= 1        
#define ZONETHREE_SECTION1_START            0           //starting LED for this zone
#define ZONETHREE_SECTION1_END              100         //ending LED for this zone
#define ZONETHREE_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 2
#define ZONETHREE_SECTION2_START            0           //starting LED for this zone
#define ZONETHREE_SECTION2_END              100         //ending LED for this zone
#define ZONETHREE_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 3
#define ZONETHREE_SECTION3_START            0           //starting LED for this zone
#define ZONETHREE_SECTION3_END              100         //ending LED for this zone
#define ZONETHREE_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 4
#define ZONETHREE_SECTION4_START            0           //starting LED for this zone
#define ZONETHREE_SECTION4_END              100         //ending LED for this zone
#define ZONETHREE_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 5
#define ZONETHREE_SECTION5_START            0           //starting LED for this zone
#define ZONETHREE_SECTION5_END              100         //ending LED for this zone
#define ZONETHREE_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 6
#define ZONETHREE_SECTION6_START            0           //starting LED for this zone
#define ZONETHREE_SECTION6_END              100         //ending LED for this zone
#define ZONETHREE_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 7
#define ZONETHREE_SECTION7_START            0          //starting LED for this zone
#define ZONETHREE_SECTION7_END              100        //ending LED for this zone
#define ZONETHREE_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 8
#define ZONETHREE_SECTION8_START            0          //starting LED for this zone
#define ZONETHREE_SECTION8_END              100        //ending LED for this zone
#define ZONETHREE_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 9
#define ZONETHREE_SECTION9_START            0          //starting LED for this zone
#define ZONETHREE_SECTION9_END              100        //ending LED for this zone
#define ZONETHREE_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

/*****************************    ZONEFOUR ROOF SETUP    *************************************/
/*****************************    ZONEFOUR ROOF SETUP    *************************************/

#if  FOURTHZONE_SECTIONS >= 1        
#define ZONEFOUR_SECTION1_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION1_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 2
#define ZONEFOUR_SECTION2_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION2_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 3
#define ZONEFOUR_SECTION3_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION3_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 4
#define ZONEFOUR_SECTION4_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION4_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 5
#define ZONEFOUR_SECTION5_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION5_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 6
#define ZONEFOUR_SECTION6_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION6_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 7
#define ZONEFOUR_SECTION7_START            0          //starting LED for this zone
#define ZONEFOUR_SECTION7_END              100        //ending LED for this zone
#define ZONEFOUR_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 8
#define ZONEFOUR_SECTION8_START            0          //starting LED for this zone
#define ZONEFOUR_SECTION8_END              100        //ending LED for this zone
#define ZONEFOUR_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 9
#define ZONEFOUR_SECTION9_START            0          //starting LED for this zone
#define ZONEFOUR_SECTION9_END              100        //ending LED for this zone
#define ZONEFOUR_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif


/*****************************    ZONEFIVE ROOF SETUP    *************************************/
/*****************************    ZONEFIVE ROOF SETUP    *************************************/

#if  FIFTHZONE_SECTIONS >= 1        
#define ZONEFIVE_SECTION1_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION1_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 2
#define ZONEFIVE_SECTION2_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION2_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 3
#define ZONEFIVE_SECTION3_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION3_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 4
#define ZONEFIVE_SECTION4_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION4_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 5
#define ZONEFIVE_SECTION5_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION5_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 6
#define ZONEFIVE_SECTION6_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION6_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 7
#define ZONEFIVE_SECTION7_START            0          //starting LED for this zone
#define ZONEFIVE_SECTION7_END              100        //ending LED for this zone
#define ZONEFIVE_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 8
#define ZONEFIVE_SECTION8_START            0          //starting LED for this zone
#define ZONEFIVE_SECTION8_END              100        //ending LED for this zone
#define ZONEFIVE_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 9
#define ZONEFIVE_SECTION9_START            0          //starting LED for this zone
#define ZONEFIVE_SECTION9_END              100        //ending LED for this zone
#define ZONEFIVE_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif


/*****************************    ZONESIX ROOF SETUP    *************************************/
/*****************************    ZONESIX ROOF SETUP    *************************************/

#if  SIXTHZONE_SECTIONS >= 1        
#define ZONESIX_SECTION1_START            0           //starting LED for this zone
#define ZONESIX_SECTION1_END              100         //ending LED for this zone
#define ZONESIX_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 2
#define ZONESIX_SECTION2_START            0           //starting LED for this zone
#define ZONESIX_SECTION2_END              100         //ending LED for this zone
#define ZONESIX_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 3
#define ZONESIX_SECTION3_START            0           //starting LED for this zone
#define ZONESIX_SECTION3_END              100         //ending LED for this zone
#define ZONESIX_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 4
#define ZONESIX_SECTION4_START            0           //starting LED for this zone
#define ZONESIX_SECTION4_END              100         //ending LED for this zone
#define ZONESIX_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 5
#define ZONESIX_SECTION5_START            0           //starting LED for this zone
#define ZONESIX_SECTION5_END              100         //ending LED for this zone
#define ZONESIX_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 6
#define ZONESIX_SECTION6_START            0           //starting LED for this zone
#define ZONESIX_SECTION6_END              100         //ending LED for this zone
#define ZONESIX_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 7
#define ZONESIX_SECTION7_START            0          //starting LED for this zone
#define ZONESIX_SECTION7_END              100        //ending LED for this zone
#define ZONESIX_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 8
#define ZONESIX_SECTION8_START            0          //starting LED for this zone
#define ZONESIX_SECTION8_END              100        //ending LED for this zone
#define ZONESIX_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 9
#define ZONESIX_SECTION9_START            0          //starting LED for this zone
#define ZONESIX_SECTION9_END              100        //ending LED for this zone
#define ZONESIX_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif


/*****************  END USER CONFIG SECTION *********************************/


/***********************  WIFI AND MQTT SETUP *****************************/
/***********************  DON'T CHANGE THIS INFO *****************************/

const char* ssid = USER_SSID ; 
const char* password = USER_PASSWORD ;
const char* mqtt_server = USER_MQTT_SERVER ;
const int mqtt_port = USER_MQTT_PORT ;
const char *mqtt_user = USER_MQTT_USERNAME ;
const char *mqtt_pass = USER_MQTT_PASSWORD ;
const char *mqtt_client_name = USER_MQTT_CLIENT_NAME ; 

/*****************  DECLARATIONS  ****************************************/
WiFiClient espClient;
PubSubClient client(espClient);
SimpleTimer timer;

struct Ball {
  float position;
  float velocity;
  bool loaded;
  bool reverse;
  CRGB color;
  int exploding;
  float particlePosition;
};

#if ZONEONE == 1
CRGB firstZone[FIRSTZONE_LEDS];
const int Pin_firstZone = 5; //marked as D1 on the board
int center_firstZone = 25;
int step_firstZone = -1;
int previousLED_firstZone = 0;
const int fireworkCount_firstZone = 1;
#endif

#if ZONETWO == 1
CRGB secondZone[SECONDZONE_LEDS];
const int Pin_secondZone = 4; //marked as D2 on the board
int center_secondZone = 0;
int step_secondZone = -1;
int previousLED_secondZone = 0;
const int fireworkCount_secondZone = 3;
#endif

#if ZONETHREE == 1
CRGB thirdZone[THIRDZONE_LEDS];
const int Pin_thirdZone = 0; //marked as D3 on the board
int center_thirdZone = 0;
int step_thirdZone = -1;
int previousLED_thirdZone = 0;
const int fireworkCount_thirdZone = 1;
#endif

#if ZONEFOUR == 1
CRGB fourthZone[FOURTHZONE_LEDS];
const int Pin_fourthZone = 14; //marked as D5 on the board
int center_fourthZone = 0;
int step_fourthZone = -1;
int previousLED_fourthZone = 0;
const int fireworkCount_fourthZone = 1;
#endif

#if ZONEFIVE == 1
CRGB fifthZone[FIFTHZONE_LEDS];
const int Pin_fifthZone = 12; //marked as D6 on the board
int center_fifthZone = 0;
int step_fifthZone = -1;
int previousLED_fifthZone = 0;
const int fireworkCount_fifthZone = 1;
#endif

#if ZONESIX == 1
CRGB sixthZone[SIXTHZONE_LEDS];
const int Pin_sixthZone = 13; //marked as D7 on the board
int center_sixthZone = 0;
int step_sixthZone = -1;
int previousLED_sixthZone = 0;
const int fireworkCount_sixthZone = 1;
#endif


/*****************  GENERAL VARIABLES  *************************************/

CRGBPalette16 gPal;
int glitterFrequency = 100;
int lightningChance = 65280;
int SPARKING = 85;
int COOLING =  120;
bool gReverseDirection = false;
uint8_t mark = 0;
uint8_t gHue = 0; 
int lastPosition = 1;
int lightning = 1;
bool boot = true;
bool showGlitter = false;
bool showLightning = false;
bool audioEffects = false;
byte red1 = 255;
byte green1 = 0;
byte blue1 = 0;
byte red2 = 0;
byte green2 = 255;
byte blue2 = 0;
byte red3 = 0;
byte green3 = 0;
byte blue3 = 255;
byte redG = 255;
byte greenG = 255;
byte blueG = 255;
char charPayload[50];
int maxLEDs = 500;
int locatorLED = 0;
char MQTT_locatorLED[50];
int locatorDelay = 1000;
String zoneEffects[6] = {"None","None","None","None","None","None"};
int zoneModifer[6] = { 100, 100, 100, 100, 100, 100 };
byte zoneBrightness[6] = {255,255,255,255,255,255};
uint8_t zoneStartPosition[6] = { 0, 0, 0, 0, 0, 0 };
bool showZoneLights[6] = { false, false, false, false, false, false };
const int colorsCount = 5;
String colorStates[colorsCount+1] = { "broken", "ON", "ON", "ON", "OFF", "OFF" };
byte rgbArray[colorsCount][3] = {{255,0,0},{255,0,0},{255,0,0},{255,0,0},{255,0,0}};
uint8_t colorsEnabled = 3;
CRGB availableColors[5] = {};


/*****************  SYSTEM FUNCTIONS  *************************************/
/*****************  SYSTEM FUNCTIONS  *************************************/
/*****************  SYSTEM FUNCTIONS  *************************************/
/*****************  SYSTEM FUNCTIONS  *************************************/
/*****************  SYSTEM FUNCTIONS  *************************************/

void setup_wifi() 
{
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.hostname(USER_MQTT_CLIENT_NAME);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() 
{
  // Loop until we're reconnected
  int retries = 0;
  while (!client.connected()) {
    if(retries < 150)
    {
        Serial.print("Attempting MQTT connection...");
      // Attempt to connect
      if (client.connect(mqtt_client_name, mqtt_user, mqtt_pass)) 
      {
        Serial.println("connected");
        // Once connected, publish an announcement...
        if(boot == true)
        {
          client.publish(USER_MQTT_CLIENT_NAME"/checkIn","Rebooted");
          boot = false;
        }
        if(boot == false)
        {
          client.publish(USER_MQTT_CLIENT_NAME"/checkIn","Reconnected"); 
        }
        publishStates();
        // ... and resubscribe
        client.subscribe(USER_MQTT_CLIENT_NAME"/configure");
        client.subscribe(USER_MQTT_CLIENT_NAME"/modifier");
        client.subscribe(USER_MQTT_CLIENT_NAME"/modifier/+");
        client.subscribe(USER_MQTT_CLIENT_NAME"/effect");
        client.subscribe(USER_MQTT_CLIENT_NAME"/effect/+");
        client.subscribe(USER_MQTT_CLIENT_NAME"/state");
        client.subscribe(USER_MQTT_CLIENT_NAME"/ColorSelector/+/Toggle");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color1");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color2");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color3");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color4");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color5");
        client.subscribe(USER_MQTT_CLIENT_NAME"/power");
        client.subscribe(USER_MQTT_CLIENT_NAME"/power/+");
        client.subscribe(USER_MQTT_CLIENT_NAME"/brightness");
        client.subscribe(USER_MQTT_CLIENT_NAME"/brightness/+");
        client.subscribe(USER_MQTT_CLIENT_NAME"/addEffects");
        client.subscribe(USER_MQTT_CLIENT_NAME"/lightningChance");
        client.subscribe(USER_MQTT_CLIENT_NAME"/glitterChance");
        client.subscribe(USER_MQTT_CLIENT_NAME"/glitterColor");
      } 
      else 
      {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        retries++;
        // Wait 5 seconds before retrying
        delay(5000);
      }
    }
    if(retries > 1500)
    {
    ESP.restart();
    }
  }
}

void calculateMax()
{
  #if ZONEONE == 1
  maxLEDs = FIRSTZONE_LEDS;
  #endif
  
  #if ZONETWO == 1
  maxLEDs = max(FIRSTZONE_LEDS, SECONDZONE_LEDS);
  #endif

  #if ZONETHREE == 1
  maxLEDs = max(maxLEDs, THIRDZONE_LEDS);
  #endif

  #if ZONEFOUR == 1
  maxLEDs = max(maxLEDs, FOURTHZONE_LEDS);
  #endif

  #if ZONEFIVE == 1
  maxLEDs = max(maxLEDs, FIFTHZONE_LEDS);
  #endif

  #if ZONESIX == 1
  maxLEDs = max(maxLEDs, SIXTHZONE_LEDS);
  #endif 
}

String boolToOnOff(bool setting)
{
  String state = "OFF";
  if(setting == true)
  {
    state = ("ON");
  }
  
  return state;
}

void publishStates()
{
  char buff[50];
  client.publish(USER_MQTT_CLIENT_NAME"/modifierState", itoa(zoneModifer[0], buff, 10));
  client.publish(USER_MQTT_CLIENT_NAME"/audio/state", boolToOnOff(audioEffects).c_str());
  client.publish(USER_MQTT_CLIENT_NAME"/glitter/state", boolToOnOff(showGlitter).c_str());
  client.publish(USER_MQTT_CLIENT_NAME"/lightning/state", boolToOnOff(showLightning).c_str());
  client.publish(USER_MQTT_CLIENT_NAME"/effectState", zoneEffects[0].c_str());
  client.publish(USER_MQTT_CLIENT_NAME "/color1State", String(String(red1) + "," + String(green1) + "," + String(blue1)).c_str()); 
  client.publish(USER_MQTT_CLIENT_NAME "/color2State", String(String(red2) + "," + String(green2) + "," + String(blue2)).c_str()); 
  client.publish(USER_MQTT_CLIENT_NAME "/color3State", String(String(red3) + "," + String(green3) + "," + String(blue3)).c_str()); 
  client.publish(USER_MQTT_CLIENT_NAME "/glitterColorState", String(String(redG) + "," + String(greenG) + "," + String(blueG)).c_str()); 
  client.publish(USER_MQTT_CLIENT_NAME "/glitterChanceState", itoa(glitterFrequency, buff, 10)); 
  client.publish(USER_MQTT_CLIENT_NAME "/lightningChanceState", itoa(65535-lightningChance, buff, 10)); 
  client.publish(USER_MQTT_CLIENT_NAME "/brightnessState", itoa(zoneBrightness[0], buff, 10)); 
  client.publish(USER_MQTT_CLIENT_NAME "/powerState",  boolToOnOff(showZoneLights[0]).c_str());
  
  #if ZONEONE == 1
  client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone1", itoa(zoneModifer[0], buff, 10));
  client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone1", boolToOnOff(showZoneLights[0]).c_str());
  client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone1", zoneEffects[0].c_str());
  client.publish(USER_MQTT_CLIENT_NAME "/brightnessStateZone1", itoa(zoneBrightness[0], buff, 10));
  #endif
  #if ZONETWO == 1
  client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone2", itoa(zoneModifer[1], buff, 10));
  client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone2", boolToOnOff(showZoneLights[1]).c_str());
  client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone2", zoneEffects[1].c_str());
  client.publish(USER_MQTT_CLIENT_NAME "/brightnessStateZone2", itoa(zoneBrightness[1], buff, 10));  
  #endif
  #if ZONETHREE == 1
  client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone3", itoa(zoneModifer[2], buff, 10));
  client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone3", boolToOnOff(showZoneLights[2]).c_str());
  client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone3", zoneEffects[2].c_str());
  client.publish(USER_MQTT_CLIENT_NAME "/brightnessStateZone3", itoa(zoneBrightness[2], buff, 10));
  #endif
  #if ZONEFOUR == 1
  client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone4", itoa(zoneModifer[3], buff, 10));
  client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone4", boolToOnOff(showZoneLights[3]).c_str());
  client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone4", zoneEffects[3].c_str());
  client.publish(USER_MQTT_CLIENT_NAME "/brightnessStateZone4", itoa(zoneBrightness[3], buff, 10));
  #endif
  #if ZONEFIVE == 1
  client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone5", itoa(zoneModifer[4], buff, 10));
  client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone5", boolToOnOff(showZoneLights[4]).c_str());
  client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone5", zoneEffects[4].c_str());
  client.publish(USER_MQTT_CLIENT_NAME "/brightnessStateZone5", itoa(zoneBrightness[4], buff, 10));
  #endif
  #if ZONESIX == 1
  client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone6", itoa(zoneModifer[5], buff, 10));
  client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone6", boolToOnOff(showZoneLights[5]).c_str());
  client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone6", zoneEffects[5].c_str());
  client.publish(USER_MQTT_CLIENT_NAME "/brightnessStateZone6", itoa(zoneBrightness[5], buff, 10));
  #endif
}

/************************** MQTT CALLBACK ***********************/


void callback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Message arrived [");
  String newTopic = topic;
  Serial.print(topic);
  Serial.print("] ");
  payload[length] = '\0';
  String newPayload = String((char *)payload);
  int intPayload = newPayload.toInt();
  Serial.println(newPayload);
  Serial.println();
  newPayload.toCharArray(charPayload, newPayload.length() + 1); 
  if (newTopic == USER_MQTT_CLIENT_NAME"/modifier")
  {
    for (byte i = 0; i < 6; i = i + 1) {
      zoneModifer[i] = intPayload;
    }
    client.publish(USER_MQTT_CLIENT_NAME"/modifierState", charPayload);

    locatorDelay = map(intPayload, 0, 500, 500, 5000);
  }
  #if ZONEONE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/modifier/Zone1")
  {
    zoneModifer[0] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone1", charPayload);
  }
  #endif
  #if ZONETWO == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/modifier/Zone2")
  {
    zoneModifer[1] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone2", charPayload);
  }
  #endif
  #if ZONETHREE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/modifier/Zone3")
  {
    zoneModifer[2] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone3", charPayload);
  }
  #endif
  #if ZONEFOUR == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/modifier/Zone4")
  {
    zoneModifer[3] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone4", charPayload);
  }
  #endif
  #if ZONEFIVE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/modifier/Zone5")
  {
    zoneModifer[4] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone5", charPayload);
  }
  #endif
  #if ZONESIX == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/modifier/Zone6")
  {
    zoneModifer[5] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME"/modifierState/Zone6", charPayload);
  }
  #endif
  if (newTopic == USER_MQTT_CLIENT_NAME"/addEffects")
  {
    if(newPayload == "Audio On")
    {
      audioEffects = true;
      client.publish(USER_MQTT_CLIENT_NAME"/audio/state", charPayload);
    }
    if(newPayload == "Audio Off")
    {
      audioEffects = false;
      client.publish(USER_MQTT_CLIENT_NAME"/audio/state", charPayload);
    }
    if(newPayload == "Glitter On")
    {
      showGlitter = true;
      client.publish(USER_MQTT_CLIENT_NAME"/glitter/state", charPayload);
    }
    if(newPayload == "Glitter Off")
    {
      showGlitter = false;
      client.publish(USER_MQTT_CLIENT_NAME"/glitter/state", charPayload);
    }
    if(newPayload == "Lightning On")
    {
      showLightning = true;
      client.publish(USER_MQTT_CLIENT_NAME"/lightning/state","Lightning On");
    }
    if(newPayload == "Lightning Off")
    {
      showLightning = false;
      client.publish(USER_MQTT_CLIENT_NAME"/lightning/state","Lightning Off");
    }
  }
  if (newTopic == USER_MQTT_CLIENT_NAME"/effect") 
  {
    zoneEffects[0] = newPayload;
    client.publish(USER_MQTT_CLIENT_NAME"/effectState", charPayload);
    
    if(newPayload == "LED_Locator")
    {
      locator_Move();
    }
  }

  #if ZONEONE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/effect/Zone1" || newTopic == USER_MQTT_CLIENT_NAME"/effect") 
  {
    zoneEffects[0] = newPayload;
    fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::Black); 
    client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone1", charPayload);
  }
  #endif 

  #if ZONETWO == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/effect/Zone2" || newTopic == USER_MQTT_CLIENT_NAME"/effect") 
  {
    zoneEffects[1] = newPayload;
    fill_solid(secondZone, SECONDZONE_LEDS, CRGB::Black);
    client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone2", charPayload);
  } 
  #endif

  #if ZONETHREE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/effect/Zone3" || newTopic == USER_MQTT_CLIENT_NAME"/effect") 
  {
    zoneEffects[2] = newPayload;
    fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::Black);
    client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone3", charPayload);
  }
  #endif

  #if ZONEFOUR == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/effect/Zone4" || newTopic == USER_MQTT_CLIENT_NAME"/effect") 
  {
    zoneEffects[3] = newPayload;
    fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::Black);
    client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone4", charPayload);
  }
  #endif

  #if ZONEFIVE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/effect/Zone5" || newTopic == USER_MQTT_CLIENT_NAME"/effect") 
  {
    zoneEffects[4] = newPayload;
    fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::Black);
    client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone5", charPayload);
  }
  #endif
    
  #if ZONESIX == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/effect/Zone6" || newTopic == USER_MQTT_CLIENT_NAME"/effect") 
  {
    zoneEffects[5] = newPayload;
    fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::Black);
    client.publish(USER_MQTT_CLIENT_NAME"/effectState/Zone6", charPayload);
  }
  #endif

  if (newTopic == USER_MQTT_CLIENT_NAME "/ColorSelector/1/Toggle")
  {
      colorStates[1] = newPayload;
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/1/ToggleState", colorStates[1].c_str());
  }
  
  if (newTopic == USER_MQTT_CLIENT_NAME "/ColorSelector/2/Toggle")
  {
      colorStates[2] = newPayload;
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/2/ToggleState", colorStates[2].c_str());
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/ColorSelector/3/Toggle")
  {
      colorStates[3] = newPayload;
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/3/ToggleState", colorStates[3].c_str());
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/ColorSelector/4/Toggle")
  {
      colorStates[4] = newPayload;
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/4/ToggleState", colorStates[4].c_str());
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/ColorSelector/5/Toggle")
  {
      colorStates[5] = newPayload;
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/5/ToggleState", colorStates[5].c_str());
  }
  
  if (newTopic == USER_MQTT_CLIENT_NAME "/color1")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/color1State", charPayload); 
    // get the position of the first and second commas
    uint8_t firstIndex = newPayload.indexOf(',');
    uint8_t lastIndex = newPayload.lastIndexOf(',');
    
    uint8_t rgb_red = newPayload.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;
    } else {
      red1 = rgb_red;
      rgbArray[0][0] = rgb_red;
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      green1 = rgb_green;
      rgbArray[0][1] = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blue1 = rgb_blue;
      rgbArray[0][2] = rgb_blue;
    }
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/color2")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/color2State", charPayload); 
    // get the position of the first and second commas
    uint8_t firstIndex = newPayload.indexOf(',');
    uint8_t lastIndex = newPayload.lastIndexOf(',');
    
    uint8_t rgb_red = newPayload.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;
    } else {
      red2 = rgb_red;
      rgbArray[1][0] = rgb_red;
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      green2 = rgb_green;
      rgbArray[1][1] = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blue2 = rgb_blue;
      rgbArray[1][2] = rgb_blue;
    }
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/color3")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/color3State", charPayload); 
    // get the position of the first and second commas
    uint8_t firstIndex = newPayload.indexOf(',');
    uint8_t lastIndex = newPayload.lastIndexOf(',');
    
    uint8_t rgb_red = newPayload.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;
    } else {
      red3 = rgb_red;
      rgbArray[2][0] = rgb_red;
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      green3 = rgb_green;
      rgbArray[2][1] = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blue3 = rgb_blue;
      rgbArray[2][2] = rgb_blue;
    }
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/color4")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/color4State", charPayload); 
    // get the position of the first and second commas
    uint8_t firstIndex = newPayload.indexOf(',');
    uint8_t lastIndex = newPayload.lastIndexOf(',');
    
    uint8_t rgb_red = newPayload.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;
    } else {
      rgbArray[3][0] = rgb_red;
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      rgbArray[3][1] = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      rgbArray[3][2] = rgb_blue;
    }
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/color5")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/color5State", charPayload); 
    // get the position of the first and second commas
    uint8_t firstIndex = newPayload.indexOf(',');
    uint8_t lastIndex = newPayload.lastIndexOf(',');
    
    uint8_t rgb_red = newPayload.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;
    } else {
      rgbArray[4][0] = rgb_red;
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      rgbArray[4][1] = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      rgbArray[4][2] = rgb_blue;
    }
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/glitterColor")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/glitterColorState", charPayload); 
    // get the position of the first and second commas
    uint8_t firstIndex = newPayload.indexOf(',');
    uint8_t lastIndex = newPayload.lastIndexOf(',');
    
    uint8_t rgb_red = newPayload.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;
    } else {
      redG = rgb_red;
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      greenG = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blueG = rgb_blue;
    }
  }
  
  if (newTopic == USER_MQTT_CLIENT_NAME"/glitterChance") 
  {
    client.publish(USER_MQTT_CLIENT_NAME "/glitterChanceState", charPayload); 
    glitterFrequency = intPayload;
  }
  
  if (newTopic == USER_MQTT_CLIENT_NAME"/lightningChance") 
  {
    client.publish(USER_MQTT_CLIENT_NAME "/lightningChanceState", charPayload); 
    lightningChance = (65535 - intPayload);
  }
  
  if (newTopic == USER_MQTT_CLIENT_NAME"/brightness") 
  {
    zoneBrightness[0] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME "/brightnessState", itoa(zoneBrightness[0], charPayload, 10));
  }
  #if ZONEONE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/brightness/Zone1" || newTopic == USER_MQTT_CLIENT_NAME"/brightness") 
  {
    zoneBrightness[0] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME "/brightnessState/Zone1", itoa(zoneBrightness[0], charPayload, 10));
  }
  #endif
  #if ZONETWO == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/brightness/Zone2" || newTopic == USER_MQTT_CLIENT_NAME"/brightness") 
  {
    zoneBrightness[1] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME "/brightnessState/Zone2", itoa(zoneBrightness[1], charPayload, 10));
  }
  #endif
  #if ZONETHREE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/brightness/Zone3" || newTopic == USER_MQTT_CLIENT_NAME"/brightness") 
  {
    zoneBrightness[2] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME "/brightnessState/Zone3", itoa(zoneBrightness[2], charPayload, 10));
  }
  #endif
  #if ZONEFOUR == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/brightness/Zone4" || newTopic == USER_MQTT_CLIENT_NAME"/brightness") 
  {
    zoneBrightness[3] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME "/brightnessState/Zone4", itoa(zoneBrightness[3], charPayload, 10));
  }
  #endif
  #if ZONEFIVE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/brightness/Zone5" || newTopic == USER_MQTT_CLIENT_NAME"/brightness") 
  {
    zoneBrightness[4] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME "/brightnessState/Zone5", itoa(zoneBrightness[4], charPayload, 10));
  }
  #endif
  #if ZONESIX == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/brightness/Zone6" || newTopic == USER_MQTT_CLIENT_NAME"/brightness") 
  {
    zoneBrightness[5] = intPayload;
    client.publish(USER_MQTT_CLIENT_NAME "/brightnessState/Zone6", itoa(zoneBrightness[5], charPayload, 10));
  }
  #endif
  
  if (newTopic == USER_MQTT_CLIENT_NAME"/power")
  {
    showZoneLights[0] = newPayload == "ON";
    client.publish(USER_MQTT_CLIENT_NAME "/powerState", boolToOnOff(showZoneLights[0]).c_str());
    if(newPayload == "OFF")
    {
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/1/ToggleState", charPayload);
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/2/ToggleState", charPayload);
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/3/ToggleState", charPayload);
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/4/ToggleState", charPayload);
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/5/ToggleState", charPayload);
    }
    if(newPayload == "ON")
    {
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/1/ToggleState", colorStates[1].c_str());
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/2/ToggleState", colorStates[2].c_str());
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/3/ToggleState", colorStates[3].c_str());
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/4/ToggleState", colorStates[4].c_str());
      client.publish(USER_MQTT_CLIENT_NAME "/ColorSelector/5/ToggleState", colorStates[5].c_str());
    }
  }
  #if ZONEONE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/power/Zone1" || newTopic == USER_MQTT_CLIENT_NAME"/power")
  {
    showZoneLights[0] = newPayload == "ON";
    client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone1", boolToOnOff(showZoneLights[0]).c_str());
  }
  #endif
  #if ZONETWO == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/power/Zone2" || newTopic == USER_MQTT_CLIENT_NAME"/power")
  {
    showZoneLights[1] = newPayload == "ON";
    client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone2", boolToOnOff(showZoneLights[1]).c_str());
  }
  #endif
  #if ZONETHREE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/power/Zone3" || newTopic == USER_MQTT_CLIENT_NAME"/power")
  {
    showZoneLights[2] = newPayload == "ON";
    client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone3", boolToOnOff(showZoneLights[2]).c_str());
  }
  #endif
  #if ZONEFOUR == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/power/Zone4" || newTopic == USER_MQTT_CLIENT_NAME"/power")
  {
    showZoneLights[3] = newPayload == "ON";
    client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone4", boolToOnOff(showZoneLights[3]).c_str());
  }
  #endif
  #if ZONEFIVE == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/power/Zone5" || newTopic == USER_MQTT_CLIENT_NAME"/power")
  {
    showZoneLights[4] = newPayload == "ON";
    client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone5", boolToOnOff(showZoneLights[4]).c_str());
  }
  #endif
  #if ZONESIX == 1
  if (newTopic == USER_MQTT_CLIENT_NAME"/power/Zone6" || newTopic == USER_MQTT_CLIENT_NAME"/power")
  {
    showZoneLights[5] = newPayload == "ON";
    client.publish(USER_MQTT_CLIENT_NAME "/powerState/Zone6", boolToOnOff(showZoneLights[5]).c_str());
  }
  #endif
}



/*****************  GLOBAL LIGHT FUNCTIONS  *******************************/

void chase(void* args)
{
  
  int i = (int)args;
  if(zoneStartPosition[i] == ((colorsEnabled*2)-1))
  {
    zoneStartPosition[i] = 0;
  }
  else
  {
    zoneStartPosition[i] = zoneStartPosition[i] + 1;
  }

  int chaseDelay = 1000;
  
  if (zoneEffects[i] == "Color_Chase" || zoneEffects[i] == "Blocked_Colors")
  {
      chaseDelay = (zoneModifer[i]*5);
      if(chaseDelay < 100)
      {
        chaseDelay = 100;
      }
  }
  else if (zoneEffects[i] == "Heartbeat")
  {
    chaseDelay = map(zoneModifer[i], 0, 500, 150, 350);
  }

  timer.setTimeout(chaseDelay, chase, args);
}

void checkIn()
{
  client.publish(USER_MQTT_CLIENT_NAME"/checkIn","OK");
  timer.setTimeout(120000, checkIn);
}

void updateColorsEnabled()
{
  uint8_t count = 0;
  availableColors[5] = {};
  for(uint8_t i = 1; i <= colorsCount; i++)
  {
    if(colorStates[i] == "ON")
    {
      availableColors[count] = CRGB(rgbArray[i-1][0],rgbArray[i-1][1],rgbArray[i-1][2]);
      count++;
    }
  }

  if(colorsEnabled != count)
  {
    colorsEnabled = count;
    for(uint8_t i = 0; i < 5; i++)
    {
      zoneStartPosition[i] = 0;
    }
  }
  
  if(colorsEnabled == 0)
  {
    availableColors[0] = CRGB(255,0,0);
    colorsEnabled = 1;
  }
}

void setSectionPattern(CRGB zone[], int zoneLEDS, int sectionStart, int sectionEnd, byte heat[], int fireStart, int fireEnd, int zoneIndex)
{
  String effect = zoneEffects[zoneIndex];
  int modifier = zoneModifer[zoneIndex];
  if(effect == "Double_Crash")
  {
    fadeToBlackBy(zone, zoneLEDS, 15);
    Crash(zone, zoneLEDS, sectionStart, sectionEnd, (modifier/20));
  }
  if(effect == "Fire")
  {
    fire(zone, heat, sectionStart, sectionEnd, fireStart, fireEnd, map(modifier, 0, 500, 10, 120));
  }
}

void setZonePattern(CRGB zone[], int zoneLEDS, int previousZoneLED, Ball balls[], int fireworkCount, int zoneCenter, int zoneStep, int zoneIndex)
{
  String effect = zoneEffects[zoneIndex];
  int modifier = zoneModifer[zoneIndex];
  uint8_t startPosition = zoneStartPosition[zoneIndex];
  
  if(effect == "Color_Chase")
  {
    rGB(zone, zoneLEDS, startPosition);
  }
  if(effect == "Color_Glitter")
  {
    ColorGlitter(zone, zoneLEDS, (modifier/2), startPosition);
  }
  if(effect == "Single_Race")
  {
    previousZoneLED = SingleRace(zone, zoneLEDS, previousZoneLED, (modifier/20));
  }
  if(effect == "Rainbow")
  {
    Rainbow(zone, zoneLEDS, (modifier/30));
  }
  if(effect == "Blocked_Colors")
  {
    Blocked(zone, zoneLEDS, startPosition);
  }
  if(effect == "BPM")
  {
    BPM(zone, zoneLEDS,(modifier/4));
  }
  if(effect == "Twinkle")
  {
    Twinkle(zone, zoneLEDS, map(modifier, 0, 500, 0, 255));
  }
  if(effect == "Fill_Solid")
  {
    Solid(zone, zoneLEDS);
  }
  if(effect == "Spooky_Eyes")
  {
    Eyes(zone, zoneLEDS, map(modifier, 0, 500, 200, 255));
  }
  if(effect == "LED_Locator")
  {
    Locator(zone, zoneLEDS);
  }
  if(effect == "Ripple")
  {
    zoneStep = Ripple(zone, zoneLEDS, zoneCenter, zoneStep);
  }
  if(effect == "Fireworks")
  {
    fadeToBlackBy(zone, zoneLEDS, 8);
    fireworks(zone, zoneLEDS, balls, fireworkCount, map(modifier, 0, 500, 0, 50));
  }
  if(effect == "Heartbeat")
  {
    heartbeat(zone, zoneLEDS, startPosition);
  }
  if(effect == "Traditional")
  {
    traditionalSolid(zone, zoneLEDS);
  }
}

void choosePattern()
{
  #if ZONEONE == 1
    if(showZoneLights[0] == true)
    {
      static Ball zone1balls[fireworkCount_firstZone];
      setZonePattern(firstZone, FIRSTZONE_LEDS, previousLED_firstZone, zone1balls, fireworkCount_firstZone, center_firstZone, step_firstZone, 0);
      #ifdef ZONEONE_SECTION1_START
        static byte zOneS1heat[ZONEONE_SECTION1_END-ZONEONE_SECTION1_START];
        setSectionPattern(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION1_START, ZONEONE_SECTION1_END, 
          zOneS1heat, ZONEONE_SECTION1_START_FIRE, ZONEONE_SECTION1_END_FIRE, 0);
      #endif
      #ifdef ZONEONE_SECTION2_START
        static byte zOneS1heat[ZONEONE_SECTION2_END-ZONEONE_SECTION2_START];
        setSectionPattern(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION2_START, ZONEONE_SECTION2_END, 
          zOneS1heat, ZONEONE_SECTION2_START_FIRE, ZONEONE_SECTION2_END_FIRE, 0);
      #endif
      #ifdef ZONEONE_SECTION3_START
        static byte zOneS1heat[ZONEONE_SECTION3_END-ZONEONE_SECTION3_START];
        setSectionPattern(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION3_START, ZONEONE_SECTION3_END, 
            zOneS1heat, ZONEONE_SECTION3_START_FIRE, ZONEONE_SECTION3_END_FIRE , 0);
      #endif
      #ifdef ZONEONE_SECTION4_START
        static byte zOneS1heat[ZONEONE_SECTION4_END-ZONEONE_SECTION4_START];
        setSectionPattern(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION4_START, ZONEONE_SECTION4_END, 
            zOneS1heat, ZONEONE_SECTION4_START_FIRE, ZONEONE_SECTION4_END_FIRE, 0);
      #endif
      #ifdef ZONEONE_SECTION5_START
        static byte zOneS1heat[ZONEONE_SECTION5_END-ZONEONE_SECTION5_START];
        setSectionPattern(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION5_START, ZONEONE_SECTION5_END, 
            zOneS1heat, ZONEONE_SECTION5_START_FIRE, ZONEONE_SECTION5_END_FIRE, 0);
      #endif
      #ifdef ZONEONE_SECTION6_START
        static byte zOneS1heat[ZONEONE_SECTION6_END-ZONEONE_SECTION6_START];
        setSectionPattern(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION6_START, ZONEONE_SECTION6_END, 
            zOneS1heat, ZONEONE_SECTION6_START_FIRE, ZONEONE_SECTION6_END_FIRE, 0);
      #endif
      #ifdef ZONEONE_SECTION7_START
        static byte zOneS1heat[ZONEONE_SECTION7_END-ZONEONE_SECTION7_START];
        setSectionPattern(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION7_START, ZONEONE_SECTION7_END, 
            zOneS1heat, ZONEONE_SECTION7_START_FIRE, ZONEONE_SECTION7_END_FIRE, 0);
      #endif
      #ifdef ZONEONE_SECTION8_START
        static byte zOneS1heat[ZONEONE_SECTION8_END-ZONEONE_SECTION8_START];
        setSectionPattern(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION8_START, ZONEONE_SECTION8_END, 
            zOneS1heat, ZONEONE_SECTION8_START_FIRE, ZONEONE_SECTION8_END_FIRE, 0);
      #endif
      #ifdef ZONEONE_SECTION9_START
        static byte zOneS1heat[ZONEONE_SECTION9_END-ZONEONE_SECTION9_START];
        setSectionPattern(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION9_START, ZONEONE_SECTION9_END, 
            zOneS1heat, ZONEONE_SECTION9_START_FIRE, ZONEONE_SECTION9_END_FIRE, 0);
      #endif
    }
    else {
      fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::Black); 
    }
  #endif

  #if ZONETWO == 1
    if(showZoneLights[1] == true)
    {
      static Ball zone2balls[fireworkCount_secondZone];
      setZonePattern(secondZone, SECONDZONE_LEDS, previousLED_secondZone, zone2balls, fireworkCount_secondZone, center_secondZone, step_secondZone, 1);
            
      #ifdef ZONETWO_SECTION1_START
        static byte zTwoS1heat[ZONETWO_SECTION1_END-ZONETWO_SECTION1_START];
        setSectionPattern(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION1_START, ZONETWO_SECTION1_END, 
          zTwoS1heat, ZONETWO_SECTION1_START_FIRE, ZONETWO_SECTION1_END_FIRE, 1);
      #endif
      #ifdef ZONETWO_SECTION2_START
        static byte zTwoS2heat[ZONETWO_SECTION2_END-ZONETWO_SECTION2_START];
        setSectionPattern(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION2_START, ZONETWO_SECTION2_END,
          zTwoS2heat, ZONETWO_SECTION2_START_FIRE, ZONETWO_SECTION2_END_FIRE, 1);
      #endif
      #ifdef ZONETWO_SECTION3_START
        static byte zTwoS3heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
        setSectionPattern(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION3_START, ZONETWO_SECTION3_END,
          zTwoS3heat, ZONETWO_SECTION3_START_FIRE, ZONETWO_SECTION3_END_FIRE, 1);
      #endif
      #ifdef ZONETWO_SECTION4_START
        static byte zTwoS4heat[ZONETWO_SECTION4_END-ZONETWO_SECTION4_START];
        setSectionPattern(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION4_START, ZONETWO_SECTION4_END,
          zTwoS4heat, ZONETWO_SECTION4_START_FIRE, ZONETWO_SECTION4_END_FIRE, 1);
      #endif
      #ifdef ZONETWO_SECTION5_START
        static byte zTwoS5heat[ZONETWO_SECTION5_END-ZONETWO_SECTION5_START];
        setSectionPattern(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION5_START, ZONETWO_SECTION5_END, 
          zTwoS5heat, ZONETWO_SECTION5_START_FIRE, ZONETWO_SECTION5_END_FIRE, 1);
      #endif
      #ifdef ZONETWO_SECTION6_START
        static byte zTwoS6heat[ZONETWO_SECTION6_END-ZONETWO_SECTION6_START];
        setSectionPattern(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION6_START, ZONETWO_SECTION6_END,
          zTwoS6heat, ZONETWO_SECTION6_START_FIRE, ZONETWO_SECTION6_END_FIRE, 1);
      #endif
      #ifdef ZONETWO_SECTION7_START
        static byte zTwoS7heat[ZONETWO_SECTION7_END-ZONETWO_SECTION7_START];
        setSectionPattern(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION7_START, ZONETWO_SECTION7_END,
          zTwoS7heat, ZONETWO_SECTION7_START_FIRE, ZONETWO_SECTION7_END_FIRE, 1);
      #endif
      #ifdef ZONETWO_SECTION8_START
        static byte zOneS8heat[ZONETWO_SECTION8_END-ZONETWO_SECTION8_START];
        setSectionPattern(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION8_START, ZONETWO_SECTION8_END,
          zTwoS8heat, ZONETWO_SECTION8_START_FIRE, ZONETWO_SECTION8_END_FIRE, 1);
      #endif
      #ifdef ZONETWO_SECTION9_START
        static byte zTwoS9heat[ZONETWO_SECTION9_END-ZONETWO_SECTION9_START];
        setSectionPattern(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION9_START, ZONETWO_SECTION9_END,
          zTwoS9heat, ZONETWO_SECTION9_START_FIRE, ZONETWO_SECTION9_END_FIRE, 1);
      #endif
    }
    else {
      fill_solid(secondZone, SECONDZONE_LEDS, CRGB::Black); 
    }
  #endif

  #if ZONETHREE == 1
    if(showZoneLights[2] == true)
    {
      static Ball zone3balls[fireworkCount_thirdZone];
      setZonePattern(thirdZone, THIRDZONE_LEDS, previousLED_thirdZone, zone3balls, fireworkCount_thirdZone, center_thirdZone, step_thirdZone, 2);

      #ifdef ZONETHREE_SECTION1_START
        static byte zThreeS1heat[ZONETHREE_SECTION1_END-ZONETHREE_SECTION1_START];
        setSectionPattern(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION1_START, ZONETHREE_SECTION1_END,
          zThreeS1heat, ZONETHREE_SECTION1_START_FIRE, ZONETHREE_SECTION1_END_FIRE, 2);
      #endif
      #ifdef ZONETHREE_SECTION2_START
        static byte zThreeS2heat[ZONETHREE_SECTION2_END-ZONETHREE_SECTION2_START];
        setSectionPattern(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION2_START, ZONETHREE_SECTION2_END,
          zThreeS2heat, ZONETHREE_SECTION2_START_FIRE, ZONETHREE_SECTION2_END_FIRE, 2);
      #endif
      #ifdef ZONETHREE_SECTION3_START
        static byte zThreeS3heat[ZONETHREE_SECTION3_END-ZONETHREE_SECTION3_START];
        setSectionPattern(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION3_START, ZONETHREE_SECTION3_END,
          zThreeS3heat, ZONETHREE_SECTION3_START_FIRE, ZONETHREE_SECTION3_END_FIRE, 2);
      #endif
      #ifdef ZONETHREE_SECTION4_START
        static byte zThreeS4heat[ZONETHREE_SECTION4_END-ZONETHREE_SECTION4_START];
        setSectionPattern(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION4_START, ZONETHREE_SECTION4_END,
          zThreeS4heat, ZONETHREE_SECTION4_START_FIRE, ZONETHREE_SECTION4_END_FIRE, 2);
      #endif
      #ifdef ZONETHREE_SECTION5_START
        static byte zThreeS5heat[ZONETHREE_SECTION5_END-ZONETHREE_SECTION5_START];
        setSectionPattern(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION5_START, ZONETHREE_SECTION5_END,
          zThreeS5heat, ZONETHREE_SECTION5_START_FIRE, ZONETHREE_SECTION5_END_FIRE, 2);
      #endif
      #ifdef ZONETHREE_SECTION6_START
        static byte zThreeS6heat[ZONETHREE_SECTION6_END-ZONETHREE_SECTION6_START];
        setSectionPattern(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION6_START, ZONETHREE_SECTION6_END,
          zThreeS6heat, ZONETHREE_SECTION6_START_FIRE, ZONETHREE_SECTION6_END_FIRE, 2);
      #endif
      #ifdef ZONETHREE_SECTION7_START
        static byte zThreeS7heat[ZONETHREE_SECTION7_END-ZONETHREE_SECTION7_START];
        setSectionPattern(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION7_START, ZONETHREE_SECTION7_END,
          zThreeS7heat, ZONETHREE_SECTION7_START_FIRE, ZONETHREE_SECTION7_END_FIRE, 2);
      #endif
      #ifdef ZONETHREE_SECTION8_START
        static byte zThreeS8heat[ZONETHREE_SECTION8_END-ZONETHREE_SECTION8_START];
        setSectionPattern(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION8_START, ZONETHREE_SECTION8_END,
          zThreeS8heat, ZONETHREE_SECTION8_START_FIRE, ZONETHREE_SECTION8_END_FIRE, 2);
      #endif
      #ifdef ZONETHREE_SECTION9_START
        static byte zThreeS9heat[ZONETHREE_SECTION9_END-ZONETHREE_SECTION9_START];
        setSectionPattern(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION9_START, ZONETHREE_SECTION9_END,
          zThreeS9heat, ZONETHREE_SECTION9_START_FIRE, ZONETHREE_SECTION9_END_FIRE, 2);
      #endif
    }
    else {
      fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::Black);
    }
  #endif

  #if ZONEFOUR == 1
    if(showZoneLights[3] == true)
    {
      static Ball zone4balls[fireworkCount_fourthZone];
      setZonePattern(fourthZone, FOURTHZONE_LEDS, previousLED_fourthZone, zone4balls, fireworkCount_fourthZone, center_fourthZone, step_fourthZone, 3);
            
      #ifdef ZONEFOUR_SECTION1_START
        static byte zFourS1heat[ZONEFOUR_SECTION1_END-ZONEFOUR_SECTION1_START];
        setSectionPattern(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION1_START, ZONEFOUR_SECTION1_END,
          zFourS1heat, ZONEFOUR_SECTION1_START_FIRE, ZONEFOUR_SECTION1_END_FIRE, 3);
      #endif
      #ifdef ZONEFOUR_SECTION2_START
        static byte zFourS2heat[ZONEFOUR_SECTION2_END-ZONEFOUR_SECTION2_START];
        setSectionPattern(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION2_START, ZONEFOUR_SECTION2_END,
          zFourS2heat, ZONEFOUR_SECTION2_START_FIRE, ZONEFOUR_SECTION2_END_FIRE, 3);
      #endif
      #ifdef ZONEFOUR_SECTION3_START
        static byte zFourS3heat[ZONEFOUR_SECTION3_END-ZONEFOUR_SECTION3_START];
        setSectionPattern(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION3_START, ZONEFOUR_SECTION3_END,
          zFourS3heat, ZONEFOUR_SECTION3_START_FIRE, ZONEFOUR_SECTION3_END_FIRE, 3);
      #endif
      #ifdef ZONEFOUR_SECTION4_START
        static byte zFourS4heat[ZONEFOUR_SECTION4_END-ZONEFOUR_SECTION4_START];
        setSectionPattern(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION4_START, ZONEFOUR_SECTION4_END,
          zFourS4heat, ZONEFOUR_SECTION4_START_FIRE, ZONEFOUR_SECTION4_END_FIRE, 3);
      #endif
      #ifdef ZONEFOUR_SECTION5_START
        static byte zFourS5heat[ZONEFOUR_SECTION5_END-ZONEFOUR_SECTION5_START];
        setSectionPattern(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION5_START, ZONEFOUR_SECTION5_END,
          zFourS5heat, ZONEFOUR_SECTION5_START_FIRE, ZONEFOUR_SECTION5_END_FIRE, 3);
      #endif
      #ifdef ZONEFOUR_SECTION6_START
        static byte zFourS6heat[ZONEFOUR_SECTION6_END-ZONEFOUR_SECTION6_START];
        setSectionPattern(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION6_START, ZONEFOUR_SECTION6_END, 
          zFourS6heat, ZONEFOUR_SECTION6_START_FIRE, ZONEFOUR_SECTION6_END_FIRE, 3);
      #endif
      #ifdef ZONEFOUR_SECTION7_START
        static byte zFourS7heat[ZONEFOUR_SECTION7_END-ZONEFOUR_SECTION7_START];
        setSectionPattern(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION7_START, ZONEFOUR_SECTION7_END, 
          zFourS7heat, ZONEFOUR_SECTION7_START_FIRE, ZONEFOUR_SECTION7_END_FIRE, 3);
      #endif
      #ifdef ZONEFOUR_SECTION8_START
        static byte zFourS8heat[ZONEFOUR_SECTION8_END-ZONEFOUR_SECTION8_START];
        setSectionPattern(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION8_START, ZONEFOUR_SECTION8_END,
          zFourS8heat, ZONEFOUR_SECTION8_START_FIRE, ZONEFOUR_SECTION8_END_FIRE, 3);
      #endif
      #ifdef ZONEFOUR_SECTION9_START
        static byte zFourS9heat[ZONEFOUR_SECTION9_END-ZONEFOUR_SECTION9_START];
        setSectionPattern(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION9_START, ZONEFOUR_SECTION9_END,
          zFourS9heat, ZONEFOUR_SECTION9_START_FIRE, ZONEFOUR_SECTION9_END_FIRE, 3);
      #endif
    }
    else {
      fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::Black);
    }
  #endif

  #if ZONEFIVE == 1
    if(showZoneLights[4] == true)
    {
      static Ball zone5balls[fireworkCount_fifthZone];
      setZonePattern(fifthZone, FIFTHZONE_LEDS, previousLED_fifthZone, zone5balls, fireworkCount_fifthZone, center_fifthZone, step_fifthZone, 4);
            
      #ifdef ZONEFIVE_SECTION1_START
        static byte zFiveS1heat[ZONEFIVE_SECTION1_END-ZONEFIVE_SECTION1_START];
        setSectionPattern(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION1_START, ZONEFIVE_SECTION1_END,
          zFiveS1heat, ZONEFIVE_SECTION1_START_FIRE, ZONEFIVE_SECTION1_END_FIRE, 4);
      #endif
      #ifdef ZONEFIVE_SECTION2_START
        static byte zFiveS2heat[ZONEFIVE_SECTION2_END-ZONEFIVE_SECTION2_START];
        setSectionPattern(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION2_START, ZONEFIVE_SECTION2_END,
          zFiveS2heat, ZONEFIVE_SECTION2_START_FIRE, ZONEFIVE_SECTION2_END_FIRE, 4);
      #endif
      #ifdef ZONEFIVE_SECTION3_START
        static byte zFiveS3heat[ZONEFIVE_SECTION3_END-ZONEFIVE_SECTION3_START];
        setSectionPattern(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION3_START, ZONEFIVE_SECTION3_END,
          zFiveS3heat, ZONEFIVE_SECTION3_START_FIRE, ZONEFIVE_SECTION3_END_FIRE, 4);
      #endif
      #ifdef ZONEFIVE_SECTION4_START
        static byte zFiveS4heat[ZONEFIVE_SECTION4_END-ZONEFIVE_SECTION4_START];
        setSectionPattern(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION4_START, ZONEFIVE_SECTION4_END,
          zFiveS4heat, ZONEFIVE_SECTION4_START_FIRE, ZONEFIVE_SECTION4_END_FIRE, 4);
      #endif
      #ifdef ZONEFIVE_SECTION5_START
        static byte zFiveS5heat[ZONEFIVE_SECTION5_END-ZONEFIVE_SECTION5_START];
        setSectionPattern(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION5_START, ZONEFIVE_SECTION5_END, 
          zFiveS5heat, ZONEFIVE_SECTION5_START_FIRE, ZONEFIVE_SECTION5_END_FIRE, 4);
      #endif
      #ifdef ZONEFIVE_SECTION6_START
        static byte zFiveS6heat[ZONEFIVE_SECTION6_END-ZONEFIVE_SECTION6_START];
        setSectionPattern(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION6_START, ZONEFIVE_SECTION6_END,
          zFiveS6heat, ZONEFIVE_SECTION6_START_FIRE, ZONEFIVE_SECTION6_END_FIRE, 4);
      #endif
      #ifdef ZONEFIVE_SECTION7_START
        static byte zFiveS7heat[ZONEFIVE_SECTION7_END-ZONEFIVE_SECTION7_START];
        setSectionPattern(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION7_START, ZONEFIVE_SECTION7_END,
          zFiveS7heat, ZONEFIVE_SECTION7_START_FIRE, ZONEFIVE_SECTION7_END_FIRE, 4);
      #endif
      #ifdef ZONEFIVE_SECTION8_START
        static byte zFiveS8heat[ZONEFIVE_SECTION8_END-ZONEFIVE_SECTION8_START];
        setSectionPattern(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION8_START, ZONEFIVE_SECTION8_END, 
          zFiveS8heat, ZONEFIVE_SECTION8_START_FIRE, ZONEFIVE_SECTION8_END_FIRE, 4);
      #endif
      #ifdef ZONEFIVE_SECTION9_START
        static byte zFiveS9heat[ZONEFIVE_SECTION9_END-ZONEFIVE_SECTION9_START];
        setSectionPattern(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION9_START, ZONEFIVE_SECTION9_END,
          zFiveS9heat, ZONEFIVE_SECTION9_START_FIRE, ZONEFIVE_SECTION9_END_FIRE, 4);
      #endif
    }
    else {
      fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::Black); 
    }
  #endif
    
  #if ZONESIX == 1
    if(showZoneLights[5] == true)
    {
      static Ball zone6balls[fireworkCount_sixthZone];
      setZonePattern(sixthZone, SIXTHZONE_LEDS, previousLED_sixthZone, zone6balls, fireworkCount_sixthZone, center_sixthZone, step_sixthZone, 5);
            
      #ifdef ZONESIX_SECTION1_START
        static byte zSixS1heat[ZONESIX_SECTION1_END-ZONESIX_SECTION1_START];
        setSectionPattern(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION1_START, ZONESIX_SECTION1_END,
          zSixS1heat, ZONESIX_SECTION1_START_FIRE, ZONESIX_SECTION1_END_FIRE, 5);
      #endif
      #ifdef ZONESIX_SECTION2_START
        static byte zSixS2heat[ZONESIX_SECTION2_END-ZONESIX_SECTION2_START];
        setSectionPattern(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION2_START, ZONESIX_SECTION2_END,
          zSixS2heat, ZONESIX_SECTION2_START_FIRE, ZONESIX_SECTION2_END_FIRE, 5);
      #endif
      #ifdef ZONESIX_SECTION3_START
        static byte zSixS3heat[ZONESIX_SECTION3_END-ZONESIX_SECTION3_START];
        setSectionPattern(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION3_START, ZONESIX_SECTION3_END,
          zSixS3heat, ZONESIX_SECTION3_START_FIRE, ZONESIX_SECTION3_END_FIRE, 5);
      #endif
      #ifdef ZONESIX_SECTION4_START
        static byte zSixS4heat[ZONESIX_SECTION4_END-ZONESIX_SECTION4_START];
        setSectionPattern(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION4_START, ZONESIX_SECTION4_END,
          zSixS4heat, ZONESIX_SECTION4_START_FIRE, ZONESIX_SECTION4_END_FIRE, 5);
      #endif
      #ifdef ZONESIX_SECTION5_START
        static byte zSixS5heat[ZONESIX_SECTION5_END-ZONESIX_SECTION5_START];
        setSectionPattern(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION5_START, ZONESIX_SECTION5_END,
          zSixS5heat, ZONESIX_SECTION5_START_FIRE, ZONESIX_SECTION5_END_FIRE, 5);
      #endif
      #ifdef ZONESIX_SECTION6_START
        static byte zSixS6heat[ZONESIX_SECTION6_END-ZONESIX_SECTION6_START];
        setSectionPattern(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION6_START, ZONESIX_SECTION6_END, 
          zSixS6heat, ZONESIX_SECTION6_START_FIRE, ZONESIX_SECTION6_END_FIRE, 5);
      #endif
      #ifdef ZONESIX_SECTION7_START
        static byte zSixS7heat[ZONESIX_SECTION7_END-ZONESIX_SECTION7_START];
        setSectionPattern(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION7_START, ZONESIX_SECTION7_END,
          zSixS7heat, ZONESIX_SECTION7_START_FIRE, ZONESIX_SECTION7_END_FIRE, 5);
      #endif
      #ifdef ZONESIX_SECTION8_START
        static byte zSixS8heat[ZONESIX_SECTION8_END-ZONESIX_SECTION8_START];
        setSectionPattern(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION8_START, ZONESIX_SECTION8_END,
          zSixS8heat, ZONESIX_SECTION8_START_FIRE, ZONESIX_SECTION8_END_FIRE, 5);
      #endif
      #ifdef ZONESIX_SECTION9_START
        static byte zSixS9heat[ZONESIX_SECTION9_END-ZONESIX_SECTION9_START];
        setSectionPattern(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION9_START, ZONESIX_SECTION9_END, 
          zSixS9heat, ZONESIX_SECTION9_START_FIRE, ZONESIX_SECTION9_END_FIRE, 5);
      #endif
    } 
    else
    {
      fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::Black);
    }
  #endif 

  addGlitter();
  addLightning(); 
}

/*********************** PATTERN MODIFIERS ***************************/


void addLightning()
{
  if(showLightning == true)
  {
    #if ZONEONE == 1 
    fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 1); 
    #endif

    #if ZONETWO == 1
    fadeToBlackBy(secondZone, SECONDZONE_LEDS, 1); 
    #endif

    #if ZONETHREE == 1
    fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 1);
    #endif

    #if ZONEFOUR == 1
    fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 1);
    #endif

    #if ZONEFIVE == 1
    fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 1); 
    #endif
    
    #if ZONESIX == 1
    fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 1);
    #endif
    
    unsigned int chance = random16();
    if( chance > lightningChance) 
    {
      #if ZONEONE == 1 
      fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::White); 
      #endif
  
      #if ZONETWO == 1
      fill_solid(secondZone, SECONDZONE_LEDS, CRGB::White); 
      #endif
  
      #if ZONETHREE == 1
      fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::White);
      #endif
  
      #if ZONEFOUR == 1
      fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::White);
      #endif
  
      #if ZONEFIVE == 1
      fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::White); 
      #endif
      
      #if ZONESIX == 1
      fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::White);
      #endif

      lightning = 20;
      if(audioEffects == true)
      {
        int thunder = random8();
        if( thunder > 128)
        {
          client.publish("Audio","2");
        }
        if( thunder < 127)
        {
          client.publish("Audio","1");
        }
      }
    }
    if(lightning != 1)
    {
      if(lightning > 15)
      {
        #if ZONEONE == 1  
        fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 150); 
        #endif
    
        #if ZONETWO == 1
        fadeToBlackBy(secondZone, SECONDZONE_LEDS, 150); 
        #endif
    
        #if ZONETHREE == 1
        fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 150);
        #endif
    
        #if ZONEFOUR == 1
        fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 150);
        #endif
    
        #if ZONEFIVE == 1
        fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 150); 
        #endif
        
        #if ZONESIX == 1
        fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 150);
        #endif

        lightning--;
      }
      if(lightning == 15)
      {

        #if ZONEONE == 1 
        fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::White); 
        #endif
    
        #if ZONETWO == 1
        fill_solid(secondZone, SECONDZONE_LEDS, CRGB::White); 
        #endif
    
        #if ZONETHREE == 1
        fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::White);
        #endif
    
        #if ZONEFOUR == 1
        fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::White);
        #endif
    
        #if ZONEFIVE == 1
        fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::White); 
        #endif
        
        #if ZONESIX == 1
        fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::White);
        #endif
        lightning--; 
      }
      if(lightning > 5 && lightning < 15)
      {
        #if ZONEONE == 1
        fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 150); 
        #endif
    
        #if ZONETWO == 1
        fadeToBlackBy(secondZone, SECONDZONE_LEDS, 150); 
        #endif
    
        #if ZONETHREE == 1
        fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 150);
        #endif
    
        #if ZONEFOUR == 1
        fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 150);
        #endif
    
        #if ZONEFIVE == 1
        fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 150); 
        #endif
        
        #if ZONESIX == 1
        fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 150);
        #endif
        lightning--;
      }
      if(lightning == 5)
      {
        #if ZONEONE == 1 
        fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::White); 
        #endif
    
        #if ZONETWO == 1
        fill_solid(secondZone, SECONDZONE_LEDS, CRGB::White); 
        #endif
    
        #if ZONETHREE == 1
        fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::White);
        #endif
    
        #if ZONEFOUR == 1
        fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::White);
        #endif
    
        #if ZONEFIVE == 1
        fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::White); 
        #endif
        
        #if ZONESIX == 1
        fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::White);
        #endif
        lightning--; 
      }
      if(lightning > 0 && lightning < 5)
      {
        #if ZONEONE == 1
        fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 150); 
        #endif
    
        #if ZONETWO == 1
        fadeToBlackBy(secondZone, SECONDZONE_LEDS, 150); 
        #endif
    
        #if ZONETHREE == 1
        fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 150);
        #endif
    
        #if ZONEFOUR == 1
        fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 150);
        #endif
    
        #if ZONEFIVE == 1
        fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 150); 
        #endif
        
        #if ZONESIX == 1
        fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 150);
        #endif
        lightning--;
      }
    }
  }
}

void addGlitter() 
{
  if(showGlitter == true)
  {     
    if( random8() < glitterFrequency) 
    {
      #if ZONEONE == 1 
      {
        firstZone[ random16(FIRSTZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif
  
      #if ZONETWO == 1
      {
        secondZone[ random16(SECONDZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif
  
      #if ZONETHREE == 1
      {
        thirdZone[ random16(THIRDZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif
  
      #if ZONEFOUR == 1
      {
        fourthZone[ random16(FOURTHZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif
  
      #if ZONEFIVE == 1
      {
        fifthZone[ random16(FIFTHZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif
      
      #if ZONESIX == 1
      {
        sixthZone[ random16(SIXTHZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif  
    }
  }
}

void setupZones()
{
    #if ZONEONE == 1
    FastLED.addLeds<WS2812B, Pin_firstZone, FIRSTZONE_COLOR_ORDER>(firstZone, FIRSTZONE_LEDS);
    timer.setTimeout(10000, chase, (void *)0);
    #endif

    #if ZONETWO == 1
    FastLED.addLeds<WS2812B, Pin_secondZone, SECONDZONE_COLOR_ORDER>(secondZone, SECONDZONE_LEDS);
    timer.setTimeout(10000, chase, (void *)1);
    #endif

    #if ZONETHREE == 1
    FastLED.addLeds<WS2812B, Pin_thirdZone, THIRDZONE_COLOR_ORDER>(thirdZone, THIRDZONE_LEDS);
    timer.setTimeout(10000, chase, (void *)2);
    #endif

    #if ZONEFOUR == 1
    FastLED.addLeds<WS2812B, Pin_fourthZone, FOURTHZONE_COLOR_ORDER>(fourthZone, FOURTHZONE_LEDS);
    timer.setTimeout(10000, chase, (void *)3);
    #endif

    #if ZONEFIVE == 1
    FastLED.addLeds<WS2812B, Pin_fifthZone, FIFTHZONE_COLOR_ORDER>(fifthZone, FIFTHZONE_LEDS);
    timer.setTimeout(10000, chase, (void *)4);
    #endif
    
    #if ZONESIX == 1
    FastLED.addLeds<WS2812B, Pin_sixthZone, SIXTHZONE_COLOR_ORDER>(sixthZone, SIXTHZONE_LEDS);
    timer.setTimeout(10000, chase, (void *)5);
    #endif
}


void locator_Move()
{
  if(locatorLED <= maxLEDs)
  {
    String temp_str = String(locatorLED);
    temp_str.toCharArray(MQTT_locatorLED, temp_str.length() + 1);
    client.publish(USER_MQTT_CLIENT_NAME"/locator", MQTT_locatorLED);
    locatorLED++;    
  }
  else
  {
    locatorLED = 0;
  }
  for (byte i = 0; i < 6; i = i + 1) {
     if(zoneEffects[i] != "LED_Locator")
     {
        return;
     }
  }
  timer.setTimeout(locatorDelay, locator_Move);
}



/*****************  SETUP FUNCTION  ****************************************/


void setup() {
  Serial.begin(115200);
  calculateMax();
  setupZones();
  FastLED.setDither( 0 );
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  WiFi.mode(WIFI_STA);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  ArduinoOTA.setHostname(USER_MQTT_CLIENT_NAME);
  ArduinoOTA.begin(); 

  gPal = HeatColors_p;
  
  timer.setTimeout(120000, checkIn);
}


/*****************  MAIN LOOP  ****************************************/


void loop() 
{
  if (!client.connected()) 
  {
    reconnect();
  }
  client.loop();
  
  bool canUpdate = true;
  for (byte i = 0; i < 6; i = i + 1) {
    if (showZoneLights[i] == true)
    {
      canUpdate = false;
    }
  }
  
  if(canUpdate == true)
  {
    ArduinoOTA.handle();  
  }
  timer.run();
  EVERY_N_MILLISECONDS( 20 ) { gHue++; }
  updateColorsEnabled();
  choosePattern();

  #if ZONEONE == 1
  FastLED[0].showLeds(zoneBrightness[0]);
  #endif

  #if ZONETWO == 1
  FastLED[1].showLeds(zoneBrightness[1]);
  #endif

  #if ZONETHREE == 1
  FastLED[2].showLeds(zoneBrightness[2]);
  #endif

  #if ZONEFOUR == 1
  FastLED[3].showLeds(zoneBrightness[3]);
  #endif

  #if ZONEFIVE == 1
  FastLED[4].showLeds(zoneBrightness[4]);
  #endif
  
  #if ZONESIX == 1
  FastLED[5].showLeds(zoneBrightness[5]);
  #endif
  
}


/*****************  Animation Functions  ****************************************/

int Ripple(CRGB zone[], int ledCount, int zoneCenter, int zoneStep)
{
  for (int i = 0; i < ledCount; i++)
  {
    zone[i] = CRGB((red2/75), (green2/75), (blue2/75));
  }   
  switch (zoneStep) 
  {
    case -1:                                                          
      zoneCenter = random16(ledCount);
      zoneStep = 0;
      break;
    case 0:
      zone[zoneCenter] = CRGB(red1, green1, blue1);                          
      zoneStep ++;
      break;
    case 12:                                                   
      zoneStep = -1;
      break;
    default:                                                             // Middle of the ripples.
      zone[(zoneCenter + zoneStep + ledCount) % ledCount] += CRGB((red1/(zoneStep * 5)), (green1/(zoneStep * 5)), (blue1/(zoneStep * 5)));
      zone[(zoneCenter - zoneStep + ledCount) % ledCount] += CRGB((red1/(zoneStep * 5)), (green1/(zoneStep * 5)), (blue1/(zoneStep * 5)));
      zoneStep ++;                                                         
      break;
  }
  return zoneStep;
}

void rGB(CRGB zone[], int zoneLEDS, uint8_t startPosition)
{
  int squenceLength = colorsEnabled*2;
  if(startPosition < squenceLength)
  {
    fadeToBlackBy( zone, zoneLEDS, 80);
    for(int skip = 1; skip < squenceLength; skip+=2)
    {
      for(int pixel = startPosition+skip; pixel < zoneLEDS; pixel+=squenceLength)  
      {
        if(pixel <= zoneLEDS)
        {
          int currentColor = ((skip+1)/2)-1;
          zone[pixel] = availableColors[currentColor];
        }
      }  
    }
  }
  
  int colorIndex = colorsEnabled-1;
  for(int pos = startPosition-1; pos >= 0; pos-=2)
  {
    zone[pos] = availableColors[colorIndex];
    colorIndex--;
  }
}

void ColorGlitter(CRGB zone[], int zoneLEDS, fract8 chanceOfGlitter, uint8_t startPosition) 
{
  fadeToBlackBy( zone, zoneLEDS, 2);
  if(startPosition == 0)
  {
    if( random8() < chanceOfGlitter) 
    {
      zone[ random16(zoneLEDS) ] += CRGB::Red;
    }
  }
  if(startPosition == 1)
  {
    if( random8() < chanceOfGlitter) 
    {
      zone[ random16(zoneLEDS) ] += CRGB::Orange;
    }
  }
  if(startPosition == 2)
  {
    if( random8() < chanceOfGlitter) 
    {
      zone[ random16(zoneLEDS) ] += CRGB::Yellow;
    }  
  }
  if(startPosition == 3)
  {
    if( random8() < chanceOfGlitter) 
    {
      zone[ random16(zoneLEDS) ] += CRGB::Green;
    }
  }
  if(startPosition == 4)
  {
    if( random8() < chanceOfGlitter) 
    {
      zone[ random16(zoneLEDS) ] += CRGB::Blue;
    }
  }
  if(startPosition == 5)
  {
    if( random8() < chanceOfGlitter) 
    {
      zone[ random16(zoneLEDS) ] += CRGB::Violet;
    }
  } 
}

int SingleRace(CRGB zone[], int zoneLEDS, int previousZoneLED, int raceSpeed)
{
  fadeToBlackBy( zone, zoneLEDS, 1);
  int pos = beatsin16( raceSpeed, 0, zoneLEDS);
  if(pos > previousZoneLED)
  {
    zone[pos] = CRGB(red1,green1,blue1);
  }
  if(pos < previousZoneLED)
  {
    zone[pos] = CRGB(red2,green2,blue2);
  }
  return pos;            
}

void Crash(CRGB zone[], int zoneLEDS, int sectionStart, int sectionEnd, int raceSpeed)
{
    int pos = beatsin16( raceSpeed, 0, (sectionEnd - sectionStart) );
    zone[sectionStart + pos] = CRGB(red1,green1,blue1);
    zone[sectionEnd - pos] = CRGB(red2,green2,blue2);
}

void Rainbow(CRGB zone[], int zoneLEDS, uint8_t numberOfRainbows)
{
  fill_rainbow( zone, zoneLEDS, gHue, numberOfRainbows);
}

void Blocked(CRGB zone[], int zoneLEDS, uint8_t startPosition)
{
  fadeToBlackBy( zone, zoneLEDS, 2);
  uint8_t startColorIndex = map(startPosition, 0, (colorsEnabled*2)-1, 0, colorsEnabled-1);
  
  for( int mark = 0; mark < zoneLEDS; mark+=(colorsEnabled*10)) //repeat color block sequence
  {
    for( int i = 0; i < 9; i++) // repeat for each pixel in color block size
    {
      for(int blockNum = 0; blockNum < (colorsEnabled*10); blockNum+=10) //set one of each color in each block
      {
        if((i+blockNum+mark) <= zoneLEDS)
        {
          zone[i+blockNum+mark] = availableColors[startColorIndex];
          if(startColorIndex < colorsEnabled-1)
          {
            startColorIndex++;
          }
          else
          {
            startColorIndex = 0;
          }
        }
      }
    }
  }
}

void BPM(CRGB zone[], int zoneLEDS, int BeatsPerMinute)
{
  if((red1*2) > (green1 + blue1))
  {
    CRGBPalette16 palette = LavaColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < zoneLEDS; i++) 
    {
      zone[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette = ForestColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < zoneLEDS; i++) 
    {
      zone[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette = CloudColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < zoneLEDS; i++) 
    {
      zone[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette = PartyColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < zoneLEDS; i++) 
    {
      zone[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
}

void Twinkle(CRGB zone[], int zoneLEDS, int twinkleChance)
{
  fadeToBlackBy( zone, zoneLEDS, 80);
  for( int i = 0; i < zoneLEDS-5; i+=5)
  {
    if(i <= zoneLEDS)
    {
      if (random8() > twinkleChance)
      {
        zone[i] = CRGB( red1, green1, blue1);
      }
      else
      {
        zone[i] = CRGB( 150, 100, 40);
      }  
    }
  }                     
}

void Eyes(CRGB zone[], int zoneLEDS, int eyeChance)
{
  unsigned int chance = random8();
  if( chance > eyeChance) 
  {
    unsigned int eye = random16(zoneLEDS);  
    zone[eye] = CRGB(red1,green1,blue1);
    zone[eye-4] = CRGB(red1,green1,blue1);
  }
  if( chance > 39) 
  {
    fadeToBlackBy( zone, zoneLEDS, 10);
  }
}

void Solid(CRGB zone[], int zoneLEDS)
{
  fill_solid(zone, zoneLEDS, CRGB(red1, green1, blue1));
}

void Locator(CRGB zone[], int zoneLEDS)
{
  if(locatorLED <= zoneLEDS)
  {
    fill_solid(zone, zoneLEDS, CRGB::Black); 
    zone[locatorLED]=CRGB(red1, green1, blue1);
  }
}

void fire(CRGB zone[], byte heat[], int sectionStart, int sectionEnd, int fireStart, int fireEnd, int firesize)
{
  int sizeOfSection = sectionEnd - sectionStart;
  for( int i = 0; i < sizeOfSection; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / sizeOfSection) + 2));
  }

  for( int k= sizeOfSection - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < sizeOfSection; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (sizeOfSection -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    
    
    if(fireStart == 1 && thisFlame <=  sizeOfSection)
    {
      zone[sectionStart + thisFlame] = color;
    }
    
    if(fireEnd == 1 && thisFlame <=  sizeOfSection )
    {
      zone[sectionEnd - thisFlame] = color;
    }
  }
}

void heartbeat(CRGB zone[], int zoneLEDS, uint8_t startPosition) {
  uint8_t beatIndex = map(startPosition, 0, (colorsEnabled*2)-1, 0, 5);
  if(beatIndex == 1 || beatIndex == 3) {
    fill_solid(zone, zoneLEDS, CRGB(red1, green1, blue1));
  } else {
    fill_solid(zone, zoneLEDS, CRGB(red1/2, green1/2, blue1/2));   
  }  
}

void traditionalSolid(CRGB zone[], int zoneLEDS)
{
  uint8_t gap = 4;
  for(int pixel = 0; pixel < zoneLEDS; pixel+= (gap*colorsEnabled))
  {
    for(int color = 0; color < colorsEnabled; color++)
    {
      zone[pixel+(color*gap)] = availableColors[color];
    }
  }
}

void fireworks(CRGB zone[], int zoneLEDS, Ball balls[], int fireworkCount, uint8_t chance) {

  const float ballVelocityDecay = 0.0036;
  
  for (uint8_t i = 0; i < fireworkCount; i++) {
    // initialize if not loaded
    if(!balls[i].loaded)
    {
      balls[i].position = -1;
      balls[i].exploding = 0;
      switch(random8(colorsEnabled))
      {
        case 0:
          balls[i].color = availableColors[0];
          break;
        case 1:
          balls[i].color = availableColors[1];
          break;
        case 2:
          balls[i].color = availableColors[2];
          break;
        case 3:
          balls[i].color = availableColors[3];
          break;
        case 4:
          balls[i].color = availableColors[4];
          break;
      }
      balls[i].reverse = random8(2) == 0;
      balls[i].loaded = true;
    }
    
    // launch firework
    if(balls[i].position < 0 && random8() < chance) {
      if(balls[i].reverse)
      {
        zone[zoneLEDS] += CHSV(0, 0, 128);
        balls[i].position = zoneLEDS;
        balls[i].velocity = -1.0;
      }
      else {
        zone[0] += CHSV(0, 0, 128);
        balls[i].position = 0;
        balls[i].velocity = 1.0;
      }
    } 
    else if (balls[i].exploding < 1 && balls[i].position > 15 
                && balls[i].position < zoneLEDS - 15 && random8(1,80) == 2) {
      // detonate firework
      balls[i].exploding = 1;
    }

    // update
    if (balls[i].position >= 0) {
      uint8_t exploding = balls[i].exploding;

      if (exploding == 0) {
        balls[i].position += balls[i].velocity;
        balls[i].velocity -= ballVelocityDecay;
        if (balls[i].position >= zoneLEDS) {
          balls[i].velocity *= -1.0;
          balls[i].position = zoneLEDS - 1;
        }
        else if (balls[i].position <= 0) {
          balls[i].velocity = 1.0;
          balls[i].position = 1;
        }
      }
  
      // draw
      if (exploding == 0) {
        zone[(uint8_t) balls[i].position] += CHSV(0, 0, 16);
      }
      else if (exploding == 1) {
        zone[(uint8_t) balls[i].position] += CRGB::White;
        balls[i].exploding++;
        balls[i].velocity = 1;
        balls[i].particlePosition = 50;
      }
      else if (exploding == 2) {
        int16_t explosionPosition = balls[i].position;
        int pos = map(balls[i].particlePosition, 50, 0, 1, 5);
        int particles = 2;
        if(pos > 3) { particles = 4; }
        for (uint8_t j = 0; j < particles; j++) {
          
          int topPos = explosionPosition+(j*pos);
          if(topPos <= zoneLEDS) 
          {
            zone[topPos] = balls[i].color;
          }
          int bottomPos = explosionPosition-(j*pos);
          if(bottomPos >= 0)
          {
            zone[bottomPos] = balls[i].color;
          }
        }
        if( balls[i].particlePosition >= 0)
        {
          balls[i].particlePosition -= balls[i].velocity;
        }
        else
        {
          balls[i].exploding++;
        }
        if(balls[i].velocity > 0)
        {
          balls[i].velocity -= .01;
        }
      }
      else {
        balls[i].exploding = 0;
        balls[i].position = -1;
        balls[i].reverse = random8(2) == 0;
        switch(random8(colorsEnabled))
        {
          case 0:
            balls[i].color = availableColors[0];
            break;
          case 1:
            balls[i].color = availableColors[1];
            break;
          case 2:
            balls[i].color = availableColors[2];
            break;
          case 3:
            balls[i].color = availableColors[3];
            break;
          case 4:
            balls[i].color = availableColors[4];
            break;
        }
      }
    }
  }
}
