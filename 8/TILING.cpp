// date: Wed Feb 10 21:48:15 2021
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
#define int int64_t

int N;
int dp[101];
int MOD = 1000000007;
int go(int a){
	if(a <= 1) return 1;
	int &ret = dp[a];
	if(ret!=-1)return ret;
	return ret = (go(a-1) + go(a-2) +MOD)%MOD ;
}

int32_t main(){ this_is_main_function
int tt; cin >>tt; while(tt--){
	cin >> N;
	memset(dp,-1,sizeof(dp));
	cout << go(N) << endl;
}
}

