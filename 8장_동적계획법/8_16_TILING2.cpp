#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int dp[101];

// 2*width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다.

int tiling(int width){
    // 기저사례: width가 1 이하일때
    if(width <= 1) return 1;
    // 메모이제이션
    int &ret = dp[width];
    if (ret != -1) return ret;
    return ret = (tiling(width-2) + tiling(width-1))%MOD;
}



int main(){
    int t; cin >> t;
    while(t--){
        int a;
        cin >> a;
        memset(dp,-1,sizeof(dp));
        cout << tiling(a) << '\n';
    }
}