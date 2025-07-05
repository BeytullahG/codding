#!/bin/bash
if [$# -eq 0]; then 
    echo "Не определено ни одного имени файла"
    exit 1
fi

for filename in "$@"; do
    if [ -e "$filename" ]; then
        echo "Файл '$filename' существует "
    else 
        echo "Файл '$filename' не существует"
    fi
done 