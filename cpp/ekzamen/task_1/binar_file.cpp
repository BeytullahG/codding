#include <iostream>
#include <fstream>
using namespace std;

struct application
{
    char fio[50];
    int age;
    int edu;
    int razryad;
    int normativi[3];
    int experience;
};

int main()
{
    ifstream in("kazan_sec.txt");

    if(!in){
        cout << "eror open file in";
        exit(1);
    }

    ofstream out("pretendent.bin", ios::binary);
    application a[100];

    int i=0;
    int j, n, k;
    application x;

    while(in >> x.fio >> x.age >> x.edu >> x.razryad>>
    x.normativi[0] >> x.normativi[1] >> x.normativi[2] >> 
    x.experience)
    {
        if ((x.age <= 55) && (x.edu == 2 || x.edu == 1)
     && (x.razryad == 1) && (x.normativi[0] >= 30) &&
    (x.normativi[1] <= 15) && (x.normativi[2] >= 70))
    {
        a[i] = x;
        i++;
    }
    }
    in.close();

    k = i - 1;
    for (i = 0; i<k-1; i++){
        for (j = 0; j<k; j++){
            if(a[i].experience < a[j].experience){
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }


    cout << "Введите число вакантных мест n= " << endl;
    cin >> n;

    if (k < n){
        cout << "кандидатов меньше чем вакантных мест" << endl;
        exit(1);
    }

    for (i=0; i<n; i++)
        out.write((char*)&a[i], sizeof(struct application));
    out.close();

    ifstream in_bin("pretendent.bin", ios::binary);
    bool p = false;

    for (i = 0; i<n; i++){
        in_bin.read((char*)&x, sizeof(struct application));
        if((x.edu == 2) && (x.age >= 45) && (x.normativi[1] <= 14) &&
    (x.experience >= 5)){
        p = true;
        cout << "x.fio" << " " << x.age << endl;
    }
    }
    in_bin.close();

    if (!p){
        cout << "нет подходящих кандидатов на должность начальника";
    }
    

}