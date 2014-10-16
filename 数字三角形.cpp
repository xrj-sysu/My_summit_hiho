#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int a[1001][1001] = {0};
int f[1001][1001] = {0};
int main() {
    int n, i, j, ans;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j <= i; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    f[0][0] = a[0][0];
    for (i = 1; i < n; ++i) {
        for (j = 0; j <= i; ++j) {
            if (j == 0) {
                f[i][j] = a[i][j] + f[i-1][j];
            } else {
                  f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j];  
              }
        }
    }
    ans = f[n-1][0];
    for (i = 1; i < n-1; ++i) {
        if (f[n-1][i] > ans) {
            ans = f[n-1][i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
