#include <stdio.h>
int set[20], n, target, found = 0;
void subsetSum(int index, int sum, int subset[])
{

    if (sum == target)
    {
        found = 1;
        printf("Subset: ");

        for (int i = 0; i < index; i++)
            if (subset[i])
                printf("%d ", set[i]);
        printf("\n");
        return;
    }
    if (index == n || sum > target)
        return;

    subset[index] = 1;
    subsetSum(index + 1, sum + set[index], subset);

    subset[index] = 0;
    subsetSum(index + 1, sum, subset);
}
int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    int subset[20] = {0};
    subsetSum(0, 0, subset);

    if (!found)
        printf("No subset with given sum exists.\n");
    return 0;
}
