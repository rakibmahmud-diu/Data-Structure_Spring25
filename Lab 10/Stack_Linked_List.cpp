#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

//struct Stack {
//    struct Node* top;
//};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return newNode;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", data);
}


int isEmpty(struct Node* top) {
    return top == NULL;
}


int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}


int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}


void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack1=NULL;
    struct Node* stack2=NULL;
    int popped;
    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);

    push(&stack2, 100);
    push(&stack2, 200);
    push(&stack2, 300);


    display(stack1);
    display(stack2);

    printf("Top element is %d\n", peek(stack1));

    printf("%d popped from stack\n", pop(&stack1));
    printf("Top element is %d\n", peek(stack1));

    display(stack1);

    popped = pop(&stack1);
    popped = pop(&stack1);
    popped = pop(&stack1);

    return 0;
}
