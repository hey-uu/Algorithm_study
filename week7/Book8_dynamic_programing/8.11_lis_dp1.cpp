/**
 * 해결전략 : DP
 * - lis(start) = S[start]에서 시작하는 부분 증가 수열 중 최대의 길이
 * - 기저 사례 없이 for문을 끝까지 순회. 재귀호출 없으면 1반환
 * - 시간복잡도 O(N^2)
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100;
int N;
int cache[MAX], S[MAX];

int lis2_part2(int start) {
  int &res = cache[start];
  if (res != -1) return res;
  res = 1;
  for (int next = start + 1; next < N; ++next)
    if (S[start] < S[next]) res = max(res, lis2_part2(next)) + 1;
  return res;
}

int lis2_part1(vector<int> const &v) {
  int maxLen = 0;
  for (int begin = 0; begin < N; ++begin)
    maxLen = max(maxLen, lis2_part2(begin));
  return maxLen;
}