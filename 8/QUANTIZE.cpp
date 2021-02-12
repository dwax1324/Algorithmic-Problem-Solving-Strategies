// date: Wed Feb 10 21:34:27 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t

int length;
int arr[101]; // 양자화할 수열,정렬된 상태
int partSum[101]; // arr[]의 부분합 저장, partSum[i] = A[0]+..A[i]의 합
int partSquareSum[101]; // arr[] 제곱의 부분합 저장, partSquareSum[i]는 arr[0]^2+...arr[i]^2의 합
int cache[101][11];
const int INF = 1<<30;

// arr을 정렬하고 각 부분합 계산
void preCalculate(){
	sort(arr, arr+length);
	partSum[0] = arr[0];
	partSquareSum[0] = arr[0] * arr[0];
	for(int i=1; i < length; i++){
		partSum[i] = partSum[i-1] + arr[i];
		partSquareSum[i] = partSquareSum[i-1] + arr[i]*arr[i];
	}
}

// arr[low]...arr[high]구간을 하나의 숫자로 표현할 때 최소오차 합 계산
int minDifference(int low, int high){
	int sum = partSum[high] - (low==0 ?0 : partSum[low-1]);
	int squareSum = partSquareSum[high]- (low == 0 ? 0 : partSquareSum[low-1]);

	int mean = (int) (0.5 +(double) sum/(high-low+1));

	int res = squareSum - (2*mean*sum) + (mean*mean*(high-low+1));
	return res;
}

// from번째 이후의 숫자들을 parts개의 묶음으로 묶는다.
int quantize(int from, int parts){
	if (from == length) return 0;
	if (parts == 0) return INF;
	int &ret = cache[from][parts];
	if(ret != -1) return ret;
	ret = INF;
	for(int partSize = 1; from + partSize <= length; partSize++)
			ret = min(ret, minDifference(from,from+partSize-1) + quantize(from+partSize,parts-1));
	return ret;
}

void solve(){
	int tt; cin >> tt ;while(tt--){
		int num;
		cin >> length >> num;
		for(int i=0; i < length; i++) cin >> arr[i];
		preCalculate();
		memset(cache,-1,sizeof(cache));
		cout << quantize(0,num) << endl << endl;

	}
}


int32_t main(){ F int t=1;
// cin >> t;
while(t--) solve();}

