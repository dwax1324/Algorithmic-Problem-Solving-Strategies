#include <bits/stdc++.h>

using namespace std;


int n;
int arr[101][101];
int dp[101][101];

// (y,x)위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반홚나다.
int go(int y, int x){
    // 메모이제이션
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    // 기저사례: 맨 아래줄까지 도달했을 경우
    if(y == n) return arr[y][x];


    // ret이 직선, 대각선으로 내려가는 것 중 최댓값을 취한다.
    ret = go(y+1,x);
    return ret= max(ret,go(y+1,x+1)) + arr[y][x];
}



int main(){

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;  i<= n; i++){
            for(int j=1; j<= i; j++){
                cin >> arr[i][j];
            }
        }

        memset(dp,-1,sizeof(dp));
        cout << go(1,1) << "\n";

    }

}