#include "0613348_matrix33.h"
#include <iostream>
matrix33::matrix33(){
    
}
matrix33::matrix33(const vector3 &v,const vector3 &b,const vector3 &n){
    arr[0][0]=v.x;
    arr[0][1]=v.y;
    arr[0][2]=v.z;
    arr[1][0]=b.x;
    arr[1][1]=b.y;
    arr[1][2]=b.z;
    arr[2][0]=n.x;
    arr[2][1]=n.y;
    arr[2][2]=n.z;
}
matrix33::matrix33(float qIn,float wIn,float eIn,float aIn,float sIn,float dIn,float zIn,float xIn,float cIn){
    arr[0][0]=qIn;
    arr[0][1]=wIn;
    arr[0][2]=eIn;
    arr[1][0]=aIn;
    arr[1][1]=sIn;
    arr[1][2]=dIn;
    arr[2][0]=zIn;
    arr[2][1]=xIn;
    arr[2][2]=cIn;
}

float* matrix33::operator [] (unsigned int index){
    return arr[index];
}
const float* matrix33::operator [] (unsigned int index)const{
    return arr[index];
}

matrix33& matrix33::operator=(const matrix33 &v){
    arr[0][0]=v.arr[0][0];
    arr[0][1]=v.arr[0][1];
    arr[0][2]=v.arr[0][2];
    arr[1][0]=v.arr[1][0];
    arr[1][1]=v.arr[1][1];
    arr[1][2]=v.arr[1][2];
    arr[2][0]=v.arr[2][0];
    arr[2][1]=v.arr[2][1];
    arr[2][2]=v.arr[2][2];
    return *this;
}
matrix33& matrix33::operator+=(const matrix33 &v){
    arr[0][0]+=v.arr[0][0];
    arr[0][1]+=v.arr[0][1];
    arr[0][2]+=v.arr[0][2];
    arr[1][0]+=v.arr[1][0];
    arr[1][1]+=v.arr[1][1];
    arr[1][2]+=v.arr[1][2];
    arr[2][0]+=v.arr[2][0];
    arr[2][1]+=v.arr[2][1];
    arr[2][2]+=v.arr[2][2];
    return *this;
}
matrix33& matrix33::operator-=(const matrix33 &v){
    arr[0][0]-=v.arr[0][0];
    arr[0][1]-=v.arr[0][1];
    arr[0][2]-=v.arr[0][2];
    arr[1][0]-=v.arr[1][0];
    arr[1][1]-=v.arr[1][1];
    arr[1][2]-=v.arr[1][2];
    arr[2][0]-=v.arr[2][0];
    arr[2][1]-=v.arr[2][1];
    arr[2][2]-=v.arr[2][2];
    return *this;
}
matrix33& matrix33::operator*=(float f){
    arr[0][0]*=f;
    arr[0][1]*=f;
    arr[0][2]*=f;
    arr[1][0]*=f;
    arr[1][1]*=f;
    arr[1][2]*=f;
    arr[2][0]*=f;
    arr[2][1]*=f;
    arr[2][2]*=f;
    return *this;
}
matrix33& matrix33::operator/=(float f){
    arr[0][0]/=f;
    arr[0][1]/=f;
    arr[0][2]/=f;
    arr[1][0]/=f;
    arr[1][1]/=f;
    arr[1][2]/=f;
    arr[2][0]/=f;
    arr[2][1]/=f;
    arr[2][2]/=f;
    return *this;
}
bool operator == (const matrix33 &a, const matrix33 &b){
    return  (a.arr[0][0]==b.arr[0][0]) &&(a.arr[0][1]==b.arr[0][1]) && (a.arr[0][2]==b.arr[0][2]) &&
            (a.arr[1][0]==b.arr[1][0]) &&(a.arr[1][1]==b.arr[1][1]) && (a.arr[1][2]==b.arr[1][2]) &&
            (a.arr[2][0]==b.arr[2][0]) &&(a.arr[2][1]==b.arr[2][1]) && (a.arr[2][2]==b.arr[2][2]);
}
bool operator != (const matrix33 &a, const matrix33 &b){
    return !((a.arr[0][0]==b.arr[0][0]) &&(a.arr[0][1]==b.arr[0][1]) && (a.arr[0][2]==b.arr[0][2]) &&
             (a.arr[1][0]==b.arr[1][0]) &&(a.arr[1][1]==b.arr[1][1]) && (a.arr[1][2]==b.arr[1][2]) &&
             (a.arr[2][0]==b.arr[2][0]) &&(a.arr[2][1]==b.arr[2][1]) && (a.arr[2][2]==b.arr[2][2]));
}
matrix33 operator - (const matrix33 &a){
    matrix33 tmp(-a.arr[0][0],-a.arr[0][1],-a.arr[0][2],
                 -a.arr[1][0],-a.arr[1][1],-a.arr[1][2],
                 -a.arr[2][0],-a.arr[2][1],-a.arr[2][2]);
    return tmp;
}
matrix33 operator + (const matrix33 &a, const matrix33 &b){
    matrix33 tmp(a);
    tmp+=b;
    return tmp;
}
matrix33 operator - (const matrix33 &a, const matrix33 &b){
    matrix33 tmp(a);
    tmp-=b;
    return tmp;
}
matrix33 operator * (const matrix33 &v, float f){
    matrix33 tmp(v);
    tmp*=f;
    return tmp;
}
matrix33 operator * (const matrix33 &a, matrix33 &b){
    matrix33 tmp(a.arr[0][0]*b.arr[0][0]+a.arr[1][0]*b.arr[0][1]+a.arr[2][0]*b.arr[0][2],
                 a.arr[0][1]*b.arr[0][0]+a.arr[1][1]*b.arr[0][1]+a.arr[2][1]*b.arr[0][2],
                 a.arr[0][2]*b.arr[0][0]+a.arr[1][2]*b.arr[0][1]+a.arr[2][2]*b.arr[0][2],
                 
                 a.arr[0][0]*b.arr[1][0]+a.arr[1][0]*b.arr[1][1]+a.arr[2][0]*b.arr[1][2],
                 a.arr[0][1]*b.arr[1][0]+a.arr[1][1]*b.arr[1][1]+a.arr[2][1]*b.arr[1][2],
                 a.arr[0][2]*b.arr[1][0]+a.arr[1][2]*b.arr[1][1]+a.arr[2][2]*b.arr[1][2],
                
                 a.arr[0][0]*b.arr[2][0]+a.arr[1][0]*b.arr[2][1]+a.arr[2][0]*b.arr[2][2],
                 a.arr[0][1]*b.arr[2][0]+a.arr[1][1]*b.arr[2][1]+a.arr[2][1]*b.arr[2][2],
                 a.arr[0][2]*b.arr[2][0]+a.arr[1][2]*b.arr[2][1]+a.arr[2][2]*b.arr[2][2]
                 );
    return tmp;
}
matrix33 operator * (float f, const matrix33 &v){
    matrix33 tmp(v);
    tmp*=f;
    return tmp;
}
matrix33 operator / (const matrix33 &v, float f){
    matrix33 tmp(v);
    tmp/=f;
    return tmp;
}
void matrix33::printMatrix(){
    std::cout << arr[0][0] << " " << arr[1][0] << " " << arr[2][0] << std::endl;
    std::cout << arr[0][1] << " " << arr[1][1] << " " << arr[2][1] << std::endl;
    std::cout << arr[0][2] << " " << arr[1][2] << " " << arr[2][2] << std::endl;
}
matrix33 matrix33::invert(){
    int det=determinant();
    matrix33 tmp(arr[1][1]*arr[2][2]-arr[2][1]*arr[1][2],
             -1*(arr[0][1]*arr[2][2]-arr[2][1]*arr[0][2]),
                 arr[0][1]*arr[1][2]-arr[1][1]*arr[0][2],
             -1*(arr[1][0]*arr[2][2]-arr[2][0]*arr[1][2]),
                 arr[0][0]*arr[2][2]-arr[2][0]*arr[0][2],
             -1*(arr[0][0]*arr[1][2]-arr[1][0]*arr[0][2]),
                 arr[1][0]*arr[2][1]-arr[2][0]*arr[1][1],
             -1*(arr[0][0]*arr[2][1]-arr[2][0]*arr[0][1]),
                 arr[0][0]*arr[1][1]-arr[1][0]*arr[0][1]
                 );
    tmp/=det;
    return tmp;
}
void matrix33::identity(){
    arr[0][0]=1;
    arr[0][1]=0;
    arr[0][2]=0;
    arr[1][0]=0;
    arr[1][1]=1;
    arr[1][2]=0;
    arr[2][0]=0;
    arr[2][1]=0;
    arr[2][2]=1;
}
int matrix33::determinant(){
    int output=arr[0][0]*arr[1][1]*arr[2][2]
              +arr[1][0]*arr[2][1]*arr[0][2]
              +arr[2][0]*arr[0][1]*arr[1][2]
              -arr[2][0]*arr[1][1]*arr[0][2]
              -arr[0][0]*arr[2][1]*arr[1][2]
              -arr[1][0]*arr[0][1]*arr[2][2];
    return output;
}
