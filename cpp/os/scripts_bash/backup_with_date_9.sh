#!/bin/bash

echo "Введите имя файла для резервного копирования: "
read filename 

if [ ! -f "$filename" ]; then
    echo "Файл '$filename' name "
    exit 1
fi
today=$(date +%Y%m%d_%H%M%S)
backupname="${filename%.*}_$today.${filename##*.}"
cp "$filename" "$backupname"
echo "Резервная копия создана: $backupname "