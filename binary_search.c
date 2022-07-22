#include <stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int l = 0, h = 9, m = (l + h) / 2;
    int search = 5,i=0;

    while (i != search)
    {
        if (a[m] == search)
        {
            printf("The element found on: %d",a[m]);
            i=search;
            break;
        }
        else if (a[m] > search)
        {
            l = a[m] + 1;
            printf("The element found on: %d", l);
            i=search;
            break;
        }
        else if(a[m] < search)
        {
            h = a[m] - 1;
            printf("The element found on: %d",h);
            i=search;
            break;
        }
        else
        {
            printf("Element not found");
        }
        i++;
    }
}