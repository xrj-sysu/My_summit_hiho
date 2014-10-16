#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
struct node {
    int next[26];
    int cnt;
    void init() {
        cnt = 0;
        memset(next, -1, sizeof next);
    }
}T[1000005];
int le;
void insert(string s) {
    int i, x;
    int p = 0;
    for (i = 0; i < s.size(); ++i) {
        x = s[i] - 'a';
        if (T[p].next[x] == -1) {
            T[le].init();
            T[p].next[x] = le++;
        }
        p = T[p].next[x];
        T[p].cnt++;
    }
}
int query(string s) {
    int i, x;
    int p = 0;
    for (i = 0; i < s.size(); ++i) {
        x = s[i] - 'a';
        if (T[p].next[x] == -1) {
            return 0;
        }
        p = T[p].next[x];
    }
    return T[p].cnt;
} 
int main() {
    int n, m, i;
    string s;
    cin >> n;
    le = 1;
    T[0].init();
    while (n--) {
        cin >> s;
        insert(s);
    }
    cin >> m;
    while (m--) {
        cin >> s;
        cout << query(s) << endl;
    }
    return 0;
}
