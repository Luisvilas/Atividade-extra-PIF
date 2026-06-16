#include <stdio.h>

typedef struct {
    int   id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual) {
    produto->preco = produto->preco * (1.0f - percentual / 100.0f);
}

int main(void) {
    Produto p = {1, 250.0f};

    printf("Produto #%d\n", p.id);
    printf("Preço original  : R$ %.2f\n", p.preco);

    aplicar_desconto(&p, 20.0f);

    printf("Preço com -20%% : R$ %.2f\n", p.preco);

    return 0;
}