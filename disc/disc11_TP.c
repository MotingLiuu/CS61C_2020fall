#include <stdio.h>
#include <string.h>

// Assume arr has length n
int fast_sum(int *arr, int n) {
    int result = 0;
    #pragma omp parallel for reduction(+:result)
    for (int i = 0; i < n; i++) {
        result += arr[i];
    }
    return result;
}

// Assume arr has length 8*n
double fast_product(double *arr, int n) {
    double product = 1;
    #pragma omp parallel for reduction(*:product)
    for (int i = 0; i < n; i++) {
        double subproduct = arr[i*8] + arr[i*8+1] + arr[i*8+2] + arr[i*8+3] + arr[i*8+4] + arr[i*8+5] + arr[i*8+6] + arr[i*8+7];
        product *= subproduct;
    }
    return product;
}

#define N 5

void func() {
    int A[N] = {1, 2, 3, 4, 5};
    int x = 0;
    #pragma omp parallel
    {
        for (int i = 0; i < N; i++) {
            x += A[i];
            A[i] = 0;
        }
    }
}
// The minimum value of x is 0.
// The maximum value of x is 30.
// 

# define ARRAY_LEN 1000

void mystery(int32_t *A, int32_t *B, int32_t *C) {
    #pragma omp parallel
    {
        int N = OMP_NUM_THREADS;
        int tid = omp_get_thread_num();
        
        for (int i = tid; i < ARRAY_LEN; i += N) {
            C[i] = A[i] - B[i];
        }
    }
}

void mystery2(int32_t *A, int32_t *B, int32_t *C) {
    #pragma omp parallel for
    for (int i = 0; i < ARRAY_LEN; i++) {
        C[i] = A[i] - B[i];
    }
}

int mystery(int32_t *A, int32_t *B) {
    int result = 0;
    #pragma omp parallel for
    for (int i = 0; i < ARRAY_LEN; i++) {
        #pragma omp critical
        result ^= A[i] - B[i];
    }
    return result;
}

int mystery2(int32_t *A, int32_t *B) {
    int result = 0;
    #pragma omp parallel for reduction(^:result)
    for (int i = 0; i < ARRAY_LEN; i++) {
        result ^= A[i] - B[i];
    }
    return result;
}















