#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>>* p_tickets;
vector<string> answer;
vector<int> v_chk;
bool fin = false;

bool cmp(vector<string> fir, vector<string> sec){
    if(fir[1] == sec[1])
        return fir[0] < sec[0];
    return fir[1] < sec[1];
}

void solve(int n){
    
    if(p_tickets->size() + 1 == answer.size()){
        fin = true;
        return;
    }
    else{
        for(int i = 0; i < p_tickets->size() && !fin; ++i){
            if(v_chk[i] == 0 && answer[n] == p_tickets->at(i).at(0)){
                answer.push_back(p_tickets->at(i).at(1));
                v_chk[i] = 1;
                solve(n+1);
                if(!fin){
                    answer.pop_back();
                    v_chk[i] = 0;
                }
            }
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    p_tickets = &tickets;
    sort(tickets.begin(), tickets.end(), cmp);
    v_chk.assign(30000, 0);
    
    answer.push_back("ICN");
    
    solve(0);

    
    return answer;
}