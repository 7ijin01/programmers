#include <string>
#include <vector>
#include<stack>
using namespace std;

int solution(string s) 
{
    int answer = 0;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        stack<char> st;
        int status=1;
        for(int j=0;j<len;j++)
        {
            
            char ch=s[(i+j)%len];
            if(ch=='{'||ch=='['||ch=='(')
            {
                st.push(ch);
                continue;
            }
            if(!st.empty() && ch=='}')
            {
                if(st.top()=='{')
                {
                    st.pop();
                }
                
                continue;
            }
            else if(!st.empty() && ch==']')
            {
                if(st.top()=='[')
                {
                    st.pop();
                }
                
                continue;
            }
            else if(!st.empty() && ch==')')
            {
                if(st.top()=='(')
                {
                    st.pop();
                }
                
                continue;
            }
            else if(st.empty())
            {
                status=0;
            }
            
            
        }
        if(st.empty() && status==1)
        {
            answer+=1;
        }
    }
    
    
    return answer;
}