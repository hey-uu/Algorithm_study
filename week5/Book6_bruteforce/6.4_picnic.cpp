/**
 * PICNIC
 * - 특징 : 조합
 * 	  - 선택 여부를 확인하기 위해 bool 배열 사용
 *    - 중복을 피하기 위해 사전 순으로 가장 먼저 오는 답 하나만 셀 것
 *    - 각 단계에서 남아 있는 학생들 중 가장 번호가 빠른 학생의 짝 찾아주면 됨
 * - 기저 사례
 *	  - 남아 있는 학생이 없는 경우
 * - 상한
 * 	  - 열 명의 학생이 모두 서로 친구인 경우 : 9 * 7 * 5 * 3 * 1 = 945
 *    - 학생 수가 적기 때문에 브루트 포스로도 시간 내에 해결 가능함
*/
#include <iostream>

int		c, n, m; // c : 테스트 케이스 수, n : 학생의 수, m : 친구 쌍의 수
bool	areFriends[10][10];

int	countParings(bool taken[10])
{
	// 기저 사례 : 남아 있는 학생이 없는 경우
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break ;
		}
	}
	if (firstFree == -1) return (1);
	
	int	res = 0;
	for (int pairWith = firstFree + 1 ; pairWith < n ; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			res += countParings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return (res);
}

int	main(void)
{
	bool	taken[10];

	// 입력 받기
	std::cin >> c;
	for (int i = 0 ; i < c ; i++)
	{
		std::cin >> n >> m;
		for (int j = 0 ; j < m ; j++)
		{
			int	a, b;
			std::cin >> a >> b;
			if (a > b)
				areFriends[b][a] = true;
			else
				areFriends[a][b] = true;
			for (int k = 0 ; k < n ; k++)
				taken[k] = false;
		}
		std::cout << countParings(taken) << "\n";
	}

}