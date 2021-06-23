#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int now = 0, day = 0;

    while (now < progresses.size()) {

        int count = 0;

        for (; progresses[now] + speeds[now] * day < 100; day++) {

        }

        for (; now < progresses.size() && progresses[now] + speeds[now] * day >= 100; now++) {
            count++;
        }

        answer.push_back(count);

    }

    return answer;
}