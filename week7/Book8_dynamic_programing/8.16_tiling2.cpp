/**
 * 타일링 방법의 수 세기(tiling2)
 * 문제 해결전략: DP
 * - tiling(n) = 2 * n 크기의 사각형을 타일로 덮는 방법
 * - tiling(n) = tiling(n - 1) + tiling(n - 2)
 * - 시간 복잡도 O(n)
 */

#include <iostream>

using namespace std;
const int MOD = 1000000007;
int cache[101];

int tiling(int n) {
  // base case
  if (n <= 1) return 1;
  // 메모이제이션
  int &res = cache[n];
  if (res != -1) return res;
  return res = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    int n;
    cin >> n;
    cout << tiling(n) << "\n";
  }

  return 0;
}