#include <stdio.h>

int main() {
    int n, pos;
    scanf("%d %d", &n, &pos);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = pos; i < n - 1; i++)
        a[i] = a[i + 1];

    for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
    return 0;
}