#include "Header.h"



int main(int argc, char* argv[])
{
    try {
        if (argc < 2)
            throw std::exception(EXCEPTION_NO_PARAMETER);

        // Открытие текстового файла для кодирования
        ifstream encodedFile(argv[1], ios::binary);
        if (!encodedFile.is_open())
            throw std::exception(WRONG_PATH);
        else
            cout << "Got file: " << argv[1] << endl;


        map<char, int> frequency;   // хранение связок байт-частота
        char gotByte;               // байт из файла
        // Побайтное чтение файла и подсчитывание частоты
        encodedFile.get(gotByte);
        if (encodedFile.eof())
            throw std::exception(EXCEPTION_EMPTY_FILE);
        while (!encodedFile.eof()) {
            frequency[gotByte]++;
            encodedFile.get(gotByte);
        }

        // Запись узлов в очередь с приоритетом
        map<char, int>::iterator it;
        priority_queue<Node*, vector<Node*>, cmpNode> priorQ;
        for (it = frequency.begin(); it != frequency.end(); ++it) {
            Node* tmp = new Node;

            tmp->byte_ = it->first;
            tmp->frequency_ = it->second;
            priorQ.push(tmp);
        }

        // Построение дерева кодов
        Node* root = buildTree(priorQ);

        // Построение таблицы кодов
        vector <bool> code;
        map<char, vector<bool>> table;
        buildTable(root, code, table);

        // Очитска флагов для кодируемого файла и передвижение в его начало
        encodedFile.clear();
        encodedFile.seekg(0);

        // Создание файла, в который будут записываться закодированные данные
        ofstream out(CODE_FILE, ios::binary);

        // Кодирование файла
        encodeFile(encodedFile, out, root, table);
        cout << "Compression successful" << endl;

        out.close();
        encodedFile.close();
    }

    catch (std::exception& err) {
        cout << err.what() << endl;
    }


    system("pause");
    return 0;
}