#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int next[10005];
void make_next(string p) {
    int len = p.size();
    int i, k;
    next[0] = 0;
    for (i = 1, k = 0; i < len; ++i) {
        while (k > 0 && p[i] != p[k]) {
            k = next[k-1];
        }
        if (p[i] == p[k]) {
            k++;
        }
        next[i] = k;
    }
}
int kmp(string s, string t) {
    int len1 = s.size();
    int len2 = t.size();
    int i, j;
    int count = 0;
    for (i = 0, j = 0; i < len2; ++i) {
        while (j > 0 && t[i] != s[j]) {
            j = next[j-1];
        }
        if (s[j] == t[i]) {
            j++;
        }
        if (j == len1) {
            count++;
            j = next[j-1];
        }
    }
    return count;
}
int main() {
    int n;
    string pma, ori;
    cin >> n;
    while (n--) {
        cin >> pma >> ori;
        make_next(pma);
        cout << kmp(pma, ori) << endl;
    }
    return 0;
}
