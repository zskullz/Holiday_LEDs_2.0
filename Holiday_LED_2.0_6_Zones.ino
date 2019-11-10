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

#if ZONEONE == 1
CRGB firstZone[FIRSTZONE_LEDS];
const int Pin_firstZone = 5; //marked as D1 on the board
int center_firstZone = 0;
int step_firstZone = -1;
int previousLED_firstZone = 0;
#endif

#if ZONETWO == 1
CRGB secondZone[SECONDZONE_LEDS];
const int Pin_secondZone = 4; //marked as D2 on the board
int center_secondZone = 0;
int step_secondZone = -1;
int previousLED_secondZone = 0;
#endif

#if ZONETHREE == 1
CRGB thirdZone[THIRDZONE_LEDS];
const int Pin_thirdZone = 0; //marked as D3 on the board
int center_thirdZone = 0;
int step_thirdZone = -1;
int previousLED_thirdZone = 0;
#endif

#if ZONEFOUR == 1
CRGB fourthZone[FOURTHZONE_LEDS];
const int Pin_fourthZone = 14; //marked as D5 on the board
int center_fourthZone = 0;
int step_fourthZone = -1;
int previousLED_fourthZone = 0;
#endif

#if ZONEFIVE == 1
CRGB fifthZone[FIFTHZONE_LEDS];
const int Pin_fifthZone = 12; //marked as D6 on the board
int center_fifthZone = 0;
int step_fifthZone = -1;
int previousLED_fifthZone = 0;
#endif

#if ZONESIX == 1
CRGB sixthZone[SIXTHZONE_LEDS];
const int Pin_sixthZone = 13; //marked as D7 on the board
int center_sixthZone = 0;
int step_sixthZone = -1;
int previousLED_sixthZone = 0;
#endif



/*****************  GENERAL VARIABLES  *************************************/

CRGBPalette16 gPal;
int glitterFrequency = 100;
int lightningChance = 65280;
int firesize = 40;
int SPARKING = 85;
int COOLING =  120;
bool gReverseDirection = false;
uint8_t mark = 0;
uint8_t gHue = 0; 
uint8_t startPosition = 0;
uint8_t glitterChance = 250;
int chaseDelay = 1000;
int lastPosition = 1;
int lightning = 1;
int raceSpeed = 12;
int BeatsPerMinute = 62;
uint8_t numberOfRainbows = 7;
int twinkleChance = 250;
int eyeChance = 248;
bool boot = true;
String effect = "None";
bool showGlitter = false;
bool showLightning = false;
bool audioEffects = false;
bool showLights = false;
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
byte brightness = 255;
char charPayload[50];
int maxLEDs = 500;
int locatorLED = 0;
char MQTT_locatorLED[50];
int locatorDelay = 1000;


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
        // ... and resubscribe
        client.subscribe(USER_MQTT_CLIENT_NAME"/configure");
        client.subscribe(USER_MQTT_CLIENT_NAME"/modifier");
        client.subscribe(USER_MQTT_CLIENT_NAME"/effect");
        client.subscribe(USER_MQTT_CLIENT_NAME"/state");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color1");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color2");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color3");
        client.subscribe(USER_MQTT_CLIENT_NAME"/power");
        client.subscribe(USER_MQTT_CLIENT_NAME"/brightness");
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
    client.publish(USER_MQTT_CLIENT_NAME"/modifierState", charPayload);
    if(effect == "Double_Crash" || effect == "Single_Race")
    {
      raceSpeed = (intPayload/20);
    }
    if(effect == "BPM")
    {
      BeatsPerMinute = (intPayload/4);
    }
    if(effect == "Color_Chase" || effect == "Blocked_Colors")
    {
      chaseDelay = (intPayload*5);
      if(chaseDelay < 100)
      {
        chaseDelay = 100;
      }
    }
    if(effect == "Color_Glitter")
    {
      glitterChance = (intPayload/2);
    }
    if(effect == "Rainbow")
    {
      numberOfRainbows = (intPayload/30);
    }
    if(effect == "Twinkle")
    {
      twinkleChance = map(intPayload, 0, 500, 0, 255);
    }
    if(effect == "Spooky_Eyes")
    {
      eyeChance = map(intPayload, 0, 500, 200, 255);
    }
    if(effect == "Fire")
    {
      firesize = map(intPayload, 0, 500, 10, 120);
    }
    if(effect == "LED_Locator")
    {
      locatorDelay = map(intPayload, 0, 500, 500, 5000);
    }
  }
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
    effect = newPayload;
    client.publish(USER_MQTT_CLIENT_NAME"/effectState", charPayload);
    
    #if ZONEONE == 1
    fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::Black); 
    #endif

    #if ZONETWO == 1
    fill_solid(secondZone, SECONDZONE_LEDS, CRGB::Black); 
    #endif

    #if ZONETHREE == 1
    fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::Black);
    #endif

    #if ZONEFOUR == 1
    fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::Black);
    #endif

    #if ZONEFIVE == 1
    fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::Black); 
    #endif
    
    #if ZONESIX == 1
    fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::Black);
    #endif  

    if(effect == "LED_Locator")
    {
      locator_Move();
    }
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
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      green1 = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blue1 = rgb_blue;
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
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      green2 = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blue2 = rgb_blue;
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
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      green3 = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blue3 = rgb_blue;
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
    client.publish(USER_MQTT_CLIENT_NAME "/brightnessState", charPayload); 
    brightness = intPayload;
  }
  
  if (newTopic == USER_MQTT_CLIENT_NAME"/power")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/powerState", charPayload); 
    if(newPayload == "ON")
    {
      showLights = true;
    }
    if(newPayload == "OFF")
    {
      showLights = false;
    }
  }
}



/*****************  GLOBAL LIGHT FUNCTIONS  *******************************/

void chase()
{
  if(startPosition == 5)
  {
    startPosition = 0;
  }
  else
  {
    startPosition++;
  }
  timer.setTimeout(chaseDelay, chase);
}

