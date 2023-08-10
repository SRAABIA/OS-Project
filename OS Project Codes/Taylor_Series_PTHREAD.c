#include <stdio.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 4

struct ThreadData {
    double x;
    int n;
    int start;
    int end;
    double sum;
};

int factorial(int num) {
    if (num <= 1)
        return 1;
    else
        return num * factorial(num - 1);
}

void* calculateTerms(void* arg) {
    struct ThreadData* data = (struct ThreadData*)arg;
    double x = data->x;
    int n = data->n;
    int start = data->start;
    int end = data->end;
    int sign = start % 2 == 0 ? -1 : 1;
    
    for (int i = start; i <= end; i += 2) {
        double term = sign * pow(x, i) / factorial(i);
        data->sum += term;
        sign *= -1;
    }
    
    pthread_exit(NULL);
}

double taylorSeriesSine(double x, int n) {
    pthread_t threads[MAX_THREADS];
    struct ThreadData threadData[MAX_THREADS];
    double sum = 0.0;
    
    int termsPerThread = n / MAX_THREADS;
    int remainingTerms = n % MAX_THREADS;
    
    for (int i = 0; i < MAX_THREADS; i++) {
        threadData[i].x = x;
        threadData[i].n = n;
        threadData[i].start = i * termsPerThread + 1;
        threadData[i].end = (i + 1) * termsPerThread;
        
        if (i == MAX_THREADS - 1)
            threadData[i].end += remainingTerms;
        
        pthread_create(&threads[i], NULL, calculateTerms, (void*)&threadData[i]);
    }
    
    for (int i = 0; i < MAX_THREADS; i++)
        pthread_join(threads[i], NULL);
    
    for (int i = 0; i < MAX_THREADS; i++)
        sum += threadData[i].sum;
    
    return sum;
}

int main() {
    double x, result;
    int n;
    
    printf("Enter the value of x (in radians): ");
    scanf("%lf", &x);
    
    printf("Enter the number of terms in the series: ");
    scanf("%d", &n);
    
    // Calculate time taken
    clock_t start = clock();
    result = taylorSeriesSine(x, n);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSeries: ");
    for (int i = 1; i <= n; i++) {
        printf("%lf ", pow(x, (2 * i) - 1) / factorial((2 * i) - 1));
        if (i != n)
            printf("+ ");
    }
    
    printf("\n\nTime taken: %lf seconds\n", time_taken);
    
    return 0;
}
