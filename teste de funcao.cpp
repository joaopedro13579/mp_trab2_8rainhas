#include <iostream>
#include <fstream>

const int ROWS = 8;
const int COLS = 8;

int main() {
    int matrix[ROWS][COLS];

    // Open the file
    std::ifstream file("matrix.txt");

    // Read the matrix from the file
    if (file.is_open()) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                file >> matrix[i][j];
            }
        }

        file.close();

        // Output the matrix
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }

    return 0;
}
