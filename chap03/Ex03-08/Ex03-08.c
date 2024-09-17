#include <stdio.h>

/* 포인터 연산자 예제 */
int main(int argc, char *argv[])
{
    int i = 10, j = 20;
    int *ptr;

    printf("\n i의 값 = %d \n j의 값 = %d", i, j);
    printf("\n i의 메모리 주소(&i) = %p", &i);
    printf("\n j의 메모리 주소(&j) = %p", &j);

    ptr = &i; // .
    printf("\n\n << ptr=&i 실행 >>");
    printf("\n ptr의 메모리 주소(&ptr) = %p", &ptr);
    printf("\n ptr의 값(ptr) = %p", ptr);
    printf("\n ptr의 참조 값(*ptr) = %d", *ptr);

    ptr = &j; // .
    printf("\n\n << ptr=&j 실행 >>");
    printf("\n ptr의 메모리 주소(&ptr) = %p", &ptr);
    printf("\n ptr의 값(ptr) = %p", ptr);
    printf("\n ptr의 참조값(*ptr) = %d", *ptr);

    i = *ptr; // .
    printf("\n\n << i=*ptr 실행 >>");
    printf("\n i의 값 = %d", i);

    return 0;
}
