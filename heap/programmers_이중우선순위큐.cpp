#include <string>
#include <vector>
using namespace std;

vector<int> _heap;
int count = 0;
int min = 0;
void ins(int i){
    

}

void del(int i){
    

}

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for(string operation : operations){
        if(operation[0] == 'I'){
            int i = stoi(operation.substr(2));
        }
        else if(operation[0] == 'D'){
            
        }
    }

    return answer;
}