#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    i = low; //0
    j = mid+1;//2
    k = low;//0
    int b[100];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        b[k] = arr[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}

void printarr(int arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d\t", arr[i]);
    }
}

void merge_sort(int arr[], int low, int high)
{   //low = 0 high = 3
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2; //low + high /2 = 1
        merge_sort(arr, low, mid); //arr , 0 , 1
        merge_sort(arr, mid + 1, high); //arr , 2 , 3
        merge(arr, low, mid, high); // arr , 0 , 1 ,3
    }
}

int main()
{
    int arr[] = {1, 68, 26, 30};
    printarr(arr,4);
    merge_sort(arr, 0, 3); //passing value of starting point and ending point of array
    printarr(arr, 4);
    return 0;
}
