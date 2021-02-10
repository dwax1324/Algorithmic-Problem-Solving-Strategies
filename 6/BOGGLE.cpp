// Sat Feb  6 21:49:07 KST 2021
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


// check the word from each idices
// check the 5*5 map = 25 times,
// one idx 8 driections, maximum 10 length word = 8* 10 each index
// 80(per index) * 25(map size) * 10(queries) = 20000
// 20000 * 50 ( tescases) =  1000000
// NO!! one idx have 8 directions, maximum 10 = 8^10 not 8 * 10
// now it makes sense why i got TLE
char mapp[6][6];
int dxy[8][2] = {
	{1,1},
	{1,-1},
	{-1,1},
	{-1,-1},
	{1,0},
	{-1,0},
	{0,1},
	{0,-1},
};
bool dfs(int r, int c, string s){
	if(s[0] != mapp[r][c]) return false;
	if(s.size() == 1 && s[0] == mapp[r][c]) return true;
	bool ret= false;
	for(int d=0; d<8; d++){
		int nr = dxy[d][0] + r;
		int nc = dxy[d][1] + c;
		if(nr <0 || nc <0 || nr >= 5 || nc >= 5) continue;
		ret |= dfs(nr,nc,s.substr(1,sz(s)-1));
	}
	return ret;
}

bool is_there_word(string &s){
	for(int i=0; i < 5; i++)
		for(int j=0; j < 5; j++)
			if(dfs(i,j,s)) return true;
	return false;
}


void solve(){

	for(int i=0; i < 5; i++)
		for(int j=0; j < 5; j++)
			cin >> mapp[i][j];
	int Q; cin >> Q;
	for(int i=0; i < Q; i++){
		string s; cin >> s;
		if(is_there_word(s)) {
			cout << s << ' ' << "YES" << endl;
		}else{
			cout << s << ' ' << "NO" << endl;
		}
	}
}


int32_t main(){ F int t=1;
cin >> t;
while(t--) solve();}

