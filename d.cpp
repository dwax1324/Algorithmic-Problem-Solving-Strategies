// date: Sat Feb 13 01:42:23 2021
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

int W,H,dp[101][101][2][2];
const int MOD = 100000;
int path(int r, int c, bool prevv, bool curr){
	if(r == H-1 && c == W-1) return 1;
	int &ret = dp[r][c][prevv][curr];
	if(ret != -1) return ret;

	ret =0;
	if( r < H-1 && !(prevv && !curr)) ret += path(r+1,c,(r||c)? curr : true , true);
	if(c<W-1 && !(!prevv && curr)) ret += path(r,c+1,(r||c)? curr: false,false);
	return ret %= MOD;

}

int32_t main(){ this_is_main_function
	cin >> W >> H;
	memset(dp,-1,sizeof(dp));
	cout << path(0,0,0,0);

}

