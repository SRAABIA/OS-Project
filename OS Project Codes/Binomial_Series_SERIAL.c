#include <stdio.h>
#include <math.h>
#include <time.h>

unsigned long long factorial(int num)
{
    unsigned long long fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}


int main()
{
    double a, x, result;
    int n;

    printf("Enter the value of a: ");
    scanf("%lf", &a);

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the number of terms in the series: ");
    scanf("%d", &n);

    // Calculate time taken
    clock_t start = clock();

    

    printf("\nSeries: ");
    for (int k = 0; k <= n; k++)
    {
        unsigned long long coef = factorial(n) / (factorial(k) * factorial(n - k));
        result = result + coef;
        printf("%.0f  ", (double)coef * a);
        if (k != n)
            printf("+ ");
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nSum: %.6f", result);

    printf("\n\nTime taken: %lf seconds\n", time_taken);

    return 0;
}
