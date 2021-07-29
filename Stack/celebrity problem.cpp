#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //stack based solution T->O(n)  S->O(n)
        stack<int> st;
        for(int i=0; i<n; i++) st.push(i);
        while(st.size()>1){
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();
            if(M[A][B]) st.push(B);
            else st.push(A);
        }
        if(st.empty()) return -1;
        int C = st.top();
        st.pop();
        for(int i=0; i<n; i++){
            if((i!=C) && (M[C][i]||(!M[i][C]))) return -1;
        }
        return C;
    }
    
};

int main(){
    return 0;
}