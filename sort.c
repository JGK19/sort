#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b, long int *t) {
  int x;
  x = *a;
  *a = *b;
  *b = x;
}

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

void insertion(int *array, int q) {
  int i, x, j;
  for (i = 1; i < q; i++) {
    x = array[i];
    while ((j >= 0) && (array[j] > x)) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = x;
  }
}

void mergeSort(int *array, int i, int f) {
  int meio = (i+f)/2;
  if (i != f) {
    mergeSort(array, i, meio);
    mergeSort(array, meio+1, f);

    merge(array, i, meio, f);
  }
}

void merge(int *array, int i, int meio,int f) {
  int x, y, j, choice, qt;
  qt = (f + 1) - i;
  int a[qt];
  x = i;
  y = meio + 1;
  
  for (int k = 0; k < qt; k++) {
    
    choice = cmp(array, &x, &y, i, meio, f);
    a[k] = choice;
  }
  j = 0;
  for (int k = i; k <= f; k++) {
    array[k] = a[j];
    j++;
  }
}

int cmp(int *array, int *x, int *y, int i, int meio, int f) {
  int result, compare;
  if (*x == *y) {
    result = array[*x];
    *x = *x + 1;
    *y = *x;
    return result;
}
  
  if (array[*x] < array[*y]) {
    result = array[*x];
    *x = (*x < meio) ? (*x + 1): (*y);
  } else {
    result = array[*y];
    *y = (*y < f) ? (*y + 1): (*x);
  }
  return result;
}

void quickSort(int *array, int ini, int fim) {
  int i, j, pivo;
  if (fim - ini < 2) {
    if (fim - ini == 1) {
      if (array[fim] < array[ini]) {
        trocax(&array[fim], &array[ini]);
      }
    }
  } else {
    i = ini;
    j = fim;
    pivo = array[ini];

    while (j > i) {
      i++;
      while(array[i] < pivo) {
        i++;
      }
      while (array[j] > pivo) {
        j--;
      }
      if (j > i) {
        trocax(&array[j], &array[i]);
      }
    }
    trocax(&array[ini], &array[j]);
    quickSort(array ,ini , j-1);
    quickSort(array, j+1, fim);
  }
}
