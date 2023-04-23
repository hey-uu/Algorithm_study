/**
 * 합친 LIS(JLIS, Joined Longest Increasing Subsequence)
 * 문제 해결전략 : DP (lis3의 응용)
 * - lis3 :  lis3(start) = S[start]에서 시작하는 최대 증가 부분 수열의 길이
 * - jlis : jlis(indexA, indexB) = A[indexA]와 B[indexB]에서 시작하는 합친 증가
 * 부분 수열의 최대 길이
 * - 다음 숫자 선택하기 :A[indexA + 1] 이후 혹은 B[indexB + 1] 이후의 수열 중
 * 						max(A[indexA], B[indexB]) 보다
 *큰 수 중 하나
 *- A[-1] = B[-1] = -infinity로 생각하고 JLIS에 포함한다고 생각함
 *   => JLIS를 호출한 함수에서 나중에 2를 빼줘야함
 */

#include <algorithm>
#include <limits>

using namespace std;

// 문제 조건 : 입력=32비트 부호있는 정수 => 인위적 최소치(-infinity)는 64비트
const long long NEGINF = numeric_limits<long long>::min();
const int MAX_LEN = 100;
int n, m, A[MAX_LEN], B[MAX_LEN];
int cache[MAX_LEN + 1][MAX_LEN + 1];  // index로 -1이 들어올 수 있기 때문에 +1

int jlis(int indexA, int indexB) {
  // 메모이제이션
  int &ret = cache[indexA + 1][indexB + 1];
  if (ret != -1) return ret;
  // A[indexA], B[indexB]가 이미 존재하므로 길이는 2이상
  // indexA==indexB==-1인 경우에도 2개 존재한다고 생각하므로 나중에 2만큼
  // 빼줘야할듯
  ret = 2;
  long long a = (indexA == -1 ? NEGINF : A[indexA]);
  long long b = (indexB == -1 ? NEGINF : B[indexB]);
  long long maxElement = max(a, b);
  // 다음 숫자 선택하기
  for (int nextA = indexA + 1; nextA < n; ++nextA)
    if (maxElement < A[nextA]) ret = max(ret, 1 + jlis(nextA, indexB));
  for (int nextB = indexB + 1; nextB < n; ++nextB)
    if (maxElement < B[nextB]) ret = max(ret, 1 + jlis(indexA, nextB));
  return ret;
}