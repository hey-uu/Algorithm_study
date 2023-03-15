#include <stdio.h>

int			matrix[5][5];
int			n;
long long	b; // b의 범위를 고려하지 않음

void	matrix_multiplication(
		const int mat_a[5][5],
		const int mat_b[5][5],
		int mat_c[5][5])
{
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			mat_c[i][j] = 0;
			for (int k = 0 ; k < n ; k++)
			{
				mat_c[i][j] += (mat_a[i][k] * mat_b[k][j]) % 1000;
			}
			mat_c[i][j] %= 1000;
		}
	}
}

void	matrix_exponentation(
		int mat_a[5][5], int mat_res[5][5], long long exponent)
{
	int	mat_temp1[5][5];
	int	mat_temp2[5][5];

	if (exponent == 1)
	{
		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < n ; j++)
				mat_res[i][j] = (mat_a[i][j]) % 1000; // 2 1 / 1000 1000 / 1000 1000 엣지 케이스 처리
		return ;
	}
	if (exponent == 2)
	{
		matrix_multiplication(mat_a, mat_a, mat_res);
		return ;
	}
	matrix_exponentation(mat_a, mat_temp1, exponent / 2);
	if (exponent % 2 == 0)
	{
		matrix_multiplication(mat_temp1, mat_temp1, mat_res);
	}
	else
	{
		// 원래 여기서 matrix_exponentation(mat_a, mat_temp2, exponent - exponent / 2);를 호출함
		// 상당히 비효율적이었음...
		matrix_multiplication(mat_temp1, mat_a, mat_temp2);
		matrix_multiplication(mat_temp1, mat_temp2, mat_res);
	}
}

int	main(void)
{
	int	matrix_res[5][5];

	// 입력받기
	scanf("%d %lld", &n, &b);
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < n ; j++)
			scanf("%d", &matrix[i][j]);
	
	// 계산하기
	matrix_exponentation(matrix, matrix_res, b);
	// 출력하기
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
			printf("%d ", matrix_res[i][j]);
		printf("\n");
	}
}