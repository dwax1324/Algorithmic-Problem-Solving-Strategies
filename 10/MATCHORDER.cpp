// date: Fri Feb 12 20:24:08 2021
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

vector<int> korean,russian;

int order(){
	int n = russian.size(), wins=0;

	multiset<int> ratings(korean.begin(),korean.end());
	for(int rus=0; rus <n; rus++){
		if(*ratings.rbegin() < russian[rus]) ratings.erase(ratings.begin());
		else{
			ratings.erase(ratings.lower_bound(russian[rus]));
			wins++;
		}
	}
	return  wins;
}


int32_t main(){ this_is_main_function
int tt; cin >> tt; while(tt--){
	int n; cin >> n;
	korean.resize(n);
	russian.resize(n);
	for(int i=0; i< n; i++) cin >> russian[i];
	for(int i=0; i < n; i++) cin >> korean[i];
	cout << order() << endl;
}
}

