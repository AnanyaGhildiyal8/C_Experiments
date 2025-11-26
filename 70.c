#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    k = k % n;

    int temp[k];
    for (int i = 0; i < k; i++)
        temp[i] = a[n - k + i];

    for (int i = n - 1; i >= k; i--)
        a[i] = a[i - k];

    for (int i = 0; i < k; i++)
        a[i] = temp[i];

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}