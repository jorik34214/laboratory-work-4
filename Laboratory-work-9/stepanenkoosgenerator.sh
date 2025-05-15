#!/bin/bash

# Кількість створюваних файлів
COUNT=$((30+22))

# Цикл для автоматичного створення файлів
for i in $(seq 1 $COUNT); do
    # Генеруємо випадкове число для назви файлу
    RANDOM_NUM=$RANDOM
    FILE_NAME="file${RANDOM_NUM}.txt"

    # Створюємо файл
    touch "$FILE_NAME"

    echo "Створено файл: $FILE_NAME"
done

# Виводимо список створених файлів
ls -l | awk '{print $9, $3}'
