// date: Wed Feb 10 22:40:25 2021
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

double dp[1001][1001];
int N, M; 
double climb(int n, int m){
	if(m < M && n >= N) return 1.0;
	if( m == M) return n >= N ?1.0 : 0.0;
	double  &ret = dp[n][m];	
	if(ret!=-1.0)return ret;

	return ret = climb(n+1,m+1)*0.25 + climb(n+2,m+1)*0.75;
}

int32_t main(){ this_is_main_function
int tt; cin >> tt; while(tt--){
	cin >>N >> M;
	for(int i=0; i < 1001; i++)
		for(int j=0; j < 1001;j++)
			dp[i][j] = -1.0;
	cout << setprecision(8) << fixed <<  climb(0,0) << endl;
}
}