void checkIn()
{
  client.publish(USER_MQTT_CLIENT_NAME"/checkIn","OK");
  timer.setTimeout(120000, checkIn);
}

void choosePattern()
{
  if(showLights == true)
  {
   if(effect == "Color_Chase")
   {
    #if ZONEONE == 1 
      rGB(firstZone, FIRSTZONE_LEDS);
    #endif

    #if ZONETWO == 1
      rGB(secondZone, SECONDZONE_LEDS); 
    #endif

    #if ZONETHREE == 1
      rGB(thirdZone, THIRDZONE_LEDS); 
    #endif

    #if ZONEFOUR == 1
      rGB(fourthZone, FOURTHZONE_LEDS); 
    #endif

    #if ZONEFIVE == 1
      rGB(fifthZone, FIFTHZONE_LEDS); 
    #endif
    
    #if ZONESIX == 1
      rGB(sixthZone, SIXTHZONE_LEDS); 
    #endif 
      
   }
   if(effect == "Color_Glitter")
   {

    #if ZONEONE == 1
      ColorGlitter(firstZone, FIRSTZONE_LEDS, glitterChance);
    #endif

    #if ZONETWO == 1
      ColorGlitter(secondZone, SECONDZONE_LEDS, glitterChance);
    #endif

    #if ZONETHREE == 1
      ColorGlitter(thirdZone, THIRDZONE_LEDS, glitterChance);
    #endif

    #if ZONEFOUR == 1
      ColorGlitter(fourthZone, FOURTHZONE_LEDS, glitterChance);
    #endif

    #if ZONEFIVE == 1
      ColorGlitter(fifthZone, FIFTHZONE_LEDS, glitterChance);
    #endif
    
    #if ZONESIX == 1
      ColorGlitter(sixthZone, SIXTHZONE_LEDS, glitterChance);
    #endif  
   }
   if(effect == "Single_Race")
   {

    #if ZONEONE == 1
      previousLED_firstZone = SingleRace(firstZone, FIRSTZONE_LEDS, previousLED_firstZone);
    #endif

    #if ZONETWO == 1
      previousLED_secondZone = SingleRace(secondZone, SECONDZONE_LEDS, previousLED_secondZone); 
    #endif

    #if ZONETHREE == 1
      previousLED_thirdZone = SingleRace(thirdZone, THIRDZONE_LEDS, previousLED_thirdZone);
    #endif

    #if ZONEFOUR == 1
      previousLED_fourthZone = SingleRace(fourthZone, FOURTHZONE_LEDS, previousLED_fourthZone);
    #endif

    #if ZONEFIVE == 1
      previousLED_fifthZone = SingleRace(fifthZone, FIFTHZONE_LEDS, previousLED_fifthZone);
    #endif
    
    #if ZONESIX == 1
      previousLED_sixthZone = SingleRace(sixthZone, SIXTHZONE_LEDS, previousLED_sixthZone);
    #endif 
   }
   if(effect == "Double_Crash")
   {
    #if ZONEONE == 1
      fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 15);
      #ifdef ZONEONE_SECTION1_START
        Crash(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION1_START, ZONEONE_SECTION1_END);
      #endif
      #ifdef ZONEONE_SECTION2_START
        Crash(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION2_START, ZONEONE_SECTION2_END);
      #endif
      #ifdef ZONEONE_SECTION3_START
        Crash(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION3_START, ZONEONE_SECTION3_END);
      #endif
      #ifdef ZONEONE_SECTION4_START
        Crash(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION4_START, ZONEONE_SECTION4_END);
      #endif
      #ifdef ZONEONE_SECTION5_START
        Crash(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION5_START, ZONEONE_SECTION5_END);
      #endif
      #ifdef ZONEONE_SECTION6_START
        Crash(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION6_START, ZONEONE_SECTION6_END);
      #endif
      #ifdef ZONEONE_SECTION7_START
        Crash(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION7_START, ZONEONE_SECTION7_END);
      #endif
      #ifdef ZONEONE_SECTION8_START
        Crash(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION8_START, ZONEONE_SECTION8_END);
      #endif
      #ifdef ZONEONE_SECTION9_START
        Crash(firstZone, FIRSTZONE_LEDS, ZONEONE_SECTION9_START, ZONEONE_SECTION9_END);
      #endif
    #endif

    #if ZONETWO == 1
      fadeToBlackBy(secondZone, SECONDZONE_LEDS, 15);
      #ifdef ZONETWO_SECTION1_START
        Crash(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION1_START, ZONETWO_SECTION1_END);
      #endif
      #ifdef ZONETWO_SECTION2_START
        Crash(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION2_START, ZONETWO_SECTION2_END);
      #endif
      #ifdef ZONETWO_SECTION3_START
        Crash(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION3_START, ZONETWO_SECTION3_END);
      #endif
      #ifdef ZONETWO_SECTION4_START
        Crash(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION4_START, ZONETWO_SECTION4_END);
      #endif
      #ifdef ZONETWO_SECTION5_START
        Crash(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION5_START, ZONETWO_SECTION5_END);
      #endif
      #ifdef ZONETWO_SECTION6_START
        Crash(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION6_START, ZONETWO_SECTION6_END);
      #endif
      #ifdef ZONETWO_SECTION7_START
        Crash(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION7_START, ZONETWO_SECTION7_END);
      #endif
      #ifdef ZONETWO_SECTION8_START
        Crash(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION8_START, ZONETWO_SECTION8_END);
      #endif
      #ifdef ZONETWO_SECTION9_START
        Crash(secondZone, SECONDZONE_LEDS, ZONETWO_SECTION9_START, ZONETWO_SECTION9_END);
      #endif
    #endif

    #if ZONETHREE == 1
      fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 15);
      #ifdef ZONETHREE_SECTION1_START
        Crash(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION1_START, ZONETHREE_SECTION1_END);
      #endif
      #ifdef ZONETHREE_SECTION2_START
        Crash(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION2_START, ZONETHREE_SECTION2_END);
      #endif
      #ifdef ZONETHREE_SECTION3_START
        Crash(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION3_START, ZONETHREE_SECTION3_END);
      #endif
      #ifdef ZONETHREE_SECTION4_START
        Crash(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION4_START, ZONETHREE_SECTION4_END);
      #endif
      #ifdef ZONETHREE_SECTION5_START
        Crash(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION5_START, ZONETHREE_SECTION5_END);
      #endif
      #ifdef ZONETHREE_SECTION6_START
        Crash(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION6_START, ZONETHREE_SECTION6_END);
      #endif
      #ifdef ZONETHREE_SECTION7_START
        Crash(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION7_START, ZONETHREE_SECTION7_END);
      #endif
      #ifdef ZONETHREE_SECTION8_START
        Crash(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION8_START, ZONETHREE_SECTION8_END);
      #endif
      #ifdef ZONETHREE_SECTION9_START
        Crash(thirdZone, THIRDZONE_LEDS, ZONETHREE_SECTION9_START, ZONETHREE_SECTION9_END);
      #endif
    #endif

    #if ZONEFOUR == 1
      fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 15);
      #ifdef ZONEFOUR_SECTION1_START
        Crash(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION1_START, ZONEFOUR_SECTION1_END);
      #endif
      #ifdef ZONEFOUR_SECTION2_START
        Crash(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION2_START, ZONEFOUR_SECTION2_END);
      #endif
      #ifdef ZONEFOUR_SECTION3_START
        Crash(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION3_START, ZONEFOUR_SECTION3_END);
      #endif
      #ifdef ZONEFOUR_SECTION4_START
        Crash(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION4_START, ZONEFOUR_SECTION4_END);
      #endif
      #ifdef ZONEFOUR_SECTION5_START
        Crash(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION5_START, ZONEFOUR_SECTION5_END);
      #endif
      #ifdef ZONEFOUR_SECTION6_START
        Crash(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION6_START, ZONEFOUR_SECTION6_END);
      #endif
      #ifdef ZONEFOUR_SECTION7_START
        Crash(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION7_START, ZONEFOUR_SECTION7_END);
      #endif
      #ifdef ZONEFOUR_SECTION8_START
        Crash(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION8_START, ZONEFOUR_SECTION8_END);
      #endif
      #ifdef ZONEFOUR_SECTION9_START
        Crash(fourthZone, FOURTHZONE_LEDS, ZONEFOUR_SECTION9_START, ZONEFOUR_SECTION9_END);
      #endif
    #endif

    #if ZONEFIVE == 1
      fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 15);
      #ifdef ZONEFIVE_SECTION1_START
        Crash(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION1_START, ZONEFIVE_SECTION1_END);
      #endif
      #ifdef ZONEFIVE_SECTION2_START
        Crash(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION2_START, ZONEFIVE_SECTION2_END);
      #endif
      #ifdef ZONEFIVE_SECTION3_START
        Crash(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION3_START, ZONEFIVE_SECTION3_END);
      #endif
      #ifdef ZONEFIVE_SECTION4_START
        Crash(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION4_START, ZONEFIVE_SECTION4_END);
      #endif
      #ifdef ZONEFIVE_SECTION5_START
        Crash(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION5_START, ZONEFIVE_SECTION5_END);
      #endif
      #ifdef ZONEFIVE_SECTION6_START
        Crash(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION6_START, ZONEFIVE_SECTION6_END);
      #endif
      #ifdef ZONEFIVE_SECTION7_START
        Crash(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION7_START, ZONEFIVE_SECTION7_END);
      #endif
      #ifdef ZONEFIVE_SECTION8_START
        Crash(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION8_START, ZONEFIVE_SECTION8_END);
      #endif
      #ifdef ZONEFIVE_SECTION9_START
        Crash(fifthZone, FIFTHZONE_LEDS, ZONEFIVE_SECTION9_START, ZONEFIVE_SECTION9_END);
      #endif
    #endif
    
    #if ZONESIX == 1
      fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 15);
      #ifdef ZONESIX_SECTION1_START
        Crash(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION1_START, ZONESIX_SECTION1_END);
      #endif
      #ifdef ZONESIX_SECTION2_START
        Crash(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION2_START, ZONESIX_SECTION2_END);
      #endif
      #ifdef ZONESIX_SECTION3_START
        Crash(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION3_START, ZONESIX_SECTION3_END);
      #endif
      #ifdef ZONESIX_SECTION4_START
        Crash(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION4_START, ZONESIX_SECTION4_END);
      #endif
      #ifdef ZONESIX_SECTION5_START
        Crash(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION5_START, ZONESIX_SECTION5_END);
      #endif
      #ifdef ZONESIX_SECTION6_START
        Crash(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION6_START, ZONESIX_SECTION6_END);
      #endif
      #ifdef ZONESIX_SECTION7_START
        Crash(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION7_START, ZONESIX_SECTION7_END);
      #endif
      #ifdef ZONESIX_SECTION8_START
        Crash(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION8_START, ZONESIX_SECTION8_END);
      #endif
      #ifdef ZONESIX_SECTION9_START
        Crash(sixthZone, SIXTHZONE_LEDS, ZONESIX_SECTION9_START, ZONESIX_SECTION9_END);
      #endif
    #endif 
   }
   if(effect == "Rainbow")
   {
    #if ZONEONE == 1  
      Rainbow(firstZone, FIRSTZONE_LEDS);
    #endif

    #if ZONETWO == 1
      Rainbow(secondZone, SECONDZONE_LEDS);
    #endif

    #if ZONETHREE == 1
      Rainbow(thirdZone, THIRDZONE_LEDS);
    #endif

    #if ZONEFOUR == 1
      Rainbow(fourthZone, FOURTHZONE_LEDS);
    #endif

    #if ZONEFIVE == 1
      Rainbow(fifthZone, FIFTHZONE_LEDS);
    #endif
    
    #if ZONESIX == 1
      Rainbow(sixthZone, SIXTHZONE_LEDS);
    #endif 
   }
   if(effect == "Blocked_Colors")
   {
    #if ZONEONE == 1
      Blocked(firstZone, FIRSTZONE_LEDS);
    #endif

    #if ZONETWO == 1
      Blocked(secondZone, SECONDZONE_LEDS);
    #endif

    #if ZONETHREE == 1
      Blocked(thirdZone, THIRDZONE_LEDS);
    #endif

    #if ZONEFOUR == 1
      Blocked(fourthZone, FOURTHZONE_LEDS);
    #endif

    #if ZONEFIVE == 1
      Blocked(fifthZone, FIFTHZONE_LEDS);
    #endif
    
    #if ZONESIX == 1
      Blocked(sixthZone, SIXTHZONE_LEDS);
    #endif 

   }
   if(effect == "BPM")
   {

    #if ZONEONE == 1
      BPM(firstZone, FIRSTZONE_LEDS);
    #endif

    #if ZONETWO == 1
      BPM(secondZone, SECONDZONE_LEDS);
    #endif

    #if ZONETHREE == 1
      BPM(thirdZone, THIRDZONE_LEDS);
    #endif

    #if ZONEFOUR == 1
      BPM(fourthZone, FOURTHZONE_LEDS);
    #endif

    #if ZONEFIVE == 1
      BPM(fifthZone, FIFTHZONE_LEDS);
    #endif
    
    #if ZONESIX == 1
      BPM(sixthZone, SIXTHZONE_LEDS);
    #endif 
    
   }
   if(effect == "Twinkle")
   {
    #if ZONEONE == 1
      Twinkle(firstZone, FIRSTZONE_LEDS);
    #endif

    #if ZONETWO == 1
      Twinkle(secondZone, SECONDZONE_LEDS);
    #endif

    #if ZONETHREE == 1
      Twinkle(thirdZone, THIRDZONE_LEDS);
    #endif

    #if ZONEFOUR == 1
      Twinkle(fourthZone, FOURTHZONE_LEDS);
    #endif

    #if ZONEFIVE == 1
      Twinkle(fifthZone, FIFTHZONE_LEDS);
    #endif
    
    #if ZONESIX == 1
      Twinkle(sixthZone, SIXTHZONE_LEDS);
    #endif 

   }
   if(effect == "Fill_Solid")
   {
    #if ZONEONE == 1
      Solid(firstZone, FIRSTZONE_LEDS);
    #endif

    #if ZONETWO == 1
      Solid(secondZone, SECONDZONE_LEDS);
    #endif

    #if ZONETHREE == 1
      Solid(thirdZone, THIRDZONE_LEDS);
    #endif

    #if ZONEFOUR == 1
      Solid(fourthZone, FOURTHZONE_LEDS);
    #endif

    #if ZONEFIVE == 1
      Solid(fifthZone, FIFTHZONE_LEDS);
    #endif
    
    #if ZONESIX == 1
      Solid(sixthZone, SIXTHZONE_LEDS);
    #endif
    
   }
   if(effect == "Spooky_Eyes")
   {
    #if ZONEONE == 1
      Eyes(firstZone, FIRSTZONE_LEDS);
    #endif

    #if ZONETWO == 1
      Eyes(secondZone, SECONDZONE_LEDS);
    #endif

    #if ZONETHREE == 1
      Eyes(thirdZone, THIRDZONE_LEDS);
    #endif

    #if ZONEFOUR == 1
      Eyes(fourthZone, FOURTHZONE_LEDS);
    #endif

    #if ZONEFIVE == 1
      Eyes(fifthZone, FIFTHZONE_LEDS);
    #endif
    
    #if ZONESIX == 1
      Eyes(sixthZone, SIXTHZONE_LEDS);
    #endif

   }
   
   if(effect == "LED_Locator")
   {
    #if ZONEONE == 1
      Locator(firstZone, FIRSTZONE_LEDS);
    #endif

    #if ZONETWO == 1
      Locator(secondZone, SECONDZONE_LEDS);
    #endif

    #if ZONETHREE == 1
      Locator(thirdZone, THIRDZONE_LEDS);
    #endif

    #if ZONEFOUR == 1
      Locator(fourthZone, FOURTHZONE_LEDS);
    #endif

    #if ZONEFIVE == 1
      Locator(fifthZone, FIFTHZONE_LEDS);
    #endif
    
    #if ZONESIX == 1
      Locator(sixthZone, SIXTHZONE_LEDS);
    #endif

   }
   if(effect == "Ripple")
   {

    #if ZONEONE == 1
      Ripple(firstZone, FIRSTZONE_LEDS, center_firstZone, step_firstZone); 
    #endif

    #if ZONETWO == 1
      Ripple(secondZone, SECONDZONE_LEDS, center_secondZone, step_secondZone);
    #endif

    #if ZONETHREE == 1
      Ripple(thirdZone, THIRDZONE_LEDS, center_thirdZone, step_thirdZone);
    #endif

    #if ZONEFOUR == 1
      Ripple(fourthZone, FOURTHZONE_LEDS, center_fourthZone, step_fourthZone);
    #endif

    #if ZONEFIVE == 1
      Ripple(fifthZone, FIFTHZONE_LEDS, center_fifthZone, step_fifthZone);
    #endif
    
    #if ZONESIX == 1
      Ripple(sixthZone, SIXTHZONE_LEDS, center_sixthZone, step_sixthZone);
    #endif
   }
   if(effect == "Fire")
   {
      #if ZONEONE == 1 
        #if FIRSTZONE_SECTIONS >= 1
          static byte z1s1heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(firstZone, z1s1heat, ZONEONE_SECTION1_START, ZONEONE_SECTION1_END, ZONEONE_SECTION1_START_FIRE, ZONEONE_SECTION1_END_FIRE);
        #endif
        #if FIRSTZONE_SECTIONS >= 2
          static byte z1s2heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(firstZone, z1s2heat, ZONEONE_SECTION2_START, ZONEONE_SECTION2_END, ZONEONE_SECTION2_START_FIRE, ZONEONE_SECTION2_END_FIRE);
        #endif
        #if FIRSTZONE_SECTIONS >= 3
          static byte z1s3heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(firstZone, z1s3heat, ZONEONE_SECTION3_START, ZONEONE_SECTION3_END, ZONEONE_SECTION3_START_FIRE, ZONEONE_SECTION3_END_FIRE);
        #endif
        #if FIRSTZONE_SECTIONS >= 4
          static byte z1s4heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(firstZone, z1s4heat, ZONEONE_SECTION4_START, ZONEONE_SECTION4_END, ZONEONE_SECTION4_START_FIRE, ZONEONE_SECTION4_END_FIRE);
        #endif
        #if FIRSTZONE_SECTIONS >= 5
          static byte z1s5heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(firstZone, z1s5heat, ZONEONE_SECTION5_START, ZONEONE_SECTION5_END, ZONEONE_SECTION5_START_FIRE, ZONEONE_SECTION5_END_FIRE);
        #endif
        #if FIRSTZONE_SECTIONS >= 6
          static byte z1s6heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(firstZone, z1s6heat, ZONEONE_SECTION6_START, ZONEONE_SECTION6_END, ZONEONE_SECTION6_START_FIRE, ZONEONE_SECTION6_END_FIRE);
        #endif
        #if FIRSTZONE_SECTIONS >= 7
          static byte z1s7heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(firstZone, z1s7heat, ZONEONE_SECTION7_START, ZONEONE_SECTION7_END, ZONEONE_SECTION7_START_FIRE, ZONEONE_SECTION7_END_FIRE);
        #endif
        #if FIRSTZONE_SECTIONS >= 8
          static byte z1s8heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(firstZone, z1s8heat, ZONEONE_SECTION8_START, ZONEONE_SECTION8_END, ZONEONE_SECTION8_START_FIRE, ZONEONE_SECTION8_END_FIRE);
        #endif
        #if FIRSTZONE_SECTIONS >= 9
          static byte z1s9heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(firstZone, z1s9heat, ZONEONE_SECTION9_START, ZONEONE_SECTION9_END, ZONEONE_SECTION9_START_FIRE, ZONEONE_SECTION9_END_FIRE);
        #endif
      #endif
      #if ZONETWO == 1 
        #if SECONDZONE_SECTIONS >= 1
          static byte z2s1heat[ZONETWO_SECTION1_END-ZONETWO_SECTION1_START];
          fire(secondZone, z2s1heat, ZONETWO_SECTION1_START, ZONETWO_SECTION1_END, ZONETWO_SECTION1_START_FIRE, ZONETWO_SECTION1_END_FIRE);
        #endif
        #if SECONDZONE_SECTIONS >= 2
          static byte z2s2heat[ZONETWO_SECTION2_END-ZONETWO_SECTION2_START];
          fire(secondZone, z2s2heat, ZONETWO_SECTION2_START, ZONETWO_SECTION2_END, ZONETWO_SECTION2_START_FIRE, ZONETWO_SECTION2_END_FIRE);
        #endif
        #if SECONDZONE_SECTIONS >= 3
          static byte z2s3heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(secondZone, z2s3heat, ZONETWO_SECTION3_START, ZONETWO_SECTION3_END, ZONETWO_SECTION3_START_FIRE, ZONETWO_SECTION3_END_FIRE);
        #endif
        #if SECONDZONE_SECTIONS >= 4
          static byte z2s4heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(secondZone, z2s4heat, ZONETWO_SECTION4_START, ZONETWO_SECTION4_END, ZONETWO_SECTION4_START_FIRE, ZONETWO_SECTION4_END_FIRE);
        #endif
        #if SECONDZONE_SECTIONS >= 5
          static byte z2s5heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(secondZone, z2s5heat, ZONETWO_SECTION5_START, ZONETWO_SECTION5_END, ZONETWO_SECTION5_START_FIRE, ZONETWO_SECTION5_END_FIRE);
        #endif
        #if SECONDZONE_SECTIONS >= 6
          static byte z2s6heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(secondZone, z2s6heat, ZONETWO_SECTION6_START, ZONETWO_SECTION6_END, ZONETWO_SECTION6_START_FIRE, ZONETWO_SECTION6_END_FIRE);
        #endif
        #if SECONDZONE_SECTIONS >= 7
          static byte z2s7heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(secondZone, z2s7heat, ZONETWO_SECTION7_START, ZONETWO_SECTION7_END, ZONETWO_SECTION7_START_FIRE, ZONETWO_SECTION7_END_FIRE);
        #endif
        #if SECONDZONE_SECTIONS >= 8
          static byte z2s8heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(secondZone, z2s8heat, ZONETWO_SECTION8_START, ZONETWO_SECTION8_END, ZONETWO_SECTION8_START_FIRE, ZONETWO_SECTION8_END_FIRE);
        #endif
        #if SECONDZONE_SECTIONS >= 9
          static byte z2s9heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(secondZone, z2s9heat, ZONETWO_SECTION9_START, ZONETWO_SECTION9_END, ZONETWO_SECTION9_START_FIRE, ZONETWO_SECTION9_END_FIRE);
        #endif
      #endif
      #if ZONETHREE == 1 
        #if THIRDZONE_SECTIONS >= 1
          static byte z3s1heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(thirdZone, z3s1heat, ZONETHREE_SECTION1_START, ZONETHREE_SECTION1_END, ZONETHREE_SECTION1_START_FIRE, ZONETHREE_SECTION1_END_FIRE);
        #endif
        #if THIRDZONE_SECTIONS >= 2
          static byte z3s2heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(thirdZone, z3s2heat, ZONETHREE_SECTION2_START, ZONETHREE_SECTION2_END, ZONETHREE_SECTION2_START_FIRE, ZONETHREE_SECTION2_END_FIRE);
        #endif
        #if THIRDZONE_SECTIONS >= 3
          static byte z3s3heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(thirdZone, z3s3heat, ZONETHREE_SECTION3_START, ZONETHREE_SECTION3_END, ZONETHREE_SECTION3_START_FIRE, ZONETHREE_SECTION3_END_FIRE);
        #endif
        #if THIRDZONE_SECTIONS >= 4
          static byte z3s4heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(thirdZone, z3s4heat, ZONETHREE_SECTION4_START, ZONETHREE_SECTION4_END, ZONETHREE_SECTION4_START_FIRE, ZONETHREE_SECTION4_END_FIRE);
        #endif
        #if THIRDZONE_SECTIONS >= 5
          static byte z3s5heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(thirdZone, z3s5heat, ZONETHREE_SECTION5_START, ZONETHREE_SECTION5_END, ZONETHREE_SECTION5_START_FIRE, ZONETHREE_SECTION5_END_FIRE);
        #endif
        #if THIRDZONE_SECTIONS >= 6
          static byte z3s6heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(thirdZone, z3s6heat, ZONETHREE_SECTION6_START, ZONETHREE_SECTION6_END, ZONETHREE_SECTION6_START_FIRE, ZONETHREE_SECTION6_END_FIRE);
        #endif
        #if THIRDZONE_SECTIONS >= 7
          static byte z3s7heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(thirdZone, z3s7heat, ZONETHREE_SECTION7_START, ZONETHREE_SECTION7_END, ZONETHREE_SECTION7_START_FIRE, ZONETHREE_SECTION7_END_FIRE);
        #endif
        #if THIRDZONE_SECTIONS >= 8
          static byte z3s8heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(thirdZone, z3s8heat, ZONETHREE_SECTION8_START, ZONETHREE_SECTION8_END, ZONETHREE_SECTION8_START_FIRE, ZONETHREE_SECTION8_END_FIRE);
        #endif
        #if THIRDZONE_SECTIONS >= 9
          static byte z3s9heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(thirdZone, z3s9heat, ZONETHREE_SECTION9_START, ZONETHREE_SECTION9_END, ZONETHREE_SECTION9_START_FIRE, ZONETHREE_SECTION9_END_FIRE);
        #endif
      #endif
  
      #if ZONEFOUR == 1 
        #if FOURTHZONE_SECTIONS >= 1
          static byte z4s1heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fourthZone, z4s1heat, ZONEFOUR_SECTION1_START, ZONEFOUR_SECTION1_END, ZONEFOUR_SECTION1_START_FIRE, ZONEFOUR_SECTION1_END_FIRE);
        #endif
        #if FOURTHZONE_SECTIONS >= 2
          static byte z4s2heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fourthZone, z4s2heat, ZONEFOUR_SECTION2_START, ZONEFOUR_SECTION2_END, ZONEFOUR_SECTION2_START_FIRE, ZONEFOUR_SECTION2_END_FIRE);
        #endif
        #if FOURTHZONE_SECTIONS >= 3
          static byte z4s3heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fourthZone, z4s3heat, ZONEFOUR_SECTION3_START, ZONEFOUR_SECTION3_END, ZONEFOUR_SECTION3_START_FIRE, ZONEFOUR_SECTION3_END_FIRE);
        #endif
        #if FOURTHZONE_SECTIONS >= 4
          static byte z4s4heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fourthZone, z4s4heat, ZONEFOUR_SECTION4_START, ZONEFOUR_SECTION4_END, ZONEFOUR_SECTION4_START_FIRE, ZONEFOUR_SECTION4_END_FIRE);
        #endif
        #if FOURTHZONE_SECTIONS >= 5
          static byte z4s5heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fourthZone, z4s5heat, ZONEFOUR_SECTION5_START, ZONEFOUR_SECTION5_END, ZONEFOUR_SECTION5_START_FIRE, ZONEFOUR_SECTION5_END_FIRE);
        #endif
        #if FOURTHZONE_SECTIONS >= 6
          static byte z4s6heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fourthZone, z4s6heat, ZONEFOUR_SECTION6_START, ZONEFOUR_SECTION6_END, ZONEFOUR_SECTION6_START_FIRE, ZONEFOUR_SECTION6_END_FIRE);
        #endif
        #if FOURTHZONE_SECTIONS >= 7
          static byte z4s7heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fourthZone, z4s7heat, ZONEFOUR_SECTION7_START, ZONEFOUR_SECTION7_END, ZONEFOUR_SECTION7_START_FIRE, ZONEFOUR_SECTION7_END_FIRE);
        #endif
        #if FOURTHZONE_SECTIONS >= 8
          static byte z4s8heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fourthZone, z4s8heat, ZONEFOUR_SECTION8_START, ZONEFOUR_SECTION8_END, ZONEFOUR_SECTION8_START_FIRE, ZONEFOUR_SECTION8_END_FIRE);
        #endif
        #if FOURTHZONE_SECTIONS >= 9
          static byte z4s9heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fourthZone, z4s9heat, ZONEFOUR_SECTION9_START, ZONEFOUR_SECTION9_END, ZONEFOUR_SECTION9_START_FIRE, ZONEFOUR_SECTION9_END_FIRE);
        #endif
      #endif
  
      #if ZONEFIVE == 1 
        #if FIFTHZONE_SECTIONS >= 1
          static byte z5s1heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fifthZone, z5s1heat, ZONEFIVE_SECTION1_START, ZONEFIVE_SECTION1_END, ZONEFIVE_SECTION1_START_FIRE, ZONEFIVE_SECTION1_END_FIRE);
        #endif
        #if FIFTHZONE_SECTIONS >= 2
          static byte z5s2heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fifthZone, z5s2heat, ZONEFIVE_SECTION2_START, ZONEFIVE_SECTION2_END, ZONEFIVE_SECTION2_START_FIRE, ZONEFIVE_SECTION2_END_FIRE);
        #endif
        #if FIFTHZONE_SECTIONS >= 3
          static byte z5s3heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fifthZone, z5s3heat, ZONEFIVE_SECTION3_START, ZONEFIVE_SECTION3_END, ZONEFIVE_SECTION3_START_FIRE, ZONEFIVE_SECTION3_END_FIRE);
        #endif
        #if FIFTHZONE_SECTIONS >= 4
          static byte z5s4heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fifthZone, z5s4heat, ZONEFIVE_SECTION4_START, ZONEFIVE_SECTION4_END, ZONEFIVE_SECTION4_START_FIRE, ZONEFIVE_SECTION4_END_FIRE);
        #endif
        #if FIFTHZONE_SECTIONS >= 5
          static byte z5s5heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fifthZone, z5s5heat, ZONEFIVE_SECTION5_START, ZONEFIVE_SECTION5_END, ZONEFIVE_SECTION5_START_FIRE, ZONEFIVE_SECTION5_END_FIRE);
        #endif
        #if FIFTHZONE_SECTIONS >= 6
          static byte z5s6heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fifthZone, z5s6heat, ZONEFIVE_SECTION6_START, ZONEFIVE_SECTION6_END, ZONEFIVE_SECTION6_START_FIRE, ZONEFIVE_SECTION6_END_FIRE);
        #endif
        #if FIFTHZONE_SECTIONS >= 7
          static byte z5s7heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fifthZone, z5s7heat, ZONEFIVE_SECTION7_START, ZONEFIVE_SECTION7_END, ZONEFIVE_SECTION7_START_FIRE, ZONEFIVE_SECTION7_END_FIRE);
        #endif
        #if FIFTHZONE_SECTIONS >= 8
          static byte z5s8heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fifthZone, z5s8heat, ZONEFIVE_SECTION8_START, ZONEFIVE_SECTION8_END, ZONEFIVE_SECTION8_START_FIRE, ZONEFIVE_SECTION8_END_FIRE);
        #endif
        #if FIFTHZONE_SECTIONS >= 9
          static byte z5s9heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(fifthZone, z5s9heat, ZONEFIVE_SECTION9_START, ZONEFIVE_SECTION9_END, ZONEFIVE_SECTION9_START_FIRE, ZONEFIVE_SECTION9_END_FIRE);
        #endif
      #endif
  
      #if ZONESIX == 1
        #if SIXTHZONE_SECTIONS >= 1
          static byte z6s1heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(sixthZone, z6s1heat, ZONESIX_SECTION1_START, ZONESIX_SECTION1_END, ZONESIX_SECTION1_START_FIRE, ZONESIX_SECTION1_END_FIRE);
        #endif
        #if SIXTHZONE_SECTIONS >= 2
          static byte z6s2heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(sixthZone, z6s2heat, ZONESIX_SECTION2_START, ZONESIX_SECTION2_END, ZONESIX_SECTION2_START_FIRE, ZONESIX_SECTION2_END_FIRE);
        #endif
        #if SIXTHZONE_SECTIONS >= 3
          static byte z6s3heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(sixthZone, z6s3heat, ZONESIX_SECTION3_START, ZONESIX_SECTION3_END, ZONESIX_SECTION3_START_FIRE, ZONESIX_SECTION3_END_FIRE);
        #endif
        #if SIXTHZONE_SECTIONS >= 4
          static byte z6s4heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(sixthZone, z6s4heat, ZONESIX_SECTION4_START, ZONESIX_SECTION4_END, ZONESIX_SECTION4_START_FIRE, ZONESIX_SECTION4_END_FIRE);
        #endif
        #if SIXTHZONE_SECTIONS >= 5
          static byte z6s5heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(sixthZone, z6s5heat, ZONESIX_SECTION5_START, ZONESIX_SECTION5_END, ZONESIX_SECTION5_START_FIRE, ZONESIX_SECTION5_END_FIRE);
        #endif
        #if SIXTHZONE_SECTIONS >= 6
          static byte z6s6heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(sixthZone, z6s6heat, ZONESIX_SECTION6_START, ZONESIX_SECTION6_END, ZONESIX_SECTION6_START_FIRE, ZONESIX_SECTION6_END_FIRE);
        #endif
        #if SIXTHZONE_SECTIONS >= 7
          static byte z6s7heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(sixthZone, z6s7heat, ZONESIX_SECTION7_START, ZONESIX_SECTION7_END, ZONESIX_SECTION7_START_FIRE, ZONESIX_SECTION7_END_FIRE);
        #endif
        #if SIXTHZONE_SECTIONS >= 8
          static byte z6s8heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(sixthZone, z6s8heat, ZONESIX_SECTION8_START, ZONESIX_SECTION8_END, ZONESIX_SECTION8_START_FIRE, ZONESIX_SECTION8_END_FIRE);
        #endif
        #if SIXTHZONE_SECTIONS >= 9
          static byte z6s9heat[ZONETWO_SECTION3_END-ZONETWO_SECTION3_START];
          fire(sixthZone, z6s9heat, ZONESIX_SECTION9_START, ZONESIX_SECTION9_END, ZONESIX_SECTION9_START_FIRE, ZONESIX_SECTION9_END_FIRE);
        #endif
      #endif
    }
  }
  if(showLights == false)
  {
    #if ZONEONE == 1 
    fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::Black); 
    #endif

    #if ZONETWO == 1
    fill_solid(secondZone, SECONDZONE_LEDS, CRGB::Black); 
    #endif

    #if ZONETHREE == 1
    fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::Black);
    #endif

    #if ZONEFOUR == 1
    fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::Black);
    #endif

    #if ZONEFIVE == 1
    fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::Black); 
    #endif
    
    #if ZONESIX == 1
    fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::Black);
    #endif
  }
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
    #endif

    #if ZONETWO == 1
    FastLED.addLeds<WS2812B, Pin_secondZone, SECONDZONE_COLOR_ORDER>(secondZone, SECONDZONE_LEDS);
    #endif

    #if ZONETHREE == 1
    FastLED.addLeds<WS2812B, Pin_thirdZone, THIRDZONE_COLOR_ORDER>(thirdZone, THIRDZONE_LEDS);
    #endif

    #if ZONEFOUR == 1
    FastLED.addLeds<WS2812B, Pin_fourthZone, FOURTHZONE_COLOR_ORDER>(fourthZone, FOURTHZONE_LEDS);
    #endif

    #if ZONEFIVE == 1
    FastLED.addLeds<WS2812B, Pin_fifthZone, FIFTHZONE_COLOR_ORDER>(fifthZone, FIFTHZONE_LEDS);
    #endif
    
    #if ZONESIX == 1
    FastLED.addLeds<WS2812B, Pin_sixthZone, SIXTHZONE_COLOR_ORDER>(sixthZone, SIXTHZONE_LEDS);
    #endif
}


