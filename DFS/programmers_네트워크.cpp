#include <string>
#include <vector>
using namespace std;

int answer;
int gn;
vector<int> v_chk;

void solve(int seq, vector<vector<int>> &coms) {
        v_chk[seq] = 1;
        for (int i = 0; i < gn; ++i) {
            if (coms[seq][i] == 1 && v_chk[i] == 0) {
                solve(i, coms);
            }
        }
}

int solution(int n, vector<vector<int>> computers) {
    answer = 0;
    gn = n;
    v_chk.assign(n, 0);
    
    for (int i = 0; i < n; i++) {
        if(v_chk[i] == 0){
            solve(i, computers);
            answer++;
        }
    }
    
    return answer;
}