#include <string.h>
#include <omp.h>
#define ARRAY_SIZE 1000

void mystery(int32_t *A, int32_t *B, int32_t *C) {
    #pragma omp parallel
    {
        int N = omp_get_num_threads();
        int tid = omp_get_thread_num();
        
        for (int i = tid; i < ARRAY_SIZE; i += N) {
            C[i] = A[i] + B[i];
        }
    }
}


void mystery2(int32_t *A, int32_t *B, int32_t *C) {
    #pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] + B[i];
    }
}

int mystery(int32_t *A, int32_t *B) {
    int result = 0;
    #pragma omp parallel for reduction(^:result)
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result ^= A[i] ^ B[i];
    }
    return result;
}

int mystery2(int32_t *A, int32_t *B) {
    int result = 0;
    #pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; i++) {
        #pragma omp critical
        result ^= A[i] ^ B[i];
    }
    return result;
}

