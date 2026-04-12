#include <stdio.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
}

void search(int table[], int m, int key) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[idx] == EMPTY) {
            break; // key not present
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[1000];

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') { // INSERT
            insert(table, m, key);
        } else if (op[0] == 'S') { // SEARCH
            search(table, m, key);
        }
    }

    return 0;
}