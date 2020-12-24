#include <bits/stdc++.h>

using namespace std;


int n;
int dp[100001], s[100001];
// s[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis3(int start){
    int&ret = dp[start+1];
    if(ret != -1) return ret;
    // 항상 s[start]는 있기 때문에 길이는 최하 1
    ret =1;
    for(int next = start +1; next < n; next++)
        if(start == -1 || s[start] < s[next])
            ret = max(ret,lis3(next)+1);
    
    return ret;
}


int main(){

    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0; i < n ;i++){
            cin >> s[i];
        }
        memset(dp,-1,sizeof(dp));
        cout << lis3(-1)-1 << '\n';
    }
}