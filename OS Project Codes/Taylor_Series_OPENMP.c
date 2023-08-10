#include <stdio.h>
#include <math.h>
#include <time.h>
#include <omp.h>

int main() {
    double x, term, sum = 0;
    int i, n;

    printf("Enter the value of x (in radians): ");
    scanf("%lf", &x);

    printf("Enter the number of terms in the series: ");
    scanf("%d", &n);

    sum = 0.0;
    double t1 = clock();

    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < n; i++) {
        int denominator = 1;
        for (int j = 1; j <= 2 * i + 1; j++) {
            denominator *= j;
        }
        term = pow(-1, i) * pow(x, 2 * i + 1) / denominator;
        sum += term;
        printf("Term %d: %lf\n", i + 1, term);
    }

    double t2 = clock();
    printf("sin(%lf) = %lf\n", x, sum);

    double runTime = t2 - t1;
    printf("\nTime taken: %.8f seconds\n", runTime);

    return 0;
}
