// date: Wed Feb 10 21:55:29 2021
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

int dp[101][101];
int cnt_dp[101][101];
int mapp[101][101];
int N;

int path(int r, int c){
	if(r == N-1) return mapp[r][c];
	int&ret = dp[r][c];
	if(ret!=-1) return ret;
	return ret = max(path(r+1,c), path(r+1,c+1)) + mapp[r][c];
}

int cnt(int r, int c){
	if(r == N-1)return 1;
	int&ret = cnt_dp[r][c];
	if(ret != -1)return ret;
	ret=0;
	int down = path(r+1,c);
	int right_down = path(r+1,c+1);
	if(down >= right_down) ret += cnt(r+1,c);
	if(right_down >= down) ret += cnt(r+1,c+1);
	return ret;
}

int32_t main(){ this_is_main_function
int tt; cin >>tt ;while(tt--){
	cin >> N;
	for(int i=0; i < N; i++)
		for(int j=0; j <i+1; j++)
			cin >> mapp[i][j];
	memset(cnt_dp,-1,sizeof(cnt_dp));
	memset(dp,-1,sizeof(dp));
	cout << cnt(0,0) << endl;
}
}

