#include <stdio.h>

void aplicar_desconto(float *preco, float percentual) {
    *preco = *preco * (1.0f - percentual / 100.0f);
}

int main(void) {
    float preco = 100.0f;

    printf("Preço original  : R$ %.2f\n", preco);

    aplicar_desconto(&preco, 15.0f);

    printf("Preço com -15%% : R$ %.2f\n", preco);

    return 0;
}