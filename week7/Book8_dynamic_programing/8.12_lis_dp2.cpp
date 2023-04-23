/**
 * 해결전략: DP
 * - 시간복잡도 O(n^2)
 * - 2개로 쪼개진 코드 하나로 합치기 -> -1도 입력값으로 받아서 처리
 */

#include <algorithm>

using namespace std;

const int MAX = 100;
int N;
int cache[MAX], S[MAX];

int lis3(int start) {
  int &res = cache[start];
  if (res != -1) return res;
  res = 1;
  for (int next = start + 1; next < N; ++next)
    if (S[next] > S[start] || start == -1) res = max(res, lis3(next) + 1);
  return res;
}

/**
 * LIS: Longest Increasing Subsequence
 * 해결전략:
 *  - C[i]: 길이가 i인 증가 부분 수열 중 최소의 마지막값
 * - 시간 복잡도
 *   - LIS의 길이 k에 대하여, O(nk) 시간에 찾을 수 있음
 *   - C가 순증가하므로 이분 검색을 하면, O(nlgk) <= O(lgn)에 찾을 수 있음
 */

// https://shoark7.github.io/programming/algorithm/3-LIS-algorithms

int lis4(int start) {}