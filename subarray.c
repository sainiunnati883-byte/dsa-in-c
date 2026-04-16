#include <stdio.h>

int maxLen(int arr[], int n) {
    int maxLength = 0;
    int sum = 0;

    // Hash map using arrays (since constraints are small enough)
    // Using large range offset
    int hash[200001];
    
    for (int i = 0; i < 200001; i++)
        hash[i] = -2;  // -2 means not visited

    int offset = 100000;  // to handle negative sums

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLength = i + 1;
        }

        if (hash[sum + offset] == -2) {
            hash[sum + offset] = i;
        } else {
            int length = i - hash[sum + offset];
            if (length > maxLength)
                maxLength = length;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));
    return 0;
}