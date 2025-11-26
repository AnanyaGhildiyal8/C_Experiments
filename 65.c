#include <stdio.h>

int main() {
    int n, key;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    scanf("%d", &key);

    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] == key) {
            printf("Found at index %d", mid);
            return 0;
        } else if (a[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }

    printf("Not Found");
    return 0;
}
