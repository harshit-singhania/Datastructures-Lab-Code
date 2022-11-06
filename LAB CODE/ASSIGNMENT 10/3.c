// Given an array “container[]” and integer “hunt”. WAP to find whether “hunt” is
// present in container[] or not. If present, then triple the value of “hunt” and
// search again. Repeat these steps until “hunt” is not found. Finally return the
// value of “hunt”.
// Input : container[] = {1, 2, 3} and hunt = 1 then Output : 9
// Explanation: Start with hunt = 1. Since it is present in array, it becomes 3.
// Now 3 is present in array and hence hunt becomes 9 . Since 9 is not present,
// program returns 9.

#include <stdio.h>

int triple(int container[], int size, int hunt) {
    int i; 
    for (i=0; i<size;i++) {
        if (container[i] == hunt) {
            hunt*=3; 
        }
    }
    return hunt;
}

int main() {
    int size, hunt, i, c2; 
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int container[size];
    printf("Enter the elements of the array: ");
    for (i=0; i<size; i++) {
        scanf("%d", &container[i]);
    }
    printf("Enter hunt: ");
    scanf("%d", &hunt);
    int c1 = triple(container, size, hunt);
    for (i=0; i<size; i++) {
        if (c1 == container[i]) {
             c2 = c1*3;
        }
    } 
    printf("The value of hunt is: %d", c2 );
}