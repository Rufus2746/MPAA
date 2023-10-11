#include <iostream>
#include <fstream>
#include <ctime> 

using namespace std;

double *allocate_memory(int n) {
   double *data = NULL;
   if (data == NULL) 
      return new double[n * n];
}

void create_random_matrix(int n, string fileName) {
   ofstream matrixFile(fileName);
   double x;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         x = -10 + rand() % 20;
         matrixFile << x << " ";
      }
      matrixFile << endl;
   }
   matrixFile.close();
}

void create_random_vector(int n, string fileName) {
   ofstream vectorFile(fileName);
   double x;
   for (int i = 0; i < n; i++)
   {
      x = -10 + rand() % 20;
      vectorFile << x << " ";
      vectorFile << endl;
   }
   vectorFile.close();
}

void read_data(int n, double *data, string fileName) {
   ifstream file(fileName);
   for (int i = 0; i < n * n; i++) {
      file >> data[i];
   }
   file.close();
}

int main()
{
   srand(unsigned int(time(NULL)));
   const int n = 5;
   string matrixFileName = "matrix.txt";
   string vectorFileName = "vector.txt";
   double* matrix = NULL;
   double* vector = NULL;
   if (matrix == NULL) matrix = new double[n * n];
   if (vector == NULL) vector = new double[n * n];

   create_random_matrix(n, matrixFileName);
   create_random_vector(n, vectorFileName);

   read_data(n, matrix, matrixFileName);
   read_data(n, vector, matrixFileName);

   if (matrix) { delete[] matrix; matrix = NULL; }
}