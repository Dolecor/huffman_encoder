#include "Header.h"


// Функция построения таблицы кодов
// таблица основана на структуре map
void buildTable(Node* node, vector<bool>& code, map<char, vector<bool>>& table)
{
	if (node->left_ != nullptr)
	{
		code.push_back(0);
		buildTable(node->left_, code, table);
		code.pop_back();
	}
	if (node->right_ != nullptr)
	{
		code.push_back(1);
		buildTable(node->right_, code, table);
		code.pop_back();
	}
	if (node->left_ == nullptr && node->right_ == nullptr)
	{
		table[node->byte_] = code;
		//cout << node->symbol_ << ' ' << node->frequency_ << ' ' << table[node->symbol_] << endl;
	}
}