#include <stdio.h>
#include <stdlib.h>
struct Results {
    int * C;
    int L;
};

static int max = 0;
struct Results solution(int N, int A[], int M) {
    int arr[N];
    for (int i=0;i<N;++i)
        arr[i]=0;

    for (int i=0; i<M; ++i) {
        int n = A[i];
        if (n < N + 1) {
            int newVal = ++arr[n-1];
            if (newVal > max)
            	max = newVal;
        } else if (n == N + 1) {
            for (int j=0; j<N; ++j)
            	arr [j] = max;
        } else {
            printf("ERROR: A[%i] = %i",i,n);   
        }
    }
    
    struct Results result;
    result.C = (int*)arr;//malloc(sizeof(int)*N);
    result.L = N;
    
    printf("[ %i", result.C[0]);
	for (int i = 1; i<N; ++i) {
   		 printf(", %i", result.C[i] );
	}
	printf(" ]\n");
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int A[] = {
        3,4,4,6,1,4,4//[3, 2, 2, 4, 2]
    };
    struct Results r = solution(5, A, 7);
    printf("[ %i", r.C[0]);
    for (int i = 1; i<5; ++i) {
        printf(", %i", r.C[i] );
    }
    printf(" ]\n");
    return 0;
}
