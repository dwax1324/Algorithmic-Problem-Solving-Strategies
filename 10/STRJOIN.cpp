// date: Fri Feb 12 23:16:45 2021
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


vector<int> v;
int STRJOIN(){
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0; i < v.size(); i++) pq.push(v[i]);
	int ret=0;
	while(pq.size()>1){
		int min1 = pq.top();pq.pop();
		int min2= pq.top();pq.pop();
		pq.push(min1+min2);
		ret += min1+ min2;
	}
	return ret;
}


int32_t main(){ this_is_main_function
int tt; cin >> tt; while(tt--){
	int n; cin >> n;
	v.resize(n);
	for(int i=0; i <n; i++) cin >> v[i];
	cout << STRJOIN() << endl;	
}

}

