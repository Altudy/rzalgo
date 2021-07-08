#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct q_cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a.back() > b.back();
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<int>> map(n, vector<int>(n,0));
    vector<int> visited(n, 0);
    int cnt = 0;
    priority_queue<vector<int>, vector<vector<int>>, q_cmp> pq;
    for(vector<int> cost : costs){
        map[cost[0]][cost[1]] = cost[2];
        map[cost[1]][cost[0]] = cost[2];
    }
    int next = 0;
    for(int i = 0; i < n; i++){
        if(map[next][i] != 0)
            pq.push(vector<int> {i, map[next][i]});
    }
    while(!pq.empty()){
        visited[next]++;
        vector<int> now = pq.top();
        pq.pop();
        next = now[0];
        if(visited[now[0]] > 0) continue;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            if(map[next][i] != 0)
                pq.push(vector<int> {i, map[next][i]});
        }
        answer += now[1];
        cout << now[1] << " ";
    }


    
    
    
    return answer;
}