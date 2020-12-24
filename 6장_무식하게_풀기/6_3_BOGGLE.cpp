#include <bits/stdc++.h>

// 5*5의 문자격자판에서 주어진 단어를 찾을 수 있는가?

// 문제주소
// https://www.algospot.com/judge/problem/read/BOGGLE
using namespace std;

char board[6][6];
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

bool inRange(int y, int x) {
    if (y < 0 || x < 0 || y >= 5 || x >= 5) return false;
    return true;
}

// 5*5의 보글 게임 판의 해당 위치에서 주어진 단어가 시작하는지를 반환
bool hasWord(int y, int x, const string& word) {
    // 기저 사례1: 시작 위치가 범위 밖이면 무조건 실패
    if (!inRange(y, x)) return false;
    // 기저 사례2: 첫 글자가 일치하지 않으면 실패
    if (board[y][x] != word[0]) return false;
    // 기저 사례3: 단어 길이가 1이면 성공
    if (word.size() == 1) return true;

    // 인접한 여덟 칸을 검사한다.
    for (int i = 0; i < 8; i++) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        // 다음 칸이 범위 안에 있는지, 첫 글자는 일치하는지 확인할 필요가 없다.
        if (hasWord(nextY, nextX, word.substr(1))) {
            return true;
        }
    }
    return false;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> board[i][j];
            }
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            bool flag = false;
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (hasWord(j, k, s)) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) {
                cout << s << " "
                     << "YES\n";
            } else {
                cout << s << " "
                     << "NO\n";
            }
        }
    }
}

/*
    입력:
    1
    URLPM
    XPRET
    GIAET
    XTNZY
    XOQRS
    6
    PRETTY
    GIRL
    REPEAT
    KARA
    PANDORA
    GIAZAPX
    
    결과:
    PRETTY YES
    GIRL YES
    REPEAT YES
    KARA NO
    PANDORA NO
    GIAZAPX YES

    결과: 시간초과
    최적화기법은 나머지 8장에서 소개
*/