#include "Header.h"


// Функция для работы потока с вектором
ostream& operator << (ostream& out, vector<bool> vec)
{
	for (int i = 0; i < vec.size(); i++)
		out << vec[i];

	return out;
}