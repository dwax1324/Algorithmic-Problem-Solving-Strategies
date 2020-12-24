#include <bits/stdc++.h>


using namespace std;


const int INF = 987654321;
string N;
int dp[100002];

// N[a..b] 구간의 난이도를 반환한다.

int classify(int a, int b){
    // 숫자 조각을 가져온다.
    string M = N.substr(a, b-a+1);
    // 첫글자만으로 이루어진 문자열과 같으면 난이도는 1
    if(M== string(M.size(),M[0])) return 1;
    // 등차수열인지 검사한다.
    bool progressive = true;
    for (int i=0; i < M.size()-1; i++){
        if(M[i+1] -M[i] != M[1] -M[0]) progressive = false;
    }
    // 등차수열이고 공차가 1 혹은 -1이면 난이도는 2
    if(progressive && abs(M[1] - M[0]) ==1) return 2;

    // 두 수가 번갈아 등장하는지 확인한다.
    bool alternating = true;
    for(int i=0; i < M.size() ;i++){
        if(M[i] != M[i%2]) alternating = false;
    }
    if(alternating) return 4;
    if(progressive) return 5;
    return 10;
}

// 수열 N[begin..]을 외우는 방법 중 난이도의 최소 합을 출력한다.

int memorize(int begin){
    // 기저사례: 수열의 끝에 도달했을 경우
    if(begin == N.size()) return 0;
    // 메모이제이션
    int&ret = dp[begin];
    if(ret != -1) return ret;
    ret = INF;
    for(int i=3; i<=5 ;i++){
        if(begin+i <= N.size())
            ret= min(ret, memorize(begin+i) + classify(begin,begin+i-1));
    }
    return ret;
}


int main(){

    int T;
    cin >> T;
    while(T--){
        cin >> N;
        memset(dp,-1,sizeof(dp));
        cout << memorize(0) << "\n";
        

    }


}