#include <stdio.h>

int main()
{
    int arr[100];
    int n, mm = 1, ctr = 0;
    int i, j, min = 100000;  // Declare loop counters

    printf("Input the number of elements to be stored in the array :");
    scanf("%d", &n);

    printf("Input %d elements in the array :\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i]<min)
         min = arr[i];
    }

    min--;
    //printf("%d",min);


    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j] && arr[j]!=min)
            {
                ctr++;

                for(int k = j; k < n; k++){
                if (arr[i] == arr[k])
                {
                    arr[k] = min;
                }

                }
            }



        }
    }

    printf("Total number of duplicate elements found in the array: %d\n", ctr);
    return 0;
}
