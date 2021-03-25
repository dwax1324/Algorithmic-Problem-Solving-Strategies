// date: Sat Feb 13 00:45:20 2021
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

int w,h;
int dp[101][101][4];
const int MOD = 100000;
int32_t main(){ this_is_main_function
	cin >> w >> h;
	w--;h--;	
	for(int j=0; j < h; j++){
		dp[0][j][1] =1;
	}
	
	for(int i=0; i < w; i++){
		dp[i][0][3] =1;
	}

	// 0 ld , 1 ud , 2 ur, 3 lr
	for(int i=1; i < w; i++){
		for(int j=1; j < h; j++){
			dp[i][j][0] = dp[i][j-1][3];
			dp[i][j][1] = (dp[i-1][j][0] + dp[i-1][j][1]) %MOD;
			dp[i][j][2] = dp[i-1][j][1];
			dp[i][j][3] = (dp[i][j-1][2] + dp[i][j-1][3])%MOD;
		}
	}
	int ans=0;	
	for(int i=0; i <4; i++){
		ans += dp[w-1][h-1][i];
	}
	cout << ans%MOD;

}

