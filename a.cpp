// date: Fri Feb 12 23:39:58 2021
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

int w,h; 
int dp[101][101][2][2];
// f(r,c,changed) r,c에서 changed여부에 따른 w,h까지 도차갛ㄹ 수 있는 경로의 수
// f(r,c,changed,dir) r,c 에서 changed여부와 dir여부에 따른 w,h까지 도착가능한 경로의 수
// dir 0 : down 1 : rightdown
int f(int r, int c, int changed,int dir){
	cout << r << " " << c << endl;
	if(r >w || c >h) {
	//	cout << 1;
		return 0;
	}
	if(r == w && c == h){
		cout << "@";
		return 1;
	}
	// int&ret = dp[r][c][changed][dir];
	// if(ret!=-1) return ret;
	int ret =0;
	if(dir == -1){
		ret += f(r+1,c,0,0);
		ret += f(r+1,c+1,0,1);
	}
	if(changed == 0){
		// down
		if( dir == 0){
			ret += f(r+1,c,0,0);
			ret += f(r+1,c+1,1,1);
		}
		// rightdown
		if(dir == 1){
			ret += f(r+1,c,1,0);
			ret += f(r+1,c+1,0,1);
		}
	}
	if(changed == 1){
		if(dir ==0)
			ret += f(r+1,c,0,dir);
		if(dir == 1)
			ret += f(r+1,c+1,0,dir);
	}
	return ret;
}

int32_t main(){ this_is_main_function
	cin >> w >> h; w--;h--;
	memset(dp,-1,sizeof(dp));
	cout << f(0,0,0,-1);
}

