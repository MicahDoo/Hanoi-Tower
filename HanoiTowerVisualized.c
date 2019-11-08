#include <stdio.h>
#include <stdlib.h>
#define ANSI_COLOR_RED //"\x1b[31m"
#define ANSI_COLOR_CYAN //"\x1b[36m"
#define ANSI_COLOR_RESET //"\x1b[0m"
int a[20] = {0}, b[20] = {0}, c[20] = {0}, start = 1, counter = 0;
int N = 0;
char fromRod, toRod;
void moves(int n, int* x, int* y);
void printDisks(int n, int* x, int* y, int* z);
void printSingleDisk (int n, int* r, int i);

int main()
{
    while(1)
    {
        for(int i = 0; i <20; i++, a[i] = 0, b[i] = 0, c[i] = 0);  //clears all rods
        start = 1;
        counter = 0; //restart, reset
    printf("How many disks are there? (Maximum = 10, Enter 0 to exit guide) ");
    scanf("%d", &N);
        if (N < 0 || N > 15)
        {
            printf("N outside of acceptable range. Try Again.\n");
        }
        else if (N == 0)
        {
            exit(0);
        }
        else
        {
            moves(N, a, c);
        }
    }
}

void moves(int n, int* x, int* y)
{
    int* z;
    if (x == a && y == b) {z = c; fromRod = 'A'; toRod = 'B';}
    else if (x == b && y == a) {z = c; fromRod = 'B'; toRod = 'A';}
    else if (x == a && y == c) {z = b; fromRod = 'A'; toRod = 'C';}
    else if (x == c && y == a) {z = b; fromRod = 'C'; toRod = 'A';}
    else if (x == b && y == c) {z = a; fromRod = 'B'; toRod = 'C';}
    else {z = a; fromRod = 'C'; toRod = 'B';}
   
    if (start == 1)
    {
        for(int i = 0; i < N; i++, x[i] = 2 * i + 1, printf("Start\n"), printDisks(N, a, b, c),start = 0); //initializing //x = diameter of the disk
    }
    if (n == 1)
    {
        counter++;
        printf("Step %d: Move 1 disk from %c to %c\n", counter, fromRod, toRod);
        for(int i = 0; i < N; i++ ) //moves top item of x to top of y
        {
            if (x[i] != 0)
            {
                for(int j = 0; j < N; j++)
                {
                    if (y[j] != 0)
                    {
                        y[j-1] = x[i];
                        break;
                    }
                    else continue;
                }
                y[N-1] = y[N-1] == 0?x[i]:y[N-1];
                x[i] = 0;
                break;
            }
        }
        printDisks(N, a, b, c);
    }
    else if (n > 1)
    {
        moves(n-1, x, z);
        moves(1, x, y);
        moves(n-1,z, y);
    }
}

void printDisks(int n, int* x, int* y, int* z)
{
    for(int i = 0; i < n; i++) //rows
    {
        printSingleDisk (n, x, i);
        printSingleDisk (n, y, i);
        printSingleDisk (n, z, i);
        printf("\n");
    }
    printf("%*s%*s%*s%*s%*s%*s\n\n", n+1, "A", n, " ", n+1, "B", n, " ", n+1, "C", n, " ");
}

void printSingleDisk (int n, int* r, int i)
{
    if (r[i] == 0)
    {
            printf("%*s%*s", n+1, "|", n, " ");
    }
    else
    {
        printf("%*s", ((n * 2) + 1 - r[i])/2, " ");
        for (int j = 0; j < r[i]; j++) //disk
        {
            printf(ANSI_COLOR_CYAN"█"ANSI_COLOR_RESET);
        }
        printf("%*s", ((n * 2) + 1 - r[i])/2, " ");
    }
}
