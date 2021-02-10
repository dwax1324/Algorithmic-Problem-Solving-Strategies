// Sat Feb  6 22:29:37 KST 2021
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

// combination 
// friend N <= 10
// realtion M <= 45
// 45C5 = 1221759 
// after find the combinations, check whether theres unmatched student

int n,m;
vector<pii> v;
int comb(int a, vector<int> &vv){
	if(a*2 >= n){
		int arr[11]={0};
		for(auto x : vv){
			arr[v[x].o1]++;
			arr[v[x].o2]++;
		}
		for(int i=0; i < n; i++){
			if(arr[i] ==0 ) return 0;
		}
		return 1;
	}
	int first = vv.size() ? vv.back()+1  : 0;
	int ret=0;
	for(int i= first; i< sz(v); i++){
		vv.push_back(i);
		ret += comb(a+1,vv);
		vv.pop_back();
	}
	return ret;
}
void solve(){
	cin >> n >> m;
	v={};
	for(int i=0; i < m; i++){
		int a,b; cin >> a >> b;
		v.push_back({a,b});
	}
	vector<int> a;
	cout << comb(0,a) << endl;
}


int32_t main(){ F int t=1;
cin >> t;
while(t--) solve();}

