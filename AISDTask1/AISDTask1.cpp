// AISDTask1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<stdio.h>

using namespace std;

void visit(bool** matrix, bool* visited, int U, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (matrix[U][i] == true && visited[i] == false) {
            visited[i] = true;
            visit(matrix, visited, i, size);
        }

    }

}

int check(bool** matrix, bool* visited, int size) {
    int i, count = -1;
    for (i = 0; i < size; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            visit(matrix, visited, i, size);
            count++;
        }
            
    }
    if (count == 0)
        count = -1;
    return count;
}

int main()
{
    int i, size, edge, U, V, j, result;
    
    cin >> size >> edge;

    bool* visited = new bool[size];

    bool** matrix = new bool* [size];
    for (i = 0; i < size; i++) {
        matrix[i] = new bool[size];
        visited[i] = false;
    }

    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            matrix[i][j] = false;

    for (i = 0; i < edge; i++) {
        scanf("%d%d", &U, &V);
        matrix[U - 1][V - 1] = true;
        matrix[V - 1][U - 1] = true;
    }

    result = check(matrix, visited, size);
    cout << result;

    for (i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
