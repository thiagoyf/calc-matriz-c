#include<stdio.h>
#include<stdlib.h>

int main()
{
  int m;
  float **matriz, produto, somatoria, subtracao;

  printf("Entre com o tamanho de 'm' da matriz quadrada: ");

  // a) espera entrada do teclado
  scanf("%d", &m);

  printf("Preencha o valores das matrizes:\n");
  // b) matriz de float de m x (m + (m - 1))
  // criando um vetor dinamicos de ponteiro do tipo float
  matriz = (float **)malloc(m * sizeof(float*));

  for (int i = 0; i < m; i++) {
    // criando um vetor dinamico de float
    matriz[i] = (float *)malloc((m + (m - 1)) * sizeof(float));
    for (int j = 0; j < m; j++) {
      printf("pos[%d][%d]: ", i, j);
      scanf("%f", &matriz[i][j]);

      if (j > 0) {
        // replica as m - 1 ultimas colunas.
        matriz[i][j + (m - 1)] = matriz[i][j];
      }
    }
  }

  // imprime a matriz para ver como ficou
  printf("\nmatriz:\n\n");
  for (int i = 0; i < m; i++) {
    printf("[%d][%d] = %f", i, 0, matriz[i][0]);
    for(int j = 1; j < (m + (m - 1)); j++) {
        printf(",[%d][%d] = %f", i, j, matriz[i][j]);
    }
    printf("\n");
  }

  printf("\nDiagonal somatoria: ");
  somatoria = 0;
  for (int i = 0; i < m; i++) {
    produto = 1;
    for (int j = 0; j < m; j++) {
      produto *= matriz[j][j + i];
    }
    somatoria += produto;
  }
  printf("%f\n", somatoria);

  printf("\nDiagonal subtracao: ");
  subtracao = 0;
  for (int i = 0; i < m; i++) {
    produto = 1;
    for (int j = 0; j < m; j++) {
      produto *= matriz[j][i + (m - 1) - j];
    }
    subtracao += produto;
  }
  printf("%f\n", subtracao);

  printf("\nDeterminante da matriz: %f\n", somatoria - subtracao);

  return 0;
}