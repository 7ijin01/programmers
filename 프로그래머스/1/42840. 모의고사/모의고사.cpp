#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> first={1,2,3,4,5};
vector<int> second={2, 1, 2, 3, 2, 4, 2, 5};
vector<int> third={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> m(3);
    for(int i=0;i<answers.size();i++)
    {
        if(answers[i]==first[i%first.size()])
            m[0]++;
            if(answers[i]==second[i%second.size()])
            m[1]++;
        if(answers[i]==third[i%third.size()])
            m[2]++;
    }
    int max=*max_element(m.begin(),m.end());
    for(int i=0;i<3;i++)
    {
        if(m[i]==max)
        {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}