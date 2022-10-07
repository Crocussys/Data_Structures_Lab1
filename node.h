#ifndef NODE_H
#define NODE_H


/* Узел списка */
class Node
{
private:
    int number;
    Node *prev;
    Node *next;
public:
    Node();
    void SetNext(Node *nxt);  // Установить ссылку на следующий узел
    void SetPrev(Node *prv);  // Установить ссылку на предыдущий узел
    void SetNum(int num);     // Установить значение узла
    int GetNum();             // Получить значение узла
    Node *GetNext();          // Получить следующий узел
    Node *GetPrev();          // Получить предыдущий узел
};

#endif // NODE_H
