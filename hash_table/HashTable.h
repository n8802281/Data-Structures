//
//  hashtable.hpp
//  class hashtable
//
//  Created by 吳辰亮 on 2018/5/20.
//  Copyright © 2018年 吳辰亮. All rights reserved.
//

#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
using namespace std;
/*
 HashTable is the class implemented by yourself, 5 member functions you need to implement as belows:
 1. addItem(key, gender, height, weight) : add data into your hash table
 2. operator[key]    : return item by selected key
 3. getGender()      : return gender by item
 4. getHeight()      : return height by item
 5. getWeight()      : return weight by item
 */
class Node
{
public:
    string gender;
    int Height,Weight;
    string key;
    Node *next;
    Node():key(0),gender(0),Height(0),Weight(0),next(NULL){};
    Node(string k,string g ,int h,int w):key(k),gender(g),Height(h),Weight(w),next(NULL){};
    Node(Node const &data){
        key=data.key;
        gender=data.gender;
        Height=data.Height;
        Weight=data.Weight;
        next=data.next;
    }
    string getGender() const;
    int getHeight() const;
    int getWeight() const;
};

class HashTable
{
private:
    Node **table;
    int hashfunction(string key);
public:
    HashTable();
    ~HashTable(){};
    
    void addItem(string key,string gender ,int height,int weight);
    Node &operator[](string key);
    
};
#endif /* HashTable */
