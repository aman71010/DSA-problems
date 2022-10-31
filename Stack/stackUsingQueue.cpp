#include<bits/stdc++.h>
using namespace std;


// ------------------------- using two queues ------------------------------
class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    void push(int x) { // O(n) operation
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {  // O(1) operation
        int ret = q1.front();
        q1.pop();
        return ret;
    }
    
    int top() {  // O(1) operation
        return q1.front();
    }
    
    bool empty() {  // O(1) operation
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


// ---------------------------------- using one queue -----------------------------------------------
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {  // O(n) operation  
        int currSize = q.size();
        q.push(x);
        while(currSize--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {  // O(1) operation
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    int top() {  // O(1) operation
        return q.front();
    }
    
    bool empty() {  // O(1) operation
        return q.empty();
    }
};