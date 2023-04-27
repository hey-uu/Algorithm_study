/**
 * 회의실 예약(Conference Room Reservation)
 * - r길이와 상관없이 가장 먼저 끝나는 회의 선택하기
 */

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int n;
int begin[MAX], end[MAX];

int schedule() {
  vector<pair<int, int>> order;
  for (int i = 0; i < n; ++i)
    order.push_back(make_pair(end[i], begin[i]));

  // 가장 먼저 끝나는 회의부터 순서 정렬하기
  sort(order.begin(), order.end());

  int nextBegin = 0, selectedCnt = 0;
  for (int i = 0; i < order.size(); ++i) {
    int meetingBegin = order[i].second;
    int meetingEnd = order[i].first;
    if (nextBegin <= meetingBegin) {
      nextBegin = meetingEnd;
      ++selectedCnt;
    }
  }
  return (selectedCnt);
}