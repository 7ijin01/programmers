#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map <string,int> map;
    for(int i=0;i<want.size();i++)
    {
        map[want[i]]=number[i];
    }
    for(int i=0;i<discount.size()-9;i++)
    {
        unordered_map<string,int> map2;
        for(int j=i;j<i+10;j++)
        {
            map2[discount[j]]+=1;    
        }
        if(map==map2)
        {
            answer+=1;
        }
        
        
    }
    return answer;
}