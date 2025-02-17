#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
   int id;
   float cgpa;
   char name[100];
   struct node *next;
};

struct Node
{
   struct Node *prev;
   struct node data;
};


int main()
{
   struct Node *head = NULL;
   struct Node ob1;
   struct Node ob2;

   head = &ob2;

   ob1.data.id = 1;
   ob1.data.cgpa = 3.5;
   strcpy(ob1.data.name,"Hamid");

   struct node temp;
   temp.id = 2;
   temp.cgpa = 2.9;
   strcpy(temp.name,"Fahmid");
   temp.next = NULL;

   ob1.data.next = &temp;

   printf("%s\n",ob1.data.next->name);

   ob1.prev = &ob2;
   ob2.prev = &ob1;


}





