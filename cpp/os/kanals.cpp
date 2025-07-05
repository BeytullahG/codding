// 2. Задача нахождения суммы элементов матрицы. Процесс 1 открывает файл
//  и считывает матрицу, записанную в следующем формате 
//  (на месте букв целые числа, в том числе отрицательные, 
//     количество строк и столбцов произвольное):
// a b c
// d e f
// g h k
// Далее процесс 1 порождает потомков по количеству строк матрицы, 
// каждый из которых находит сумму элементов соответствующей ему строки. 
// Процесс 1 собирает результаты от потомков и находит сумму элементов матрицы 
// и выводит ее на экран. 
// Использовать каналы (pipe) для передачи информации между процессами.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>


using namespace std;

int main(int argc, char* argv[]){
    if (argc < 2){
        cerr << "Eror, add a file name \n";
        return 1;
    }

    ifstream fin(argv[1]);
    if (!fin){
        cerr << "Can't open file" << argv[1] << "\n";
        return 1;
    }

    vector<vector<int>> matrix;
    string line;
    while (getline(fin, line)){
        if (line.empty()) continue;
        istringstream iss(line);
        vector <int> row;
        int val;
        while (iss >> val) row.push_back(val);
        if (!row.empty()) matrix.push_back(row);
    }

    const int rows = matrix.size();
    if (rows == 0){
        cerr << "Matrix is empty \n";
        return 1;
    }
     
    vector<int> pipe_fds;
    for (int i=0;i<rows;++i){
        int fd[2];
        if (pipe(fd) == -1){
            cerr << "Ошибка с каналом \n";
            return 1;
        }
        
    
        pid_t pid = fork();

        if (pid == -1){
            cerr << "Проблема с созданием дочернего прорцесса \n";
            return 1;
        }

        if (pid == 0){
            close(fd[0]);
            int sum = 0;
            for(int num : matrix[i]) sum += num;
        if(write(fd[1], &sum, sizeof(sum)) != sizeof(sum)){
            cerr << "Ошибка записи" << endl;
        }
        close(fd[1]);
        exit(0);
        } else{
            close(fd[1]);
            pipe_fds.push_back(fd[0]);
        }
    }
    
    int total_sum = 0;
    for (int fd : pipe_fds){
        int partial = 0;
        ssize_t r = read(fd, &partial, sizeof(partial));
        if (r == -1){
            cerr << "Ошибка чтения" << endl;
        }
        close(fd);
        total_sum += partial;
    }

    while(wait(nullptr) > 0) {}

    cout << "Total sum: " << total_sum << endl;
    return 0;


}


