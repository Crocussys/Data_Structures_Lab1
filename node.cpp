#include "node.h"

Node::Node()
{
    number = 0;
    prev = nullptr;
    next = nullptr;
}
void Node::SetNext(Node *nxt){
    next = nxt;
}
void Node::SetPrev(Node *prv){
    prev = prv;
}
void Node::SetNum(int num){
    number = num;
}
int Node::GetNum(){
    return number;
}
Node *Node::GetNext(){
    return next;
}
Node *Node::GetPrev(){
    return prev;
}
