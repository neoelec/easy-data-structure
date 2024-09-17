#include <stdio.h>

long fact(int);

int main(int argc, char *argv[])
{
    int n;
    long result;

    printf("\n 정수를 입력하세요!! ");
    scanf("%d", &n);
    result = fact(n);
    printf("\n\n %d의 factorial 값은 %ld입니다.\n", n, result);

    return 0;
}

long fact(int n)
{
    long value;

    if (n <= 1) {
        printf("\n fact(1)함수 호출!");
        printf("\n fact(1)값 1 반환!!");

        return 1;
    } else {
        printf("\n fact(%d)함수 호출!", n);
        value = (n * fact(n - 1));
        printf("\n fact(%d)값 %ld 반환!!", n, value);

        return value;
    }
}
