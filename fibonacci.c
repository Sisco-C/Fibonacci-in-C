#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    TypeTag type;
} Node;

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    FIBO
} TypeTag;

Node* makeFunc(TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    return node;
}

void calc(Node* node) {
    if (node->type == ADD) {
        int a = *((int*)node + 1);
        int b = *((int*)node + 2);
        int result = a + b;
        printf("add : %d\n", result);
    } else if (node->type == SUB) {
        int* op1 = (int*)node + 1;
        int* op2 = (int*)node + 2;
        if (*op2 == NULL) {
            printf("fibo : %d\n", fibonacci(*op1));
        } else {
            int result = *op1 - *op2;
            printf("sub : %d\n", result);
        }
    } else if (node->type == MUL) {
        int a = *((int*)node + 1);
        int b = *((int*)node + 2);
        int result = a * b;
        printf("mul : %d\n", result);
    }
}

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int prev3 = 0;
    int prev2 = 1;
    int prev1 = 2;
    int current;

    for (int i = 3; i <= n; i++) {
        current = prev3 + prev2;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {
    Node* add = (*makeFunc(ADD))(10, 6);
    Node* mul = (*makeFunc(MUL))(5, 4);
    Node* sub = (*makeFunc(SUB))(mul, add);
    Node* fibo = (*makeFunc(SUB))(sub, NULL);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    return 0;
}
