#include <iostream>
#include <Windows.h>

#include "BasLengthException.h"

int function(std::string str, int forbidden_length);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	try
	{
		int length{};
		std::cout << "Введите запретную длину: ";
		std::cin >> length;

		while (true)
		{
			std::string str{};
			std::cout << "Введите слово: ";
			std::cin >> str;

			int strLength = function(str, length);
			std::cout << "Длина слова \"" << str << "\" равна " << strLength;
		}
	}
	catch (BasLengthException& ex)
	{
		std::cout << ex.what()<< std::endl;
	}
	catch (...)
	{
		std::cout << "Неизвестная ошибка!" << std::endl;
	}
}

int function(std::string str, int forbidden_length)
{
    int length = str.length();
    if (forbidden_length == length)
        throw BasLengthException();
    return length;
}
