# Лабораторная работа №6 --- Трехмерное Моделирование

- [Лабораторная работа №6 --- Трехмерное Моделирование](#лабораторная-работа-6-----трехмерное-моделирование)
  - [Постановка задачи и реализация](#постановка-задачи-и-реализация)
  
## Постановка задачи и реализация

Задача --- Написать приложение-виджет, в котором формируется и визуализируется заданный трехмерный объект, его преобразования и двухмерное проецирование.

В качестве заданного объекта была использована трехмерная модель
первой буквы имени автора --- буквы Г.

Для реализации поставленной задачи была использована внутренняя библиотека QT ---
OpenGL. Построив массив вершин трехмерной модели, и массив индексации мы оптимизировали
процесс визуализации модели.

Реализованный функционал приложения:

    - Отображение первой буквы моего имени после нажатия кнопки "draw letter", а именно буквы "Г".
    - Возможность выбора цвета буквы после нажатия кнопки "letter colour".
    - Задание масштабирования в LineEdits: "x scale", "y scale", "z scale".
    - Отображение полученного объекта после масштабирования с помощью кнопки "scaling".
    - Задание переноса трехмерного объекта в LineEdits: "x transfer", "y transfer", "z transfer".
    - Отображение полученного объекта после переноса с помощью кнопки "transfer".
    - Задание вращения вокруг произвольной оси в LineEdits: "rotation x", "rotation y", "rotation z".
    - Отображение полученного объекта после вращения с помощью кнопок: "rotation x", "rotation y", "rotation z".
