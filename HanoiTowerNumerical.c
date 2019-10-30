#include <stdio.h>
#include <stdlib.h>
int a, b, c, start = 1;
void moves(int n, int* x, int* y);

int main()
{
    moves(10, &a, &c);
}

void moves(int n, int* x, int* y)
{
    int* z;
    if (x != &a && y != &a) z = &a;
    else if (x != &b && y != &b) z = &b;
    else z = &c;
    if (start == 1)
    {
        *x = n; *y = 0; *z = 0;
        printf("A %d B %d C %d\n", a, b, c);
        start = 0;
    }
    if (n == 1)
    {
        (*x)--;
        (*y)++;
        printf("A %d B %d C %d\n", a, b, c);
    }
    else if (n > 1)
    {
        moves(n-1, x, z);
        moves(1, x, y);
        moves(n-1,z, y);
    }
}
