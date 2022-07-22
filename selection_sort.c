#include <stdio.h>

void selection_sort(int arr[], int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i+1; j < n ; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int main()
{
    int a[4] = {2, 1, 5, 3};
    printf("Before Sorting:\n");
    for (int i = 0; i < 4; i++)
        printf("%d\t", a[i]);

    selection_sort(a, 4);
}