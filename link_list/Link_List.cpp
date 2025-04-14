#include <iostream>
#include "0613348_Link_List.h"
using namespace std;
ostream &operator<<(ostream &os, const Link_List &l){
    for(int i=0;i<l.size;i++) os << l[i] << " ";
    return os;
}
istream &operator>>(istream &is, Link_List &l){
    int tmp;
    is >> tmp;
    l.insert_node(tmp);
    return is;
}
Link_List::Link_List(){
    size = 0;
    head=NULL;
    tail=NULL;
};                                        // default constructor
Link_List::Link_List(const Link_List &l){
    size = 0;
    head = NULL;
    tail = NULL;
    Int_Node* i=l.head;
    while(i!=NULL){
        insert_node(i->value);
        i=i->next;
    }
    
}                    // copy constructor
Link_List::~Link_List(){
    if(tail!=NULL){
        head = head->next;
        while(head != NULL) {
            free(head->pre);
            head = head->next;
        }
    }
}
int Link_List::getSize() const{
    return size;
};
const Link_List& Link_List:: operator=(const Link_List &l){
    size = 0;
    head=NULL;
    tail=NULL;
    Int_Node* i=l.head;
    while(i!=NULL){
        insert_node(i->value);
        i=i->next;
    }
    return *this;
};        // assignment operator
bool Link_List::operator==(const Link_List &l) const{
    if(size!=l.size) return false;
    Int_Node *a=head;
    Int_Node *b=l.head;
    for(int i=0;i<size;i++){
        if(a->value!=b->value) return false;
        a=a->next;
        b=b->next;
    }
    return true;
};            // equality operator
bool Link_List::operator!=(const Link_List &right) const        // inequality operator
{
    return !(*this == right);
}
int &Link_List::operator[](int index){
    if(size<=index || size==0) return size;
    Int_Node *now=head;
    for(int i=0;i<index;i++){
        now=now->next;
    }
    return now->value;
};                            // subscript operator for non-const objects
int Link_List::operator[](int index) const{
    if(size<=index || size==0) return size;
    Int_Node *now=head;
    for(int i=0;i<index;i++){
        now=now->next;
    }
    return now->value;
};                    // subscript operator for const objects

bool Link_List::insert_node(int value){
    if(size==0){
        Int_Node *newone= (struct Int_Node *)malloc(sizeof(struct Int_Node));
        if(newone==NULL) return false;
        head=newone;
        tail=newone;
        newone->value=value;
        newone->pre=NULL;
        newone->next=NULL;
        size=1;
    }else{
        Int_Node *newone= (struct Int_Node *)malloc(sizeof(struct Int_Node));
        if(newone==NULL) return false;
        newone->value=value;
        newone->pre=tail;
        newone->next=NULL;
        tail->next=newone;
        tail=newone;
        size++;
    }
    return true;
};                        // insert an integer at the back of link list
bool Link_List::delete_node(){
    if(tail==NULL) return false;
    if(tail->pre==NULL) free(tail);
    else{
        tail=tail->pre;
        free(tail->next);
        tail->next=NULL;
        size--;
    }
    return true;
};                                    // delete the last node
bool Link_List::insert_node(int index, int value){
    if(size < index) return false;
    Int_Node *now=head;
    for(int i=0;i<index;i++){
        now=now->next;
    }
    Int_Node *tmp=now->pre;
    Int_Node *newone= (struct Int_Node *)malloc(sizeof(struct Int_Node));
    if(newone==NULL) return false;
    newone->pre=tmp;
    tmp->next=newone;
    newone->next=now;
    now->pre=newone;
    newone->value=value;
    size++;
    return true;
};                // insert an integer after the i_th position
bool Link_List::delete_node(int index){
    if(size<index) return false;
    Int_Node *now=head;
    for(int i=1;i<index;i++){
        now=now->next;
    }
    Int_Node *tmp=now->pre;
    tmp->next=now->next;
    tmp=tmp->next;
    tmp->pre=now->pre;
    size--;
    return true;
};                        // delete the i_th node

int main()
{
    
    // test default constructor
    Link_List linkList1;
    
    // test copy constructor
    Link_List linkList2(linkList1);
    
    // test getSize()
    cout << "linkList2 Size: " << linkList2.getSize() << endl;
    
    // test insert_node(value), delete_node(), operator<<, operator>>
    
    Link_List linkList3;
    cout << "Enter a integer: ";
    cin >> linkList3;
    cout << "linkList3: "<< linkList3 << endl;
    
    linkList3.insert_node(11);
    linkList3.insert_node(12);
    linkList3.insert_node(13);
    linkList3.insert_node(14);
    linkList3.insert_node(15);
    cout << "Insert Boolean: " << linkList3.insert_node(16) << endl;
    cout << "linkList3: " << linkList3 << endl;
    
    cout << "Delete Boolean: " << linkList3.delete_node() << endl;
    cout << "linkList3: " << linkList3 << endl;
    
    // test assignment operator, equality operator, insert_node(index, value), delete_node(index)
    Link_List linkList4 = linkList3;
    cout << "linkList4: " << linkList4 << endl;
    
    cout << "Insert Boolean: " << linkList4.insert_node(3, 17) << endl;
    cout << "linkList4: " << linkList4 << endl;
    
    cout << "Delete Boolean: " << linkList4.delete_node(4) << endl;
    cout << "Equality Boolean: " << (linkList4==linkList3) << endl;
    cout << "linkList4: " << linkList4 << endl;
    
    // test subscript operator []
    const Link_List linkList5 = linkList4;
    cout << "linkList4[1]: " << linkList4[1] << endl;
    cout << "linkList5[1]: " << linkList5[1] << endl;
    
    return 0;
}

