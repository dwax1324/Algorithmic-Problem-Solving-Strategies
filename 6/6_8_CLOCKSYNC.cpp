#include <bits/stdc++.h>


using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;


const char linked[SWITCHES][CLOCKS+1] = {
    // 0123456789012345
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};


// 모든 시계가 12시를 가리키고 있는지 확인한다.
bool areAligned(const vector<int>& clocks){
    for(auto x : clocks){
        if(x != 12) return false;
    }
    return true;
}
// swtch번 스위치를 누른다.
void push(vector<int>& clocks, int swtch){
    for(int clock= 0; clock < CLOCKS; clock++){
        clocks[clock] +=3;
        if(clocks[clock]==15) clocks[clock] = 3;
    }
}

// clocks: 현재 시계들의 상태
// swtch:: 이번에 누를 스위치의 번호
// 가 주어질 때, 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소횟수를 반환한다.
// 만약 불가능하다면 INF 이상의 큰 수를 반환한다.

int solve(vector<int>& clocks, int swtch){
    if(swtch == SWITCHES) return areAligned(clocks)? 0 : INF;
    // 이 스위치를 0번 누르는 경우부터 세 번누르는 경우까지 모두 시도한다.
    int ret = INF;
    for(int cnt=0; cnt< 4; cnt++){
        ret = min(ret,cnt+solve(clocks,swtch+1));
        push(clocks,swtch);
    }
    // push(clocks,swtch)가 네 번 호출되었으니 clocks는 원래와 같은 상태가 된다.
    return ret;

}



int main(){

    int t;
    cin >> t;
    while(t--){

        vector<int> v(16);
        for(int i=0; i < 16; i++){
            cin >> v[i];
        }
        cout << solve(v,0) << '\n';


    }

}