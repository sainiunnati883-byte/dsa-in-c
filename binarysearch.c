#include <stdio.h>

int sqrtInt(int n) {
    if (n == 0 || n == 1)
        return n;

    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // avoid overflow
        if (mid <= n / mid) {
            ans = mid;          // store valid answer
            left = mid + 1;     // try bigger value
        } else {
            right = mid - 1;    // go smaller
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", sqrtInt(n));

    return 0;
}