#include <iostream>      // Для вывода и ошибок
#include <fstream>       // Для работы с файлами (ifstream)
#include <vector>        // Для использования вектора (vector)
#include <string>        // Для строк (string)
#include <sstream>       // Для разбора строк (istringstream)
#include <unistd.h>      // Для pipe, fork, read, write, close (POSIX)
#include <sys/wait.h>    // Для функции wait (ожидание завершения процессов)
#include <cerrno>        // Для переменной errno (ошибки)
#include <cstring>       // Для strerror, используется perror

using namespace std;

int main(int argc, char* argv[]){
    // Проверяем, что передан аргумент с именем файла
    if (argc < 2){
        cerr << "Error: add a file name\n";
        return 1;
    }

    // Открываем файл для чтения
    ifstream fin(argv[1]);
    if (!fin){
        cerr << "Can't open file: " << argv[1] << "\n";
        return 1;
    }

    // Читаем матрицу из файла построчно
    vector<vector<int>> matrix;  // Двумерный вектор для хранения матрицы
    string line;                 // Для хранения текущей строки из файла
    while (getline(fin, line)){
        if (line.empty()) continue;          // Пропускаем пустые строки
        istringstream iss(line);             // Создаём поток для разбора строки
        vector<int> row;                     // Вектор для чисел текущей строки
        int val;
        while (iss >> val) row.push_back(val); // Разбираем строку на числа
        if (!row.empty()) matrix.push_back(row); // Если строка не пуста — добавляем в матрицу
    }

    const int rows = matrix.size();          // Считаем количество строк в матрице
    if (rows == 0){
        cerr << "Matrix is empty\n";         // Если матрица пустая — выводим ошибку
        return 1;
    }
     
    vector<int> pipe_fds;                    // Вектор для хранения дескрипторов каналов (концов для чтения)

    // Для каждой строки матрицы создаём отдельный процесс и канал (pipe)
    for (int i = 0; i < rows; ++i){
        int fd[2];                          // fd[0] — чтение, fd[1] — запись
        if (pipe(fd) == -1){
            perror("Pipe");                 // Ошибка при создании канала
            return 1;
        }

        pid_t pid = fork();                 // Создаём дочерний процесс
        if (pid == -1){
            perror("Fork");                 // Ошибка при создании процесса
            return 1;
        }

        if (pid == 0){                      // В дочернем процессе:
            close(fd[0]);                   // Закрываем неиспользуемый конец канала (чтение)
            long long sum = 0;              // Переменная для суммы строки
            for (int num : matrix[i]) sum += num; // Считаем сумму всех элементов строки
            // Отправляем сумму родителю через канал
            if (write(fd[1], &sum, sizeof(sum)) != sizeof(sum)){
                perror("Write");            // Если не удалось записать — выводим ошибку
            }
            close(fd[1]);                   // Закрываем конец на запись
            exit(0);                        // Завершаем дочерний процесс
        } else{
            close(fd[1]);                   // Родителю запись не нужна — закрываем
            pipe_fds.push_back(fd[0]);      // Сохраняем дескриптор для чтения в вектор
        }
    }
    
    // Собираем суммы от всех дочерних процессов через каналы
    long long total_sum = 0;                // Итоговая сумма матрицы
    for (int fd : pipe_fds){
        long long partial = 0;
        ssize_t r = read(fd, &partial, sizeof(partial)); // Читаем сумму из канала
        if (r == -1){
            perror("Read");                 // Ошибка при чтении
        }
        close(fd);                          // Закрываем дескриптор после чтения
        total_sum += partial;               // Прибавляем частичную сумму к общей
    }

    // Ждём завершения всех дочерних процессов, чтобы не было зомби-процессов
    while (wait(nullptr) > 0) {}

    // Выводим итоговую сумму матрицы
    cout << "Total sum: " << total_sum << endl;
    return 0;
}
