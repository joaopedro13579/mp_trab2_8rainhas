#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Struct representing a queen on the chessboard.
 */
struct rainha {
    int row;/**< The row position of the queen. */
    int col;/**< The column position of the queen. */
};
/**
 * Checks if two queens can attack each other.
 *
 * @param q1 The first queen.
 * @param q2 The second queen.
 * @return True if the queens can attack each other, False otherwise.
 */
bool checkAttack(const rainha& q1, const rainha& q2) {
    return (q1.row == q2.row) || (q1.col == q2.col) || (abs(q1.row - q2.row) == abs(q1.col - q2.col));
}
/**
 * Validates the chessboard configuration.
 *
 * @param queens The vector of queens.
 * @return True if the queens do not attack each other, False otherwise.
 */
bool validateBoard(const vector<rainha>& queens) {
    for (int i = 0; i < queens.size(); ++i) {
        for (int j = i + 1; j < queens.size(); ++j) {
            if (checkAttack(queens[i], queens[j])) {
                return false;
            }
        }
    }
    return true;
}
/**
 * Reads a chessboard configuration from a file and checks if the queens attack each other.
 *
 * @param teste The name of the input file.
 * @return 1 if the queens do not attack each other, 0 if they do, -1 if an error occurs.
 */
int codigo(string teste) {
    ifstream file_entrada(teste);
    if (!file_entrada) {
        cerr << "Não foi possível abrir o arquivo de entrada." << endl;
        return -1;
    }

    vector<rainha> queens;
    vector<string> board;
    string line;
    int row = 0;

    while (getline(file_entrada, line) && queens.size() < 8) {

        if (line.size() != 9 ) {
            cerr << "O arquivo de entrada não possui um tabuleiro de 8x8." << endl;
            return -1;
        }

        line.erase(line.size() - 1); // Remove o caractere de quebra de linha

        board.push_back(line);

        for (int col = 0; col < line.size(); ++col) {
            if (line[col] == '1') {
                queens.push_back({ static_cast<int>(row), static_cast<int>(col) });
            }
        }

        ++row;
    }

    file_entrada.close();

    if (queens.size() != 8) {
        cerr << "O arquivo de entrada não contém 8 rainhas." << endl;
        return -1;
    }

    //cout << "Tabuleiro original:" << endl;
    for (const auto& row : board) {
        //cout << row << endl;
    }

    if (validateBoard(queens)) {
        //cout << "As rainhas não se atacam." << endl;
        return 1;
    } else {
        //cout << "As rainhas se atacam." << endl;

        ofstream file_entrada("ataques.txt");
        if (!file_entrada) {
            cerr << "Não foi possível criar o arquivo de saída." << endl;
            return 0;
        }

        for (int i = 0; i < queens.size(); ++i) {
            for (int j = i + 1; j < queens.size(); ++j) {
                if (checkAttack(queens[i], queens[j])) {
                    file_entrada << queens[i].row << "," << queens[i].col;
                    file_entrada << " " << queens[j].row << "," << queens[j].col << endl;
                    file_entrada << endl;
                }
            }
        }

        file_entrada.close();
        return 0;
    }
}