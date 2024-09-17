#include <stdio.h>
#include <string.h>

struct employee {
    char name[10];
    int year;
    int pay;
};

int main(int argc, char *argv[])
{
    size_t i;
    struct employee Lee[4]
        = { { "이민수", 2002, 3200 }, { "이상건", 2002, 3000 },
              { "이진호", 2004, 2500 }, { "이한영", 2003, 2900 } };

    for (i = 0; i < 4; i++) {
        printf("\n 이름 : %s", Lee[i].name);
        printf("\n 입사 : %d", Lee[i].year);
        printf("\n 연봉 : %d \n", Lee[i].pay);
    }

    return 0;
}
