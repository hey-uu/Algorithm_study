/**
 * 원주율외우기
 * 문제 해결전략: DP
 *  - memorize(begin) = 숫자 S[begin .. ]를 외우는 방법 중 난이도의 최소 합
 *  - memorize(begin)=min_{L=3}^{5}{memorize(begin+L)+classify(S_{begin, L})}
 *  - 시간복잡도 O(N)
 */

using namespace std;
#include <string>

const int INF = 987654321;
const int MAX = 10000;
string S;
int cache[MAX + 2];  // 왜 +2?

// S[a .. b]구간의 난이도를 반환한다
int classify(int a, int b) {
  string M = S.substr(a, b - a + 1);
  // 모든 숫자가 같은지 판별
  if (M == string(M.size(), M[0])) return 1;
  // 등차 수열인지 판별
  bool progressive = true;
  for (int i = 0; i < M.size() - 1; ++i)
    if (M[i + 1] - M[i] != M[1] - M[0]) {
      progressive = false;
      break;
    }
  // 숫자가 1씩 단조 증가/감소하는지 판별
  if (progressive && abs(M[1] - M[0]) == 1) return 2;
  // 숫자가 등차 수열을 이루는지 판별
  if (progressive) return 5;
  // 두 개의 숫자가 번갈아가며 나타나는지 판별
  bool alternating = true;
  for (int i = 0; i < M.size(); ++i) {
    if (M[i] != M[i % 2]) {
      alternating = false;
      break;
    }
  }
  if (alternating) return 4;
  // 이 외의 모든 경우
  return 10;
}

int memorize(int begin) {
  // base case
  if (begin == S.size()) return 0;
  // 메모이제이션
  int& ret = cache[begin];
  if (ret != -1) return ret;

  ret = INF;
  for (int L = 3; L <= 5; ++L)
    if (begin + L <= S.size())
      ret = min(ret, classify(begin, begin + L - 1) + memorize(begin + L));
  return ret;
}
