#include <stdio.h>

/* 문자 배열 예제 */
int main(int argc, char *argv[])
{
    char str[20] = "Data Structure!";
    size_t i;

    printf("\n문자 배열 str[] : ");
    for (i = 0; str[i]; i++)
        printf("%c", str[i]);

    return 0;
}
