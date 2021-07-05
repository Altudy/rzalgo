#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int numOfNotA = 0;
    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] != 'A'){
            numOfNotA++;
        }
        if(name[i] < 'N'){
            answer += name[i] - 'A';
            cout << name[i] - 'A' << " ";
        }
        else{
            answer += 'Z' - name[i] + 1;
            cout << 'Z' - name[i] + 1 << " ";
        }
    }
    cout << endl;
    int ind = 0;
    while(numOfNotA > 0){
        if(name[ind] != 'A'){
            name[ind] = 'A';
            numOfNotA--;
        }
        int rightDis = 0;
        int rightInd;
        for(int i = ind + 1; i < name.length(); i++){
            if(name[i] != 'A'){
                rightDis = i - ind;
                rightInd = i;
                break;
            }
        }
        int leftDis = 0;
        int leftInd;
        for(int i = ind - 1; i >= 0; i--){
            if(name[i] != 'A'){
                leftDis = ind - i;
                leftInd = i;
                break;
            }
        }
        if(leftDis == 0){
            for(int i = name.length() - 1; i > ind; i--){
                if(name[i] != 'A'){
                    leftDis = ind + name.length() - i;
                    leftInd = i;
                    break;
                }
            }
        }
        if(leftDis < rightDis || rightDis == 0){
            ind = leftInd;
            answer += leftDis;
            cout << ind << " " << leftDis << endl;
        }
        else{
            ind = rightInd;
            answer += rightDis;
            cout << ind << " " << rightDis << endl;
        }
        

    }



    return answer;
}