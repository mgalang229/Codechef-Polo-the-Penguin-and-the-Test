#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct qst {
	int n, p, t;
};

const int mxN=100;
int n, w, dp[mxN+1][mxN+1];
qst q[mxN];

void solve() {
	cin >> n >> w;
	for(int i=0; i<n; ++i)
		cin >> q[i].n >> q[i].p >> q[i].t;
	// apply knapsack (dynamic programming)
	dp[0][0]=0;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<=w; ++j) {
			dp[i][j]=dp[i-1][j];
			if(q[i-1].t<=j)
				dp[i][j]=max(dp[i][j], (q[i-1].n*q[i-1].p)+dp[i-1][j-q[i-1].t]);
		}
	cout << dp[n][w] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc=1;
	cin >> tc;
	for(int t=0; t<tc; ++t)
		solve();
}
