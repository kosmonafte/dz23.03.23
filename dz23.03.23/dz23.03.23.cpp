// dz23.03.23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
char* changeWord(char* text, char* str1, char* str2);
void upLetter(char* text);
int letterInString(char* text);
int numberInString(char* text);
int main()
{
    setlocale(LC_ALL, "RUS");
    char text[] = {"Lorem Ipsum is fish text 32 often used in print and web design. lorem Ipsum has been the standard 45 fish for Latin texts since the early 16th century. at the time, an 78 unnamed printer created a large collection 32548 of font sizes and shapes, using Lorem Ipsum to print samples. Lorem Ipsum not only successfully survived five centuries without noticeable changes, but also stepped into electronic design. it has been popularized in modern times by the publication of Letraset sheets with Lorem Ipsum patterns in the 60s and, more recently, by layout programs such as Aldus PageMaker, which use Lorem Ipsum in their templates.\0"};
    cout << text;
    cout << endl;
    char* str = new char[100];
    char* strNew = new char[100];
    cout << "Какое слово необходимо заменить? ";
    cin >> str;
    cout << "Каким словом необходимо заменить? ";
    cin >> strNew;
    cout << endl;
    cout << "Замена слова в тексте: ";
    cout << endl << endl;
    cout << changeWord(text, str, strNew);
    cout << endl;
    upLetter(text);
    cout << endl << "Перевод начало предложений в заглавные: " << endl << endl << text << endl;
    cout << endl << "Количество букв в тексте: " << endl;
    letterInString(text);
    cout << endl << "Количество цифр в тексте: " << endl;
    numberInString(text);
}

int numberInString(char* text) {
    int k = 0;
    char alfavit[53] = { "1234567890" };
    for (int i = 0; i < strlen(alfavit); i++) {
        for (int j = 0; j < strlen(text); j++) {
            if (alfavit[i] == text[j]) {
                k++;
            }
        }
        cout << alfavit[i] << " - " << k << "\t";
        k = 0;
    }
    return 0;
}

int letterInString(char* text) {
    int k = 0;
    char alfavit[53] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
    for (int i = 0; i < strlen(alfavit); i++) {
        for (int j = 0; j < strlen(text); j++) {
            if (alfavit[i] == text[j]) {
                k++;
            }
        }
        ((i + 1) % 10)?cout << alfavit[i] << " - " << k << "\t": cout << alfavit[i] << " - " << k << "\t" << endl;
        k = 0;
    }
    return 0;
}

void upLetter(char* text) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' && text[i+1] == ' ' && text[i+2] > 96 && text[i+2] < 123) {
            text[i + 2] = text[i + 2] - 32;
        }
    }
}

char* changeWord(char* text, char* str1, char* str2) {
    if (!strstr(text, str1)) {
        return text;
    }
    else {
        char* firstSymbol = strstr(text, str1);
        char* textNew = new char[strlen(text) - strlen(str1) + strlen(str2) + 1];
        int i = 0;
        for (; i < firstSymbol - text; i++) {
            textNew[i] = text[i];
        }
        for (; i < firstSymbol - text + strlen(str2); i++) {
            textNew[i] = str2[i - (firstSymbol - text)];
        }
        for (int m = 0; i < strlen(text) - strlen(str1) + strlen(str2) + 1; i++, m++) {
            textNew[i] = text[firstSymbol - text + strlen(str1) + m];
        }
        return changeWord(textNew, str1, str2);
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
