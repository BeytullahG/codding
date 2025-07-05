#!/bin/bash

echo "Создаем 10 файлов ... "
for i in {1..10}; do
    touch "file${i}.txt"
    echo "Создан файл file${i}.txt "
done
echo "Все созданные файлы: "
ls file*.txt