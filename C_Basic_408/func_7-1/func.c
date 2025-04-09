//
// Created by yyz on 2025/4/9.
//
#include "func.h"

int printstar(int n) {
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
}

void print_message() {
    printstar(10);
    printf("message");
}