#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}


void insertAtFront(struct Node** head, int new_data)
{
    struct Node* new_node = createNode(new_data);
    new_node->next = *head;
    *head = new_node;
    //return head;
}
////

void insertAfter(struct Node* head, int key, int newData)
{
    struct Node* curr = head;
    while (curr != NULL) {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    if (curr == NULL)
        return;

    struct Node* newNode = createNode(newData);
    newNode->next = curr->next;
    curr->next = newNode;
}


void printList(struct Node* head)
{
    struct Node* curr = head;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


int main()
{
    // Create the linked list 2->3->4->5
//    struct Node* head = createNode(2);
//    head->next = createNode(3);
//    head->next->next = createNode(4);
//    head->next->next->next = createNode(5);
    int n, val;
    struct Node *head=NULL, *temp, *newnode;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&val);
        newnode = createNode(val);
        if(head == NULL){
            head = newnode;
            temp = head;
        }
        else{
            temp->next = newnode;
            temp = temp->next;
        }
    }

    // Print the original list
    printf("Original Linked List:");
    printList(head);

    // Insert a new node at the front of the list
    int data = 6;
    insertAtFront(&head, data);
    printList(head); //printf("%d\n",head->data);
//
    int key = 3, newData = 6;// Insert a new node with data 4 after the node having data 3
    insertAfter(head, key, newData);
    printList(head);

//    int key = 3, newData = 4;// Insert a new node with data 4 after the node having data 3
//    insertBefore(&head, key, newData);
//    printList(head);
//
//    int data = 12; int pos = 4;
//    insertAtPosition(&head, pos, data);
//    printList(head);
//    insertAtPosition(&head, 1, 44);
//    printList(head);
////
////    insertAtEnd(&head, 10);
////    printList(head);
//    // Print the updated list
//    deleteNode(&head, 12);
//    printList(head);
//////
//    update(head, 4, 400);
//    printList(head);
//
//    printf("%d Nodes in the list\n", count(head));

    return 0;
}
