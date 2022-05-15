long long sum(int* a, int n) {
    long long ans = 0;
    int i;
    if (n >= 1 && n <= 3000000) {
        for (i = 0; i < n; i++) {
            if (a[i] >= 0 && a[i] <= 1000000) {
                ans += a[i];
            }
        }
    }

    return ans;
}
