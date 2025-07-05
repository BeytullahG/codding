
// #include <iostream>
// using namespace std;
// int main(){
//     int number {25};
// int *pnumber {&number}; // указатель pnumber хранит адрес переменной number
// }

#include <iostream>
using namespace std;
int main(){
    int x = 10;
    int *px = &x;
    *px = 45;
    cout << "x = " << x << std::endl;     // 45 
}


// короче & превращает все в адрес. * рзыменовывает и создает указатель
