#pragma once
#include <stdexcept>

class BasLengthException : public std::exception
{
public:
	const char* what() const override { return "�� ����� ����� ��������� �����! �� ��������"; };
};

