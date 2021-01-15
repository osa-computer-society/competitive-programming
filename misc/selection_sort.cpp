void selection_sort(int s[], int len) {
  int min;
  for (int j, i = 0; i < len; i++) {
    min = i;
    for (j = i + 1; j < len; j++) {
      if (s[j] < s[min]) min = j;
    }
  }
}
