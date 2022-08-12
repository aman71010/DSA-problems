#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.

    int precedence(char c){
        if(c=='^') return 3;
        if(c=='*' || c=='/') return 2;
        if(c=='+' || c=='-') return 1;
        return -1;
    }

    string infixToPostfix(string s) {
        int n = s.length();
        string res = "";
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i]>='a'&&s[i]<='z' || s[i]>='A'&&s[i]<='Z')
                res += s[i];
            else if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')'){
                while(st.top()!='('){
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && st.top() != '(' && precedence(st.top())>=precedence(s[i])){
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};