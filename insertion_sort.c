/*
1.consider the first element of the array as sorted array
2.Take out the next index element and compare first and second element if the second element is smaller than first one so swap those two elements,
  and consider those two elements as sorted array.
3. Repeat step 2.
*/

#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)
    {
      int key = arr[i];
      int j = i-1;

      while (j>=0 && arr[j] > key)
      {
        arr[j+1] = arr[j];
        j--;
      }
        arr[j+1] = key;
    }
    
        printf("\nAfter Sorting:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", arr[i]);
        }
    
}

int main()
{
    int arr[5] = {35, 25, 15, 5, 45};

    printf("Before Sorting:\n");
    for(int i =0 ; i<5;i++)
        printf("%d\t",arr[i]);

    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
}
