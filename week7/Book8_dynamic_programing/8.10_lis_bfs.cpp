/**
 * LIS = Longest Increasing Subsequence
 * 해결 전략 : 완전 탐색 알고리즘
 * - lis(A) : A의 모든 증가 부분 수열을 만든 뒤 가장 긴 것의 길이를 반환
 *  1. A에서 수열의 첫번째 숫자를 고른다.
 *  2. 고른 숫자보다 오른쪽에 있고 큰 숫자들만 고른 부분 수열 B를 만들어 lis()를
 * 재귀호출한다.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int N;
using namespace std;

int myLIS2(vector<int> const &v) {
  if (v.empty()) return 0;
  int res = 1;
  for (int nxt = 1; nxt < v.size(); ++nxt) {
    if (v[nxt] <= v[0]) continue;
    vector<int> sub_v(v.begin() + nxt, v.end());
    int sublen = myLIS(sub_v) + 1;
    res = (sublen > res) ? sublen : res;
  }
  return res;
}

int myLIS(vector<int> const &v) {
  int res = 0;
  for (int i = 0; i < v.size(); ++i) {
    vector<int> sub_v(v.begin() + i, v.end());
    int sublen = myLIS2(sub_v);
    res = (sublen > res) ? sublen : res;
  }
  return (res);
}

int LIS(vector<int> const &v) {
  if (v.empty()) return 0;
  int res = 0;
  for (int i = 0; i < v.size(); ++i) {
    vector<int> sub_v;
    for (int j = i + 1; j < v.size(); ++j)
      if (v[i] < v[j]) sub_v.push_back(v[j]);
    res = max(res, 1 + LIS(sub_v));
  }
  return res;
}

int main(void) {
  std::cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    int tem;
    std::cin >> tem;
    v.push_back(tem);
  }
  std::cout << "myLIS : " << myLIS(v) << std::endl;
  std::cout << "LIS   : " << LIS(v) << std::endl;
}