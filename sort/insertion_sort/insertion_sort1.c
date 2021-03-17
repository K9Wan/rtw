#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *a, int n)
{
    int i, j;
    for(i=1;i<n;i++)
    {
        int temp = a[i];
        for(j=i-1; j>=0 && a[j]>temp; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
        /*/
        for(j=i; j>0 && a[j-1]>temp; j--)
        {
            a[j] = a[j-1];
        }
        a[j] = temp;
        /*/
    }   //without swaping function or memmove();
}

static void print(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%i ", a[i]);
    }
    puts("");
}

int main(void)
{
    int arr[] = {1,4,35,23,3,6,8,5,6,15,9,0,32,11,98,13,25,27};
    insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));
    print(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
