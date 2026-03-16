#include <stdio.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    int queue[MAX], stack[MAX];
    int front = 0, rear = 0;
    int top = -1;

    /* Input queue elements */
    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[rear++]);
    }

    /* Step 1: Push queue elements into stack */
    while(front < rear) {
        stack[++top] = queue[front++];
    }

    /* Reset queue */
    front = rear = 0;

    /* Step 2: Pop stack back into queue */
    while(top >= 0) {
        queue[rear++] = stack[top--];
    }

    /* Print reversed queue */
    for(int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}