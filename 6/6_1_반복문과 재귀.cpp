#include <bits/stdc++.h>

using namespace std;

// 반복문 버전
// 필수 조건 n>=1
// 결과 : 1부터 n까지의 합을 반환한다.
int sum(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += i;
    }
    return ret;
}
// 재귀 버전
// 필수 조건 n>=1
// 결과 : 1부터 n까지의 합을 반환한다.
int recursiveSum(int n) {
    if (n == 1) return 1;
    return n + recursiveSum(n - 1);
}

int main() {
    cout << sum(10) << '\n';
    // 결과 : 55
    cout << recursiveSum(10);
    // 결과 : 55
}