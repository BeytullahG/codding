#!/bin/bash

echo "enter first number: "
read a
echo "enter second number: "
read b

sum=$((a + b))
echo "сумма $sum"

dif=$((a - b))
echo "разность: $dif "

prod=$((a * b))
echo "Произведение: $prod"

if [ $b -ne 0 ]; then 
    div=$((a / b))
    echo "Частное: $div"
else
    echo "Деление на ноль невозможно"
fi
