#include <stdio.h>

int main(int argc, char *argv[])
{
    size_t i;
    int sale[4] = { 157, 209, 251, 312 };

    for (i = 0; i < 4; i++)
        printf("\n address: %p sale[%zu]= %d", &sale[i], i, sale[i]);

    return 0;
}
