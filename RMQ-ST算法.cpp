#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n; 
int num[1000005];
int f[1000005][30];

void RMQ_ST() {
	int i, j;
	int temp = (int)(log((double)n) / log(2.0)); 
	for (i = 0; i < n; ++i) {
		f[i][0] = i;
	}
	for (j = 1; j <= temp; ++j) {
		for (i = 0; i+(1<<j)-1 < n; ++i) {
			int p = f[i][j-1];
			int q = f[i+(1<<(j-1))][j-1];
			if (num[p] <= num[q]) {
				f[i][j] = f[i][j-1];
			} else {
			      f[i][j] = f[i+(1<<(j-1))][j-1];	
			  }
		}
	}
}
int query(int l, int r) {
	int temp = (int)(log(double(r-l+1))/log(2.0));
	int p = f[l][temp];
	int q = f[r-(1<<temp)+1][temp];
	if (num[p] <= num[q]) {
		return p;
	} else {
	      return q;	
	  }
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	RMQ_ST();
	int t, l, r, ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &l, &r);
		ans = query(l-1, r-1);
		printf("%d\n", num[ans]);
	}
	return 0;
}
