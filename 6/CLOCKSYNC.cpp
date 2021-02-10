// date: Sun Feb 7 23:53:05 2021
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
int clocks[16];
vector<int> CLOCK[10] =
{
    vector<int>{0, 1, 2 },
    vector<int>{3, 7, 9, 11 },
    vector<int>{4, 10, 14, 15 },
    vector<int>{0, 4, 5, 6, 7 },
    vector<int>{6, 7, 8, 10, 12 },
    vector<int>{0, 2, 14, 15 },
    vector<int>{3, 14, 15 },
    vector<int>{4, 5, 7, 14, 15 },
    vector<int>{1, 2, 3, 4, 5 },
    vector<int>{3, 4, 5, 9, 13 },
};

bool is_sync(){
    for(int i=0; i < 16 ;i++){
        if(clocks[i] !=12) return false;
    }
    return true;
}

void push(int curr){
    for(auto &x : CLOCK[curr]){
        clocks[x] += 3;
        if(clocks[x] > 12) clocks[x] = 3;
    }
}
const int INF =1<<30;
int dfs(int curr){
    if(curr== 10) {
        if(is_sync()) return 0;
        return INF;
    }
    int ret= INF;
    for(int d= 0; d < 4; d++){
        // 여기에 배울점이 있네요
        // d= 누른횟수니까 0번부터 3번누르는 횟수를 재귀에 더해줌
        ret = min(ret,d+ dfs(curr+1));
        push(curr);
    }
    return ret;
}


void solve(){
    int T; cin >> T; while(T--){
        for(int i=0; i <16; i++) cin >> clocks[i];
        int k = dfs(0);
        cout << (k== 1<<30 ? -1 : k) << endl;
    }
}


int32_t main(){ F int T=1;
// cin >> t;
for(int tt=0;tt<T;tt++) {solve(); }}