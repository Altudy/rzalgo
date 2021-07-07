#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 맞긴 했는데 문제를 잘못 봄
// 보트에 최대 2명만 탈 수 있는데 인원에 제한이 없는 상태로 풀이함.
// 제일 큰 값과 제일 작은 값으로 쌍을 채우기만 하면 됨 (17line에 break만 추가함)
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int taked = 0;
    for(int i = 0; i < people.size() - taked; i++){
        int tracked = people[i];
        
        for(int j = people.size() - taked - 1; j > i; j--){
            int available = limit - tracked;
            if(available < people[j]) break;
            tracked += people[j];
            taked++;
            break;
        }
        answer++;
    }

    return answer;
}