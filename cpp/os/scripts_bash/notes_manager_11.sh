#!/bin/bash

NOTES_DIR="./notes"
if [ ! -d  "$NOTES_DIR" ]; then 
    mkdir "$NOTES_DIR"
fi 

while true; do
    echo
    echo "===== Менеджер заметок ====="
    echo "1) Добавить заметку"
    echo "2) Прочитать заметку"
    echo "3) Удалить заметку"
    echo "4) Показать список заметок"
    echo "5) Выход"
    echo -n "Выберите действие: "
    read choice
    case $choice in
        1)
            echo -n "Введите имя новой заметки: "
            read note
            echo "Введите текст (закончите Ctrl+D):"
            cat > "$NOTES_DIR/$note.txt"
            echo "Заметка '$note' сохранена!"
            ;;
        2)
            echo -n "Введите имя заметки: "
            read note
            if [ -f "$NOTES_DIR/$note.txt" ]; then
                echo "Содержимое заметки '$note':"
                cat "$NOTES_DIR/$note.txt"
            else
                echo "Такой заметки нет."
            fi
            ;;
        3)
            echo -n "Введите имя заметки для удаления: "
            read note
            if [ -f "$NOTES_DIR/$note.txt" ]; then
                rm "$NOTES_DIR/$note.txt"
                echo "Заметка '$note' удалена."
            else
                echo "Такой заметки нет."
            fi
            ;;
        4)
            echo "Список заметок:"
            ls "$NOTES_DIR"/*.txt 2>/dev/null | xargs -n 1 basename | sed 's/\.txt$//'
            ;;
        5)
            echo "Выход. Хорошего дня!"
            break
            ;;
        *)
            echo "Некорректный выбор."
            ;;
    esac
done
