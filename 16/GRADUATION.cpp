// date: Sat Feb 13 17:29:23 2021
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


const int INF = 1<<30, MAXN = 13;
int n,k,m,l;
int prerequisite[MAXN];
int classes[10];
int cache[10][1<<MAXN];
int bitCount(int n){
	return __builtin_popcount(n);
}

int graduate(int semester, int taken){
	if(bitCount(taken) >= k) return 0;
	if(semester == m) return INF;
	int& ret = cache[semester][taken];
	if(ret != -1) return ret;
	ret = INF;
	int canTake = (classes[semester] & ~taken);

	for(int i=0; i < n; i++)
		if((canTake & (1<<i)) && (taken & prerequisite[i]) != prerequisite[i]) canTake &= ~(1<<i);
	for(int take = canTake; take >0 ; take = ((take-1 ) & canTake)){
		if(bitCount(take) > l) continue;
		ret = min(ret, graduate(semester+1, taken | take) +1);
	}
	ret = min(ret, graduate(semester +1, taken));
	return ret;
}
int32_t main(){ this_is_main_function
int tt; cin >> tt; while(tt--){
	memset(cache,-1,sizeof(cache));
	memset(prerequisite,0,sizeof(prerequisite));
	memset(classes,0,sizeof(classes));
	cin >> n >> k >> m >> l;
	for(int i=0; i < n; i++) {
		int a; cin >> a; for(int j=0; j < a; j++){
			int t; cin >> t;
			prerequisite[i] |= (1<<t);
		}
	}
	for(int i=0; i < m; i++){
		int a; cin >> a; for(int j=0; j < a; j++){
			int t; cin >> t;
			classes[i] |= (1<<t);
		}
	}

	int ans = graduate(0,0);
	if(ans == INF) cout << "IMPOSSIBLE" << endl;
	else cout << ans << endl;
}
}
