/**
 * 양자화(Quantization)
 * - 더 넓은 범위를 갖는 값들을 작은 범위를 갖는 값들로 근사해 표현함으로써
 *   자료를 손실 압출하는 과정을 의미함
 * - 오차 제곱의 합을 최소화하는 양자화 결과?
 * 문제 해결전략:
 *  - quantize(A) = A에 속한 수를 양자화해서 얻을 수 있는 최소 오차 제곱의 합
 *    => 최적 부분 구조 문제가 아니라 위와 같은 정의로는 문제를 해결할 수 없음
 *      - 최적 부분 구조 = 각 부분 문제의 최적해만 있으면 전체 문제의 최적해를
 *                       쉽게 알 수 있는 경우
 *  - quantize(A, U) = 지금까지 한 번 이상 사용한 숫자들의 집합인 U에 대해 A에
 *                     속한 수를 양자화해서 얻을 수 있는 최소 오차 제곱의 합
 *    => 경우의 수가 너무 많음. 불가능
 *  - 답의 형태 제안하기
 *      - 수열을 정렬하면, 같은 숫자로 양자화되는 숫자들은 항상 인접하다
 *      - 수 정렬 후, 인접 숫자 묶음으로 분할 후, 각 묶음은 하나의 숫자로 표현
 *      - 이 경우, 최적 부분 구조가 성립함!
 * - quantize(from, parts) = min_{size=1}^{n-from}[minError(from, from+size-1) +
 *                                                 quantize(from+size, parts-1)]
 *      - from번째 이후의 숫자들을 parts개의 묶음으로 묶을 경우
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int INF = 987654321;
const int MAX = 101;
int cache[MAX][11];
int A[MAX], pSum[MAX], pSqSum[MAX];
int n, s;

void precalc() {
  sort(A, A + n);
  pSum[0] = A[0];
  pSqSum[0] = A[0] * A[0];
  for (int i = 1; i < n; i++) {
    pSum[i] = pSum[i - 1] + A[i];
    pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
  }
}

// A[lo..hi] 구간을 하나의 숫자로 표현시 최소 오차 합
int minError(int lo, int hi) {
  // 구간의 합
  int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
  int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
  int m = int(0.5 + (double)sum / (hi - lo + 1));  // 반올림->+0.5
  // 구간의 오차
  int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
  return ret;
}

int quantize(int from, int parts) {
  // base case
  if (from == n) return 0;
  if (parts == 0) return INF;
  // 메모이제이션
  int &ret = cache[from][parts];
  if (ret != -1) return ret;
  ret = INF;
  // 최솟값 찾기
  for (int partSize = 1; from + partSize <= n; ++partSize)
    ret = min(ret, minError(from, from + partSize - 1) +
                       quantize(from + partSize, parts - 1));

  return ret;
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    memset(cache, -1, sizeof(cache));
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> A[i];
    precalc();
    cout << quantize(0, s) << '\n';
  }

  return 0;
}