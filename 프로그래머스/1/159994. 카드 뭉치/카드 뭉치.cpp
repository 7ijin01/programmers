#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    queue <string> c1;
    queue <string> c2;
    
    for(int i=0;i<cards1.size();i++)
    {
        c1.push(cards1[i]);
    }
    for(int i=0;i<cards2.size();i++)
    {
        c2.push(cards2[i]);
    }
    
    for(int i=0;i<goal.size();i++)
    {
        string arr=goal[i];
        string string1=c1.front();
        string string2=c2.front();
        
        if(arr==string1)
        {
            c1.pop();
        }
        else if(arr==string2)
        {
            c2.pop();
        }
        else
        {
            answer="No";
            break;
        }
        
    }
    
    
    
    
    return answer;
}