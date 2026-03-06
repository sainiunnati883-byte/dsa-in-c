#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* exp) {
    char* token = strtok(exp, " ");

    while (token != NULL) {

        if (isdigit(token[0])) {
            push(atoi(token));
        }
        else {
            int val2 = pop();
            int val1 = pop();
            int result;

            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char exp[100];

    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = 0;

    printf("%d\n", evaluatePostfix(exp));

    return 0;
}