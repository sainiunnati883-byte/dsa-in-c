#include <stdio.h>

int main() {
    int p, q;
    int i, j, k = 0;

    int log1[200], log2[200], merged[400];

    // Read p
    scanf("%d", &p);

    // Read first log
    for (i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Read q
    scanf("%d", &q);

    // Read second log
    for (i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    i = 0;
    j = 0;

    // Merge logs
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    while (i < p) {
        merged[k++] = log1[i++];
    }

    while (j < q) {
        merged[k++] = log2[j++];
    }

    // Print result
    for (i = 0; i < k; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}

