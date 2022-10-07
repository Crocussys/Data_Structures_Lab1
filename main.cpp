#include <iostream>
#include "node.h"

using namespace std;

/* Создание двусвязного цикличного списка
   n - количество узлов
   Возвращает первый узел                 */
Node *create(int n){
    Node *first = new Node;
    first->SetNum(1);
    Node *previous = first;       // Пока цикл состоит из одного элемента
    for (int i = 2; i <= n; i++){
        Node *nd = new Node;
        nd->SetNum(i);            // Задаём значение новому узлу
        nd->SetPrev(previous);    // Задаём предыдущий узел
        previous->SetNext(nd);    // Задаём обратную ссылку у предыдущего узла
        previous = nd;            // Теперь новый узел становится предыдущим и
                                  //   мы готовы создавать следующий
    }
    previous->SetNext(first);     // Окончательно зацикливаем список
    first->SetPrev(previous);
    return first;
}

// Задание a
int exercise_a(int n, int m){
    Node *List = create(n);             // Создаём список
    for (int i = 0; i < n - 1; i++){    // Должны исключить всех, кроме одного
        for(int j = 0; j < m; j++){     // Считаем
            List = List->GetNext();
        }
        Node *next = List->GetNext();   // Удаляем узел из списка
        Node *prev = List->GetPrev();   // путём переопределения ссылок
        prev->SetNext(next);            // на предыдущем и следующем узлах
        next->SetPrev(prev);
        List = List->GetNext();         // Переходим к следующему узлу
                                        // и окончательно теряем доступ к этому узлу
    }                                   // В итоге у нас остался один элемент. Его значение - ответ
    cout << "Номер оставшегося человека: " << List->GetNum() << endl;
    return 0;
}

// Задание b
int exercise_b(int n, int m, int l){    // Аналогично заданию a
    Node *List = create(n);
    while (List->GetNum() != l){        // но начинаем с заданного элемента
        List = List->GetNext();
    }
    for (int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            List = List->GetPrev();     // И идём в обратную сторону
        }
        Node *next = List->GetNext();
        Node *prev = List->GetPrev();
        prev->SetNext(next);
        next->SetPrev(prev);
        List = List->GetPrev();         // И здесь обратно
    }
    cout << "Номер человека, с которого начинался чсёт: " << List->GetNum() << endl;
    return 0;
}

int main(){
    char exercise;
    cout << "Выберете задание ('a' или 'b'): ";
    cin >> exercise;
    if (exercise == 'a'){
        int n;
        int m;
        cout << "Общее количество человек: ";
        cin >> n;
        cout << "Вести счёт до: ";
        cin >> m;
        cout << endl;
        return exercise_a(n, m);
    }
    else if (exercise == 'b'){
        int n;
        int m;
        int l;
        cout << "Общее количество человек: ";
        cin >> n;
        cout << "Вести счёт до: ";
        cin >> m;
        cout << "Номер оставшегося человека: ";
        cin >> l;
        cout << endl;
        return exercise_b(n, m, l);
    }
   else{
        cout << "Invalid value" << endl;
        return -1;
    }
}

// @Crocussys
