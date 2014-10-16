#include<iostream>
#include<string>
#include<map>
using namespace std;
int a[200005];

void init(int n) {
	for (int i = 1; i <= n; ++i) {
		a[i] = i;
	}
}
int find(int x) {
	if (x == a[x]) {
		return x;
	} else {
	      a[x] = find(a[x]);
		  return a[x];	
	  }
}
void merge(int m, int n) {
	int x = find(m);
	int y = find(n);
	if (x == y) {
		return;
	} else {
	      a[x] = y;	
	  }
}
int query(int m, int n) {
	int x = find(m);
	int y = find(n);
	if (x == y) return 1;
	else return 0;
}
int main() {
    int n, flag, ans;
	cin >> n;
	map<string, int> m;
	string s, t;
	init(2 * n);
	int k = 1;
	while (n--) {
		cin >> flag >> s >> t;
		if (!m[s]) {
			m[s] = k++;
		}
		if (!m[t]) {
		    m[t] = k++;
		}
		if (flag == 0) {
			merge(m[s], m[t]);
		}
		if (flag == 1) {
			ans = query(m[s], m[t]);
			if (ans == 1) {
				cout << "yes" << endl;
			} else {
			      cout << "no" << endl;	
			  } 
		}	
	}
	return 0;
}
