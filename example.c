#include "MedianFilter.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define NUM_ELEMENTS    7

static sMedianFilter_t medianFilter;
static sMedianNode_t medianBuffer[NUM_ELEMENTS];

int main()
{
    medianFilter.numNodes = NUM_ELEMENTS;
    medianFilter.medianBuffer = medianBuffer;
    
    MEDIANFILTER_Init(&medianFilter);
    
    while(1)
    {
        int newValue = rand() % 10;
        int medianValue = MEDIANFILTER_Insert(&medianFilter, newValue);
        printf("New value: %d \tMedian value: %d\r\n", newValue, medianValue);
        sleep(1);
    }

    return 0;
}
