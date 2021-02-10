// Wed Feb 10 16:48:57 KST 2021
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
#define int int64_t

int N,M;
vector<int> A,B;
int dp[101][101];
int INF= 1ll<<62;
int jlis(int a, int b){	
	int &ret = dp[a+1][b+1];
	if(ret !=-1) return ret;
	ret =2;
	int a_val = (a == -1 ?-INF : A[a]);
	int b_val = (b == -1 ?-INF : B[b]);
	int MAX = max(a_val,b_val);
	for(int next = a+1; next < N; next++){
		if(MAX < A[next]) ret = max(ret,jlis(next,b)+1);
	}
	for(int next = b+1; next < M; next++){
		if(MAX < B[next]) ret = max(ret,jlis(a,next)+1);
	}
	return ret;
}

void solve(){
int tt; cin >> tt; while(tt--){
	cin >> N >> M;
	A.resize(N);
	B.resize(M);
	for(int i=0; i < N; i++)
		cin >> A[i];
	for(int i=0; i < M; i++)
		cin >> B[i];
	memset(dp,-1,sizeof(dp));
	cout << jlis(-1,-1)-2 << endl;
}
}


int32_t main(){ F int t=1;
// cin >> t;
while(t--) solve();}

