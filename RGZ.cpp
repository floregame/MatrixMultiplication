#include <iostream> 
#include <vector>
#include <locale.h> 

using namespace std; 

void InputMatrix(vector<vector<int>>& matrix, int size, const string& name) {
   cout << "Введите элементы матрицы " << name << " размером " << size << "x" << size << ":\n";
   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         cout << name << "[" << i << "][" << j << "]: ";
         cin >> matrix[i][j];
      }
   }
}

void PrintMatrix(const vector<vector<int>>& matrix, int size) {
   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }
}

vector<vector<int>> MultiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int size) {
   vector<vector<int>> result(size, vector<int>(size, 0));

   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         for (int k = 0; k < size; k++) {
            result[i][j] += A[i][k] * B[k][j];
         }
      }
   }
   return result;
}

int main() {
   setlocale(0, "");
   int size;
   cout << "Введите размер квадратных матриц: ";
   cin >> size;

   vector<vector<int>> A(size, vector<int>(size));
   vector<vector<int>> B(size, vector<int>(size));

   InputMatrix(A, size, "A");
   InputMatrix(B, size, "B");

   vector<vector<int>> result = MultiplyMatrices(A, B, size);

   cout << "Результат умножения матриц A и B:\n";
   PrintMatrix(result, size);

   return 0;
}
