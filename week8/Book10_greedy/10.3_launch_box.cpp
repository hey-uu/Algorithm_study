/**
 * 회의실 예약(Conference Room Reservation)
 * - 먹는데 오래 걸리는 도시락부터 데우자
 */

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int n;
int e[MAX], m[MAX];

int heat()
{
    vector<pair<int, int>> order;
    for (int i = 0; i < n; ++i)
        order.push_back(make_pair(-e[i], i));
    sort(order.begin(), order.end());
    int ret = 0, beginEat = 0;
    for (int i = 0; i < n; i++)
    {
        int box = order[i].second;
        beginEat += m[box];
        ret = max(ret, beginEat + e[box]);
    }
}