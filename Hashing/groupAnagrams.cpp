#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<string_list.size(); i++){
            string str = string_list[i];
            sort(str.begin(), str.end());
            mp[str].push_back(string_list[i]);
        }
        for(auto it=mp.begin(); it!=mp.end(); it++){
            res.push_back((*it).second);
        }
        return res;
    }

    //Another solution
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> res;
        int n = string_list.size();
        map <map<char, int>, vector<string>> myMap;
        for(string str: string_list){
            map<char, int> tempMap;
            vector<string> tempList;
            for(char c: str){
                tempMap[c]++;
            }

            auto it = myMap.find(tempMap);
            if(it!=myMap.end())
                (*it).second.push_back(str);
            else
                myMap.insert({tempMap, {str}});
        }
        for(auto it=myMap.begin(); it!=myMap.end(); it++){
            res.push_back((*it).second);
        }
        return res;
    }

};

int main(){
    return 0;
}