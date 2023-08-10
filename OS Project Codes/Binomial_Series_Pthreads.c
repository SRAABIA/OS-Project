#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
typedef struct{
    double a;
    double x;
    int n;
    double result;
} struct_obj;
void* calculateTerm(void* arg) {
    struct_obj* args = (struct_obj*)arg;
    int i;
    double term = 1.0;
    
    for (i = 0; i < args->n; i++) {
        term *= (args->a * args->x) / (i + 1);
    }
    
    args->result = term;
    
    pthread_exit(NULL);
}

int main() {
    double a, x;
    int n, i;
    
    printf("Enter the value of 'a': ");
    scanf("%lf", &a);
    
    printf("Enter the value of 'x': ");
    scanf("%lf", &x);
    
    printf("Enter the value of 'n': ");
    scanf("%d", &n);
    
    pthread_t threads[n];
    struct_obj data[n];
    clock_t start = clock();
    
    // Create threads and calculate binomial terms
    for (i = 0; i < n; i++) {
        data[i].a = a;
        data[i].x = x;
        data[i].n = i;
        
        pthread_create(&threads[i], NULL, calculateTerm, &data[i]);
    }
    
    // Wait for all threads to finish
    for (i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print the binomial terms
    printf("\nBinomial Series:\n");
    for (i = 0; i < n; i++) {
        printf("Term %d: %.4lf\n", i, data[i].result);
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nTime taken: %lf seconds\n", time_taken);
    return 0;
}