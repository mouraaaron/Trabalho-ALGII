
void InsereHeap(int tam, int vetor[])
{
  int aux;
  int i = tam + 1;
  while (i>1 && vetor[i/2]<vetor[i])
  {  
    aux = vetor[i/2];
    vetor[i/2] = vetor[i];
    vetor[i] = aux;
    i = i/2;
  }
}

void Heapfy(int Vetor[])
{
  int i;
  for (i=1; i<N; i++)
    InsereHeap(i, vetor);
}

int checaHeap(int Vetor[])
{
  int i = N;
  for (i=N; i>1; i--)
    if (Vetor[i] > Vetor[i/2])
      return 0;
  return 1;
}

void SacodeHeap (int tam, int vetor[])
{
  int aux;
  int i = 2;
  while (i <= tam)
  {
    if (i<tam && Vetor[i]<Vetor[i+1])
      i++;
    if (Vetor[i/2] >= Vetor[i])
      break;
    aux = Vetor[i/2];
    Vetor[i/2] = Vetor[i];
    Vetor[i] = aux;
    i = i * 2;
  }
}

void HeapSort(int Vetor[])
{
  int i, aux;
  Heapfy(vetor);
  for (i=N; i>1; i--)
  {
    aux = Vetor[1];
    Vetor[1] = Vetor[i];
    Vetor[i] = aux;
    SacodeHeap(i-1, Vetor);
  }
}
















