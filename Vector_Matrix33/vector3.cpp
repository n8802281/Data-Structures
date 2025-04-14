#include "0613348_vector3.h"
#include <math.h>
#include <iostream>
vector3::vector3(){
    
}
vector3::vector3(float inX, float inY, float inZ){
    set(inX, inY, inZ);
}
vector3::vector3(const vector3 &v){
    set(v.x, v.y, v.z);
}
float& vector3::operator[](unsigned int index){
    if(index==0) return x;
    if(index==1) return y;
    if(index==2) return z;
    else return x;
}

const float& vector3::operator[](unsigned int index)const{
    if(index==0) return x;
    if(index==1) return y;
    if(index==2) return z;
    else return x;
}
vector3& vector3::operator= (const vector3 &v){
    x=v.x;
    y=v.y;
    z=v.z;
    return *this;
}
vector3& vector3::operator+=(const vector3 &v){
    x=x+v.x;
    y=y+v.y;
    z=z+v.z;
    return *this;
}
vector3& vector3::operator-=(const vector3 &v){
    x=x-v.x;
    y=y-v.y;
    z=z-v.z;
    return *this;
}
vector3& vector3::operator *= (float f){
    x=x*f;
    y=y*f;
    z=z*f;
    return *this;
}
vector3& vector3::operator /= (float f){
    x=x/f;
    y=y/f;
    z=z/f;
    return *this;
}
bool operator == (const vector3 &a, const vector3 &b){
    return (a.x==b.x) && (a.y==b.y) && (a.z==b.z);
}
bool operator != (const vector3 &a, const vector3 &b){
    return !((a.x==b.x) && (a.y==b.y) && (a.z==b.z));
}
vector3 operator - (const vector3 &a){
    vector3 tmp(-a.x,-a.y,-a.z);
    return tmp;
}
vector3 operator + (const vector3 &a, const vector3 &b){
    vector3 tmp(a.x+b.x,a.y+b.y,a.z+b.z);
    return tmp;
}
vector3 operator - (const vector3 &a, const vector3 &b){
    vector3 tmp(a.x-b.x,a.y-b.y,a.z-b.z);
    return tmp;
}
vector3 operator * (const vector3 &v, float f){
    vector3 tmp(v.x*f,v.y*f,v.z*f);
    return tmp;
}
vector3 operator * (float f, const vector3 &v){
    vector3 tmp(v.x*f,v.y*f,v.z*f);
    return tmp;
}
vector3 operator / (const vector3 &v, float f){
    vector3 tmp(v.x/f,v.y/f,v.z/f);
    return tmp;
}
void vector3::set(float xIn, float yIn, float zIn){
    x=xIn;
    y=yIn;
    z=zIn;
}
float vector3::length()const{
    float output=x*x+y*y+z*z;
    return sqrtf(output);
}
void vector3::printVector3() const{
    std::cout << "(" << x << ", " << y << ", " << z << ")" ;
}


