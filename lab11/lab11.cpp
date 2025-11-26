#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h> 
const int ROWS = 4;
const int COLS = 5;

long long calculate_even_indices_sum(const int matrix[ROWS][COLS]) {
    long long sum = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {

            if (i % 2 == 0 && j % 2 == 0) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

void initialize_matrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 50 + 1;
        }
    }
}

void print_matrix(const int matrix[ROWS][COLS], const std::string& name) {
    std::cout << "--- " << name << " (" << ROWS << "x" << COLS << ") ---" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------" << std::endl;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    srand(static_cast<unsigned int>(time(0)));

    int matrix1[ROWS][COLS];
    initialize_matrix(matrix1);
    print_matrix(matrix1, "Матриця 1");

    long long sum1 = calculate_even_indices_sum(matrix1);

    std::cout << " Сума елементів з парними індексами у Матриці 1: " << sum1 << std::endl;

    std::cout << "\n";

    int matrix2[ROWS][COLS];
    initialize_matrix(matrix2);
    print_matrix(matrix2, "Матриця 2");

    long long sum2 = calculate_even_indices_sum(matrix2);

    std::cout << " Сума елементів з парними індексами у Матриці 2: " << sum2 << std::endl;

    return 0;
}
