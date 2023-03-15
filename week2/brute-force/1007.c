#include <stdio.h>
#include <math.h>

int	t, n;
int	arr[20][2];
double min_sum;

// first version : 두 포인트를 선택함(시간초과)
/*
void	get_min_sum(bool is_chosen[20], int sum_x, int sum_y)
{
	bool	is_done = true;
	double	sum_x1, sum_y1, sum_x2, sum_y2;

	for (int i = 0 ; i < n - 1 ; i++)
	{
		if (is_chosen[i] == true)
			continue ;
		is_done = false;
		is_chosen[i] = true;
		for (int j = i + 1 ; j < n ; j++)
		{
			if (is_chosen[j] == true)
				continue ;
			is_chosen[j] = true;
			sum_x1 = sum_x + (arr[i][0] - arr[j][0]);
			sum_y1 = sum_y + (arr[i][1] - arr[j][1]);
			sum_x2 = sum_x - (arr[i][0] - arr[j][0]);
			sum_y2 = sum_y - (arr[i][1] - arr[j][1]);
			if ((pow(sum_x1, 2) + pow(sum_y1, 2)) < (pow(sum_x2, 2) + pow(sum_y2, 2)))
				get_min_sum(is_chosen, sum_x1, sum_y1);
			else
				get_min_sum(is_chosen, sum_x2, sum_y2);
			is_chosen[j] = false;
		}
		is_chosen[i] = false;
	}
	if (is_done == true)
	{
		double	sum = sqrt(pow(sum_x, 2) + pow(sum_y, 2));
		if (min_sum == -1 || min_sum > sum)
			min_sum = sum;
	}
}
*/

// second version : 
// 일단 전체 점의 x좌표와 y좌표 합을 구하고 
// 거기서 n/2 개 점을 선택해서 해당 점의 x좌표랑 y좌표를 각각 2배해서 뺄셈하는 방식으로 해결

void	get_min_sum(int sum_x, int sum_y, int depth, int cur_idx)
{
	if (depth == 0)
	{
		double	sum = sqrt(pow(sum_x, 2) + pow(sum_y, 2));

		if (min_sum == -1 || min_sum > sum)
			min_sum = sum;
		return ;
	}
	for (int i = cur_idx + 1; i < n ; i++)
	{
		int	next_sum_x, next_sum_y;
		
		next_sum_x = sum_x - 2 * arr[i][0];
		next_sum_y = sum_y - 2 * arr[i][1];
		get_min_sum(next_sum_x, next_sum_y, depth - 1, i);
	}
}

int	main(void)
{
	int		sum_x;
	int		sum_y;

	// 입력 받기
	scanf("%d", &t);
	for (int i = 0 ; i < t ; i++)
	{
		sum_x = 0;
		sum_y = 0;
		scanf("%d", &n);
		for (int j = 0 ; j < n ; j++)
		{
			scanf("%d %d", &arr[j][0], &arr[j][1]);
			sum_x += arr[j][0];
			sum_y += arr[j][1];
		}
		min_sum = -1;
		get_min_sum(sum_x, sum_y, n / 2, 0);
		printf("%0.7lf\n", min_sum);
	}
}
