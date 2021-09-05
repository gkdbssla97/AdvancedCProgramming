#include <stdio.h>

void MaxAndMin(int ** maxPtr, int ** minPtr, int arr[], int size);

int main(void) {
    int * maxPtr, * minPtr;
    int arr[5];

    for(int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

    MaxAndMin(&maxPtr, &minPtr, arr, sizeof(arr)/sizeof(int));
    printf("max:%d\nmin:%d\n", *maxPtr, *minPtr);
}

void MaxAndMin(int ** maxPtr, int ** minPtr, int arr[], int size) {
    int * max,* min;
    max = min = &arr[0];

    for(int i = 0; i < size; i++) {
        if(arr[i] > *max)
            max = &arr[i];
        if(arr[i] < * min)
            min = &arr[i];
    } *maxPtr = max, *minPtr = min;
}

/*12
 * 3
 * 1
 * 4
 * 3
 * 4
 * 1
 * ///
 * 2
 * 3
 * 4
 * 4
 * 12
 * 2
 * */