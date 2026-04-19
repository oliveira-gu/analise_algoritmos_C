#include <studio.h>

//Função para retornar o máximo entre dois valores
int max(int a, int b) {
  return (a > b) ? a : b;
}

// Função da Mochila 0/1 usando Programação Dinâmica
int mochila(int capacidade, int pesos[], int valores[], int n) {
    int dp[n + 1][capacidade + 1];

    // Construção da tabela dp[][]
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacidade; w++) {

            if (i == 0 || w == 0) {
                dp[i][w] = 0; // caso base
            }
            else if (pesos[i - 1] <= w) {
                dp[i][w] = max(
                    valores[i - 1] + dp[i - 1][w - pesos[i - 1]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidade];
}

int main() {
    int valores[] = {60, 100, 120};
    int pesos[] = {10, 20, 30};
    int capacidade = 50;
    int n = sizeof(valores) / sizeof(valores[0]);

    int resultado = mochila(capacidade, pesos, valores, n);

    printf("Valor máximo na mochila: %d\n", resultado);

    return 0;
}
