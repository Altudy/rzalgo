#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer;
vector<int>* nums;
int result, len;
int* t;
void solve(int n){
    
    if(n == len){
        if(result == *t)
            answer++;
        return;
    }
    else{
        result += nums->at(n);
        solve(n+1);
        result -= 2 * nums->at(n);
        solve(n+1);
        result += nums->at(n);
    }
    
    
}


int solution(vector<int> numbers, int target) {
    answer = 0;
    nums = &numbers;
    t = &target;
    len = nums->size();
    
    solve(0);
    
    return answer;
}