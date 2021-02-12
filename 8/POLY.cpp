// date: Thu Feb 11 01:21:12 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define this_is_main_function ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t

const int MOD = 1e7;
int dp[101][101];

int poly(int n, int first){
	if(n == first) return 1;

	int &ret = dp[n][first];
	if(ret != -1) return ret;
	ret =0;
	for(int second =1; second <= n-first; second++){
		int add =second + first -1;
		add *= poly(n-first,second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int32_t main(){ this_is_main_function
int tt; cin >> tt; while(tt--){
	int n; cin >> n;
	memset(dp,-1,sizeof(dp));
	int ans =0;
	for(int i=1 ;i <= n; i++){
		ans += poly(n,i);
		ans %= MOD;
	}
	cout << ans << endl;
}

}
