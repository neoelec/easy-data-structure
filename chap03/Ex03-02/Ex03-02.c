#include <stdio.h>

/* 1차원 배열의 초기화 */
int main(int argc, char *argv[])
{
    size_t i;
    unsigned int score[3] = { 91, 86, 97 };
    char grade[3] = { 'A', 'B', 'A' };

    printf("\n *** 학년별 취득 학점 *** \n\n");

    for (i = 0; i < 3; i++)
        printf("%3zu 학년 : 총점= %u , 등급= %c\n", i + 1, score[i], grade[i]);

    return 0;
}
