/**
 * CLOCKSYNC
 * - 특징
 * 	  1) 조합
 * 	  	- 스위치를 눌리는 순서는 중요하지 않다. 각 스위치를 누르는 횟수가 중요하다.
 * 	  	- 시계는 12시간이 지나면 제자리로 돌아오기 때문에 스위치를 누르는 횟수 범위는 0 ~ 3이다.
 * 	  2) 2차원 배열을 통해 스위치와 시계가 연결되어있는지 표현
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const bool linked[SWITCHES][CLOCKS] = {
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

bool	allSynced(const vector<int> &clocks)
{
	for (auto itr = clocks.begin() ; itr != clocks.end() ; itr++)
		if (*itr != 12) return (false);
	return (true);
}

void	pushSwitch(vector<int> &clocks, int switchIdx)
{
	for (int clockIdx = 0; clockIdx < CLOCKS; clockIdx++) {
		if (linked[switchIdx][clockIdx]) {
			clocks[clockIdx] += 3;
			if (clocks[clockIdx] > 12) clocks[clockIdx] = 3;
		}
	}
}

int	minPushNum(vector<int> &clocks, int switchIdx)
{
	if (switchIdx == SWITCHES) return (allSynced(clocks) ? 0 : INF);

	int	res = INF;
	for (int cnt = 0 ; cnt < 4 ; cnt++) {
		res = min(res, cnt + minPushNum(clocks, switchIdx + 1));
		pushSwitch(clocks, switchIdx);
	}
	return (res);
}

int	main(void)
{
	int			c;
	vector<int>	clocks(16);

	cin >> c;
	for (int i = 0 ; i < c ; i++)
	{
		for (int j = 0; j < CLOCKS; j++)
			cin >> clocks[j];
		cout << minPushNum(clocks, 0) << "\n";
	}
}