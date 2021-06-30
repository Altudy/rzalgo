#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    
    unordered_map<string, int> m;
    
    for(const auto& p : phone_book){
        ++m[p];
    }
    for(int i = 0; i < phone_book.size(); ++i){
        string n = "";
        for(int j = 0; j < phone_book[i].size(); ++j){
            n += phone_book[i][j];
            if(m[n] && n != phone_book[i])
                return false;
        }
    }
    
    return true;
}