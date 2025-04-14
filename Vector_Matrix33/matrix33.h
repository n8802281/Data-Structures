#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "0613348_vector3.h"

class matrix33 
{  
public:
    float arr[3][3];
public:
    matrix33();
    matrix33(const vector3 &v,const vector3 &b,const vector3 &n);
    matrix33(float qIn,float wIn,float eIn,float aIn,float sIn,float dIn,float zIn,float xIn,float cIn);
public:
    float* operator [] (unsigned int index);
    const float* operator [] (unsigned int index) const;
    
    matrix33              &operator =  (const matrix33 &v);
    matrix33              &operator += (const matrix33 &v);
    matrix33              &operator -= (const matrix33 &v);
    matrix33              &operator *= (float f);
    matrix33              &operator /= (float f);
    friend bool           operator == (const matrix33 &a, const matrix33 &b);
    friend bool           operator != (const matrix33 &a, const matrix33 &b);
    friend matrix33       operator - (const matrix33 &a);
    friend matrix33       operator + (const matrix33 &a, const matrix33 &b);
    friend matrix33       operator - (const matrix33 &a, const matrix33 &b);
    friend matrix33       operator * (const matrix33 &v, float f);
    friend matrix33       operator * (const matrix33 &a, matrix33 &b);
    friend matrix33       operator * (float f, const matrix33 &v);
    friend matrix33       operator / (const matrix33 &v, float f);
public:
    void printMatrix();
    matrix33 invert();
    void identity();
    int determinant();
};

#endif
