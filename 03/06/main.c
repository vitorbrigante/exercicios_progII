#include <stdio.h>
#include "temperature_conversor.h"

int main() {
    float temperature = 0.0;
    char o1, o2;

    scanf("%f", &temperature);
    scanf(" %c %c", &o1, &o2);

    if (o1 == 'c' && o2 == 'k') {
        printf("Temperature: %.2fK\n",
               convert_temperature(temperature, convert_celsius_to_kelvin));
    }

    if (o1 == 'c' && o2 == 'f') {
        printf("Temperature: %.2fFº\n",
               convert_temperature(temperature, convert_celsius_to_fahrenheit));
    }

    if (o1 == 'k' && o2 == 'c') {
        printf("Temperature: %.2fCº\n",
               convert_temperature(temperature, convert_kelvin_to_celsius));
    }

    if (o1 == 'k' && o2 == 'f') {
        printf("Temperature: %.2fFº\n",
               convert_temperature(temperature, convert_kelvin_to_fahrenheit));
    }

    if (o1 == 'f' && o2 == 'c') {
        printf("Temperature: %.2fCº\n",
               convert_temperature(temperature, convert_fahrenheit_to_celsius));
    }

    if (o1 == 'f' && o2 == 'k') {
        printf("Temperature: %.2fK\n",
               convert_temperature(temperature, convert_fahrenheit_to_kelvin));
    }

    return 0;
}
