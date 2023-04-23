/**
 * TSP(Traveling Salesman Problem)
 * - 특징
 * 	  1) 도시 방문 여부를 확인하기 위한 bool visted[] 배열 사용
 * - 시간 복잡도
 * 	  2) n!
*/
#include <vector>
#include <algorithm>
#define MAX 10
#define INF 9999

using namespace std;

int		n;
double	dist[MAX][MAX];

double	shortestPath(
		vector<int> &path, vector<bool> &visited, double currentLength)
{
// 기저 사례
	if (path.size() == n) 
		return (currentLength + dist[path[0]][path.back()]);
// 본론
	double	res = INF;
	for (int next = 0; next < n; next++) {
		if (visited[next]) continue ;
		int	cur = path.back();
		visited[next] = true;
		double length = shortestPath(path, visited, currentLength + dist[cur][next]);
		res = min(res, length);
		visited[next] = false;
	}
}
