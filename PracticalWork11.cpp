#include <iostream>
#include <string>
#include <conio.h> // Для очистки консоли функцией _getch()

using namespace std;


enum CharTextureColor {
    Default = 0,
    Red,
    Purple,
    Green,
    Yellow,
    Blue
};

enum LineType {
    Horizontal = 1, Vertical
};


void showMenuInterface();
void showLineMenuInterface();
void printColorChoiceInfo(); // Вывод меню выбора цветов
void setCharTextureColor(CharTextureColor color); // Функция для вывода цвета в консоль


int main() {
    setlocale(LC_ALL, "RU");

    while (true) {
        system("cls"); // Отчищаем консоль

        showMenuInterface(); // Выводим интерфейс программы

        char choice; cin >> choice; // Пользователь вводит значение выбора

        system("cls"); // Снова отчищаем консоль

        if (choice == '1') {
            showLineMenuInterface(); // Выводим меню выбора типа фигуры

            short lineType; cin >> lineType;

            system("cls"); // Отчищаем консоль

            int length;
            char texture;
            CharTextureColor color;

            cout << "[ + ] Длина линии: "; cin >> length;
            printColorChoiceInfo(); short colorChoice; cin >> colorChoice;
            cout << "[ + ] Текстура линии: "; cin >> texture;

            switch (colorChoice) {
            case 0:
                color = Default;
                break;
            case 1:
                color = Red;
                break;
            case 2:
                color = Purple;
                break;
            case 3:
                color = Green;
                break;
            case 4:
                color = Yellow;
                break;
            case 5:
                color = Blue;
                break;
            default:
                color = Default; // По умолчанию обычный
                break;
            }

            system("cls"); // Отчищаем консоль

            cout << "[ + ] Результат: \n\n";

            setCharTextureColor(color);

            if (lineType == LineType::Horizontal) { // Горизонтальная линия
                for (short i = 0; i < length; i++) {
                    cout << texture;
                }
            }
            else if (lineType == LineType::Vertical) { // Вертикальная линия
                for (short i = 0; i < length; i++) {
                    cout << texture << "\n";
                }
            }

            cout << "\x1b[0m"; // Сброс цвета
        }
        else if (choice == '2') {
            cout << "[ + ] Фигура: \"Прямоугольник\"\n\n";

            short width, height;
            char texture;
            CharTextureColor color;

            cout << "[ + ] Ширина прямоугольника: "; cin >> width;
            cout << "[ + ] Высота прямоугольника: "; cin >> height;
            printColorChoiceInfo(); short colorChoice; cin >> colorChoice;
            cout << "[ + ] Текстура прямоугольника: "; cin >> texture;
            
            switch (colorChoice) {
            case 0:
                color = Default;
                break;
            case 1:
                color = Red;
                break;
            case 2:
                color = Purple;
                break;
            case 3:
                color = Green;
                break;
            case 4:
                color = Yellow;
                break;
            case 5:
                color = Blue;
                break;
            default:
                color = Default; // По умолчанию обычный
                break;
            }

            system("cls"); // Отчищаем консоль

            cout << "[ + ] Результат: \n\n";

            setCharTextureColor(color);

            for (short i = 0; i < height; i++) {
                for (short j = 0; j < width; j++) {
                    cout << texture;
                }
                cout << "\n";
            }

            cout << "\x1b[0m"; // Сброс цвета
        }
        
        cout << "\nНажмите любую клавишу для продолжения...\n"; // Ожидание ввода для продолжения
        _getch();
    }

    return 0;
}


void showMenuInterface() {
    cout << "[ ! ] Программа - \"Геометрические фигуры\"\n\n[ 1 ] Линия\n[ 2 ] Прямоугольник\n\n[ + ] Выберите фигуру: ";
}


void showLineMenuInterface() {
    cout << "[ + ] Фигура: “Линия\"\n\n[ 1 ] Горизонтальная\n[ 2 ] Вертикальная\n[ + ] Выберите тип: ";
}


void printColorChoiceInfo() {
    cout << "[ + ] Выберите цвет:\n[ 0 ] Обычный\n[ 1 ] Красный\n[ 2 ] Фиолетовый\n[ 3 ] Зеленый\n[ 4 ] Желтый\n[ 5 ] Синий\n\n[ + ] Выберите цвет: ";
}


void setCharTextureColor(CharTextureColor color) {
    switch (color) {
    case Default:
        cout << "\x1b[0m"; // Обычный
        break;
    case Red:
        cout << "\x1b[31m"; // Красный
        break;
    case Purple:
        cout << "\x1b[35m"; // Фиолетовый
        break;
    case Green:
        cout << "\x1b[32m"; // Зеленый
        break;
    case Yellow:
        cout << "\x1b[33m"; // Желтый
        break;
    case Blue:
        cout << "\x1b[34m"; // Синий
        break;
    default:
        cout << "\x1b[0m"; // Сброс цвета
        break;
    }
}