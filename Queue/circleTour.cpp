#include<bits\stdc++.h>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};


// T-> O(n^2) and S->O(1)
class Solution{
  public:
    int tour(petrolPump p[],int n){
        for(int i=0; i<n; i++){
            int currP = p[i].petrol;
            if(currP < p[i].distance)
                continue;
            else
                currP -= p[i].distance;
            int j = (i+1)%n;
            while(j != i){
                currP += p[j].petrol;
                if(currP < p[j].distance)
                    break;
                else
                    currP -= p[j].distance;
                j = (j+1)%n;
            }
            if(j == i)
                return i;
        }
        return -1;
    }
};

// T-> O(n) and S->O(1)
class Solution {
    public:
    int tour(petrolPump p[],int n){
        int start = 0, lack = 0;
        int capPet = 0;
        for (int i = 0; i < n; i++) {
            capPet += (p[i].petrol - p[i].distance);
            if (capPet < 0) {
                start = i + 1;
                lack += capPet;
                capPet = 0;
            }
        }
        if(capPet + lack >= 0)
            return start;
        return -1;
    }
};

int main(){
    return 0;
}