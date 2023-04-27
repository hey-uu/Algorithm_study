/**
 * 문자열 합치기(STRJOIN)
 * - 항상 가장 짧은 두 문자열을 먼저 합치자
 * - 관련 참고 내용 : 호프만 코드
 *      -> 각 글자의 출연 확률 * 코드 길이의 합 최소화하기
*/

#include <vector>
#include <queue>
using namespace std;

int concat(const vector<int> &lengths)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < lengths.size(); ++i)
        pq.push(lengths[i]);
    int ret = 0;
    while (pq.size() > 1)
    {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        pq.push(min1 + min2);
        ret += min1 + min2;
    }
    return ret;
}