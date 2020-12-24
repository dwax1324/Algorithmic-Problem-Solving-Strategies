#include <bits/stdc++.h>

using namespace std;

// https://algospot.com/judge/problem/read/JUMPGAME


int n, board[101][101];
int cache[101][101];

bool jump2(int y, int x){
    // 기저사례처리
    if(y>=n || x >= n ) return 0;
    if(y == n-1 && x == n-1) return 1;
    //메모제이션
    int & ret = cache[y][x];

    if(ret != -1) return ret;
    int jumpSize = board[y][x];

    return ret = (jump2(y+jumpSize,x) || jump2(y,x+jumpSize));

}


int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        memset(cache,-1,sizeof(cache));
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                cin >> board[i][j];
            }
        } 
        cout << (jump2(0,0) ? "YES\n" :"NO\n");
    }
}