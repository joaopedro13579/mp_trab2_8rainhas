#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Queen {
    int row;
    int col;
};

bool checkAttack(const Queen& q1, const Queen& q2) {
    return (q1.row == q2.row) || (q1.col == q2.col) || (abs(q1.row - q2.row) == abs(q1.col - q2.col));
}

bool validateBoard(const vector<Queen>& queens) {
    for (int i = 0; i < queens.size(); ++i) {
        for (int j = i + 1; j < queens.size(); ++j) {
            if (checkAttack(queens[i], queens[j])) {
                return false;
            }
        }
    }
    return true;
}

int codigo(string teste) {
    ifstream inputFile(teste);
    if (!inputFile) {
        cerr << "Não foi possível abrir o arquivo de entrada." << endl;
        return -1;
    }

    vector<Queen> queens;
    vector<string> board;
    string line;
    int row = 0;

    while (getline(inputFile, line) && queens.size() < 8) {

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

    inputFile.close();

    if (queens.size() != 8) {
        cerr << "O arquivo de entrada não contém 8 rainhas." << endl;
        return -1;
    }

    cout << "Tabuleiro original:" << endl;
    for (const auto& row : board) {
        cout << row << endl;
    }

    if (validateBoard(queens)) {
        cout << "As rainhas não se atacam." << endl;
        return 1;
    } else {
        cout << "As rainhas se atacam." << endl;

        ofstream outputFile("ataques.txt");
        if (!outputFile) {
            cerr << "Não foi possível criar o arquivo de saída." << endl;
            return 0;
        }

        for (int i = 0; i < queens.size(); ++i) {
            for (int j = i + 1; j < queens.size(); ++j) {
                if (checkAttack(queens[i], queens[j])) {
                    outputFile << queens[i].row << "," << queens[i].col;
                    outputFile << " " << queens[j].row << "," << queens[j].col << endl;
                    outputFile << endl;
                }
            }
        }

        outputFile.close();
        return 0;
    }
}