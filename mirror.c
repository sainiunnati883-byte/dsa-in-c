#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    int i;

    scanf("%s", s);          // read the string
    int n = strlen(s);       // length of string

    for (i = n - 1; i >= 0; i--) {
        printf("%c", s[i]);  // print in reverse order
    }

    return 0;
}
