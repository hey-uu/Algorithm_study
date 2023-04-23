/**
 * FASTSUM
 * 
 * - 총 호출 횟수 = N의 이진수 자릿수 + N의 이진수 1의 갯수 - 1
 * - 시간 복잡도 O(logN);
*/

int	fastSum(int n)
{
	if (n == 1) return (1);
	// n이 홀수인 경우 반을 나누는 것보다 아래의 경우가 빠름
	// 중복되는 값이 계산될 수 있기 때문
	// - 절반으로 나누는 경우 : 
	// 9 -> 4 -> 2 -> 1
	//   -> 5 -> 3 -> 2
	//             -> 1
	//        -> 2 -> 1
	// - 하나와 나머지로 나누는 경우 :
	// 9 -> 8 -> 4 -> 2 -> 1
	if (n & 1) return (fastSum(n - 1) + n);
	int half = n / 2;
	return (2 * fastSum(half) + half * half);
}