#include <iostream>
#include <math.h>


class vector2 {
public:
    float x;
    float y;

    vector2(float x_,float y_){
        x = x_;
        y = y_;
    }


    float length(){
        return sqrt(x*x + y*y);
    }


    void scale(float s){
        x = s*x;
        y = s*y;
    }


    void add(vector2 v){
        x = x + v.x;
        y = y + v.y;
    }

    void sub(vector2 v){
        x = x - v.x;
        y = y - v.y;
    }

    float distance(vector2 v){
        return sqrt((x - v.x)*(x - v.x) + (y - v.y)*(y - v.y));
    }

    float dot_product(vector2 v){
        return (x*v.x) + (y*v.y);
    }

};








int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
