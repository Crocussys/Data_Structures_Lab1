#include <iostream>
#include "node.h"

using namespace std;

Node *create(int n){
    Node *first = new Node;
    first->SetNum(1);
    Node *previous = first;
    for (int i = 2; i <= n; i++){
        Node *nd = new Node;
        nd->SetNum(i);
        nd->SetPrev(previous);
        previous->SetNext(nd);
        previous = nd;
    }
    previous->SetNext(first);
    first->SetPrev(previous);
    return first;
}

int exercise_a(int n, int m){
    Node *List = create(n);
    for (int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            List = List->GetNext();
        }
        Node *next = List->GetNext();
        Node *prev = List->GetPrev();
        prev->SetNext(next);
        next->SetPrev(prev);
        //cout << List->GetNum() << endl;
        List = List->GetNext();
    }
    //cout << endl;
    cout << List->GetNum() << endl;
    return 0;
}

int exercise_b(int n, int m, int l){
    Node *List = create(n);
    while (List->GetNum() != l){
        List = List->GetNext();
    }
    for (int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            List = List->GetPrev();
        }
        Node *next = List->GetNext();
        Node *prev = List->GetPrev();
        prev->SetNext(next);
        next->SetPrev(prev);
        //cout << List->GetNum() << endl;
        List = List->GetPrev();
    }
    //cout << endl;
    cout << List->GetNum() << endl;
    return 0;
}

int main(){
    char exercise;
    cin >> exercise;
    if (exercise == 'a'){
        int n;
        int m;
        cin >> n;
        cin >> m;
        cout << endl;
        return exercise_a(n, m);
    }
    else if (exercise == 'b'){
        int n;
        int m;
        int l;
        cin >> n;
        cin >> m;
        cin >> l;
        cout << endl;
        return exercise_b(n, m, l);
    }
   else{

        return -1;
    }
}
