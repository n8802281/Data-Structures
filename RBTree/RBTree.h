//
//  RBTree.h
//  study
//
//  Created by 吳辰亮 on 2018/6/30.
//  Copyright © 2018年 吳辰亮. All rights reserved.
//
#ifndef RBTREE
#define RBTREE
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
class RBTree
{
public:
    RBTree(const RBTree& input){};
    enum COLOR{ RED, BLACK };
    class RBNode{
        public:
            RBNode(){
                right = NULL;
                left = NULL;
                parent = NULL;
            }
            COLOR RB_COLOR;
            RBNode* right;
            RBNode* left;
            RBNode* parent;
            string gender;
            int Height,Weight;
            int key;
        string getGender(){
            return gender;
        }
        int getHeight(){
            return Height;
        }
        int getWeight(){
            return Weight;
        }
    };
    void clear(RBNode* node){
        if (node != m_nullNode){
            clear(node->left);
            clear(node->right);
            delete node;
        }
    };
    RBNode *m_nullNode;
    RBNode *m_root;
public:
    RBTree();
    bool Empty();
    RBNode* find(int key);
    bool insert(int key, string gender, int height,int weight);
    void InsertFixUp(RBNode* node);
    bool RotateLeft(RBNode* node);
    bool RotateRight(RBNode* node);
    bool Delete(int key);
    void DeleteFixUp(RBNode* node);
    inline RBNode* InOrderPredecessor(RBNode* node);
    inline RBNode* InOrderSuccessor(RBNode* node);
    void InOrderTraverse();
    void InOrderTraverse(RBNode* node);
    RBNode &operator[](int key);
    ~RBTree(){};
};
#endif /* RBTREE */
