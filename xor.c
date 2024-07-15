#include <stdio.h>

#define KEY 32
#define TEXT 52



unsigned int encryption(int a, int b) {
    return a ^ b;
}


unsigned int decryption(int a, int b) {
    return a ^ b;
}


int main() {
    unsigned int encrypted = encryption(KEY, TEXT);
    unsigned int decrypted = decryption(KEY, encrypted);

    printf("암호화 값 => %d \n", encrypted);
    printf("복호화 시 원문 => %d\n", decrypted);

    return 0;
}
