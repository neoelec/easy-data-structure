#include <stdio.h>

#define MAX(a, b) ((a > b) ? a : b)
#define MAX_DEGREE 50

struct polynomial { // 구조체 polynomial 정의
    int degree; // 다항식의 차수를 저장할 변수
    float coef[MAX_DEGREE]; // 다항식의 각 항의 계수를 저장할 1차원 배열
};

static void addPoly(const struct polynomial *A, const struct polynomial *B,
    struct polynomial *C)
{
    int A_index = 0, B_index = 0, C_index = 0;
    int A_degree = A->degree, B_degree = B->degree;

    C->degree = MAX(A->degree, B->degree);

    while (A_index <= A->degree && B_index <= B->degree) {
        if (A_degree > B_degree) {
            C->coef[C_index++] = A->coef[A_index++];
            A_degree--;
        } else if (A_degree == B_degree) {
            C->coef[C_index++] = A->coef[A_index++] + B->coef[B_index++];
            A_degree--;
            B_degree--;
        } else {
            C->coef[C_index++] = B->coef[B_index++];
            B_degree--;
        }
    }
}

static void printPoly(const struct polynomial *P)
{
    int i, degree;
    degree = P->degree;

    for (i = 0; i <= P->degree; i++)
        printf("%3.0fx^%d", P->coef[i], degree--);

    printf("\n");
}

int main(int argc, char *argv[])
{
    struct polynomial A = { 3, { 4, 3, 5, 0 } }; // 다항식 A의 초기화
    struct polynomial B = { 4, { 3, 1, 0, 2, 1 } }; // 다항식 B의 초기화
    struct polynomial C;

    // 다항식 A, B에 대한 덧셈을 수행하기 위해 addPoly 함수 호출
    addPoly(&A, &B, &C);

    printf("\n A(x)=");
    printPoly(&A); // 다항식 A 출력
    printf("\n B(x)=");
    printPoly(&B); // 다항식 B 출력
    printf("\n C(x)=");
    printPoly(&C); // 다항식 C 출력

    return 0;
}
