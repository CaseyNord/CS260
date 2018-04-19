#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX 10

//prototypes
unsigned long fibonacci(unsigned long n);

int main()
{
    char input[MAX];
    char *ch;
    ch = &input[0];

    printf("Enter a value: ");
    fgets(input, MAX, stdin);
    int num = atoi(ch);

    struct timeval start, stop;
    double elapsedtime = 0;
    gettimeofday(&start, NULL);

    for (int i = 0; i < num; i++)
    {
        printf("%lu\n", fibonacci(i));
    }

    gettimeofday(&stop, NULL);
    elapsedtime = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("Completed in %.3f seconds\n", elapsedtime);

    return 0;
}

unsigned long fibonacci(unsigned long n)
{
    unsigned long result = 0;
    if(n == 0)
    {
        result = 0;
    }
    else if(n == 1)
    {
        result = 1;
    }
    else
    {
        unsigned long a = 1, b = 1;
        for (int i = 3; i <= n; i++)
        {
            unsigned long c = a + b;
            a = b;
            b = c;
        }
        result = b;
    }
 
    return result;
}