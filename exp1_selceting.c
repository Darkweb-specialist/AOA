#include<stdio.h>
void selectionSort(int arr[], int n)
{
    int i,j,minindex,temp;
    for ( i = 0; i < n-1; i++)
    {
        minindex=i;
        for ( j = 1; j < n; j++)
        {
            if (arr[j]< arr[minindex])
            {
                minindex=j;
            }
            
        }
        temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
        
    }
    
}
void printArray(int arr[],int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    
}

int main()
{
    int arr[100],n,i;
    printf("Enter the number of element:");
    scanf("%d",&n);
    printf("Enter %d element:\n", n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Original Array:\n");
    printArray(arr,n);

    selectionSort(arr,n);
    printf("Sorted Array:\n");
    printArray(arr,n);
    return 0;
    
}