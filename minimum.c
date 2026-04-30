#include <stdio.h>

int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;
    
    for (int i = 0; i < n; i++) {
        if (pages + arr[i] > maxPages) {
            students++;
            pages = 0;
        }
        pages += arr[i];
    }
    
    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int arr[n];
    int left = 0, right = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > left) left = arr[i]; // max
        right += arr[i]; // sum
    }
    
    int ans = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    printf("%d", ans);
    
    return 0;
}