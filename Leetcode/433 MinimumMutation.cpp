#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getDifference(string &s1, string &s2){
        int count = 0;
        for(int i=0; i<8; i++){
            if(s1[i]!=s2[i])
                count++;
        }
        return count;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        unordered_set<string> st;
        queue<string> q;
        q.push(startGene);
        st.insert(startGene);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr == endGene)
                    return ans;
                for(string gene: bank){
                    if(st.find(gene) == st.end() && getDifference(gene, curr) == 1){
                        q.push(gene);
                        st.insert(gene);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};