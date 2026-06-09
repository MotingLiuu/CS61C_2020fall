#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int x = 0;
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        #pragma omp critical
        {
            x++;
        }
        printf("Thread %d: x = %d\n", tid, x);

        #pragma omp parallel
        if (tid == 0) {
            printf("Number of threads: %d\n", omp_get_num_threads());
        }
    }
}