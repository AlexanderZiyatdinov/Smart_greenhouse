#include "mbed.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;
Serial pc(USBTX, USBRX); // tx, rx

AnalogIn h(PA_0); //D11 on board
DigitalOut led(PA_0);
DigitalOut motor(D4);

float brightness=0.0;


//public map<string,string> states;

void light(string v)
{
    if (v == "ON")
        led = true;
    else if (v == "OFF")
        led = false;
    
    }
    
void set_motor(string v)
{
    if (v == "ON")
        motor = true;
    else if (v == "OFF")
        motor = false;
    
    }

void test(string k, string v)
{
    if (k == "LIGHT")
        
        light(v);
    
    
    else if (k == "MOTOR")
    {
        set_motor(v);
        }
    }


int main()
{
   // string h = "qwe";
//    const char * c = h.c_str();
    printf("\nSTM32 ADC example\n");
    string motor_state = "";
    string light_state = "";
 
   // pc.printf(c);
    string allResults = "";
    while(1) {
      // pc.printf()
   //   
//      if (motor)
//        motor_state = "ON";
//      else
//         motor_state = "OFF";
//         
//      if (led)
//         light_state = "ON";
//      else
//         light_state = "OFF";
      
     // printf("HUMIDITY=%f&LIGHT=%b&MOTOR=%b\n\r", (h.read()*100), motor, led );
    
      while (pc.readable() > 0)
      {
          char c = pc.getc();
          if (c != '\n')
        
            allResults += c;
          
         
          
          if (c == '\n')
          {
              const char *tmp = allResults.c_str();
              //pc.printf(result);
//              allResults = "";
             // const char *r = (char *)result[4]; 
//              pc.printf(r);

              string key = "";
              string value = "";
              bool is_key = true;
              for (int i = 0; i < strlen(tmp); i++)
              {
                  
//                if (allResults[i] == '#')
//                      break;
                      
                  if (allResults[i] == '=') {
                      is_key=false;continue;}
                      
                  if (is_key)
                    {
                         key += allResults[i];
                    }
                    
                  else {
                    value += allResults[i];
                    }
                     
                 
                pc.putc(allResults[i]);
//                  i++;
                  }
                  

              const char *result = key.c_str();
              pc.printf(result);
              result = value.c_str();
              pc.printf(result);
              allResults = "";
              
              test(key, value);
              
              
              break;
          }
          
          
      }
    }
}
