#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int sco : scoville) {
        pq.push(sco);
    }

    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int result = first + second * 2;
        pq.push(result);
        answer++;
    }

    if (pq.top() < K)
        return -1;

    return answer;
}