echo "Введите расширение файлов(например txt): "
read ext
count=$(ls *.$ext 2>/dev/null | wc -l)
if [ $count -eq 0 ]; then 
    echo "Файлов с расширением .$ext не найдено."
else 
    echo "Количество файлов с расширением .$ext: $count"
fi

