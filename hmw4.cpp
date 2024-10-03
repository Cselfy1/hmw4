#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//1
/*
int main() {
    int rows, cols, n;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter the initial number: ";
    cin >> n;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    int value = n;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;
            value *= 2;
        }
    }

    cout << "Resulting matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/


//2
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows, cols, n;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter the initial number: ";
    cin >> n;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    int value = n;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;
            value += 1;
        }
    }

    cout << "Resulting matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/

//3 
void shiftRight(vector<vector<int>>& matrix, int shifts) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    shifts %= cols;

    for (int i = 0; i < rows; i++) {
        vector<int> temp = matrix[i];
        for (int j = 0; j < cols; j++) {
            matrix[i][(j + shifts) % cols] = temp[j];
        }
    }
}

void shiftLeft(vector<vector<int>>& matrix, int shifts) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    shifts %= cols;

    for (int i = 0; i < rows; i++) {
        vector<int> temp = matrix[i];
        for (int j = 0; j < cols; j++) {
            matrix[i][(j - shifts + cols) % cols] = temp[j];
        }
    }
}

void shiftUp(vector<vector<int>>& matrix, int shifts) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    shifts %= rows;

    for (int j = 0; j < cols; j++) {
        vector<int> temp(rows);
        for (int i = 0; i < rows; i++) {
            temp[(i - shifts + rows) % rows] = matrix[i][j];
        }
        for (int i = 0; i < rows; i++) {
            matrix[i][j] = temp[i];
        }
    }
}

void shiftDown(vector<vector<int>>& matrix, int shifts) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    shifts %= rows;

    for (int j = 0; j < cols; j++) {
        vector<int> temp(rows);
        for (int i = 0; i < rows; i++) {
            temp[(i + shifts) % rows] = matrix[i][j];
        }
        for (int i = 0; i < rows; i++) {
            matrix[i][j] = temp[i];
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    int shifts;
    string direction;
    cout << "Enter number of shifts: ";
    cin >> shifts;
    cout << "Enter direction (left, right, up, down): ";
    cin >> direction;

    if (direction == "right") {
        shiftRight(matrix, shifts);
    }
    else if (direction == "left") {
        shiftLeft(matrix, shifts);
    }
    else if (direction == "up") {
        shiftUp(matrix, shifts);
    }
    else if (direction == "down") {
        shiftDown(matrix, shifts);
    }
    else {
        cout << "Invalid direction!" << endl;
        return 1;
    }

    cout << "Matrix after shifting:" << endl;
    printMatrix(matrix);

    return 0;
}