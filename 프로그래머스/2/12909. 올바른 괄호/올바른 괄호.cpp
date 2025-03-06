#include<string>
#include <iostream>
#include<stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<int> stack;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            stack.push(1);
        }
        else if(s[i]==')')
        {
            if(stack.empty())
            {
                answer=false;
                break;
            }
                
            stack.pop();
        }
    }
    if(!stack.empty())
    {
        answer=false;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}