#include <bits/stdc++.h>

using namespace std;
/*
코드 6.2
n : 전체 원소 수
r : 뽑을 원소 수
v : 지금까지 고른 원소
*/
void go(int n, int r, vector<int> v) {
    // 기저사례: 더 고를 원소가 없으면 고른 원소들을 출력한다.
    if (r == 0) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << '\n';
        return;
    }

    // 고를 수 있는 가장 작은 번호를 계산한다.
    int smallest = !v.size() ? 1 : v.back() + 1;

    // 원소를 하나 고른다.
    for (int i = smallest; i <= n; i++) {
        v.push_back(i);
        go(n, r - 1, v);
        v.pop_back();
    }
}

int main() {
    go(5, 2, {});
    // 결과: 5C2
    // 1 2
    // 1 3
    // 1 4
    // 1 5
    // 2 3
    // 2 4
    // 2 5
    // 3 4
    // 3 5
    // 4 5
}