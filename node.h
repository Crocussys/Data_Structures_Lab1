#ifndef NODE_H
#define NODE_H


class Node
{
private:
    int number;
    Node *prev;
    Node *next;
public:
    Node();
    void SetNext(Node *nxt);
    void SetPrev(Node *prv);
    void SetNum(int num);
    int GetNum();
    Node *GetNext();
    Node *GetPrev();
};

#endif // NODE_H
