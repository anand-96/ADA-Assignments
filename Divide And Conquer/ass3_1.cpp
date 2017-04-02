#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
#define MAX_DIGITS 1024

#define KARAT_CUTOFF 4

void karatsuba(int *a, int *b, int *ret, int d);
void normalMultiplication(int *a, int *b, int *ret, int d);
void Carry(int *a, int d);
void getNum(int *a, int *d_a);
void printNum(int *a, int d);

int main() {
    int a[MAX_DIGITS], b[MAX_DIGITS],r[6 * MAX_DIGITS]; 
    int d_a,d_b,d,i; 

    getNum(a, &d_a);
    getNum(b, &d_b);

    if(d_a < 0 || d_b < 0) {
        printf("0\n");
        exit(0);
        return 0;
    }

    i = (d_a > d_b) ? d_a : d_b;
    for(d = 1; d < i; d *= 2);
    for(i = d_a; i < d; i++) 
        a[i] = 0;
    for(i = d_b; i < d; i++)
          b[i] = 0;
    int start_s=clock();

        karatsuba(a, b, r, d);
        Carry(r, 2 * d); 
    printNum(r, 2 * d);
    int stop_s=clock();
	        cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

}

void karatsuba(int *a, int *b, int *ret, int d) {
    int i;
    int *ar = &a[0]; 
    int *al = &a[d/2];
    int *br = &b[0]; 
    int *bl = &b[d/2]; 
    int *asum = &ret[d * 5];
    int *bsum = &ret[d * 5 + d/2]; 
    int *x1 = &ret[d * 0]; 
    int *x2 = &ret[d * 1];
    int *x3 = &ret[d * 2]; 

    if(d <= KARAT_CUTOFF) {
        normalMultiplication(a, b, ret, d);
        return;
    }

    for(i = 0; i < d / 2; i++) {
        asum[i] = al[i] + ar[i];
        bsum[i] = bl[i] + br[i];
    }
    karatsuba(ar, br, x1, d/2);
    karatsuba(al, bl, x2, d/2);
    karatsuba(asum, bsum, x3, d/2);

    for(i = 0; i < d; i++)
         x3[i] = x3[i] - x1[i] - x2[i];
    for(i = 0; i < d; i++) 
        ret[i + d/2] += x3[i];
}

void normalMultiplication(int *a, int *b, int *ret, int d) {
    int i, j;

    for(i = 0; i < 2 * d; i++) 
        ret[i] = 0;
    for(i = 0; i < d; i++) {
        for(j = 0; j < d; j++) ret[i + j] += a[i] * b[j];
    }
}

void Carry(int *a, int d) {
    int c;
    int i;

    c = 0;
    for(i = 0; i < d; i++) {
        a[i] += c;
        if(a[i] < 0) {
            c = -(-(a[i] + 1) / 10 + 1);
        } else {
            c = a[i] / 10;
        }
        a[i] -= c * 10;
    }
}

void getNum(int *a, int *d_a) {
    int c;
    int i;

    *d_a = 0;
    while(true) {
        c = getchar();
        if(c == '\n' || c == EOF) break;
        if(*d_a >= MAX_DIGITS) {
            fprintf(stderr, "using only first %d digits\n", MAX_DIGITS);
            while(c != '\n' && c != EOF) c = getchar();
        }
        a[*d_a] = c - '0';
        ++(*d_a);
    }
    for(i = 0; i * 2 < *d_a - 1; i++) {
        c = a[i], a[i] = a[*d_a - i - 1], a[*d_a - i - 1] = c;
    }
}

void printNum(int *a, int d) {
    int i;
    for(i = d - 1; i > 0; i--) if(a[i] != 0) break;
    for(; i >= 0; i--) printf("%d", a[i]);
}
