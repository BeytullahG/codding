#!/bin/bash

echo "Введите имя файла: "
read filename

echo "Введите текст для поиска: "
read pattern

if [ ! -f "$filename" ]; then
    echo "Файл '$filename' не найден "
    exit 1
fi 

echo "Результаты поиска: "
grep --color=always "$pattern" "$filename"

if [ $? -eq 0 ]; then
    echo "Строки найдены!"
else
    echo "Такого текста нет в файле. "
fi