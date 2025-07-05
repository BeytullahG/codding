#include <iostream>
#include <fstream>
using namespace std;

struct criteria{
    char fio[40]; // ФИО
    int age; // Возраст
    int edu; // Степень образования (2 — высшее, 1 — среднее специальное, 0 — неполное среднее)
    int programming_skills[4]; // Навыки программирования: 0 — C++; 1 — Python;
    //2 — JavaScript; 3 — Java; где 0-нет, 1-да
    int experience; // Стаж работы
    int num_of_proj; // Количество проектов, в которых принимал участие
    int comand_work; // Программирование в команде 0-no, 1-yes
    int buisnes_trips; // Готовность к командировкам 1-да, 0-нет
    
};

int main()
{
    ifstream in("candidates.txt");
    if (!in)
    {
        cout << "eror";
        return -1;
    }
    
    ofstream out("pret.bin", ios::binary);

    criteria a[100];
    int i = 0;
    criteria x;
    
    while (in >> x.fio >> x.age >> x.edu >> x.programming_skills[0] >> x.programming_skills[1] >> x.programming_skills[2] >> x.programming_skills[3] >> x.experience >> x.num_of_proj >> x.comand_work >> x.buisnes_trips){
        if((x.age <= 50) && (x.edu == 1 || x.edu == 2) && (x.programming_skills[0] || x.programming_skills[1]) && (x.experience >= 7) && (x.num_of_proj >= 10) && (x.comand_work) && (x.buisnes_trips)){
            a[i] = x;
            i++;
        }
            }
    in.close();
    int k = i;
    
    for (int i = 0; i<k-1; i++){
        for (int j=i+1; j<k; j++){
            if(a[i].experience < a[j].experience){
                swap(a[i], a[j]);
            }
        }
    }
    
    int n;
    cout << "Введите требуемое количество сотрудников: " << endl;
    cin >> n;
    
    if (k < n) {
        cout << "Кандидатов меньше, чем требуется!" << endl;
        return 1;
    }
    
    ofstream res("res.txt");
    res << "Список подходящих кандидатов:" << endl;
    for (int i = 0; i<n; i++){
        res << a[i].fio << endl;
    }
    
    for (int i=0; i<n; i++){
        out.write((char*)&a[i], sizeof(criteria));
    }

    out.close();

    ifstream in_bin("pret.bin", ios::binary);
    bool found = false;

    cout << "Претенденты на начальника отдела: " << endl;
    for (int i = 0; i<n; i++){
        in_bin.read((char*)&x, sizeof(criteria));

        if((x.age <= 50) && (x.edu == 2) && (x.programming_skills[0] || x.programming_skills[1]) && (x.experience >= 10) && (x.num_of_proj >= 20) && (x.comand_work) && (x.buisnes_trips)){
            found = true;
            cout << x.fio << " " << x.age << endl;
        }
        in_bin.close();
        
    }
    if (!found){
                cout << "Подходящих кандидатов нет" << endl;
            }

    return 0;

}
