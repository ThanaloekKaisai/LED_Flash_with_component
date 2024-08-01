#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

LED led1(16); 
LED led2(17); 
LED led3(5); 
LED led4(18); 
LED led5(19); 
LED led6(21); 
LED led7(22); 
LED led8(23); 

LED leds[] = {led1, led2, led3, led4, led5, led6, led7, led8};

extern "C" void app_main(void)
{
    int i = 0;
    int direction = 1; // 1 for forward, -1 for backward

    while(1)
    {
        leds[i].ON();
        vTaskDelay(100 / portTICK_PERIOD_MS);
        leds[i].OFF();

        // Move to the next LED
        i += direction;

        // Check if we need to change direction
        if (i == 7) // reached the end, switch direction to backward
        {
            direction = -1;
        }
        else if (i == 0) // reached the start, switch direction to forward
        {
            direction = 1;
        }
    }
}
