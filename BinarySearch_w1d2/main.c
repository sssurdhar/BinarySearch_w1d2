//
//  main.c
//  BinarySearch_w1d2
//
//  Created by Sunny Surdhar on 2015-05-05.
//  Copyright (c) 2015 Sunny Surdhar. All rights reserved.
//

#include <stdio.h>

typedef struct{
    int startIndex;
    int count;
}Range;

Range binarySearch (Range range, int value, int ints[], int min, int max);

int main() {
    
    int array[] = {0,1,2,2,2,2,10,10,10,12,13,14,16,20,21,23};
    
    int arraylength = (sizeof(array)/sizeof(int));
    
    Range range;

    Range result = binarySearch(range, 10, array, 0, arraylength);
    
    printf("{%d,%d}\n", result.startIndex,result.count);
    
    return 0;
}

Range binarySearch (Range range, int value, int ints[], int min, int max){
    if (max < min) {
        range.startIndex = -1;
        range.count = 0;
        return range;
    }
    else {
        int midpoint = (min+max)/2;
        
        if (ints[midpoint] < value) {
            return binarySearch(range, value, ints, midpoint + 1, max);
        }
        else if (ints[midpoint] > value) {
            return binarySearch(range, value, ints, min, midpoint -1);
        }
        else {
            while (ints[midpoint-1] == value) {
                midpoint--;
            }
            range.startIndex = midpoint;
            range.count = 1;
            while (ints[midpoint+1] == value) {
                range.count++;
                midpoint++;
            }
            return range;
            }
        }
}






