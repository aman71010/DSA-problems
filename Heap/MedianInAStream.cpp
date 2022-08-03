#include<bits\stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxHeap.size() > minHeap.size()){
            if(x > maxHeap.top())
                minHeap.push(x);
            else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
        } else if(minHeap.size() > maxHeap.size()){
            if(x < minHeap.top())
                maxHeap.push(x);
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            }
        } else {
            if(maxHeap.empty() && minHeap.empty()){
                maxHeap.push(x);
                return;
            }
            if(x > minHeap.top())
                minHeap.push(x);
            else
                maxHeap.push(x);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size()==minHeap.size())
            return (double) (maxHeap.top() + minHeap.top())/2;
        else if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else
            return minHeap.top();
    }
};