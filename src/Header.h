#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <list>
#include <vector>

#include "Node.h"

#define BYTE 8

using namespace std;



// Имя сжатого файла
constexpr char CODE_FILE[] = "code.bin";

// Сообщения об ошибках
constexpr char EXCEPTION_NO_PARAMETER[] = 
    "Parameter no entered.\nEnter the parameter (path to encoded file)";
constexpr char EXCEPTION_EMPTY_FILE[] =
    "File is empty. Compression is not required";
constexpr char WRONG_PATH[] = "Wrong file path";


// Функция для работы потока с вектором
ostream& operator << (ostream& out, vector<bool> vec);

// Функция построения дерева кодов
Node* buildTree(priority_queue<Node*, vector<Node*>, cmpNode> priorQ);

// Функция построения таблицы кодов
void buildTable(Node* node, vector<bool>& code, 
    map<char, vector<bool>>& table);

// Функция, которая кодирует файл
void encodeFile(ifstream& encodedFile, ofstream& codeFile, 
				Node* codeTree, map<char, vector<bool>> table);