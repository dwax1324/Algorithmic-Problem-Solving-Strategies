#include <bits/stdc++.h>

// 학생의 수와 친구의 정보가 주어졌을 때,
// 친구끼리로만 짝지을 수 있는 경우의 수?
// 문제 주소
// https://www.algospot.com/judge/problem/read/PICNIC

using namespace std;

int n, m;
bool areFriends[10][10];
// taken[i] = i번째 학생이 짝이 결정됐는지?
int countPairings(bool taken[10]) {
    // *중복제거* - 답 중에서 사전순으로 가장 먼저오는 답 하나만 센다.
    // 남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
    int first = -1;
    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            first = i;
            break;
        }
    }
    // 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾앗으니 종료한다.
    // 모든 사람이 짝이 결정됐다면 first==-1이다. 한가지 방법을 찾았으니 1을 리턴한다.
    if (first == -1) return 1;
    int ret = 0;
    // 이 학생과 짝지을 학생을 결정한다.
    // 자신의 뒷번호부터 끝번호까지 탐색한다.
    for (int i = first + 1; i < n; i++) {
        // 짝이없으면서 이 학생과 친구인 사람을 찾았으면 taken배열에 표시하고 다음 짝찾기로 넘어간다.
        if (!taken[i] && areFriends[first][i]) {
            taken[first] = taken[i] = true;
            ret += countPairings(taken);
            taken[first] = taken[i] = false;
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(areFriends, 0, sizeof(areFriends));
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }
        bool arr[10];
        memset(arr, 0, sizeof(arr));
        cout << countPairings(arr) << '\n';
    }
}
