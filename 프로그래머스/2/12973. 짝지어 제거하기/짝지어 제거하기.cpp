#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> stack;
    for(int i=0;i<s.length();i++)
    {
        char top;
        if(!stack.empty())
        {
            top=stack.top();    
            if(s[i]==top)
            {
                stack.pop();
                continue;
            }
        }
        stack.push(s[i]);
        
        
        
        
        
    }
    if(stack.empty())
        {
            answer=1;
        }

    return answer;
}