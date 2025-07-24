#include <iostream>
#include <fstream>
using namespace std;

struct application // zajavka
{
    char fio[40];
    int age; // возраст
    char edu; // образование
    int kitchen[4]; // кухня
    int experience; // стаж работы
    int one_place_period; // макс стаж работы на одном месте
    int number_change_work; // сколько раз менял работу
    int dismiss_from_office; // количество увольнений за нарушения
};

int main()
{
    ifstream in("Kazan_restaurant.txt");
    ofstream out("Pretendent.bin", ios::binary);
    application a[100];

    if (!in)
    {
        cout << "Can't open file!" << endl;
        exit(-1);
    }

    int i = 0;
    int j, k, n;
    application x;

    while (in >> x.fio >> x.age >> x.edu >> x.kitchen[0] >> x.kitchen[1] >>
               x.kitchen[2] >> x.kitchen[3] >> x.experience >>
               x.one_place_period >> x.number_change_work >> x.dismiss_from_office)
    {
        if ((x.age <= 50) && (x.edu == '1' || x.edu == '2') &&
            (x.kitchen[0] || x.kitchen[1]) && (x.one_place_period * 2 >= x.experience) &&
            (x.dismiss_from_office <= 1) && (x.number_change_work <= 5))
        {
            a[i] = x;
            i++;
        }
    }
    in.close();

    k = i;

    // order
    for (i = 0; i < k - 1; i++)
        for (j = i + 1; j < k; j++)
            if (a[i].experience < a[j].experience)
            {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }

    cout << "Enter number of vacant seats n=";
    cin >> n;

    if (k < n)
    {
        cout << "Pretendents less necessary!";
        exit(1);
    }

    for (i = 0; i < n; i++)
        out.write((char *)&a[i], sizeof(struct application));
    out.close();

    ifstream in_bin("Pretendent.bin", ios::binary);
    bool p = false;

    for (i = 0; i < n; i++)
    {
        in_bin.read((char *)&x, sizeof(struct application));
        if ((x.age <= 45) && (x.edu == '2') && (x.experience >= 15) &&
            (x.dismiss_from_office == 0) && (x.number_change_work <= 2))
        {
            p = true;
            cout << x.fio << ' ' << x.age << endl;
        }
    }
    in_bin.close();

    if (!p)
    {
        cout << "Sorry! Chief cook is not appeared!" << endl;
    }
}
