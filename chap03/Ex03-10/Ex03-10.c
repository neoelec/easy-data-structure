#include <stdio.h>

int main(int argc, char *argv[])
{
    size_t i;
    char *ptrArray[4] = { "Korea", "Seoul", "Mapo", "152번지 2/3" };

    for (i = 0; i < 4; i++)
        printf("\n %s", ptrArray[i]);

    ptrArray[2] = "Jongno";
    printf("\n\n");
    for (i = 0; i < 4; i++)
        printf("\n %s", ptrArray[i]);

    return 0;
}
