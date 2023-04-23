/***
 * 폴리오미노(POLY)
 * - 폴리오미노(Polyomino) : 정사각형의 변들을 서로 완전하게 붙여 만든 도형들
 * 문제 해결전략: DP
 * - poly(n, first) = n개의 정사각형을 포함하되, 첫 줄에 first개의 정사각형이
 * 들어가는 폴리오미노의 수
 * - poly(n, first) = sigma_{second=1}^{n-first}{(first + second - 1) *
 * poly(n-first, second)}
 * - O(N^3)
 */

#include <iostream>

using namespace std;
const int MOD = 10 * 1000 * 1000;
int cache[101][101];

int poly(int n, int first) {
  // base case
  if (n == first) return 1;
  // 메모이제이션
  int &ret = cache[n][first];
  if (ret != -1) return ret;
  ret = 0;
  for (int second = 1; second <= n - first; ++second) {
    int add = ((second + first - 1) * poly(n - first, second)) % MOD;
    ret += add;
    ret %= MOD;
  }
  return ret;
}
