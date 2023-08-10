#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct ThreadData {
    int* arr;
    int Low;
    int High;
    int key;
    int* flag;
};

void* searchThread(void* arg) {
    struct ThreadData* data = (struct ThreadData*)arg;

    while (data->Low <= data->High && data->key >= data->arr[data->Low] && data->key <= data->arr[data->High]) {

        if (data->Low == data->High) {
            printf("Element found at position %d\n", data->Low);
        }

        int q = (data->key - data->arr[data->Low]) / (data->arr[data->High] - data->arr[data->Low]);
        int pos = data->Low + (data->High - data->Low) * q;

        if (data->arr[pos] == data->key) {
            printf("Element found at position %d\n", pos);
            *(data->flag) = 0;
            break;
        }

        if (data->arr[pos] < data->key) {
            data->Low = pos + 1;
        }
        else {
            data->High = pos - 1;
        }
    }

    pthread_exit(NULL);
}

void interpolationSearch(int arr[], int n, int key) {
    int Low = 0, High = n - 1;
    int flag = 1;

    pthread_t threads;
    struct ThreadData data;
    data.arr = arr;
    data.Low = Low;
    data.High = High;
    data.key = key;
    data.flag = &flag;

    pthread_create(&threads, NULL, searchThread, (void*)&data);
    pthread_join(threads, NULL);

    if (flag == 1) {
        printf("Element not found\n");
    }
}

//Main function to take in the inputs from the user
int main() {
    int n = 10000, i, x;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter the element to be searched\n");
    scanf("%d", &x);

    clock_t t1 = clock();
    interpolationSearch(arr, n, x);
    clock_t t2 = clock();
    float RunTime = (float)(t2 - t1) / CLOCKS_PER_SEC;
    printf("\nTime taken: %.8f", RunTime);

    return 0;
}
