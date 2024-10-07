#include <stdio.h>

// function declarations
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float temp, converted_temp;
    int input_scale, output_scale;
    float (*convert_function)(float);  // function pointer for conversion

    // input temperature value
    printf("Enter temperature value: ");
    scanf("%f", &temp);

    // input scale
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &input_scale);

    // output scale
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &output_scale);

    // choose appropriate conversion function based on input and output scales
    if (input_scale == 1 && output_scale == 2) {
        convert_function = celsius_to_fahrenheit;
    } else if (input_scale == 1 && output_scale == 3) {
        convert_function = celsius_to_kelvin;
    } else if (input_scale == 2 && output_scale == 1) {
        convert_function = fahrenheit_to_celsius;
    } else if (input_scale == 2 && output_scale == 3) {
        convert_function = fahrenheit_to_kelvin;
    } else if (input_scale == 3 && output_scale == 1) {
        convert_function = kelvin_to_celsius;
    } else if (input_scale == 3 && output_scale == 2) {
        convert_function = kelvin_to_fahrenheit;
    } else {
        printf("Invalid conversion.\n");
        return 1;
    }

    // perform conversion using the selected function
    converted_temp = convert_function(temp);
    printf("Converted temperature: %.2f\n", converted_temp);

    // convert to Celsius for categorization
    float temp_in_celsius;
    if (output_scale == 1) {
        temp_in_celsius = converted_temp; // already in Celsius
    } else if (output_scale == 2) {
        temp_in_celsius = fahrenheit_to_celsius(converted_temp); // Fahrenheit to Celsius
    } else {
        temp_in_celsius = kelvin_to_celsius(converted_temp); // Kelvin to Celsius
    }

    // categorize temp
    categorize_temperature(temp_in_celsius);

    return 0;
}

// performs the temp conversions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    // Fahrenheit to Celsius, then Celsius to Kelvin
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    // Kelvin to Celsius, then Celsius to Fahrenheit
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// prints the categorized temp
void categorize_temperature(float temp_in_celsius) {
    if (temp_in_celsius < 0) {
        printf("Category: Freezing. Advisory: Stay indoors.\n");
    } else if (temp_in_celsius <= 10) {
        printf("Category: Cold. Advisory: Wear a jacket.\n");
    } else if (temp_in_celsius <= 25) {
        printf("Category: Comfortable. Advisory: It feels nice outside.\n");
    } else if (temp_in_celsius <= 35) {
        printf("Category: Hot. Advisory: Stay hydrated.\n");
    } else {
        printf("Category: Extreme Heat. Advisory: Stay indoors.\n");
    }
}