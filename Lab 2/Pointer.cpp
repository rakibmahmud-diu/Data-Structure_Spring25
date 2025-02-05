#include<stdio.h>
#include<stdlib.h>

int main()
{
///Void Pointer
//   int n = 10;
//   int *p = &n;
//   //*p = 100;
//   n = 110;
//   printf("%d\n", *(int*)p);
   //printf("%d", n);

///NULL Pointer
//   int *p = NULL;
//   p = (int*)calloc(2,sizeof(int));
//   if(p == NULL)
//      printf("Memory Full!!\n");
//   else
//      printf("Successfully Allocated!\n");

///Dangling Pointer
//   int *p;
//   //int ara[2];
//   p = (int*) malloc(2*sizeof(int));
//   p[1] = 50;
//   printf("%d\n",*(p+1));
//   free(p);
//   p = NULL;
//   printf("%d\n",*(p+1));


///Wild Pointer
//   int *p;
//   *p = 10;
//   printf("%d\n",*p);

   return 0;
}
