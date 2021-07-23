#include <stdio.h>
#include <stdlib.h>

typedef struct ctref
{
  struct ctref *prox;
  void *end;
  int ct;
}ctref;

ctref *List = NULL;

ctref* Inserir(ctref* List, void* end)
{
  
  if(List==NULL)
  {
    ctref*aux=(ctref*)malloc(sizeof(ctref));
    aux->end=end;
    aux->prox=NULL;
    aux->ct=1;
    List=aux;
    return List;
  }
  else
  {
    List->prox = Inserir(List->prox,end);
    return  List;
  }
}

ctref *Remover(ctref *List, void *end)
{
  ctref *aux;
  if(List->end == end)
  {
    aux=List;
    List=List->prox;
    free(aux->end);
    free(aux);
    return List;
  }
  else
  {
    List->prox = Remover(List->prox,end);
    return List;
  }
}

void AumentaContador(void *end,int valor)
{
  ctref *aux = List;
  while(aux != NULL)
  {
    if(aux->end == end)
    {
      aux->ct = aux->ct + valor;
      if(aux->ct == 0)
      {
        List=Remover(List,aux->end);
        break;
      }
    }
    aux = aux->prox;
  }
}

void* malloc2(size_t size)
{
    void* end;

    end = malloc(size);
    List = Inserir(List, end);

    return end;
}

void dump()
{
  ctref *aux = List;
  printf("---------------------------------------------------------------\n");
  while(aux != NULL)
  {
    printf("Endereco de memoria: %p\t Contador de Referencia: %d\n",aux->end, aux->ct);
    aux = aux->prox;
  }
  printf("---------------------------------------------------------------\n");
}

void atrib2(void **endDa, void *endRecebe)
{
  AumentaContador((*endDa), -1);
  AumentaContador(endRecebe, 1);
  (*endDa) = endRecebe;
}
