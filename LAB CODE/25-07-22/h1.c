#include <stdio.h>
#include <string.h>

void change_pos(char *ch1, char *ch2)
{
    char temp;
    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void change_permu(char *cht, int stno, int endno)
{
    int i;
    if (stno == endno)
        printf("%s\n", cht);
    else
        for (i = stno; i <= endno; i++)
        {
            change_pos(cht + stno, cht + i);
            change_permu(cht, stno + 1, endno);
            change_pos(cht + stno, cht + i);
        }
}

int main()
{
    char str[] = "abc";
    int n = strlen(str);
    printf("the permutations of %s are:", str);
    change_permu(str, 0, n - 1);
    printf("\n\n");
    return 0;
}