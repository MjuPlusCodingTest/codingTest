#include <vector>
#include <iostream>
//push_back(@) 추가
//pop_back(a) 마지막 삭제
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answerVec;

    for (int i = 0; i < arr.size(); i++){
        if (i == 0){
            answerVec.push_back(arr[i]);
        }
        if (i > 0){
            if (arr[i] == arr[i-1]){
                continue;
            }else{
                answerVec.push_back(arr[i]);
            }
        }
    }

    vector<int> answer = answerVec;

    return answer;
}