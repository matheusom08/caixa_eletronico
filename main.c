#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERACOES 100
#define TAM_TEXTO 50

typedef struct {
    float saldo;
    char historico[MAX_OPERACOES][TAM_TEXTO];
    int total_operacoes;
} ContaBancaria;

void ver_saldo(ContaBancaria *conta) {
    printf("\n--- Saldo Atual ---\n");
    printf("R$ %.2f\n", conta->saldo);
    printf("-------------------\n");
}

void depositar(ContaBancaria *conta) {
    float valor;
    printf("Digite o valor para deposito: R$ ");
    
    if (scanf("%f", &valor) != 1) {
        printf("\n[Erro] Entrada invalida. Digite apenas numeros.\n");
        while (getchar() != '\n'); 
        return;
    }

    if (valor > 0) {
        conta->saldo += valor;
        if (conta->total_operacoes < MAX_OPERACOES) {
            sprintf(conta->historico[conta->total_operacoes], "Deposito: + R$ %.2f", valor);
            conta->total_operacoes++;
        }
        printf("\nDeposito de R$ %.2f realizado com sucesso!\n", valor);
    } else {
        printf("\n[Erro] O valor do deposito deve ser maior que zero.\n");
    }
}

void sacar(ContaBancaria *conta) {
    float valor;
    printf("Digite o valor para saque: R$ ");
    
    if (scanf("%f", &valor) != 1) {
        printf("\n[Erro] Entrada invalida. Digite apenas numeros.\n");
        while (getchar() != '\n'); 
        return;
    }

    if (valor > 0) {
        if (valor <= conta->saldo) {
            conta->saldo -= valor;
            if (conta->total_operacoes < MAX_OPERACOES) {
                sprintf(conta->historico[conta->total_operacoes], "Saque:    - R$ %.2f", valor);
                conta->total_operacoes++;
            }
            printf("\nSaque de R$ %.2f realizado com sucesso!\n", valor);
        } else {
            printf("\n[Erro] Saldo insuficiente para realizar este saque.\n");
        }
    } else {
        printf("\n[Erro] O valor do saque deve ser maior que zero.\n");
    }
}

void ver_extrato(ContaBancaria *conta) {
    printf("\n--- Extrato ---\n");
    if (conta->total_operacoes == 0) {
        printf("Nenhuma movimentacao realizada.\n");
    } else {
        for (int i = 0; i < conta->total_operacoes; i++) {
            printf("%s\n", conta->historico[i]);
        }
    }
    printf("---------------\n");
    printf("Saldo final: R$ %.2f\n", conta->saldo);
    printf("---------------\n");
}

int main() {
    ContaBancaria minha_conta;
    minha_conta.saldo = 0.0;
    minha_conta.total_operacoes = 0;

    int opcao;

    do {
        printf("\n========================\n");
        printf("    CAIXA ELETRONICO    \n");
        printf("========================\n");
        printf("1 - Ver Saldo\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("4 - Ver Extrato\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\n[Erro] Opcao invalida. Digite um numero do menu.\n");
            while (getchar() != '\n'); 
            opcao = -1; 
            continue;
        }

        switch (opcao) {
            case 1: ver_saldo(&minha_conta); break;
            case 2: depositar(&minha_conta); break;
            case 3: sacar(&minha_conta); break;
            case 4: ver_extrato(&minha_conta); break;
            case 0: printf("\nObrigado por utilizar nosso Caixa Eletronico. Ate logo!\n"); break;
            default: printf("\n[Erro] Opcao invalida. Tente novamente.\n"); break;
        }

    } while (opcao != 0);

    return 0;
}
