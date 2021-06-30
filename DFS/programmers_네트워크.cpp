#include <string>
#include <vector>
using namespace std;

int answer;
vector<vector<int>>* p_coms;
int* p_n;
vector<int> v_chk;

void solve(int seq) {
        v_chk[seq] = 1;
        for (int i = 0; i < *p_n; ++i) {
            if (p_coms->at(seq).at(i) == 1 && v_chk[i] == 0) {
                solve(i);
            }
        }
}

int solution(int n, vector<vector<int>> computers) {
    answer = 0;
    p_coms = &computers;
    p_n = &n;
    v_chk.assign(n, 0);
    
    for (int i = 0; i < n; i++) {
        if(v_chk[i] == 0){
            solve(i);
            answer++;
        }
    }
    
    return answer;
}