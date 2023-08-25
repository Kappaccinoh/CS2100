#include <stdio.h>
#define MAX 10

int readArray(int [], int);
void printArray(int [], int);
void reverseArray(int [], int);

int main(void) {
    int array[MAX], numElements;

    numElements = readArray(array, MAX);
    reverseArray(array, numElements);
    printArray(array, numElements);

    return 0;
}

int readArray(int arr[], int limit) {
    int num_elements = 0;
    int value;
    printf("Enter up to %d integers, terminating with a negative integer.\n", limit);
    for (int i = 0; i < limit; i++) {
        scanf("%d", &value);
        if (value < 0) {
            break;
        }
        *arr = value;
        arr++;
        num_elements++;
    }

    return num_elements;
}

// Iterative
void reverseArray(int arr[], int size) {
    int temp[size];
    int *temp_ptr = temp;
    for(int i = 0; i < size - 1; i++) {
        arr++;
    }
    for(int i = 0; i < size; i++) {
        *temp_ptr = *arr;
        temp_ptr++;
        arr--;
    }
    temp_ptr--;
    arr++;
    for (int i = 0; i < size; i++) {
        temp_ptr--;
    }
    temp_ptr++;

    for (int i = 0; i < size; i++) {
        *arr = *temp_ptr;
        arr++;
        temp_ptr++;
    }
}

/*
// Recursive
void reverseArray(int arr[], int size) {

}
*/

void printArray(int arr[], int size) {
    int i;

    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}