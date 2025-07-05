#include <iostream>
using namespace std;

int main(){
    int number = 5;
    int &reNumber = number;
    reNumber = 20;
    cout << &reNumber << endl;
}




// #include <iostream>
// using namespace std;

// int main(){
//     int numbers[] = {1, 2, 3, 4, 5};
//     for (auto& n: numbers){
//         n *= n;
//     }   

//     for (auto n: numbers){
//         cout << n << ", ";
//     }
// }