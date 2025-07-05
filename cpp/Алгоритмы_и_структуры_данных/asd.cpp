// 1)алгоритм Евклида
// #include <iostream>
// using namespace std;

// int evkl(int a, int b){
//     while (b != 0){
//         int temp = b;
//         b = a%b;
//         a = temp;
//     }
//     return a;
// }

// int main(){
//     cout << evkl(50, 100) << endl;
// }


// a⋅x+b⋅y=НОД(a,b). Расширенный алгоритм Евклида

// #include <iostream>
// #include <array>
// using namespace std;

// array<int, 3> ex_evkl(int a, int b){
//     if (b==0){
//         return {a, 1, 0};
//     } else{
//         auto res = ex_evkl(b, a%b);
//         int d = res[0];
//         int x1 = res[1];
//         int y1 = res[2];
//         int x = y1;
//         int y = x1 - (a/b) * y1;
//         return {d, x, y};
//     }
// }
    
// int main(){
//         auto res = ex_evkl(50, 5);
//         cout << "НОД = " << res[0]<< endl << "x = " << res[1] << endl << "y = " << res[2] << endl;
    
// }



// 1.сортировка массива прямыми включениями 

// #include <iostream>
// using namespace std;

// void sort_pryam(int* arr, int size){
//     for (int i=0; i<size; i++){
//         int value = arr[i];
//         int index = i;
//         while ((index > 0) && (arr[index-1] > value)){
//             arr[index] = arr[index - 1];
//             index--;
//         }
//     arr[index] = value;
//     }
// }

// int main(){
    
//     int arr[] = {16, 52, 83, 84, 62, 91, 20, 37, 81, 22, 30, 26};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     sort_pryam(arr, size);

//     for (int i=0; i<size;i++){
//         cout << arr[i] << ", "; 
//     }
//     cout << endl;
//     return 0;

    
// }


//2. Дан ряд, содержащий n элементов. Отсортировать их в порядке возрастания,
// отбрасывая при этом все повторяющиеся элементы.

// #include <iostream>
// using namespace std;

// void sort_pryam(int* arr, int size){
//     for (int i=0; i<size; i++){
//         int value = arr[i];
//         int index = i;
//         while ((index > 0) && (arr[index-1] > value)){
//             arr[index] = arr[index - 1];
//             index--;
//         }
//     arr[index] = value;
//     }
// }

// int remouve_duplicate(int* arr, int size){
//     if (size == 0) return 0;

//     int new_size = 1;
//     for (int i = 1; i< size; i++){
//         if (arr[i] != arr[new_size - 1]){
//             arr[new_size] = arr[i];
//             new_size++;
//         } 
//     }
//     return new_size;
// }


// int main(){
    
//     int arr[] = {16, 16,  52, 83, 84, 62, 91, 20, 20, 37, 81, 22, 22, 30, 26};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     sort_pryam(arr, size);
//     int new_size = remouve_duplicate(arr, size);


//     for (int i=0; i < new_size; i++){
//         cout << arr[i] << ", "; 
//     }
//     cout << endl;
//     return 0;

    
// }


// //3 . Определить моду ряда – значение, встречающееся среди его элементов чаще всего.

// #include <iostream>
// using namespace std;

// void sort_pryam(int* arr, int size){
//     for (int i=0; i<size; i++){
//         int value = arr[i];
//         int index = i;
//         while ((index > 0) && (arr[index-1] > value)){
//             arr[index] = arr[index - 1];
//             index--;
//         }
//     arr[index] = value;
//     }
// }

// int moda(int* arr, int size){
//     if (size == 0) return -1;
//     int mode = arr[0];
//     int max_count = 1;
//     int current_count = 1;

//     for (int i=1; i<size; i++){
//         if (arr[i] == arr[i - 1]){
//             current_count++;
//         }else{
//             if (current_count > max_count){
//                 max_count = current_count;
//                 mode = arr[i-1];
//             }
//             current_count = 1;
//         }
//     }
//     if (current_count > max_count){mode = arr[size-1];}
//     return mode;
// }

// int main(){
//     int arr[] = {16, 16, 52, 83, 84, 62, 91, 20, 20, 37, 81, 22, 22, 22, 30, 26};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     sort_pryam(arr, size);
//     int mode = moda(arr, size);
//     cout << "Мода массива: " << mode << endl; 

// }



// 4. Исходный набор данных представляет собой последовательность записей, состоящих
// из фамилии, возраста и стажа работы. Вывести этот список: 1) в порядке увеличения
// возраста; 2) в порядке увеличения стажа работы.
// #include <iostream>
// #include <fstream>
// using namespace std;

// struct sotrudnic{
//     char fio[40];
//     int age; // возраст
//     int experience; //опыт
// };

// void sort_age(sotrudnic arr[], int size){
//     for (int i = 0; i<size - 1; i++){
//         for (int j=0; j<size - i - 1; j++){
//             if(arr[j].age > arr[j+1].age){
//                 sotrudnic temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }

// void sort_experience(sotrudnic arr[], int size){
//     for (int i = 0; i<size - 1; i++){
//         for (int j = 0; j<size - i - 1; j++){
//             if (arr[j].experience > arr[j+1].experience){
//                 sotrudnic temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }

// void print_sotrud(sotrudnic arr[], int size){
//     for (int i=0; i<size; i++){
//         cout << "ФИО: " << arr[i].fio << "; " 
//         << "Возраст: " << arr[i].age << "; " 
//         << "Стаж работы: " << arr[i].experience << endl;
//     }
// }


// int main(){
//     ifstream in("sotrud.txt");

//     const int max_size = 100;
//     sotrudnic sotrudnici[max_size];
//     int count = 0;

//     while (in >> sotrudnici[count].fio >> sotrudnici[count].age >> sotrudnici[count].experience){
//         count++;
//         if (count > max_size){
//             cerr << "превышено максимальное количество записей" << endl;
//             break;
//         }
//     }
//     in.close();

//     sort_age(sotrudnici, count);
//     cout << "список сотрудников в порядке увеличения возраста: " << endl;
//     print_sotrud(sotrudnici, count);

//     sort_experience(sotrudnici, count);
//     cout << "список сотрудниквов в порядке увеличения стажа работы: " << endl;
//     print_sotrud(sotrudnici, count);

//     return 0;

// }




// 5. Написать процедуру сортировки по убыванию.
// #include <iostream>
// using namespace std;

// void sort_pryam(int* arr, int size){
//     for (int i=0; i<size; i++){
//         int value = arr[i];
//         int index = i;
//         while ((index > 0) && (arr[index-1] < value)){
//             arr[index] = arr[index - 1];
//             index--;
//         }
//     arr[index] = value;
//     }
// }

// int main(){
    
//     int arr[] = {16, 52, 83, 84, 62, 91, 20, 37, 81, 22, 30, 26};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     sort_pryam(arr, size);

//     for (int i=0; i<size;i++){
//         cout << arr[i] << ", "; 
//     }
//     cout << endl;
//     return 0;

    
// }



#include <iostream>
using namespace std;

void bubl_sort(int* add, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if(add[j] > add[j+1]){
                swap(add[j], add[j+1]);
            }
        }
    }
}


int main(){
    int arr[] = {9, 4, 3, 1, 767, 53, 24354,4565,23453,1232,8765};
    int size = sizeof(arr) / sizeof(arr[1]);
    bubl_sort(arr, size);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

