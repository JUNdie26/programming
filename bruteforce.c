#include <stdio.h>

#define KEY 32
#define TEXT 52

#define maxSize 1000000

int dictionary[maxSize];
int using[maxSize];

int i;
int j;

void delDictionary() {
    for (i = 0; i < maxSize; i++) {
        using[i] = 0;
    }
}


void insertKeyValue(int key, int value) {
    if (key >= 0 && key < maxSize) {
        dictionary[key] = value;
        using[key] = 1;
    } else {
        printf("범위 벗어남\n");
    }
}


int searchValueWithKey(int key) { // 레인보우 테이블 만든 후 사용, 지금 필요 없지만 그냥 만들어 봄
    if (key >= 0 && key < maxSize && using[key]) {
        return dictionary[key];
    } else {
        return -1;
    }
}


unsigned int encryption1(int a, int b) { //a는 원문 b는 키값
    return a ^ b;
}

unsigned int decryption1(int a, int b) {
    return a ^ b;
}

void bruteforce() {
    delDictionary();

    for(j = 0; ;j++) {
        insertKeyValue(j, j ^ TEXT); //레인보우 테이블
        if ((j ^ TEXT) == (KEY ^ TEXT)){
            printf("key는 %d 입니다.", j);

            break;
        }
    }

}



int main() {
    unsigned int encrypted = encryption1(KEY, TEXT);
    unsigned int decrypted = decryption1(KEY, encrypted);

    printf("평문 값 => %d \n", TEXT);
    printf("암호화 값 => %d \n", encrypted);
    printf("복호화 시 원문 => %d\n", decrypted);


    bruteforce();

    printf("\n 레인보우 테이블 \n");
    for(i = 0; i <= j; i++){
        printf("key : %d, value : %d \n", i, dictionary[i]);
    }

    return 0;
}