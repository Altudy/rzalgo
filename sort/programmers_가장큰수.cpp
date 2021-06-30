#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b){

    if(a+b > b+a)
        return true;
    else
        return false;

}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strN;
    
    for(const auto& n : numbers){
        strN.push_back(to_string(n));
    }
    sort(strN.begin(), strN.end(), cmp);
    
    for(const auto& s : strN){
        answer += s;
    }
    if(answer[0] == '0')
        answer = "0";
    return answer;
}