// date: Mon Feb 8 18:28:44 2021
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

string reverse(string::iterator &it){
    char head= *it;
    it++;

    if(head != 'x')
        return string(1,head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    return "x"+ lowerLeft + lowerRight + upperLeft + upperRight;
}

void solve(){
    int T; cin >> T; while(T--){
    string s; cin >> s;
    auto it = s.begin();
    cout << reverse(it) << endl;
    }


}


int32_t main(){ F int T=1;
// cin >> t;
for(int tt=0;tt<T;tt++) {solve(); }}