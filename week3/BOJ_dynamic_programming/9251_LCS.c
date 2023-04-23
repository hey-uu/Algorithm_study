#include <stdio.h>
#include <string.h>

char	s1[1001];
char	s2[1001];
int		count[1001][1001];

int	main(void)
{
	int	s1_len, s2_len;
	int	i, j;

	// 입력 받기
	scanf("%s\n%s", s1, s2);
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	
	// 초기 조건
	j = 0;
	while (j < s1_len && s2[0] != s1[j])
		j++;
	while (j < s1_len)
	{
		count[0][j] = 1;
		j++;
	}
	i = 0;
	while (i < s2_len && s1[0] != s2[i])
		i++;
	while (i < s2_len)
	{
		count[i][0] = 1;
		i++;
	}

	// (i, j) = max((i - 1, j - 1) + (s1[j] == s2[i]), (i - 1, j), (i , j - 1))
	for (j = 1 ; j < s1_len ; j++)
	{
		for (i = 1 ; i < s2_len ; i++)
		{
			count[i][j] = count[i - 1][j - 1] + (s1[j] == s2[i]);
			if (count[i][j] < count[i - 1][j])
				count[i][j] = count[i - 1][j];
			if (count[i][j] < count[i][j - 1])
				count[i][j] = count[i][j - 1];
			// printf("(%d, %d) = %d\n", i, j, count[i][j]);
		}
	}

	// 출력
	printf("%d\n", count[s2_len - 1][s1_len - 1]);
}