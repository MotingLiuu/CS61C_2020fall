2 Thread-Level Parallelism

2.1
Always correct

Slower than Serial

2.2
Sometimes correct

2.3
Always correct

Faster than Serial

2.4
Sometimes correct

3 Critical Section

a) More than one thread would do product *= subproduct simultaneously. This would cause a data race.

b) Place the directive #pragma omp critical above product *= subproduct.

3.2


4 OpenMProgramming

4.3
The issue is more than one threads would do result ^= A[i] - B[i]

4.4

4.5
SpeedUp = 1 / (0.2 + 0.1) = 3.33

4.6
5

4.7
Critical Section is important, the SpeedUp is dependent on the critical section.



