# Ponteiros em C — Atividades Práticas

Resolução das 5 atividades sobre ponteiros, structs e alocação dinâmica em C.

---

## Estrutura do repositório

```
ponteiros-c/
├── atividade1.c   # Ponteiros e modificação direta
├── atividade2.c   # Passagem por referência (função)
├── atividade3.c   # Ponteiros para structs com operador ->
├── atividade4.c   # Aritmética de ponteiros em arrays
├── atividade5.c   # Alocação dinâmica com malloc/free
└── README.md
```

---

## Como compilar e executar

Qualquer compilador C moderno funciona (gcc, clang, cc):

```bash
gcc atividade1.c -o ativ1 && ./ativ1
gcc atividade2.c -o ativ2 && ./ativ2
gcc atividade3.c -o ativ3 && ./ativ3
gcc atividade4.c -o ativ4 && ./ativ4
gcc atividade5.c -o ativ5 && ./ativ5
```

---

## Explicação por atividade

### Atividade 1 — Ponteiros e Modificação Direta

**Conceito:** Um ponteiro armazena o *endereço de memória* de outra variável.  
Com o operador de dereferência `*` é possível ler e escrever diretamente nesse endereço.

```c
float preco = 100.0f;
float *ptr = &preco;   // ptr aponta para preco
*ptr = *ptr * 1.10f;   // altera preco via ponteiro
```

Ao imprimir `preco` depois da operação, o valor já está modificado — provando que ponteiro e variável compartilham o mesmo espaço de memória.

---

### Atividade 2 — Passagem por Referência

**Conceito:** Em C não existe "passagem por referência" nativa; simulamos isso passando o *endereço* da variável para a função, que recebe um ponteiro.

```c
void aplicar_desconto(float *preco, float percentual) {
    *preco = *preco * (1.0f - percentual / 100.0f);
}

// Na main:
aplicar_desconto(&preco, 15.0f);
```

A função altera o valor original porque trabalha diretamente no endereço fornecido, não em uma cópia.

---

### Atividade 3 — Ponteiros para Structs e Operador `->`

**Conceito:** Quando temos um ponteiro para struct, usamos `->` para acessar seus campos — é equivalente a `(*ptr).campo`, mas muito mais legível.

```c
typedef struct { int id; float preco; } Produto;

void aplicar_desconto(Produto *produto, float percentual) {
    produto->preco = produto->preco * (1.0f - percentual / 100.0f);
}
```

---

### Atividade 4 — Aritmética de Ponteiros em Arrays

**Conceito:** O nome de um array é um ponteiro para seu primeiro elemento. Somar `i` ao ponteiro avança `i` posições na memória (levando em conta o tamanho do tipo automaticamente).

```c
// (ptr + i)->preco  ≡  ptr[i].preco
void imprimir_produtos(Produto *ptr, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("ID: %d  Preço: %.2f\n",
               (ptr + i)->id,
               (ptr + i)->preco);
    }
}
```

A sintaxe `ptr[i]` é apenas *açúcar sintático* para `*(ptr + i)`, mas a atividade exige o uso explícito da aritmética.

---

### Atividade 5 — Alocação Dinâmica (`malloc` / `free`)

**Conceito:** Arrays estáticos têm tamanho fixo em tempo de compilação. Com `malloc` alocamos memória em tempo de execução no *heap*, com o tamanho que o usuário informar.

```c
int n;
scanf("%d", &n);

Produto *estoque = (Produto *) malloc(n * sizeof(Produto));
// ... usa o array ...
free(estoque);   // devolve a memória ao sistema
estoque = NULL;  // boa prática: evita ponteiro dangling
```
