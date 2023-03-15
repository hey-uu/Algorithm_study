#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int	n;
int	cost_matrix[20][20];
int min_cost = INT_MAX;

void	travel_cities(int start_pos, int cur_pos, int cost, bool visited[10], int depth)
{

	bool	is_done;

	is_done = true;
	for (int i = 0 ; i < n ; i++)
	{
		if (visited[i] == true)
			continue ;
		is_done = false;
		if (cost_matrix[cur_pos][i] != 0)
		{
			visited[i] = true;
			cost += cost_matrix[cur_pos][i];
			travel_cities(start_pos, i, cost, visited, depth);
			visited[i] = false;
			cost -= cost_matrix[cur_pos][i];
		}
	}
	if (is_done == true)
	{
		if (cost_matrix[cur_pos][start_pos] == 0)
			return ;
		cost += cost_matrix[cur_pos][start_pos];
		if (min_cost > cost)
			min_cost = cost;
	}
}

int	main(void)
{
	bool	visited[10];

	// 입력 받기
	scanf("%d\n", &n);
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < n ; j++)
			scanf("%d", &cost_matrix[i][j]);
	// 시작 위치 결정 후 순회하기
	for (int i = 0 ; i < n ; i++)
	{
		// visited 초기화해주기
		for (int j = 0 ; j < n ; j++)
			visited[j] = false;
		visited[i] = true;
		travel_cities(i, i, 0, visited, 0);
	}
	printf("%d\n", min_cost);
}
