#include<stdio.h>

void bubble_sort(int arr[],int n)
{
    int i , j;
    int temp,isSorted = 1;
    for(i = 0 ; i<= n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }

        isSorted = 0;
    }
    
    printf("\nAfter Sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}       
int main()
{
    int a[] = {7,4,3000,2,1};

    printf("Before Sorting:\n");
    for(int i =0 ; i<5;i++)
        printf("%d\t",a[i]);

    int n = sizeof(a)/sizeof(a[0]);
    bubble_sort(a,n);


    return 0;    
}