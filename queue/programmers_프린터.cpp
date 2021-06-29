#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
    }

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        
        bool isSmall = false;
        for (int i = 0; i < priorities.size(); i++) {
            if (now.second < priorities[i]) {
                isSmall = true;
                break;
            }
        }
        if (isSmall) {
            q.push(now);
            continue;
        }

        if (now.first == location) {
            answer++;
            break;

        }

        priorities[now.first] = 0;
        answer++;
    }

    return answer;
}

