#include <iostream>
#include <fstream>
using namespace std;

// Структура для хранения данных о соискателе
struct application {
    char fio[40];                // ФИО
    int age;                     // Возраст
    int edu;                     // Образование (0 - неполное среднее, 1 - среднее, 2 - высшее)
    int kitchen[4];              // Массив умений приготовления кухни (0 - нет, 1 - да)
    int experience;              // Общий стаж работы (лет)
    int one_place_period;        // Наибольший срок работы на одном месте (лет)
    int number_change_work;      // Количество смен работы
    int dismiss_from_office;     // Количество увольнений за нарушения
};

int main() {
    // Открываем входной файл с кандидатами
    ifstream in("Kazan_restaurant.txt");
    if (!in) {
        cout << "Не удалось открыть файл!" << endl;
        return -1;
    }
    
    // Открываем бинарный файл для записи отфильтрованных кандидатов
    ofstream out("Pretendent.bin", ios::binary);
    
    application a[100]; // Массив для хранения подходящих кандидатов
    int i = 0;
    application x;
    
    // Читаем данные из текстового файла
    while (in >> x.fio >> x.age >> x.edu >> x.kitchen[0] >> x.kitchen[1] >>
              x.kitchen[2] >> x.kitchen[3] >> x.experience >> x.one_place_period >>
              x.number_change_work >> x.dismiss_from_office) {
        // Проверяем соответствие критериям отбора
        if ((x.age <= 50) &&                     // Возраст до 50 лет
            (x.edu == 1 || x.edu == 2) &&        // Образование: среднее или высшее
            (x.kitchen[0] || x.kitchen[1]) &&    // Умение готовить традиционную или восточную кухню
            (x.one_place_period * 2 >= x.experience) && // Наибольший срок работы >= 50% от общего стажа
            (x.dismiss_from_office <= 1) &&      // Не более 1 увольнения за нарушения
            (x.number_change_work <= 5)) {       // Менял работу не более 5 раз
            
            a[i] = x; // Добавляем кандидата в массив
            i++;
        }
    }
    in.close(); // Закрываем входной файл
    
    int k = i; // Количество подходящих кандидатов
    
    // Сортируем массив по стажу работы (по убыванию)
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (a[i].experience < a[j].experience) {
                swap(a[i], a[j]);
            }
        }
    }
    
    // Запрашиваем количество вакансий
    int n;
    cout << "Введите количество вакантных мест: ";
    cin >> n;
    
    // Если кандидатов меньше, чем вакансий, выводим сообщение и завершаем программу
    if (k < n) {
        cout << "Кандидатов меньше, чем требуется!" << endl;
        return 1;
    }
    
    ofstream suitcand("suitable_cadidates.txt");
    suitcand << "Список подходящих кандидатов:" << endl;
    for (int i = 0; i<n; i++){
        suitcand << a[i].fio << endl;
    }
    
    // Записываем n лучших кандидатов в бинарный файл
    for (i = 0; i < n; i++) {
        out.write((char *)&a[i], sizeof(application));
    }
    out.close(); // Закрываем бинарный файл
    
    // Поиск главного повара среди записанных кандидатов
    ifstream in_bin("Pretendent.bin", ios::binary);
    bool found = false;
    
    cout << "Претенденты на главного повара:" << endl;
    for (i = 0; i < n; i++) {
        in_bin.read((char *)&x, sizeof(application));
        
        // Проверяем соответствие критериям главного повара
        if ((x.age <= 45) && (x.edu == 2) && (x.experience >= 15) &&
            (x.dismiss_from_office == 0) && (x.number_change_work <= 2)) {
            found = true;
            cout << x.fio << " " << x.age << endl;
        }
    }
    in_bin.close(); // Закрываем бинарный файл
    
    // Если подходящих кандидатов нет, выводим сообщение
    if (!found) {
        cout << "Извините, подходящих кандидатов на главного повара нет!" << endl;
    }
    
    return 0;
    
    
}




