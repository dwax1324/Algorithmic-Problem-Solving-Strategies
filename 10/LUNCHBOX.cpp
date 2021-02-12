// date: Fri Feb 12 20:43:44 2021
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

const int MAX_N = 10001;
int n,e[MAX_N], m[MAX_N];

int heat(){
	vector<pii> order;
	for(int i=0; i < n; i++) order.push_back({-e[i],i});
	sort(all(order));
	int ret=0, begin_eat =0;
	for(int i=0; i < n; i++){
		int box = order[i].o2;
		begin_eat += m[box];
		ret = max(ret, begin_eat + e[box]);
	}
	return ret;
}


int32_t main(){ this_is_main_function
int tt; cin >> tt; while(tt--){
	cin >> n;
	for(int i=0; i <n ;i++) cin >> m[i];
	for(int i=0; i < n; i++) cin >> e[i];
	cout << heat() << endl;
}

}

