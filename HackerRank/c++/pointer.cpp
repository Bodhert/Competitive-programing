#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void update(int *a,int *b) {
  int tempa = *a;
  *a = tempa + *b;
  *b = abs(tempa - *b);
}

int main() {
  int a, b;
  int *pa = &a, *pb = &b;

  scanf("%d %d", &a, &b);
  update(pa, pb);
  printf("%d\n%d", a, b);

  return 0;
}
