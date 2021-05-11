#include "mbed.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;
Serial pc(USBTX, USBRX); // tx, rx

AnalogIn h(PA_0); //D11 on board
DigitalOut led(LED1);

float brightness=0.0;

int main()
{
    printf("\nSTM32 ADC example\n");
    
    

    while(1) {
        map<string,string> devices_dict;
        stringstream ss;
        string result;
        string key1 = "humidity_sensor";
        
        
        
        ss << key1;
        ss << "=";
        ss << (h.read()*100);
        // Если контейнер ss пустой, то добавлять & не будем, а так можем поставить в самое начало!!
        ss << "&";
        
        ss >> result;
        
        devices_dict.insert(make_pair(key1,value1));
        
        printf("ADC read = %f\n\r", (h.read()*100));
        led = !led;
        wait_ms(1000);
        
        printf(result.c_str());
    }
}
