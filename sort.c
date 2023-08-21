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
