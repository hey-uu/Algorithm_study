#include <stdio.h>

int		n;
char	board[50][51];
int		max = 0;

void	swap(char *a, char *b)
{
	const char	temp = *a;

	*a = *b;
	*b = temp;
}

void	find_max_candies(int i, int j)
{
	int	left = 0, right = 0, up = 0, down = 0;
	int	left_right_len, up_down_len;

	while (j - 1 - left >= 0 && board[i][j - 1 - left] == board[i][j])
		left++;
	while (j + 1 + right < n && board[i][j + 1 + right] == board[i][j])
		right++;
	left_right_len = left + right + 1;
	while (i - 1 - up >= 0 && board[i - 1 - up][j] == board[i][j])
		up++;
	while (i + 1 + down < n && board[i + 1 + down][j] == board[i][j])
		down++;
	up_down_len = up + down + 1;
	if (max < left_right_len)
		max = left_right_len;
	if (max < up_down_len)
		max = up_down_len;
}

int	main(void)
{
	int	i, j;

	// 입력 받기
	scanf("%d", &n);
	for (i = 0 ; i < n ; i++)
	{
		scanf("%s", board[i]);
	}
	// 현재 보드에서 최댓값 구하기
	max = 0;
	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n ; j++)
		{
			find_max_candies(i, j);
		}
	}
	// 좌우로 인접한 서로 다른 색의 사탕 위치 바꾸고 최댓값 구하기
	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n - 1 ; j++)
		{
			if (board[i][j] != board[i][j + 1])
			{
				swap(&board[i][j], &board[i][j + 1]);
				find_max_candies(i, j);
				find_max_candies(i, j + 1);
				swap(&board[i][j], &board[i][j + 1]);
			}
		}
	}
	// 상하로 인접한 서로 다른 색의 사탕 위치 바꾸고 최댓값 구하기
	for (i = 0 ; i < n - 1 ; i++)
	{
		for (j = 0 ; j < n ; j++)
		{
			if (board[i][j] != board[i + 1][j])
			{
				swap(&board[i][j], &board[i + 1][j]);
				find_max_candies(i, j);
				find_max_candies(i + 1, j);
				swap(&board[i][j], &board[i + 1][j]);
			}
		}
	}
	// 출력하기
	printf("%d\n", max);
}
