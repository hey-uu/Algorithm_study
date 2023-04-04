#include <stdio.h>

int	n;
int	arr[1000];

void	print_longest_arr(int cur_idx, int prev_idx[], int depth)
{
	if (depth <= 0)
		return ;
	print_longest_arr(prev_idx[cur_idx], prev_idx, depth - 1);
	printf("%d ", arr[cur_idx]);
}

int	main(void)
{
	int	count[1000];
	int	prev_idx[1000];
	int	last_idx;
	int	max_count;
	int	i, j;

	// 입력 받기
	scanf("%d\n", &n);
	for (i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);
	
	// 초기값
	count[0] = 1;
	max_count = 1;
	prev_idx[0] = -1;
	last_idx = 0;

	// (i) = (0)부터 (i - 1)에 본인을 포함했을 때 부분 수열이랑 비교
	for (i = 1 ; i < n ; i++)
	{
		prev_idx[i] = -1;
		count[i] = 1;
		for (j = 0 ; j < i ; j++)
		{
			if (arr[i] > arr[j] && count[i] < count[j] + 1)
			{
				count[i] = count[j] + 1;
				prev_idx[i] = j;
			}
		}
		if (count[i] > max_count)
		{
			max_count = count[i];
			last_idx = i;
		}
	}

	printf("%d\n", max_count);
	print_longest_arr(last_idx, prev_idx, max_count);
}