#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int   id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual) {
    produto->preco = produto->preco * (1.0f - percentual / 100.0f);
}

void imprimir_produtos(Produto *ptr, int qtd) {
    printf("\n%-5s %-10s %s\n", "ID", "Código", "Preço");
    printf("------------------------------\n");
    for (int i = 0; i < qtd; i++) {
        printf("#%-4d ID:%-6d  R$ %.2f\n",
               i + 1,
               (ptr + i)->id,
               (ptr + i)->preco);
    }
    printf("------------------------------\n");
}

int main(void) {
    int n;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade inválida.\n");
        return 1;
    }

    Produto *estoque = (Produto *) malloc(n * sizeof(Produto));
    if (estoque == NULL) {
        printf("Erro: memória insuficiente.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        printf("ID    : ");
        scanf("%d", &(estoque + i)->id);
        printf("Preço : R$ ");
        scanf("%f", &(estoque + i)->preco);
    }

    printf("\n=== Produtos cadastrados ===");
    imprimir_produtos(estoque, n);

    for (int i = 0; i < n; i++) {
        aplicar_desconto(estoque + i, 5.0f);
    }

    printf("\n=== Após desconto de 5%% ===");
    imprimir_produtos(estoque, n);

    free(estoque);
    estoque = NULL;

    printf("\nMemória liberada com sucesso.\n");
    return 0;
}