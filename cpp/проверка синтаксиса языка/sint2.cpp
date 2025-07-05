#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    ifstream in("sint2.txt");
    if (!in) cout << "ошибка открытия входного файла";

    ofstream out("out.txt");
    if (!out) cout << "ошибка открытия выходного файла";

    char x;
    int q = 0;

    while (in >> x && q != 5){
        out << x;
        switch (q){
            case 0:
                if (x == 'A') q = 1;
                else q = 5;
                break;
            case 1:
                if (x == 'B') q = 2;
                else q = 5;
                break;
            case 2:
                if (x == 'C') q =  3;
                else q = 5;
                break;
            case 3:
                if (x == 'B') q = 2;
                else if (x == 'A') q = 4;
                else if (x == 'C') q = 3;
                else q = 5;
                break;
            default:
            q = 5;
            break;
        }
        out << setw(2) << q << endl;
    }
    if (q == 4) out << "good";
    else out << "not good";
    return 0;
}