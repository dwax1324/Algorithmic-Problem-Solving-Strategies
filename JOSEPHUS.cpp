// date: Sat Feb 13 18:45:07 2021
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


pii josephus(int n, int k){
	list<int> survivors;
	for(int i=1; i<= n; i++) survivors.push_back(i);
	auto kill = survivors.begin();
	while(n> 2){
		kill = survivors.erase(kill);
		if( kill == survivors.end()) kill = survivors.begin();
		n--;

		for(int i=0; i < k-1; i++){
			kill++;
			if(kill == survivors.end()) kill= survivors.begin();
		}
	}
	return {survivors.front(), survivors.back()};

}

int32_t main(){ this_is_main_function
int tt; cin >> tt; while(tt--){
	int n, k; cin >> n >> k;
	pii ans = josephus(n,k);
	cout << ans.o1 << ' ' << ans.o2 << endl;
}
}

