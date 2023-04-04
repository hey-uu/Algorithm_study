#include <stdio.h>

int	n;
int	count[1000];

int	main(void)
{
	// 입력 받기
	scanf("%d", &n);

	// 초기 조건
	count[0] = 1;
	count[1] = 3;

	// a_i = a_(i - 1) + 2 * a_(i - 2)
	for (int i = 2 ; i < n ; i++)
	{
		count[i] = (count[i - 1] + 2 * count[i - 2]) % 10007;
	}
	printf("%d\n", count[n - 1]);
}