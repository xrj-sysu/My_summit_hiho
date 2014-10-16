#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int num[105] = {0};
int adj[105][105] = {0};
int f[105][105] = {0};
int tree[105][5] = {0};
int n, m;
void make_tree(int v);
void bulid(int v, int u, int lor) {
    tree[v][lor] = u;
    adj[v][u] = -1;
    adj[u][v] = -1;
    make_tree(u);
}
void make_tree(int v) {
    int i;
    int lr = 0;
    for (i = 0; i <= n; ++i) {
        if (adj[v][i] > 0) {
            lr++;
            bulid(v, i, lr);
            if (lr == 2) {
                return;
            }
        }
    }
}
void dfs(int root, int count) {
    int i;
    if (count == 0) {
        f[root][count] = 0;
    }
    else if (tree[root][1] == 0 && tree[root][2] == 0) {
        f[root][count] = num[root];
    }
    else {
        for (i = 0; i < count; ++i) {
            if (f[tree[root][1]][i] == 0) {
                dfs(tree[root][1], i);
            }
            if (f[tree[root][2]][count-1-i] == 0) {
                dfs(tree[root][2], count-1-i);
            }
            f[root][count] = max(f[root][count], (f[tree[root][1]][i] + f[tree[root][2]][count-1-i] + num[root]));
        }
    }
}
int main() {
    int i, x, y;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < n-1; ++i) {
        scanf("%d%d", &x, &y);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    make_tree(1); 
    dfs(1, m);
    printf("%d\n", f[1][m]);
    return 0;
} 
