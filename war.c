/*  Desenvolvido por: Northon Duarte*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da struct Territorio
typedef struct {
    char nome[50];
    char corExercito[20];
    int tropas;
} Territorio;

// Função para cadastrar territórios
void cadastrarTerritorios(Territorio *mapa, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\n=== Cadastro do Território %d ===\n", i + 1);

        printf("Nome do território: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Cor do exército: ");
        fgets(mapa[i].corExercito, sizeof(mapa[i].corExercito), stdin);
        mapa[i].corExercito[strcspn(mapa[i].corExercito, "\n")] = '\0';

        do {
            printf("Número de tropas: ");
            if (scanf("%d", &mapa[i].tropas) != 1 || mapa[i].tropas < 0) {
                printf("Valor inválido. Digite um número positivo.\n");
                while (getchar() != '\n'); // limpa buffer
            } else {
                while (getchar() != '\n'); // limpa buffer
                break;
            }
        } while (1);
    }
}

// Função para exibir os territórios cadastrados
void exibirMapa(const Territorio *mapa, int qtd) {
    printf("\n\033[1;34m=== ESTADO ATUAL DO MAPA ===\033[0m\n\n");
    for (int i = 0; i < qtd; i++) {
        printf("\033[1;32mTerritório %d:\033[0m\n", i + 1);
        printf("  Nome: %s\n", mapa[i].nome);
        printf("  Cor do Exército: %s\n", mapa[i].corExercito);
        printf("  Tropas: %d\n", mapa[i].tropas);
        printf("-----------------------------\n");
    }
}

int main() {
    int qtdTerritorios;

    printf("Quantos territórios deseja cadastrar? ");
    scanf("%d", &qtdTerritorios);
    getchar(); // limpa o '\n' do buffer

    if (qtdTerritorios <= 0) {
        printf("Número inválido. Encerrando programa.\n");
        return 1;
    }

    Territorio *mapa = malloc(qtdTerritorios * sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("\n\033[1;36m=== CADASTRO DE TERRITÓRIOS ===\033[0m\n");
    cadastrarTerritorios(mapa, qtdTerritorios);
    exibirMapa(mapa, qtdTerritorios);

    free(mapa);
    return 0;
}
