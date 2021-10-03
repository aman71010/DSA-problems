#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    priority_queue<int, vector<int>> MaxHeap;
    priority_queue<int, vector<int>, greater<int>> MinHeap;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(MinHeap.size()<MaxHeap.size())
            MinHeap.push(x);
        else
            MaxHeap.push(x);
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(MaxHeap.size()==MinHeap.size())
            return (double) (MaxHeap.top() + MinHeap.top())/2;
        else
            return MaxHeap.top();
    }
};