void locator_Move()
{
  if(effect == "LED_Locator")
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
    timer.setTimeout(locatorDelay, locator_Move);
  }
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
  
  timer.setTimeout(10000, chase);
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
  if(showLights == false)
  {
    ArduinoOTA.handle();  
  }
  timer.run();
  EVERY_N_MILLISECONDS( 20 ) { gHue++; }
  choosePattern();

  #if ZONEONE == 1
  FastLED[0].showLeds(brightness);
  #endif

  #if ZONETWO == 1
  FastLED[1].showLeds(brightness);
  #endif

  #if ZONETHREE == 1
  FastLED[2].showLeds(brightness);
  #endif

  #if ZONEFOUR == 1
  FastLED[3].showLeds(brightness);
  #endif

  #if ZONEFIVE == 1
  FastLED[4].showLeds(brightness);
  #endif
  
  #if ZONESIX == 1
  FastLED[5].showLeds(brightness);
  #endif
  
}


/*****************  Animation Functions  ****************************************/

void Ripple(CRGB zone[], int ledCount, int zoneCenter, int zoneStep)
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
}

void rGB(CRGB zone[], int zoneLEDS)
{
  if(startPosition < 6)
  {
    fadeToBlackBy( zone, zoneLEDS, 80);
    for(int pixel = startPosition+1; pixel < zoneLEDS; pixel+=6)  
    {
      if(pixel <= zoneLEDS)
      {
        zone[pixel] = CRGB(red1,green1,blue1);
      }
    }
    for(int pixel = startPosition+3; pixel < zoneLEDS; pixel+=6)
    {
      if(pixel <= zoneLEDS)
      {
        zone[pixel] = CRGB(red2,green2,blue2);
      }
    }
    for(int pixel = startPosition+5; pixel < zoneLEDS; pixel+=6)
    {
      if(pixel <= zoneLEDS)
      {
        zone[pixel] = CRGB(red3,green3,blue3);
      } 
    }
  }
  if(startPosition == 1)
  {
    zone[0]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 2)
  {
    zone[1]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 3)
  {
    zone[2]=CRGB(red3,green3,blue3);
    zone[0]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 4)
  {
    zone[3]=CRGB(red3,green3,blue3);
    zone[1]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 5)
  {
    zone[4]=CRGB(red3,green3,blue3);
    zone[2]=CRGB(red2,green2,blue2);
    zone[0]=CRGB(red1,green1,blue1);
  }
}

