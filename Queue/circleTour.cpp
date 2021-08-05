#include<bits\stdc++.h>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class Solution 
{
    public:
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int start = 0, end = 1;
       int curr_petrol = (p[start].petrol - p[start].distance);
       while(start!=end || curr_petrol<0){
           while(curr_petrol<0 && start!=end){
               curr_petrol -= (p[start].petrol - p[start].distance);
               start = (start+1)%n;
               if(start==0) return -1;
           }
           curr_petrol += (p[end].petrol - p[end].distance);
           end = (end+1)%n;
       }
       return start;
    }
};

int main(){
    return 0;
}