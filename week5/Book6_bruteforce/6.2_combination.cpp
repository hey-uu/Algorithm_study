/**
 * STL vector 사용하기 : https://modoocode.com/223
 * 
*/

#include <vector>
#include <iostream>

void	showAllCombis(int n, std::vector<int> &picked, int toPick)
{
	if (toPick == 0)
	{
		for (auto itr = picked.begin() ; itr != picked.end() ; ++itr)
			std::cout << *itr << " ";
		std::cout << std::endl;
		return ;
	}
	int	smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest ; next < n ; ++next)
	{
		picked.push_back(next);
		showAllCombis(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int	main(void)
{
	std::vector<int>	pick;

	showAllCombis(4, pick, 3);
}