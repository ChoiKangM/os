#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <assert.h>

#define MILLION 1000000 

int SIZE, NTHREADS;
int **A, **B, **C;

void init()
{    
    // 행렬 선언
    int i, j;

    A = (int**)malloc(SIZE * sizeof(int *));
    for(i = 0; i < SIZE; i++)
        A[i] = malloc(SIZE * sizeof(int));

    B = (int**)malloc(SIZE * sizeof(int *));
    for(i = 0; i < SIZE; i++)
        B[i] = malloc(SIZE * sizeof(int));

    C = (int**)malloc(SIZE * sizeof(int *));
    for(i = 0; i < SIZE; i++)
        C[i] = malloc(SIZE * sizeof(int));

    srand(time(NULL));

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            A[i][j] = rand()%100;
            B[i][j] = rand()%100;
        }
    }
}

void calWithPthread(int tid)
{    
    // Pthread 가지고 행렬 연산
    int i, j, k;
    int start = tid * SIZE/NTHREADS;
    int end = (tid+1) * (SIZE/NTHREADS) - 1;

    for(i = start; i <= end; i++) {
        for(j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for(k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void calWithoutPthread()
{
    // 그냥 행렬 연산 
    int i, j, k;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for(k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void *pthreadWorker(void *arg)
{
    int tid = (int)arg;
    calWithPthread(tid);
}

int main(int argc, char* argv[])
{
    pthread_t* threads;
    int rc, i;

    if(argc != 3)
    {
        printf("Usage: %s <size_of_square_matrix> <number_of_threads>\n", argv[0]);
        exit(1);
    }
    
    // 행렬 크기 SIZE * SIZE
    SIZE = atoi(argv[1]);
    // Thread 개수
    NTHREADS = atoi(argv[2]);
    // 행렬 선언
    init();
    // thread 할당
    threads = (pthread_t*)malloc(NTHREADS * sizeof(pthread_t));

    struct timeval tpstart, tpend;
    long timediff;

    // calcuation with pthread
    gettimeofday(&tpstart,NULL);
    
    for(i = 0; i < NTHREADS; i++) {
        rc = pthread_create(&threads[i], NULL, pthreadWorker, (void *)i);
        assert(rc == 0);
    }

    for(i = 0; i < NTHREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        assert(rc == 0);
    } 
    gettimeofday(&tpend,NULL);
    timediff = MILLION*(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

    printf("Calculation time with pthread: %ld mseconds.\n", timediff);
    
    // calculation without pthread
    gettimeofday(&tpstart,NULL);

    calWithoutPthread();

    gettimeofday(&tpend,NULL);
    timediff = MILLION*(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;


    printf("Calculation time without pthread: %ld mseconds.\n", timediff);

    // malloc한 행렬을 모두 free
    for(i = 0; i < SIZE; i++)
        free((void *)A[i]);
    free((void *)A);

    for(i = 0; i < SIZE; i++)
        free((void *)B[i]);
    free((void *)B);

    for(i = 0; i < SIZE; i++)
        free((void *)C[i]);
    free((void *)C);

    free(threads);

    return 0;
}