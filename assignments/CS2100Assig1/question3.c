/* part a */
int main() {
    int t0 = 5;
    int x = 0;

    while (t0 >= x) {
        ctr = ctr / 2;
        x++;
    }
}

/* part b */
int main() {
    int t0 = 5;
    int x = t0 + 10;

    do {
        ctr = ctr / 2;
        x += -1;
    } 
    while (x >= t0);
}


/* part c */
int main() {
    // int ctr = $s1;
    // uint32_t arrA[] = $s2;
    // uint32_t arrB[] = $s3;
    // int v = $s4
    // int t0 = v * 4
    // int s5 = A[v];
    int *s5 = A[v];
    // t0 = ctr * 4
    // int t1 = &arrB + t0;
    int *t1 = B[ctr];
    // t0 += &arrA; // t0 = A[ctr]
    int *t0= A[ctr];

    // while (A[ctr] < A[v]) {
    while (*t0 < *s5) {
        // t2 = *t0;
        int *t2 = A[ctr];
        // t3 = *t1;
        int *t3 = B[ctr];

        // if (t2 >= t3) {
        if (*t2 >= *t3) {
            // t2 = *t1;
            *t2 = B[ctr];
            // t3 = *t0;
            *t3 = A[ctr];
        }
        t0++;
        t1++;
    }
}


int main() {
    int *t1 = &B[ctr];
    int *t0 = &A[ctr];

    while (t0 < &A[v]) {
        int t2 = *t0;
        int t3 = *t1;
        if (t2 >= t3) {
            *t1 = t2;
            *t0 = t3;
        }
        t0++;
        t1++;
    }
}