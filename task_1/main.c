#include <stdio.h>
#include <stdlib.h>

int create_matrix(int size, int ***matrix);
void fill_matrix(int size, int **matrix);
void mult_matrix(int size, int ***matrix_A, int ***matrix_B, int ***matrix_C);
void print_matrix(int size, int **matrix);
void remove_matrix(int size, int ***matrix);
int main() {
  int size = 0;
  if ((scanf("%d", &size) && size != 0)) {
    int **matrix_A;
    int **matrix_B;
    int **matrix_C;
    create_matrix(size, &matrix_A);
    create_matrix(size, &matrix_B);
    create_matrix(size, &matrix_C);
		fill_matrix(size, matrix_A);
		fill_matrix(size, matrix_B);
    mult_matrix(size, &matrix_A, &matrix_B, &matrix_C);
    print_matrix(size, matrix_C);
		remove_matrix(size, &matrix_A);
    remove_matrix(size, &matrix_B);
    remove_matrix(size, &matrix_C);
  } else
    printf("n/a\n");
  return 0;
}

int create_matrix(int size, int ***matrix) {
  int outputs = 0;
  if ((*matrix = malloc(size * sizeof(int *))) != NULL) {
    for (int i = 0; i < size; i++) {
      if ((*matrix[i] =malloc(size * sizeof(int))) == NULL) {
        outputs = 1;
      }
    }
  } else {
    outputs = 0;
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i][j] = 0;
    }
  }

  return outputs;
}

void fill_matrix(int size, int **matrix) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      scanf("%d", &(matrix[i][j]));
    }
  }
}

void mult_matrix(int size, int ***matrix_A, int ***matrix_B, int ***matrix_C) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      for (int k = 0; k < size; k++) {
        (*matrix_C[i][j]) += (*matrix_A[i][k]) * (*matrix_B[k][j]);
      }
    }
  }
}

void print_matrix(int size, int **matrix) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void remove_matrix(int size, int ***matrix) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      free(*(matrix + j));
    }
    free(*(matrix + i));
  }
}
