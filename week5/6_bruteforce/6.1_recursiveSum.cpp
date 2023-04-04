/**
 * 1부터 n항까지의 합을 계산하는 함수를 구현한다.
 * 
 * 구현 방식 :
 *   - 반복 함수
 *   - 재귀 함수
 * 
*/

int	sum(int n)
{
	int	res = 0;

	for (int i = 1 ; i <= n ; i++)
	{
		res += i;
	}
	return (res);
}

int	recursiveSum(int n)
{
	// 기저 사례
	if (n == 1)
		return 1;
	return (n + recursiveSum(n - 1));
}

#include <iostream>

int	main(void)
{
	std::cout << "called sum(5)         : " << sum(5) << std::endl;
	std::cout << "called recursiveSum(5): " << recursiveSum(5) << std::endl;
}