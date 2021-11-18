#include "Header.h"

// Функция, которая кодирует файл
void encodeFile(ifstream& encodedFile, ofstream& codeFile, Node* codeTree, map<char, vector<bool>> table)
{
    vector<bool> code;  // код байта из таблицы
    char bufer = 0;     // для вывода информации в файл
    short whichBit = 0; // заполненность bufer

    // Запись количества байт в исходном файле
    // (занимает первые 8 байт в сжатом файле)
    long long byteCount = codeTree->frequency_;
    whichBit = sizeof(long long) * BYTE;
    for (int i = 0; i < sizeof(long long); ++i) {
        whichBit -= BYTE;
        bufer = static_cast<char>(byteCount >> whichBit);
        codeFile << bufer;
    }

    // Запись таблицы кодов в файл
    bufer = 0;
    whichBit = 0;
    map<char, vector<bool>>::iterator itFILE;
    for (itFILE = table.begin(); itFILE != table.end(); ++itFILE) {
        codeFile << static_cast<char>(itFILE->first);           // Запись кодируемого байта
        codeFile << static_cast<char>(itFILE->second.size());   // Запись его длины
        code = itFILE->second;      // код байта
        // Запись кода байта в буфер.
        // Если в буфере записано 8 бит (BYTE), то выгрузить его в файл
        for (int i = 0; i < code.size(); ++i) {
            bufer = bufer | code[i] << (7 - whichBit);
            whichBit++;
            if (whichBit == BYTE) {
                whichBit = 0;
                codeFile << bufer;
                bufer = 0;
            }
        }

        // Запись оставшихся бит
        if (whichBit != 0) {
            codeFile << bufer;
            whichBit = 0;
            bufer = 0;
        }
    }
    // Запись двух нулевых байтов в файл.
    // Знак об окончании области с таблицей кодов
    codeFile << (char)0 << (char)0;


    // Очитска флагов для кодируемого файла и передвижение в его начало
    encodedFile.clear();
    encodedFile.seekg(0);

    // Запись исходного файла, закодированного кодами Хаффмана
    code.clear();
    bufer = 0;
    whichBit = 0;
    char temp = 0;
    while (!encodedFile.eof()) {
        encodedFile.get(temp);
        code = table[temp];
        // Запись кода байта в буфер.
        // Если в буфер записано 8 бит (BYTE), то выгрузить его в файл
        for (int i = 0; i < code.size(); ++i) {
            bufer = bufer | code[i] << (7 - whichBit);
            whichBit++;
            if (whichBit == BYTE) {
                whichBit = 0;
                codeFile << bufer;
                bufer = 0;
            }
        }
    }

    // Запись оставшихся бит
    if (whichBit != 0)
        codeFile << bufer;

    return;
}