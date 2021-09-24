#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer;
int result, len;
int t;

void solve(int n, vector<int> &nums){
    
    if(n == len){
        if(result == t)
            answer++;
        return ;
    }
    else{
        result += nums[n];
        solve(n+1, nums);
        result -= 2 * nums[n];
        solve(n+1, nums);
        result += nums[n];
    } 
}


int solution(vector<int> numbers, int target) {
    answer = 0;
    t = target;
    len = numbers.size();
    
    solve(0, numbers);
    
    return answer;
}