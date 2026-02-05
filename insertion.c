#include <stdio.h>

int main()
{
    int n, pos, x;
    int arr[100];
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    for (i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    printf("Updated array:\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}

