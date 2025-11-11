#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>

int main()
{
    int i = 0, j = 0, n;
    char a[20], b[50], u[50];
    printf("enter string\n");
    scanf("%s", &a);
    n = strlen(a);  
    b[0] = 'x';
    b[1] = 'x';
    j = j + 2;

    while (a[i] != '\0')
    {
        if (a[i] == 'x' && a[i + 1] == 'x')
        {
            b[j] = 'x';
            b[j + 1] = 'x';
            j = j + 2;
        }
        b[j] = a[i];
        i++;
        j++;
    }

    b[j] = 'x';
    b[j + 1] = 'x';
    b[j + 2] = '\0';
    printf("\nframe after stuffing:\n");
    printf("%s", b);
    i = 0;
    j = 0;

    while (b[i] != '\0')
    {
        if (b[i] == 'x' && b[i + 1] == 'x')
        {
            u[j] = b[i + 1];
            i = i + 2;
        }
        u[j] = b[i];
        i++;
        j++;
    }

    u[j] = '\0';
    printf("\nunstuffed data is %s", u);
}
