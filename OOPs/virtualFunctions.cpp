#include<bits/stdc++.h>
using namespace std;


class Shape{
    public: 
    int width, length;
    Shape(int w, int l){
        width = w;
        length = l;
    }
    virtual int area(){ // remove virtual keyword (static binding will take place)
        cout << "base area function" << endl;
        return width*length;
    }
};

class Reactangle : public Shape{
    public:
    Reactangle(int w, int l) : Shape(w, l) {}
    int area(){
        cout << "rectangle area function" << endl;
        return width*length;
    }
};

class Triangle : public Shape{
    public:
    Triangle(int w, int l) : Shape(w, l) {}
    int area(){
        cout << "triangle area function" << endl;
        return (width*length)/2;
    }
};

int main(){
    Shape* sh;
    Reactangle rec(5,10);
    sh = &rec;
    cout << sh->area() << endl;
    Triangle tri(5,10);
    sh = &tri;
    cout << sh->area() << endl;
    return 0;
}
