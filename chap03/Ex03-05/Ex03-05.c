#include <stdio.h>
#include <string.h>

/* 문자 배열 예제-2 */
int main(int argc, char *argv[])
{
    size_t i, length = 0;
    char str[50];

    printf("\n 문자열을 입력하세요 : ");
    fgets(str, sizeof(str), stdin);
    strtok(str, "\r\n");
    printf("\n 입력된 문자열은 \n \"");
    for (i = 0; str[i]; i++) {
        printf("%c", str[i]);
        length += 1;
    }

    printf("\" \n입니다.");
    printf("\n\n입력된 문자열의 길이 = %zu \n", length);

    return 0;
}
