#include <stdio.h>
#include <stdlib.h>

#define NUM_BINS 16

int main() {
    int bins[NUM_BINS] = {0};
    int bin_size = 1;
    int range_low = 0;
    int range_high = bin_size * NUM_BINS;
    int value;

    printf("%d bins of size %d for range [%d,%d)\n", NUM_BINS, bin_size, range_low, range_high);

    while (scanf("%d", &value) != EOF) {
        if (value < 0) {
            continue;
        }

        while (value >= range_high) {
            bin_size *= 2;
            range_low = 0;
            range_high = bin_size * NUM_BINS;

            // Reset all bins
            for (int i = 0; i < NUM_BINS; i++) {
                bins[i] = 0;
            }

            printf("%d bins of size %d for range [%d,%d)\n", NUM_BINS, bin_size, range_low, range_high);
        }

        // Adjust the value to the new range
        value -= range_low;

        // Update the bin_index
        int bin_index = value / bin_size;
        bins[bin_index]++;
    }

    for (int i = 0; i < NUM_BINS; i++) {
        printf("[%3d:%3d] ", range_low + i * bin_size, range_low + (i + 1) * bin_size - 1);
        for (int j = 0; j < bins[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
