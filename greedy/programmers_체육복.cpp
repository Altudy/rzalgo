#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    for(int i = 0; i < reserve.size(); i++){
        for(int j = 0; j < lost.size(); j++){
            if(reserve[i] == lost[j]){
                reserve[i] = -1;
                lost[j] = -1;
                answer++;
                break;
            }
        }
    }

    for(int i = 0; i < reserve.size(); i++){
        for(int j = 0; j < lost.size(); j++){
            if(reserve[i] - 1 == lost[j] || reserve[i] + 1 == lost[j]){
                reserve[i] = -1;
                lost[j] = -1;
                answer++;
                break;
            }
        }
    }


    return answer;
}