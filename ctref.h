#include <stdio.h>
#include <stdlib.h>

typedef struct ctref
{
  struct ctref *prox;
  void *end;
  int ct;
}ctref;

ctref* Inserir(ctref* List, void* end);

ctref* Remover(ctref* List, void* end);

void AumentaContador(void *end, int valor);

void *malloc2(size_t size);

void dump(); 

void atrib2(void **endDa, void *endRecebe);
