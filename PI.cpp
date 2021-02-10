// date: Wed Feb 10 19:46:40 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t

string N;
const int INF = 1<<30;
int dp[10001];

int val(int a, int b){
	string M = N.substr(a, b-a+1);

	if(M == string(M.size(), M[0])) return 1;

	bool progressive = true;
	for(int i=0; i< M.size()-1; i++)
		if(M[i+1]-M[i] != M[1] -M[0]) progressive = false;

	if(progressive && abs(M[1] - M[0]) == 1) return 2;

	bool alternating = true;
	for(int i=0; i < M.size(); i++)
		if(M[i] != M[i%2]) alternating = false;
	
	if(alternating) return 4;
	if(progressive) return 5;
	return 10;
}


int go(int idx){
	if(idx == N.size()) return 0;
	int &ret = dp[idx];
	if(ret != -1) return ret;
	ret = INF;
	for(int L=3 ; L<= 5; L++){
		if(idx +L <= N.size()){
			ret = min(ret, go(idx+L)+ val(idx,idx+L-1));
		}
	}
	return ret;
}

void solve(){
int tt; cin >> tt; while(tt--){
	cin >> N;
	memset(dp,-1,sizeof(dp));
	cout << go(0) << '\n';
}
}


int32_t main(){ F int t=1;
// cin >> t;
while(t--) solve();}

