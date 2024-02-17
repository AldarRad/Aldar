
#include <iostream>
//  для подсчета вызовов
static int recursiveCalls = 0;
// Рекурсивная функция для поиска максимального элемента в массиве
int findMaxRecursive(const int* arr, int size) {
    ++recursiveCalls; // Увеличиваем счетчик вызовов
    // Когда размер массива достигает 1, функция завершает рекурсию 
    if (size == 1) {
        std::cout << "Базовый случай: " << recursiveCalls << " вызовов" << std::endl;
        return arr[0];
    }
    int maxInRest = findMaxRecursive(arr + 1, size - 1);
    return (arr[0] > maxInRest) ? arr[0] : maxInRest;
}

std::string binhex(int a, const int base)
{

    const char l[16] = { '0', '1', '2', '3','4','5','6','7','8','9','A','B','C', 'D','E','F' };
    std::string res = "00000000";
    for (int i = 7; i >= 0; --i)
    {
        res[i] = l[a % base];
        a /= base;
    }
    return res;
}



int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    // Создаем динамический массив
    int* dynamicArray = new int[size];
    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> dynamicArray[i];
    }
    // Находим максимальный элемент с помощью рекурсивной функции
    int maxElement = findMaxRecursive(dynamicArray, size);
    std::cout << "Максимальный элемент в массиве: " << maxElement << std::endl;
    // Освобождаем динамическую память
    delete[] dynamicArray;
    return 0;
}
