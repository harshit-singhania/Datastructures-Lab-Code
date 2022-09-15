#include <stdio.h>
#include <string.h>

struct Distance
{
    int km;
    int m;
} d1, d2, result;

void add_distance(struct Distance d1, struct Distance d2); 
int main()
{
    printf("enter first distance \n");
    printf("enter km: ");
    scanf("%d", &d1.km);
    printf("enter m: ");
    scanf("%d", &d1.m);

    printf("enter second distance \n");
    printf("enter km: ");
    scanf("%d", &d2.km);
    printf("enter m: ");
    scanf("%d", &d2.m);

    add_distance(d1, d2);
    return 0;
}

void add_distance(struct Distance d1, struct Distance d2) { 
    result.km = d1.km + d2.km;
    result.m = d1.m + d2.m;

    printf("the distance is %d km and %d meter", result.km, result.m);
}