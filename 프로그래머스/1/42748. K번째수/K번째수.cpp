#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> current;
    for(int i=0;i<commands.size();i++)
    {
        for(int j=commands[i][0]-1;j<=commands[i][1]-1;j++)
        {
            current.push_back(array[j]);
        }
        sort(current.begin(),current.end());
        answer.push_back(current[commands[i][2]-1]);
        current.clear();
    }
    return answer;
}