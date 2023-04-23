/***
 * 두니발 박사의 탈옥(NUMB3RS)
 * 문제 해결전략: 완전 탐색 알고리즘
 */

#include <iostream>
#include <vector>

using namespace std;
int n, d, p, q;
int connected[51][51], deg[51];

double search_bfs(vector<int> &path) {
  if (path.size() == d + 1) {
    if (path.back() != q)
      return 0.0;
    double res = 1.0;
    for (int i = 0; i + 1 < path.size(); ++i)
      res /= deg[path[i]];
    return res;
  }
  double res = 0;
  for (int there = 0; there < n; ++there)
    if (connected[path.back()][there]) {
      path.push_back(there);
      res += search_bfs(path);
      path.pop_back();
    }
  return res;
}

int main(void) {}