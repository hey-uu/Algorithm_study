/**
 * 삼각형 위의 최대 경로 개수 세기(TRIPATHCNT)
 * 문제 해결전략: DP
 * - count(y, x) = (y, x)에서 시작해 맨 아래줄까지 내려가는 최대 경로의 수
 *   path(y+1, x) > path(y+1, x+1) =>  count(y + 1, x)
 *   path(y+1, x) < path(y+1, x+1) =>  count(y + 1, x + 1)
 *   path(y+1, x) == path(y+1, x+1) =>   count(y + 1, x) + count(y + 1, x + 1)
 */

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX = 100;
int triangle[MAX][MAX];
int cache[MAX][MAX];
int countCache[MAX][MAX];
int n;

// 각 위치에서의 최대 경로의 합
int path(int y, int x) {
  if (y == n - 1) return triangle[y][x];
  int &ret = cache[y][x];
  if (ret != -1) return ret;
  return ret = triangle[y][x] + max(path(y + 1, x), path(y + 1, x + 1));
}

// 최대경로의 개수
int count(int y, int x) {
  if (y == n - 1) return 1;
  int &ret = countCache[y][x];
  if (ret != -1) return ret;
  ret = 0;
  if (path(y + 1, x + 1) >= path(y + 1, x)) ret += count(y + 1, x + 1);
  if (path(y + 1, x + 1) <= path(y + 1, x)) ret += count(y + 1, x);
  return ret;
}

int main() {
  int cnt;
  cin >> cnt;
  while (cnt--) {
    memset(cache, -1, sizeof(cache));
    memset(countCache, -1, sizeof(countCache));
    cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i; j++) cin >> triangle[i][j];

    cout << count(0, 0) << "\n";
  }

  return 0;
}