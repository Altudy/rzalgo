#include <string>
#include <vector>
using namespace std;
// 스택 활용
string solution(string number, int k) {
    string answer = "";
    vector<char> stack;
    stack.push_back(number[0]);
    int i;
    for(i = 1; i < number.length() && k > 0; i++){
        while(!stack.empty() && stack.back() < number[i]){
            stack.pop_back();
            k--;
            if(k == 0) break;
        }
        stack.push_back(number[i]);
    }
    for(; k > 0; k--)
        stack.pop_back();
    for(; i < number.length(); i++)
        stack.push_back(number[i]);
    
    for(char num : stack)
        answer += num;

    return answer;
}