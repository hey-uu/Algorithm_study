/**
 * KARATSUBA
 * - 아이디어
 * 		- a = a1 * 10^(n/2) + a0;
 * 		- b = b1 * 10^(n/2) + b0;
 * 		- a * b = (a1 * b1) * 10^(n) + (a0 * b1 + a1 * b0) * 10^(n/2) + a0 * b0;
 * 		- a0 * b1 + a1 * b0 = (a0 + a1)(b0 + b1) - a0 * b0 - a1 * b1
 * 		- 따라서 총 3 개의 곱셈만 구하면 됨 : (a0+a1)(b0+b1), a0*b0, a1*b1
 * - 시간 복잡도
 * 		- 기저 사례 처리(곱셈) -> O(n^(log3))
 * 		- 병합 -> O(n^(log3))
*/

#include <iostream>
#include <vector>

using namespace std;

void	normalize(vector<int> &num)
{
	num.push_back(0);
	for (int i = 0; i + 1 < num.size(); i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}

vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0 ; i < a.size() ; i++) {
		for (int j = 0 ; j < b.size() ; j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	normalize(c);
	return (c);
}

// a += b * (10^k)
void	addTo(vector<int> &a, const vector<int> &b, int k)
{
	int an = a.size(), bn = b.size(), newn = bn + k;
	for (int i = an; i < newn; i++) a.push_back(0);
	for (int i = 0; i < bn; i++)
	{
		a[i + k] += b[i];
	}
	normalize(a);
}

// a -= b(a >= b);
void	subFrom(vector<int> &a, const vector<int> &b)
{
	int bn = b.size();
	for (int i = 0; i < bn; i++)
	{
		a[i] -= b[i];
	}
	normalize(a);
}

// a가 b보다 길거나 같다
vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
	int	an = a.size(), bn = b.size();

	if (an < bn) return (karatsuba(b, a));
	if (an == 0 || bn == 0) return (vector<int>());
	// if (an <= 50) return (multiply(a, b));
	if (an == 1) return (multiply(a, b));

	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	
	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	
	vector<int> res;
	addTo(res, z0, 0);
	addTo(res, z1, half);
	addTo(res, z2, half + half);
	return (res);
}


int	main(void)
{
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> b = {8, 7, 6, 5, 4, 3, 2, 1};
	vector<int> c = karatsuba(a, b);
	for (auto itr = c.rbegin(); itr != c.rend() ; itr++)
	{
		std::cout << *itr;
	}

	std::cout << std::endl;
	a = {1, 1};
	b = {1, 1};
	c = karatsuba(a, b);
	for (auto itr = c.rbegin(); itr != c.rend() ; itr++)
	{
		std::cout << *itr;
	}

}