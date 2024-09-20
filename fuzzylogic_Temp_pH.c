#include <stdio.h>

// Function prototypes
float fuzzify_temperature(float temp);
float fuzzify_ph(float ph);
float defuzzify(float temp_level, float ph_level);

// Main function
int main() {
    float temperature, ph;
    float temp_level, ph_level, control_time;

    // Input temperature and pH from sensors
    printf("Enter temperature (in degrees): ");
    scanf("%f", &temperature);
    printf("Enter pH value: ");
    scanf("%f", &ph);

    // Fuzzify the inputs
    temp_level = fuzzify_temperature(temperature);
    ph_level = fuzzify_ph(ph);

    // Apply fuzzy logic rules and defuzzify to get control time
    control_time = defuzzify(temp_level, ph_level);

    // Output the time to turn on the control device
    printf("Device should be ON for %.2f seconds\n", control_time);

    return 0;
}

// Function to fuzzify temperature
float fuzzify_temperature(float temp) {
    if (temp < 20.0) {
        return 0.1;  // Low temperature
    } else if (temp >= 20.0 && temp <= 30.0) {
        return 0.5;  // Normal temperature
    } else {
        return 0.9;  // High temperature
    }
}

// Function to fuzzify pH
float fuzzify_ph(float ph) {
    if (ph < 6.5) {
        return 0.1;  // Acidic (Low pH)
    } else if (ph >= 6.5 && ph <= 7.5) {
        return 0.5;  // Neutral (Normal pH)
    } else {
        return 0.9;  // Alkaline (High pH)
    }
}

// Function to defuzzify (determine the control time based on fuzzy inputs)
float defuzzify(float temp_level, float ph_level) {
    if (temp_level > 0.7 && ph_level < 0.3) {
        return 10.0;  // Long time (if temperature is high and pH is low)
    } else if (temp_level > 0.3 && temp_level <= 0.7 && ph_level > 0.3 && ph_level <= 0.7) {
        return 3.0;   // Short time (if temperature and pH are normal)
    } else {
        return 5.0;   // Moderate time (other conditions)
    }
}
