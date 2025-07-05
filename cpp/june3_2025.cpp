// #include<iostream>
// using namespace std;

// struct  node {
//   int data;
//   node* next;
// };

// bool prime(int x) {
//   if (x <= 1) return false;
//   for (int i = 2; i * i <= x; i++) {
//     if (x % i == 0) return false;
//   }
//   return true;
// }

// int main() {
//   int n;
//   cout << "Enter n= ";
//   cin >> n;
//   node* top = nullptr;
//   node* p;
//   for (int i = 0; i < n; i++) {
//     node* p = new node;
//     cout << "Enter data= ";
//     cin >> p->data;
//     p->next = top;
//     top = p;
//   }
//   cout << "My list: " << endl;
//   p = top;
//   while (p) {
//     if (prime(p->data));
//     cout << p->data << " ";
//     p = p->next;
//   }
//   cout << endl;
//   int s = 0;
//   p = top;
//   while (p) {
//     s = s + p->data;
//     p = p->next;
//   }
//   cout << "s= " << s << endl;
//   int max = top->data;
//   p = top;
//   while (p) {
//     if (max < p->data) max = p->data;
//     p = p->next;
//   }
//   cout << "max= " << max << endl;
//   while (top) {
//     cout << top->data << " ";
//     p = top->next;
//     delete top;
//     top = p;
//   }
//   return 0;



// создание односвязного списка
// #include <iostream>
// using namespace std;

// struct node
// {
//     int data;
//     node* next;
// };

// void create_list(node* &top, int n) {
//     node* p;
//     int i;
//     top = nullptr;
//     for (i=0; i<n; i++){
//         p = new node;
//         cout << "enter p->data: ";
//         cin >> p->data;
//         p->next = top;
//         top = p;

//     }
// }

// int main(){
//     node* mylist = nullptr;
//     create_list(mylist, 3);
//     return 0;
// }


#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

// Функция создания списка
void create_list(node* &top, int n) {
    node* p;
    int i;
    top = nullptr;
    for (i=0; i<n; i++){
        p = new node;
        cout << "Enter element " << i+1 << ": ";
        cin >> p->data;
        p->next = top;
        top = p;
    }
}

// Функция вывода списка
void print_list(node* top) {
    cout << "\nList contents: ";
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main(){
    node* mylist = nullptr;
    int n;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    create_list(mylist, n);
    print_list(mylist);
    
    return 0;
}














