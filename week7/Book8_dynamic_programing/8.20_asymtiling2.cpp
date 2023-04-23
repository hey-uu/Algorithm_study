/**
 * 비대칭 타일링(asymtiling)
 * 문제 해결전략: DP
 * - 직접 비대칭 타일링의 수를 세기
 * - 앞에서부터 만들어가는게 아니라 양쪽 끝에서부터 만들어가기
 */

#include <iostream>

using namespace std;
const int MOD = 1000000007;
int d[101];
int cache2[101];

int tiling(int n) {
  if (n <= 1) return 1;
  if (d[n] != 0) return d[n];
  return d[n] = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int asymmetric2(int width) {
  // base case
  if (width <= 2) return 0;
  // 메모이제이션
  int &ret = cache2[width];
  if (ret != -1) return ret;
  ret = asymmetric2(width - 2) % MOD;
  ret = (ret + asymmetric2(width - 4)) % MOD;
  ret = (ret + tiling(width - 3)) % MOD;
  ret = (ret + tiling(width - 3)) % MOD;
  return (ret);
}
