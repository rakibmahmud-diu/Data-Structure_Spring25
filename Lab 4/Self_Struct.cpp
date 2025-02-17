#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
};

int main()
{
   struct node* head = NULL;
   struct node* second = NULL;
   struct node* third = NULL;

   head = (struct node*)malloc(sizeof(struct node));
   second = (struct node*)malloc(sizeof(struct node));
   third = (struct node*)malloc(sizeof(struct node));

   scanf("%d",&head->data);
   //head->data = 1;
   head->next = second;

   scanf("%d",&second->data);
   //second->data = 2;
   second->next = third;

   scanf("%d",&third->data);
   //third->data = 3;
   third->next = NULL;

   struct node* temp = head;
   while(temp != NULL){
      printf("%d ",temp->data);
      temp = temp->next;
   }

   return 0;
}
