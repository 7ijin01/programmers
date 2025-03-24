#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    unordered_set <string> set;
    set.insert(words[0]);
    
    for(int i=1;i<words.size();i++)
    {
        if(!set.insert(words[i]).second || words[i].front() != words[i-1].back())
        {
            answer[0]=i% n+ 1;
            answer[1]=i/n+1;
            return answer;
        }
    }
    

    return answer;
}