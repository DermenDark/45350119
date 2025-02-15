#include <iostream>
#include <vector>

using namespace std;

void print_square(const vector<vector<long long>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << '\n';
    }
}

void fill_magic_square(vector<vector<long long>>& matrix, long long size, long long start_val, long long end_val) {
    long long i = 0, j = size / 2;
    while (start_val <= end_val) {
        matrix[i][j] = start_val++;
        
        long long temp_i = i, temp_j = j;
        i--; j++;

        // Wrap-around logic
        if (i < 0 && j < size) i = size - 1;
        if (i >= 0 && j >= size) j = 0;
        if (i < 0 && j >= size) {
            i += 2;
            j--;
        }

        if (matrix[i][j] != 0) {
            i = temp_i;
            j = temp_j;
            i++;
        }
    }
}

void generate_magic_square(long long size) {
    vector<vector<long long>> matrix(size, vector<long long>(size));
    
    for (long long i = 0; i < size; ++i) {
        for (long long j = 0; j < size; j++) {
            matrix[i][j] = size * i + j + 1;
        }
    }

    for (long long i = 0; i < size / 4; i++) {
        for (long long j = 0; j < size / 4; j++) {
            matrix[i][j] = size * size - (size * i + j);
            matrix[i + size / 4 * 3][j] = size * size - ((i + size / 4 * 3) * size + j);
            matrix[i][j + size / 4 * 3] = size * size - (size * i + j + size / 4 * 3);
            matrix[i + size / 4 * 3][j + size / 4 * 3] = size * size - ((i + size / 4 * 3) * size + j + size / 4 * 3);
        }
    }

    for (long long i = size / 4; i < size / 4 * 3; i++) {
        for (long long j = size / 4; j < size / 4 * 3; j++) {
            matrix[i][j] = size * size - (size * i + j);
        }
    }

    print_square(matrix);
}

void generate_special_magic_square(long long size) {
    long long quarter_size = size * size / 4;

    vector<vector<long long>> matrix_a(size / 2, vector<long long>(size / 2, 0));
    vector<vector<long long>> matrix_b(size / 2, vector<long long>(size / 2, 0));
    vector<vector<long long>> matrix_c(size / 2, vector<long long>(size / 2, 0));
    vector<vector<long long>> matrix_d(size / 2, vector<long long>(size / 2, 0));

    fill_magic_square(matrix_a, size / 2, 1, quarter_size);
    fill_magic_square(matrix_b, size / 2, quarter_size + 1, 2 * quarter_size);
    fill_magic_square(matrix_c, size / 2, 2 * quarter_size + 1, 3 * quarter_size);
    fill_magic_square(matrix_d, size / 2, 3 * quarter_size + 1, 4 * quarter_size);

    for (long long i = 0; i < size / 2; i++) {
        for (long long j = 0; j < size / 4; j++) {
            if (j < size / 4 - 1) {
                swap(matrix_b[i][size / 2 - j - 1], matrix_d[i][size / 2 - j - 1]);
            }
            if (i == size / 4 && j == 0) {
                swap(matrix_a[i][size / 4], matrix_c[i][size / 4]);
                continue;
            }
            swap(matrix_a[i][j], matrix_c[i][j]);
        }
    }

    for (long long i = 0; i < size / 2; i++) {
        for (long long j = 0; j < size / 2; j++) {
            cout << matrix_a[i][j] << " ";
        }
        for (long long j = 0; j < size / 2; j++) {
            cout << matrix_b[i][j] << " ";
        }
        cout << '\n';
    }

    for (long long i = 0; i < size / 2; i++) {
        for (long long j = 0; j < size / 2; j++) {
            cout << matrix_c[i][j] << " ";
        }
        for (long long j = 0; j < size / 2; j++) {
            cout << matrix_d[i][j] << " ";
        }
        cout << '\n';
    }
}

void create_magic_square(long long size) {
    if (size == 1) {
        cout << "1\n";
        return;
    }

    if (size == 2) {
        cout << "NO\n";
        return;
    }

    if (size % 2 == 1) {
        vector<vector<long long>> matrix(size, vector<long long>(size, 0));
        fill_magic_square(matrix, size, 1, size * size);
        print_square(matrix);
    } else if (size % 4 == 0) {
        generate_magic_square(size);
    } else {
        generate_special_magic_square(size);
    }
}

int main() {
    long long size;
    cin >> size;

    create_magic_square(size);

    return 0;
}