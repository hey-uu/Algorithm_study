/**
 * MATRIX MULTIPLY
 * - 시간복잡도가 N^3에 달하는 비용이 큰 알고리즘
*/
#include <iostream>
#include <vector>

using namespace std;

class SquareMatrix
{
private:
	int					n;
	vector<vector<int>> arr;
public:
	SquareMatrix(const int size, vector<vector<int>> &arr) {
		this->n = size;
		this->arr = arr;
	}

	int	size(void) const {
		return (n);
	}

	vector<vector<int>> getArr(void) const{
		return (arr);
	}

	SquareMatrix operator*(const SquareMatrix &A) const{
		const vector<vector<int>> &a=arr, &b=A.getArr();
		vector<vector<int>>	c(n, vector<int>(n, 0));

		for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
            	for(int k = 0; k < n; k++)
                	c[i][j] += a[i][k] * b[k][j];
		return (SquareMatrix(n, c));
	}

	void	show(void) const
	{
		for(int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
    	}
	}
};

SquareMatrix	identity(const int size)
{
	vector<vector<int>> arr(size, vector<int>(size, 0));

	for (int i = 0; i < size; i++)
		arr[i][i] = 1;
	return (SquareMatrix(size, arr));
}

SquareMatrix pow(const SquareMatrix &A, int m)
{
	if (m == 0) return (identity(A.size()));
	if (m & 1) return (pow(A, m - 1) * A);
	SquareMatrix half = pow(A, m / 2);
	return (half * half);
}

int main()
{
	int n, m;
    cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
    }
	SquareMatrix A(n, arr);
    SquareMatrix B = pow(A, m);
	B.show();
}