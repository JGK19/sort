#include <stdio.h>
#include <stdlib.h>

void selection(int *array, int q) {
  int menor;
  for (int i = 0; i < q - 1; i++) {
    menor = i;
    for (int j = i + 1; j < q; j++) {
      if (array[j] < array[menor]) {
        menor = j;
      }
    }
    if (array[i] != array[menor]) {
      troca(&array[i], &array[menor]);
    }
  }
}

void bubble(int *array, int q) {
  for (int i = 0; i < q - 1; i++) {
    for (int j = 0; j < q - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        troca(&array[j], &array[j + 1]);
      }
    }
  }
}
