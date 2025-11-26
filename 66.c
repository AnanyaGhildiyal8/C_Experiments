#include <stdio.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    int a[n+1];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int pos = n;
    while (pos > 0 && a[pos - 1] > x) {
        a[pos] = a[pos - 1];
        pos--;
    }
    a[pos] = x;

    for (int i = 0; i <= n; i++) printf("%d ", a[i]);
    return 0;
}