void ColorGlitter(CRGB zone[], int zoneLEDS, fract8 chanceOfGlitter) 
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

int SingleRace(CRGB zone[], int zoneLEDS, int previousZoneLED)
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

void Crash(CRGB zone[], int zoneLEDS, int sectionStart, int sectionEnd)
{
    int pos = beatsin16( raceSpeed, 0, (sectionEnd - sectionStart) );
    zone[sectionStart + pos] = CRGB(red1,green1,blue1);
    zone[sectionEnd - pos] = CRGB(red2,green2,blue2);
}

void Rainbow(CRGB zone[], int zoneLEDS)
{
  fill_rainbow( zone, zoneLEDS, gHue, numberOfRainbows);
}

void Blocked(CRGB zone[], int zoneLEDS)
{
  fadeToBlackBy( zone, zoneLEDS, 2);
  for( int mark = 0; mark < zoneLEDS; mark+=30)
  {
    for( int i = 0; i < 9; i++) 
    {
      if(startPosition == 0 || startPosition == 1)
      {
        if(i+mark <= zoneLEDS)
        {
          zone[i+mark] = CRGB(red1,green1,blue1);
        }
        if(i+10+mark <= zoneLEDS)
        {
          zone[i+10+mark] = CRGB(red2,green2,blue2);
        }
        if(i+20+mark <= zoneLEDS)
        {
          zone[i+20+mark] = CRGB(red3,green3,blue3);
        }
      }
      if(startPosition == 2 || startPosition == 3)
      {
        if(i+mark <= zoneLEDS)
        {
          zone[i+mark] = CRGB(red2,green2,blue2);
        }
        if(i+10+mark <= zoneLEDS)
        {
          zone[i+10+mark] = CRGB(red3,green3,blue3);
        }
        if(i+20+mark <= zoneLEDS)
        {
          zone[i+20+mark] = CRGB(red1,green1,blue1);
        }
      }
      if(startPosition == 4 || startPosition == 5)
      {
        if(i+mark <= zoneLEDS)
        {
          zone[i+mark] = CRGB(red3,green3,blue3);
        }
        if(i+10+mark <= zoneLEDS)
        {
          zone[i+10+mark] = CRGB(red1,green1,blue1);
        }
        if(i+20+mark <= zoneLEDS)
        {
          zone[i+20+mark] = CRGB(red2,green2,blue2);
        }
      }
    }
  }
}

void BPM(CRGB zone[], int zoneLEDS)
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

void Twinkle(CRGB zone[], int zoneLEDS)
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

void Eyes(CRGB zone[], int zoneLEDS)
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

void fire(CRGB zone[], byte heat[], int sectionStart, int sectionEnd, int fireStart, int fireEnd)
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
