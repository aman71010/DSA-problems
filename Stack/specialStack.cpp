#include<bits\stdc++.h>
using namespace std;

class Solution{
    int minEle;
    stack<int> s;
    stack<int> s2;
    public:
    
        int getMin(){
            if(s2.empty())
                return -1;
           return s2.top();
        }
       
        int pop(){
            if(s.empty())
                return -1;
            int t = s.top();
            s.pop();
            if(s2.top() == t)
                s2.pop();
            return t;
        }
       
        void push(int a){
            if(s.empty()){
                s.push(a);
                s2.push(a);
            } else{
                s.push(a);
                if(a <= s2.top())
                    s2.push(a);
            }
        }
};


//All operations have a time complexity of O(1) and Aux Space complexity of O(1)
int d = 99999;

void push(stack<int>& s, int a){
    if(s.empty())
        s.push(a*d+a);
    else{
        int prevMin = getMin(s);
        int currMin = min(prevMin, a);
        s.push(a*d+currMin);
    }
}

bool isFull(stack<int>& s,int n){
	return s.size() == n;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
	int t = s.top()/d;
    s.pop();
    return t;
}

int getMin(stack<int>& s){
	return s.top()%d;
}