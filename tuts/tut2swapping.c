void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/*
void swap(byte_t a, byte_t b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return b;
}
*/