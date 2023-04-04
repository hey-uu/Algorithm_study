/**
 * BOARDCOVER
 * - 특징 : 
 * 	  1) 한 칸을 덮는 네 가지 방법을 coverType[] 배열에 상대 좌표(dy, dx)의 목록으로 저장
 * 	  2) 조합
 * 		- 선택 여부를 확인하기 위해 int 2차원 배열 사용(bool이 아닌 이유는 set함수 때문)
 * 		- 중복을 피하기 위해 각 단계마다 빈 칸 중 가장 윗 줄, 그 중 가장 왼쪽 칸을 덮도록 함
 * 	  3) set()
 * 		- 블록을 놓는 역할과 치우는 역할 수행
 * 		- 해당 칸에 블록을 놓을 수 있는지 검사 결과가 실패여도 끝까지 함수를 실행
 * - 기저 사례
 * 	  - 모든 칸이 채워진 경우
 * - 상한
 * 	- 보드판의 흰 칸의 개수는 50보다 작으므로 최대 16개의 블록을 놓을 수 있음 => 4^16
 * 	- 하지만 실제로 문제를 풀어보면 실제 답의 수는 상한보다 훨씬 작음을 확인할 수 있음
 *  - 따라서 브루트 포스로도 문제 해결 가능
*/

#include <iostream>
#include <vector>

int	c, h, w;
int	board[20][20];
const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

bool	set(int board[20][20], int y, int x, int type, int delta)
{
	bool isOk = true;
	for (int i = 0 ; i < 3 ; i++)
	{
		int	nextY = y + coverType[type][i][0];
		int nextX = x + coverType[type][i][1];
		if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w)
			isOk = false;
		else if ((board[nextY][nextX] += delta) > 1)
			isOk = false;
	}
	return (isOk);
}

int	cover(int board[20][20])
{
// 흰 칸 찾기 && 기저 사례
	int	y = -1, x = -1;
	for (int i = 0 ; i < h ; i++) {
		for (int j = 0 ; j < w ; j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break ;
			}
		}
	}
	if (y == -1) return (1);
// 본론
	int	res = 0;
	for (int type = 0; type < 4 ; type++)
	{
		if (set(board, y, x, type, 1)) res += cover(board);
		set(board, y, x, type, -1);
	}
	return (res);
}

int	main(void)
{
	std::cin >> c;
	for (int i = 0 ; i < c ; i++) {
		std::cin >> h >> w;
		for (int j = 0 ; j < h ; j++) {
			for (int k = 0 ; k < w ; k++) {
				char a;
				std::cin >> a;
				board[j][k] = (a == '#');
			}
		}
		std::cout << cover(board) << "\n";
	}
}