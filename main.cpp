#include <iostream>
#include <math.h>


// ToDo: Migrate to double
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

    void normalize(){
        float l = length();
        x = x / l;
        y = y / l;
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

    bool equals(vector2 v){
        if(x == v.x && y == v.y){
            return true;
        }
        return false;
    }
};



class vector3{
public:
    double x;
    double y;
    double z;

    vector3(){
        x = 0;
        y = 0;
        z = 0;
    }
    vector3(double x_, double y_, double z_){
        x = x_;
        y = y_;
        z = z_;
    }
    vector3(vector3 &v){
        x = v.x;
        y = v.y;
        z = v.z;

    }


    double length(){
        return sqrt(x*x + y*y + z*z);
    }

    void normalize(){
        double l = length();
        x = x/l;
        y = y/l;
        z = z/l;
    }


    void scale(double s){
        x *= s;
        y *= s;
        z *= s;
    }

    void add(vector3 v){
        x += v.x;
        y += v.y;
        z += v.z;
    }
    void sub(vector3 v){
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }


    double distance(vector3 v){
        vector3* v_ = subn(v);
        return v_->length();
    }

    double dot_product(vector3 v){
        return (x*v.x + y*v.y + z*v.z);
    }

    bool equals(vector3 v){
        return x == v.x && y == v.y && z == v.z;
    }
    bool colinear(vector3 v){
        vector3 v1 = *normalizen();
        vector3 v2 = *v.normalizen();
        vector3 v3 = *v2.scalen(-1);

        return v1.equals(v2) || v1.equals(v3);
    }
    bool opposite(vector3 v){
        vector3 v1 = *normalizen();
        vector3 v2 = *v. normalizen();
        v2.scale(-1);

        return v1.equals(v2);
    }

    double angle(vector3 v){
        vector3 v1 = *normalizen();
        vector3 v2 = *v.normalizen();
        double prod = v1.dot_product(v2);

        return acos(prod);
    }




    //add to new
    vector3* addn(vector3 v) {
        return new vector3(x + v.x, y + v.y, z + v.z);
    }
    //sub to new
    vector3* subn(vector3 v) {
        return new vector3(x - v.x, y - v.y, z - v.z);
    }
    //scale to new
    vector3* scalen(double s){
        return new vector3(x*s, y*s, z*s);
    }
    //normalize to new
    vector3* normalizen(){
        vector3* v = new vector3(*this);
        v->normalize();
        return v;
    }


    vector3* cross_product(vector3 v){
        double x_ = y*v.z - z*v.y;
        double y_ = z*v.x - x*v.z;
        double z_ = x*v.y - y*v.x;

        return new vector3(x_, y_, z_);
    }



};








int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
