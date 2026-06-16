#include <stdio.h>

typedef struct {
    int   id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual) {
    produto->preco = produto->preco * (1.0f - percentual / 100.0f);
}
void imprimir_produtos(Produto *ptr, int qtd) {
    printf("\n%-5s %-20s %s\n", "ID", "Produto", "Preço");
    printf("-------------------------------------\n");
    for (int i = 0; i < qtd; i++) {
        printf("#%-4d ID:%-3d             R$ %.2f\n",
               i + 1,
               (ptr + i)->id,
               (ptr + i)->preco);
    }
    printf("-------------------------------------\n");
}

int main(void) {
    Produto estoque[3] = {
        {101, 199.90f},
        {102, 349.50f},
        {103,  89.00f}
    };
    int total = 3;

    printf("=== Estoque inicial ===");
    imprimir_produtos(estoque, total);

    for (int i = 0; i < total; i++) {
        aplicar_desconto(estoque + i, 10.0f);
    }

    printf("\n=== Estoque após 10%% de desconto ===");
    imprimir_produtos(estoque, total);

    return 0;
}