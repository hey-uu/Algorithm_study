#include <stdio.h>
#include <stdbool.h>

int		n;
char	image[64][65];

void	compress_image(int x, int y, int n);

void	compress_image_partition(int x, int y, int half)
{
	bool	is_same;

	is_same = true;
	for (int i = 0 ; i <  half; i++)
	{
		for (int j = 0 ; j < half ; j++)
		{
			if (image[x + i][y + j] != image[x][y])
			{
				is_same = false;
				break;
			}
		}
	}
	if (is_same == true)
	{
		printf("%c", image[x][y]);
	}
	else
		compress_image(x, y, half);
}

void	compress_image(int x, int y, int n)
{
	const int	half = n / 2;

	printf("(");
	if (half == 0)
	{
		printf("%c)", image[x][y]);
		return ;
	}
	// left top
	compress_image_partition(x, y, half);
	// right top
	compress_image_partition(x, y + half, half);
	// left bottom
	compress_image_partition(x + half, y, half);
	// right bottom
	compress_image_partition(x + half, y + half, half);
	printf(")");
}

int	main(void)
{
	bool	is_all_same;

	// 입력 받기
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++)
		scanf("%s", image[i]);
	// 모두 같은 값인지 확인하기(처음에 확인안해서 틀림...)
	is_all_same = true;
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			if (image[i][j] != image[0][0])
				is_all_same = false;
		}
	}
	if (is_all_same == true)
	{
		printf("%c\n", image[0][0]);
		return (0);
	}
	// 영상 압축하기
	compress_image(0, 0, n);
	return (0);
}