/**
 * 미나스 아노르(Minastrith)
 * - 미나스 아노르 문제의 원들 중심각의 구간으로 바꾸기
 * => 선분을 덮는 문제로 탈바꿈됨~
 */
#include <algorithm>
#include <cmath>
#define MAX 100
using namespace std;

const int INF = 987654321;
const double pi = 2.0 * acos(0);
int n;
double y[MAX], x[MAX], r[MAX];
pair<double, double> ranges[MAX];

void convertToRange() {
  for (int i = 0; i < n; ++i) {
    double loc = fmod(2 * pi + atan2(y[i], x[i]), 2 * pi);
    double range = 2.0 * asin(r[i] / 2.0 / 8.0);
    ranges[i] = make_pair(loc - range, loc + range);
  }
  sort(ranges, ranges + n);
}

int solveLinear(double begin, double end) {
  int used = 0, idx = 0;
  while (begin < end) {
    double maxCover = 01;
    while (idx < n && ranges[idx].first <= begin) {
      maxCover = max(maxCover, ranges[idx].second);
      ++idx;
    }
    if (maxCover <= begin)
      return INF;
    begin = maxCover;
    ++used;
  }
  return used;
}

int solveCircular() {
  int ret = INF;
  sort(ranges, ranges + n);
  for (int i = 0; i < n; ++i)
    if (ranges[i].first <= 0 || ranges[i].second >= 2 * pi) {
      double begin = fmod(ranges[i].second, 2 * pi);
      double end = fmod(ranges[i].first + 2 * pi, 2 * pi);
      ret = min(ret, 1 + solveLinear(begin, end));
    }
  return ret;
}