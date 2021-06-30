#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    multiset<int> heap;
    for(string operation : operations){
        if(operation[0] == 'I'){
            int i = stoi(operation.substr(2));
            heap.insert(i);
        }
        else if(operation[0] == 'D'){
            if(heap.empty())
                continue;

            if(operation[2] == '-'){
                heap.erase(heap.begin());
            }
            else{
                heap.erase(--heap.end());
            }
        }
    }

    if(!heap.empty()){
        answer[0] = *(--heap.end());
        answer[1] = *heap.begin();
    }

    return answer;
}