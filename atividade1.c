#include <stdio.h>

int main(void) {
    float preco = 100.0f;
    float *ptr = &preco;

    printf("Preço original : R$ %.2f\n", preco);

    *ptr = *ptr * 1.10f;

    printf("Preço com +10%% : R$ %.2f\n", preco);

    return 0;
}