#include <stdio.h>

int main(int argc, char *argv[])
{
    char *ptrArray[2];
    char **ptrptr;
    size_t i;

    ptrArray[0] = "Korea";
    ptrArray[1] = "Seoul";
    ptrptr = ptrArray;
    printf("\n ptrArray[0]의 주소       ( &ptrArray[0]) = %p", &ptrArray[0]);
    printf("\n ptrArray[0]의 값         (  ptrArray[0]) = %p", ptrArray[0]);
    printf("\n ptrArray[0]의 참조값     ( *ptrArray[0]) = %c", *ptrArray[0]);
    printf("\n ptrArray[0]의 참조문자열 ( *ptrArray[0]) = %s \n", *ptrArray);

    printf("\n ptrArray[1]의 주소       ( &ptrArray[1]) = %p", &ptrArray[1]);
    printf("\n ptrArray[1]의 값         (  ptrArray[1]) = %p", ptrArray[1]);
    printf("\n ptrArray[1]의 참조값     ( *ptrArray[1]) = %c", *ptrArray[1]);
    printf(
        "\n ptrArray[1]의 참조문자열 ( *ptrArray[1]) = %s \n", *(ptrArray + 1));

    printf("\n ptrptr의 주소            ( &ptrptr) = %p", &ptrptr);
    printf("\n ptrptr의 값              (  ptrptr) = %p", ptrptr);
    printf("\n ptrptr의 1차 참조값      ( *ptrptr) = %p", *ptrptr);
    printf("\n ptrptr의 2차 참조값      (**ptrptr) = %c", **ptrptr);
    printf("\n ptrptr의 2차 참조문자열  (**ptrptr) = %s", *ptrptr);

    printf("\n\n *ptrArray[0] : ");
    for (i = 0; i < 5; i++)
        printf("%c", *(ptrArray[0] + i));
    printf("\n **ptrptr : ");
    for (i = 0; i < 5; i++)
        printf("%c", *(*ptrptr + i));

    printf("\n\n *ptrArray[1] : ");
    for (i = 0; i < 5; i++)
        printf("%c", *(ptrArray[1] + i));
    printf("\n **(ptrptr+1) : ");
    for (i = 0; i < 5; i++)
        printf("%c", *(*(ptrptr + 1) + i));

    return 0;
}
