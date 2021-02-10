// date: 2021-02-07 14:49:52
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
int n,m; 
char mapp[51][51];

int blocks[4][3][2]={
    { {0,0},{1,0},{0,1}},
    { {0,0},{0,1},{1,1}},
    { {0,0},{1,0},{1,1}},
    { {0,0},{1,0},{1,-1}}
};

int dfs(char mapp[51][51]){
    // find the leftuppermost blank space
    int sr,sc; sr=sc=-1;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            if(mapp[i][j] == '.'){
                sr = i; sc =j;
                goto bof;
            }
bof:
    if(sr == -1 && sc == -1) return 1;
    int ret= 0;
    //

    for(int p=0; p<4 ;p++){
        vector<pii> v;
        for(int q=0; q<3; q++){ 
            int nr = sr + blocks[p][q][0];
            int nc = sc + blocks[p][q][1];
            if(nr <0 || nc <0 || nr >= n || nc >= m) break;
            if(mapp[nr][nc] != '.') break;
            v.push_back({nr,nc});
        }
        if(v.size() == 3){
            for(auto x : v)
                mapp[x.first][x.second] = '@';
            ret += dfs(mapp);
            for(auto x : v)
                mapp[x.first][x.second] = '.';
        }

    }
    return ret;
}



void solve(){
    cin >> n >> m;
    int sr,sc;
    int cnt_blank=0;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++){
             cin >> mapp[i][j];
            if(mapp[i][j] == '.')cnt_blank++;
        }
    
    
    if(cnt_blank % 3) {
        cout << 0 << endl; return;
    }
    cout <<  dfs(mapp) << endl;
}


int32_t main(){ F int t=1;
cin >> t;
while(t--) solve();}