#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

typedef struct Node node;


void push(node *stack,int data)
{
   node *temp;
   temp=(node*)malloc(sizeof(node));
   temp->data=data;
   temp->next=NULL;

   while(stack->next != NULL){
      stack=stack->next;
   }

   stack->next=temp;
   printf("%d is pushed!\n",data);
}


int pop(node *stack)
{
   int data;
   node *temp;

   if(stack->next==NULL){
      printf("Stack is empty\n");
      return -1;
   }

   while(stack->next->next!=NULL){
      stack=stack->next;
   }

   temp=stack->next;
   data=temp->data;
   stack->next=NULL;
   free(temp);
   return data;
}


int main()
{
   node *stack;
   stack=(node*)malloc(sizeof(node));
   stack->next=NULL;


   push(stack,9);

   push(stack,11);

   push(stack,7);

   printf("\n%d is popped\n",pop(stack));

   printf("%d is popped\n",pop(stack));

   printf("%d is popped\n",pop(stack));


   return 0;
}
