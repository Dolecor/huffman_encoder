# Описание

Реализация кодирования (сжатия) файла с помощью кодов Хаффмана.  
Реализация декодирования представлена в другом репозитории: (TODO: указать репозиторий)

# Использование
В релизах загружены исполняемые файлы для кодирования и декодирования файла.


## 1. Кодирование (huffman_encoder.exe)

Для запуска кодировщика:

```
huffman_encoder.exe path/to/file
```

В результате исполнения появляется файл `code.bin` в папке с исполняемым файлом кодировщика.

## 2. Декодирование (huffman_decoder.exe)

Для запуска декодировщика:

```
huffman_decoder.exe
```

при этом необходимо поместить файл `code.bin` рядом с исполняемым файлом декодировщика.

---
Май 2018.
