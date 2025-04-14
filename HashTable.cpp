//
//  hashtable.cpp
//  class hashtable
//
//  Created by 吳辰亮 on 2018/5/20.
//  Copyright © 2018年 吳辰亮. All rights reserved.
//

#include "0613348_HashTable.h"
using namespace std;
HashTable:: HashTable(){
    table = new Node *[10000];
    for (int i = 0; i < 10000; i++)
        table[i] = 0;
}

int HashTable::hashfunction(string key){
    int tmp1=(key[0]-'0')*10+(key[1]-'0')*1;
    int tmp2=(key[2]-'0')*1000+(key[3]-'0')*100+(key[4]-'0')*10+(key[5]-'0')*1;
    int tmp3=(key[6]-'0')*1000+(key[7]-'0')*100+(key[8]-'0')*10+(key[9]-'0')*1;
    return (tmp1*7+tmp2*4+tmp3*5)%10000;
}

void HashTable::addItem(string key,string gender ,int height,int weight){
    int index=hashfunction(key);
    Node *newNode = new Node(key,gender,height,weight);
    if (table[index] == NULL) {
        table[index] = newNode;
    }
    else {
        Node *next = table[index]->next;
        table[index]->next = newNode;
        newNode->next = next;
    }
}
Node &HashTable::operator[](string key){
    int index = hashfunction(key);
    Node *current = table[index];
    while (current != NULL) {
        if ( current->key == key) {
            return *current;
        }
        current = current->next;
    }
    if(current == NULL){
        Node *Node1=new Node("-1","wrong",-1,-1);
        return *Node1;
    }
    return *current;
};
string Node::getGender() const{
    return gender;
};
int Node::getHeight() const{
    return Height;
};
int Node::getWeight() const{
    return Weight;
};

