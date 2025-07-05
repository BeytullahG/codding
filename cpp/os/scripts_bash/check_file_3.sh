#!/bin/bash

echo "Enter name a file"
read filename
if [ -e "$filename" ]; then
    echo "файл '$filename' существует"
else
    echo "файл '$filename' не найден"
fi