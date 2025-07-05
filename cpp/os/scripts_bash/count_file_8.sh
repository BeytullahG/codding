#!/bin/bash

echo "Введите имя файла для анализа: "
read filename
if [ ! -f "$filename" ]; then 
    echo "Файл '$filename' не найден "
    exit 1
fi

lines=$(wc -l < "$filename")
words=$(wc -w < "$filename")
chars=$(wc -m < "$filename")

echo "строк в файле: $lines"
echo "слов в файле: $words"
echo "символов в файле: $chars"