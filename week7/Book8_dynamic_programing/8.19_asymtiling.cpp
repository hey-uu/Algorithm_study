/**
 * 비대칭 타일링(asymtiling)
 * 문제 해결전략: DP
 * - 대칭 타일링의 수 세는 문제로 바꿔 풀기!
 * - 짝수, 홀수로 나눠서
 */

#include <iostream>

const int MOD = 1000000007;
int d[101];

int tiling(int n) {
  if (n <= 1) return 1;
  if (d[n] != 0) return d[n];
  return d[n] = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

// O(N)
int asymmetric(int n) {
  if (n % 2 == 1) return (tiling(n) - tiling(n / 2) + MOD) % MOD;

  int ret = tiling(n);
  ret = (ret - tiling(n / 2) + MOD) % MOD;
  ret = (ret - tiling(n / 2 - 1) + MOD) % MOD;

  return ret;
}
