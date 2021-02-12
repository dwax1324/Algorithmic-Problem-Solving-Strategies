// date: Thu Feb 11 01:56:53 2021
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

int n,d,p,q;
double dp[51][101];
int connected[51][51], deg[51];
double searchh(int curr, int days){
	if(days == 0) return (curr == p ? 1.0 : 0.0);

	double & ret = dp[curr][days];
	if(ret > -0.5) return ret;
	ret = 0.0;

	for(int i=0; i < n; i++){
		int next = connected[curr][i];
		if(next) ret += searchh(i,days-1)/deg[i];
	}
	return ret;
}

int32_t main(){ this_is_main_function
int tt; cin >> tt; while(tt--){
	cin >> n >> d >> p;
	memset(deg,0,sizeof(deg));
	for(int i=0; i < n; i++)
		for(int j=0; j < n; j++){
			cin >> connected[i][j];
			deg[i] += connected[i][j];
		}
	for(int i=0; i < 51 ;i++)
		for(int j=0; j < 101;j++)
			dp[i][j] = -1.0;
	int q; cin >> q;
	for(int i=0; i < q; i++){
		int a; cin >> a;
		cout << fixed << setprecision(8) <<  searchh(a,d) << ' ';
	}
	cout << endl;
}
}

