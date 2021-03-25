// date: Sat Feb 13 19:01:08 2021
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


int32_t main(){ this_is_main_function
int tt; cin >> tt; while(tt--){
	string s; cin >> s;
	stack<char> stk;
	bool matched = true;
	for(int i=0; i < s.size(); i++){
		char curr = s[i];
		if(curr == '(' || curr == '[' || curr == '{') stk.push(curr);
		else if( curr == ')'){
			if(stk.size() == 0 || stk.top() != '(') { matched = false;  break;}
			else {stk.pop();}
		}else if( curr == ']'){
			if(stk.size() == 0 || stk.top() != '[') {matched = false;  break;}
			else {stk.pop();}
		}else if(curr == '}'){
			if(stk.size() == 0 || stk.top() != '{') {matched = false; break;}
			else {stk.pop();}
		}
	}
	if(!matched || stk.size())cout << "NO" << endl;
	else cout << "YES" << endl;
}
}

