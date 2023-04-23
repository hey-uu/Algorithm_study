/**
 * 우물을 기어오르는 달팽이
 * 문제 해결전략: DP
 */
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
int n, m;
double cache[MAX_N][2 * MAX_N + 1];

// 경우의 수 반환
double climb(int days, int climbed) {
  // base case
  if (days == m) return climbed >= n ? 1 : 0;
  // 메모이제이션
  double &ret = cache[days][climbed];
  if (ret != -1) return ret;
  return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}

// 확률 반환(SNAIL)
double climb2(int days, int climbed) {
  // base case
  if (days == m) return climbed >= n ? 1 : 0;
  // 메모이제이션
  double &ret = cache[days][climbed];
  if (ret != -1) return ret;
  return ret = 0.25 * climb(days + 1, climbed + 1) +
               0.75 * climb(days + 1, climbed + 2);
}