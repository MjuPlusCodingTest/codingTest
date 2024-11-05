#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++){
        int count = 0;
        for (int k = i + 1; k < prices.size(); k++){
            count++;
            if(prices[i] > prices[k]) break;
            //prices[i] <= prices[k] ? count++ : count = count;
        }
        answer.push_back(count);
    }


    return answer;
}