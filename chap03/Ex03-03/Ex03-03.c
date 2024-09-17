#include <stdio.h>

/* 입력한 숫자의 구구단 출력하기 */
int main(int argc, char *argv[])
{
    unsigned int i, n;
    unsigned int multiply[9];

    while (1) {
        printf("\n 1~9의 정수를 입력하세요! : ");
        scanf("%u", &n);
        if (n <= 9)
            break;
    }

    printf("\n");
    for (i = 0; i < 9; i++) {
        multiply[i] = n * (i + 1);
        printf(" %u * %u = %u \n", n, i + 1, multiply[i]);
    }

    return 0;
}
