#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    map<string, int> m;
    
    for(const auto& x : clothes){
        ++m[x[1]];
    }
    for(auto x = m.begin(); x != m.end(); x++){
        answer *= x->second + 1;
    }
    answer--;
    
    return answer;
}