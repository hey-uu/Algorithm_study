/**
 * BOGGLE
 * - 특징 : dx, dy 배열로 상대 좌표를 정의함
 * - 기저 사례
 * 	  1) 입력이 잘못되거나 범위에서 벗어난 경우 
 * 		=> 재귀 함수를 호출하는 시점에서 오류 검사할 필요 x 
 * 		=> 코드가 간결해짐
 * 	  2) (1)이 아니고) 주어진 위치에 있는 글자와 단어의 첫글자가 다른 경우
 * 	  3) (1)과 2)가 아니고) 단어의 길이가 1인 경우
 * - 시간복잡도
 * 	  - 지수 시간 : O(8^N)
 * 		=> 단어의 길이가 짧을 때만 완전 탐색으로 해결 가능
 * 		=> 단어의 길이가 길 때 동적 계획법을 사용하면 빠르게 해결 가능
*/

#include <iostream>
#include <vector>

int							C, N;
char						board[5][6];
std::vector<std::string> 	words;
const int					dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int					dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};

bool	hasWord(int x, int y, const std::string &word)
{
	if (x >= 5 || y >= 5)
		return (false);
	if (board[x][y] != word[0])
		return (false);
	if (word.size() == 1)
		return (true);
	for (int dir = 0 ; dir < 8 ; dir++)
	{
		int	nextX = x + dx[dir];
		int	nextY = y + dy[dir];
		if (hasWord(nextX, nextY, word.substr(1)))
			return (true);
	}
	return (false);
}

int	main(void)
{
// 입력받기
	std::cin >> C;
	for (int i = 0 ; i < C ; i++)
	{
		for (int j= 0 ; j< 5 ; j++)
			std::cin >> board[j];
		std::cin >> N;
		for (int j = 0 ; j < N ; j++)
		{
			std::string	tmp;
			std::cin >> tmp;
			words.push_back(tmp);
		}
		for (auto itr = words.begin() ; itr != words.end() ; itr++)
		{
			for (int j = 0 ; j < 25 ; j++)
			{
				if (hasWord(j / 5, j % 5, *itr))
				{
					std::cout << *itr << " YES\n";
					break ;
				}
				if (j == 24)
					std::cout << *itr << " NO\n";

			}
		}
	}
	
}