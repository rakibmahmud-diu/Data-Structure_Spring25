#include <stdio.h>

int mx, mn;
void min_max(int arra[],int n);
//int max(int arra[],int n);
//int min(int arra[],int n);

int main()
{
    //int arr1[100];
    int i, n;

    // Prompt user for input
    printf("\n\nFind maximum and minimum element in an array :\n");
    printf("--------------------------------------------------\n");
    printf("Input the number of elements to be stored in the array :");
    scanf("%d", &n);
    int arr1[n];
    // Input elements for the array
    printf("Input %d elements in the array :\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
//    int mx = max(arr1,n);
//    int mn = min(arr1,n);
    min_max(arr1,n);
    printf("Maximum element is : %d\n", mx);
    printf("Minimum element is : %d\n", mn);
	return 0;
}

void min_max(int arra[],int n)
{
    mx = arra[0];
    mn = arra[0];
    for(int i = 1; i<n; i++){
        if(arra[i]> mx)
            mx = arra[i];

        if(arra[i]< mn)
            mn = arra[i];
    }
    //return mx;
}


//int min(int arra[],int n)
//{
//    int mn = arra[0];
//    for(int i = 1; i<n; i++){
//        if(arra[i]< mn)
//            mn = arra[i];
//    }
//    return mn;
//}
//
//
