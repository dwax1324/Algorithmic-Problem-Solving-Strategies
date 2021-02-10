// date: Tue Feb 9 14:13:27 2021
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
int N;
int mapp[101][101];
int dp[101][101];
bool go(int r, int c){
    if( r > N || c > N) return 0;
    if(r == N-1 && c == N-1) return 1;
    int &ret = dp[r][c];
    if(ret != -1) return ret;
    ret =0;
    int move = mapp[r][c];
    ret |= go(r+move,c);
    ret |= go(r,c+move);
    return ret;
}

void solve(){
    int T; cin >> T; while(T--){
        cin >> N;
        for(int i=0; i < N; i++)
            for(int j=0; j < N; j++)
                cin >> mapp[i][j];
        memset(dp,-1,sizeof(dp));
        if(go(0,0)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
         
    }
}


int32_t main(){ F int T=1;
// cin >> t;
for(int tt=0;tt<T;tt++) {solve(); }}