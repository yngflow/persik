/*
Переменная - это проименованная ячейка памяти (физической или виртуальной), 
    с определенным типом данных. Предназначенная для хранения информации.
...
double - Вещественный тип данных.
    Предназначен для хранения числа с плавующей точкой.
    Диапазоном от 1.7*10**-308 до 1.7*10**308 (256 бита)
float - Вещественный тип данных.
    Предназначен для хранения числа с плавующей точкой.
    Диапазоном от (32 бит)
int - Целочисленный тип данных.
    Предназначен для хранения числа
    Диапазоном от -32768 (−2147483648) до 32767 (2147483647). (16-32 бит)(знаковые)
    Диапазоном от 0 до 65535 (4294967295). (16-32 бит)(знаковые)
char - Символьный тип данных.
    Предназначен для хранения одного любого символа.
    Диапазон значений от -128 до 127. (8 бит)(знаковые)
    Диапазон значений от 0 до 255. (8 бит)(беззнаковые)
short - Целочисленный тип данных.
    Предназначен для хранения числа
    Диапазоном от -32768 до 32767. (16 бит)(знаковый)
    Диапазоном от 0 до 65535. (16 бит)(беззнаковый)
bool - Логический тип данных.
    Принимает значения 0 и 1 (True / False)
    (8 бит)
*/
#include <iostream>

using namespace std;
int main() {
    short a, b;
    a = 463722;
    b = 95627;
    cout << "- Double  - 256 bit - min & max values: - " << numeric_limits<double>::min() << " - " << numeric_limits<double>::max() << " -" << endl;
    cout << "- Float   - 32 bit  - min & max values: - " << numeric_limits<float>::min() << "  - " << numeric_limits<float>::max() << "  -" << endl;
    cout << "- Integer - 32 bit  - min & max values: - " << numeric_limits<int>::min() << "  - " << numeric_limits<int>::max() << "   -" << endl;
    cout << "- Char    - 8 bit   - min & max values: - " << "-128         - 127" << "          -" << endl;
    cout << "- Short   - 16 bit  - min & max values: - " << numeric_limits<short>::min() << "       - " << numeric_limits<short>::max() << "        -" << endl;
    cout << "- Bool    - 8 bit   - min & max values: - " << numeric_limits<bool>::min() << "            - " << numeric_limits<bool>::max() << "            -" << endl;
    cout << endl << "Operations: " << endl;
    cout << "Double: 5.8 + 11.2 = " << 5.8 + 11.2 << endl;
    cout << "Float: 12.5 + 7.1 = " << 12.5f + 7.1f << endl;
    cout << "Integer: 823753 + 125649 = " << 823753 + 125649 << endl;
    cout << "Char: A + B = " << 'A' + 'B' << endl;
    cout << "Short: 463722 + 95627 = " << a + b << endl;
    cout << "Bool: true + false = " << true + false << endl;
    return 0;
}
