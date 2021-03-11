#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
  int n = 50;
  printf("%p\n", &n); 
  // & : ~의 주소를 의미하는 연산자
  // %p : 주소 출력
  int *p = &n; // pointer 
  
  
  int a = 3;
  int b = 5;
  swap(&a, &b);
  printf("a is %i, and b is %i\n", a, b);
}

// 값 자체가 아닌 address 이용해서 실제 변수의 값을 바꾸는 방식
void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
