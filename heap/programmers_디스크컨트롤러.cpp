#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool job_cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}
struct q_cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, q_cmp> pq;

    sort(jobs.begin(), jobs.end(), job_cmp);

    vector<int> times;
    int count_time = 0;
    int next_job = 0;
    while (next_job < jobs.size()) {
        for (; next_job < jobs.size() && jobs[next_job][0] <= count_time; next_job++) {
            pq.push(make_pair(jobs[next_job][0], jobs[next_job][1]));
        }
        if (pq.empty() && next_job < jobs.size()) {
            count_time = jobs[next_job][0];
            continue;
        }
        while (!pq.empty()) {
            pair<int, int> now_job = pq.top();
            pq.pop();

            count_time += now_job.second;
            times.push_back(count_time - now_job.first);
        }

    }
    int sum(0);
    for (int time : times) {
        sum += time;
    }
    answer = sum / times.size();
    return answer;
}