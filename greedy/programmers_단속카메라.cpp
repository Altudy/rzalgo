#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.front() < b.front();
}
// 끝점 기준으로 정렬하면 지금보다 조건문을 더 줄일 수 있다.
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    int start = routes[0][0];
    int end = routes[0][1];
    for(int i = 1; i < routes.size(); i++){
        if(end < routes[i][0]){
            answer++;
            start = routes[i][0];
            end = routes[i][1];
        }
        if(end >= routes[i][0]){
            start = routes[i][0];
        }
        if(end > routes[i][1]){
            end = routes[i][1];
        }
    }

    return ++answer;
}