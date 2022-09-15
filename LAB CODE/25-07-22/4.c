#include <stdio.h>

struct complex
{
    float real;
    float imaginary;
} c1, c2, add, result;

void sum(struct complex c1, struct complex c2) {
    struct add;
    add.real = c1.real + c2.real;
    add.imaginary = c1.imaginary + c2.imaginary; 
    printf("SUM = %0.2f + i %0.2f", add.real, add.imaginary);
}

int main()
{

    struct complex cnum1, cnum2;
    printf("Enter real and imaginary part of first complex number:\n");
    scanf("%f%f", &cnum1.real, &cnum1.imaginary);
    printf("Enter real and imaginary part of second complex number:\n");
    scanf("%f%f", &cnum2.real, &cnum2.imaginary);
    sum(cnum1, cnum2);
    return 0;
}