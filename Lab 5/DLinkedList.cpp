#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insertAtFront(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data);
    new_node->next = *head;
    if (*head != NULL)
        (*head)->prev = new_node;
    *head = new_node;
}

void insertAfter(struct Node* head, int key, int newData) {
    struct Node* curr = head;
    while (curr != NULL) {
        if (curr->data == key) {
            struct Node* newNode = createNode(newData);
            newNode->next = curr->next;
            newNode->prev = curr;
            if (curr->next != NULL)
                curr->next->prev = newNode;
            curr->next = newNode;
            return;
        }
        curr = curr->next;
    }
}

void insertBefore(struct Node** head, int key, int newData) {
    struct Node* curr = *head;
    if (curr != NULL && curr->data == key) {
        insertAtFront(head, newData);
        return;
    }
    while (curr != NULL) {
        if (curr->data == key) {
            struct Node* newNode = createNode(newData);
            newNode->prev = curr->prev;
            newNode->next = curr;
            curr->prev->next = newNode;
            curr->prev = newNode;
            return;
        }
        curr = curr->next;
    }
}

void insertAtPosition(struct Node** head, int position, int data) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        insertAtFront(head, data);
        return;
    }
    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL; ++i) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL)
        current->next->prev = newNode;
    current->next = newNode;
}

void insertAtEnd(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void deleteNode(struct Node** head, int data) {
    struct Node* curr = *head;
    while (curr != NULL && curr->data != data) {
        curr = curr->next;
    }
    if (curr == NULL) return;
    if (curr->prev != NULL)
        curr->prev->next = curr->next;
    else
        *head = curr->next;
    if (curr->next != NULL)
        curr->next->prev = curr->prev;
    free(curr);
    printf("%d is deleted\n", data);
}

void update(struct Node* head, int data1, int data2) {
    while (head != NULL && head->data != data1) {
        head = head->next;
    }
    if (head != NULL) {
        head->data = data2;
        printf("%d updated!\n", data1);
    }
}

int count(struct Node* head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct Node* head = NULL, *temp, *newnode;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        newnode = createNode(val);
        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = temp->next;
        }
    }

    printf("Original Linked List:");
    printList(head);

    deleteNode(&head, 1);
    printList(head);

    return 0;
}
