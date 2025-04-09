#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Stack {
    struct Node* top;
};


struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void push(struct Stack* stack, int data) {
    if (stack == NULL) {
        printf("Stack is not initialized\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack\n", data);
}


int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}


int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}


int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}


void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();


    printf("Operations on Stack 1:\n");
    push(stack1, 10);
    push(stack1, 20);
    push(stack1, 30);
    display(stack1);
    printf("Top element of Stack 1 is %d\n", peek(stack1));
    printf("%d popped from Stack 1\n", pop(stack1));
    display(stack1);


    printf("\nOperations on Stack 2:\n");
    push(stack2, 100);
    push(stack2, 200);
    push(stack2, 300);
    display(stack2);
    printf("Top element of Stack 2 is %d\n", peek(stack2));
    printf("%d popped from Stack 2\n", pop(stack2));
    display(stack2);


    free(stack1);
    free(stack2);

    return 0;
}
