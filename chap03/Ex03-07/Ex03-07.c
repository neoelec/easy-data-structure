#include <stdio.h>
#include <string.h>

/* 3차원 문자 배열 예제 */
int main(int argc, char *argv[])
{
    size_t i, j, k;
    char student[2][3][20];

    for (i = 0; i < 2; i++) {
        printf("\n 학생 %zu의 이름 : ", i + 1);
        fgets(student[i][0], sizeof(student[i][0]), stdin);
        strtok(student[i][0], "\r\n");
        printf(" 학생 %zu의 학과 : ", i + 1);
        fgets(student[i][1], sizeof(student[i][0]), stdin);
        strtok(student[i][1], "\r\n");
        printf(" 학생 %zu의 학번 : ", i + 1);
        fgets(student[i][2], sizeof(student[i][0]), stdin);
        strtok(student[i][2], "\r\n");
    }

    for (i = 0; i < 2; i++) {
        printf("\n\n 학생%zu", i + 1);
        for (j = 0; j < 3; j++) {
            printf("\n\t");
            for (k = 0; student[i][j][k] != '\0'; k++) {
                printf("%c", student[i][j][k]);
            }
        }
    }

    return 0;
}
