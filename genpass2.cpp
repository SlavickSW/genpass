//==============================================================================================================================================
// Name        : genpass.cpp
// Author      : Slavick S (slavick.s.werewolf@gmail.com)
// Version     : 0.2
// Copyright   : Copyright (c) <2021>, <Slavick S>, <Creative Commons Attribution-NonCommercial-ShareAlike v. 4.0 License (CC BY-NC-SA 4.0)>
//               https://creativecommons.org/licenses/by-nc-sa/4.0/deed.uk                          
//
// Description : Программа генерирует пароли произвольной длинны, но не меньше 8 символов, и сохраняет их в файл.
//               Внимание: не используються спецсимволы; при генерации более 100 000 паролей программа может некоторое время не отвечать.
//               Компилировалась под Ubuntu 20.04.3 : g++ genpass.cpp -Wall -Werror -ansi -pedantic -O3 -o genpass   
//               g++ --version : 9.3.0
//               Для компиляции под Windows рекомендую включить код для решения проблемы с кодировкой символов: setlocale(LC_ALL, "Russian");
//==============================================================================================================================================

#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;

class PassGen {

public:
    void displayMessage()
    {
        int passLenght;
        int numOfPasswords;
        char * filename = new char;

        cout << "Введите длину пароля для генерации: ";
        cin >> passLenght;
		while (passLenght < 8) { cout << "Длина пароля слишком мала. Введите длину пароля повторно: " ; cin >> passLenght;}
        cout << "Введите количество паролей для генерации: ";
        cin >> numOfPasswords;
        cout << "Будет сгенерировано паролей: " << numOfPasswords << "." << endl;
        cout << endl;
        cout << "Введите имя файла для записи: ";
        cin >> filename;
    
        std::ofstream outFile(filename);
            if (!outFile.is_open()) {cout << "Ошибка работы с файлом " << filename << "." << " Не могу открыть файл! Возможно диск переполнен, "<<
                                             "защищен от записи или у Вас нет прав на создание/изменение файлов." << endl; exit(1);} 
            else {
        for (int k = 0; k < numOfPasswords; k++) {
            for (int i = 0; i < passLenght; ++i) {
                numOfChars(passLenght);
                passGenerator(passLenght);
                outFile << password [i];
            }
            outFile << endl;
        }
        outFile.close();

        cout << "Пароли успешно сгенерированы и записаны в файл " << filename << "" << endl;
                }
    }
                
    void passGenerator(int passLenght)
    {
        password = new char [passLenght];

        for (int i = 0; i < numOfNumbers; ++i) {
            password [i] = char(rand() % 10 + 48);
        }
        for (int i = numOfNumbers; i < numOfNumbers + numOfBigChars; ++i) {
            password [i] = char(rand() % 26 + 65);
        }
        for (int i = numOfNumbers + numOfBigChars; i < passLenght; ++i) {
            password [i] = char(rand() % 26 + 97);
        }
         std::random_shuffle(password, password + passLenght);
    }

    void numOfChars(int passLenght)
    {
        numOfSmallChars = rand() % passLenght;
        int charRandEnd = passLenght - numOfSmallChars;
        numOfBigChars = rand() % charRandEnd;
        numOfNumbers = passLenght - numOfSmallChars - numOfBigChars;
    }

private:
    int numOfSmallChars;
    int numOfBigChars;
    int numOfNumbers;
    char * password;
};

int main()
{
    //setlocale(LC_ALL, "Russian");
    cout << "=====================================================" << endl;
    cout << "== Password generator by Slavick S aka MaD-DoG2000 ==" << endl;
    cout << "=====================================================" << endl;
    cout << " " << endl;
    srand((unsigned int)time(NULL));
    PassGen * pass = new PassGen;
    pass->displayMessage();
    return 0;
}

