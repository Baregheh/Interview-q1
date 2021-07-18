#include <stdio.h>
#include <time.h>
#include <math.h>
 
int prop(long int A, long int B, long int C, long int D) {
    return (pow(A, 4) + pow(B, 4) + pow(C, 4) == pow(D, 4));
}
 
int main() {
    long int a, b, c, d;
    clock_t t;
    t = clock();
 
    for (a = 1; a < 100000; a++) {
        for (b = 1; b < 300000; b++) {
            for (c = 1; c < 500000; c++) {
                for (d = 1; d < 500000; d++) {
                    if (prop(a, b, c, d))
                        printf("FOUND IT!\na = %ld\nb = %ld\nc = %ld\nd = %ld\n", a, b, c, d);
                }
                if (!(c%1000))
                    printf("a = %ld, b = %ld, c = %ld, time = %fs\n", a, b, c, ((double)(clock() - t))/CLOCKS_PER_SEC);
            }
            printf("a = %ld, b = %ld, time = %fs\n", a, b, ((double)(clock() - t))/CLOCKS_PER_SEC);
        }
        printf("a = %ld, time = %fs\n", a, ((double)(clock() - t))/CLOCKS_PER_SEC);
    }
 
}