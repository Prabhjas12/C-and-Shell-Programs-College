#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculateCoolness(double temp, double windspeed) {
    return 35.74 + 0.6215 * temp - 35.75 * pow(windspeed, 0.16) + 0.4275 * temp * pow(windspeed, 0.16);
}

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("Temp\tWind\tCoolness");
        double previousTemp = -11.0;
        for (double x = -10; x <= 40; x = x + 10) {
            for (double y = 5; y <= 15; y = y + 5) {
                if (x != previousTemp) {
                    printf("\n");
                }
                double coolness = calculateCoolness(x, y);
                if (x >= -10 && x <= 40 && y >= 5 && y <= 15) {
                    printf("%.1f\t%.1f\t%.1f\n", x, y, coolness);
                }
                previousTemp = x;
            }
        }
    } 
    else if (argc == 2) {
        double x = atof(argv[1]);
        if (x < -99 || x > 50) {
            printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
        } else {
            printf("Temp\tWind\tCoolness\n");
            for (double y = 5; y <= 15; y = y + 5) {
                double coolness = calculateCoolness(x, y);
                printf("%.1f\t%.1f\t%.1f\n", x, y, coolness);
            }
        }
    } 
    else if (argc == 3) {
        double x = atof(argv[1]);
        double y = atof(argv[2]);
        if (x < -99 || x > 50 || y < 0.5) {
            printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
        } else {
            printf("Temp\tWind\tCoolness\n");
            double coolness = calculateCoolness(x, y);
            printf("%.1f\t%.1f\t%.1f\n", x, y, coolness);
        }
    }
    else if(argc == 4){
        printf("Usage: ./coolness [temperature] [wind speed]\n");
    }

    return 0;
}
