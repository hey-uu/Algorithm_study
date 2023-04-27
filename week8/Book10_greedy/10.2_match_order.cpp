/**
 * 회의실 예약(Conference Room Reservation)
 * - 동적 계획법 => O(n * 2^n)
 * - 그리디 알고리즘
 *    - 상대방 선수를 이길 수 있는 한국 선수가 있으면 그 중 가장 레이팅 낮은 선수로
 *    - 상대방 선수를 이길 수 있는 한국 선수가 없으면 전체에서 가장 레이팅 낮은 선수로
 * - multiset : https://www.geeksforgeeks.org/multiset-lower_bound-in-cpp-stl-with-examples/
 */


#include <vector>
#include <set>
using namespace std;

int order(const vector<int> &russian, const vector<int> &korean)
{
    int n = russian.size();
    int wins = 0;

    multiset<int> ratings(korean.begin(), korean.end());
    for (int rus = 0; rus < n; ++rus)
    {
        if (*ratings.rbegin() < russian[rus])
            ratings.erase(ratings.begin());
        else {
            ratings.erase(ratings.lower_bound(russian[rus]));
            ++wins;
        }
    }
    return wins;
}