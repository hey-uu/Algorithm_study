/***
 * 두니발 박사의 탈옥(NUMB3RS)
 * 문제 해결전략: 동적 계획법
 */

#include <iostream>
#include <vector>

using namespace std;
int n, d, p, q;
double cache[51][101]; // -1로 초기화
int connected[51][51], deg[51];

double search_dp2(int here, int days) {
  if (days == d)
    return (here == q ? 1.0 : 0.0);
  // 메모이제이션
  double &res = cache[here][days];
  if (res > -0.5)
    return res;
  res = 0.0;
  for (int there = 0; there < n; ++there)
    if (connected[here][there])
      res += search_dp2(there, days - 1) / deg[there];
  return res;
}

int main(void) {}