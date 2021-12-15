#include <stdio.h>

#define MAX 10

struct PILHA {
  int dado[MAX];
  int topo;
};
typedef struct PILHA typil;

int pop(typil *P) {
    int num;
    if (P->topo >= 0) {
	   num = P->dado[P->topo];
	   P->topo--;
    }
    return num;	
}
void push(typil *P, int num) {
    if (P->topo < MAX-1) {
	   P->topo++;
	   P->dado[P->topo] = num;
    }
}
int main(void) {

  typil P;
  int num;
    
  P.topo = -1;
  printf("Digite um num: ");
  scanf("%d", &num);
  while (num >=0) {
    push(&P,num);
    printf("Digite um num: ");
    scanf("%d", &num);
  }
  printf("\nPilha -> ");
  while (P.topo >= 0) {
    num = pop(&P);
    printf("%d -> ", num);
  }
    
  return 0;
}