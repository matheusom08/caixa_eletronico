# Sistema de Caixa Eletrônico em C

Um sistema simples e funcional de Caixa Eletrônico desenvolvido em linguagem C para rodar diretamente no terminal. Este projeto foi feito para praticar conceitos como estruturas de dados (`struct`), ponteiros, passagens de parâmetros por referência e tratamento de buffers.

## 🚀 Funcionalidades

- **Ver Saldo:** Exibe o saldo atual da conta em tempo real.
- **Depósito:** Permite adicionar fundos à conta (apenas valores positivos).
- **Saque:** Permite retirar dinheiro caso haja saldo suficiente disponível.
- **Extrato:** Exibe o histórico de todas as transações realizadas durante a sessão e o saldo final.
- **Validação de Erros:** O sistema previne quebras caso o usuário digite letras ou caracteres inválidos nos menus numéricos.

## 🛠️ Como Executar o Projeto

Você precisará de um compilador C instalado na sua máquina (como o `gcc`).

1. **Abra o seu terminal ou prompt de comando.**
2. **Compile o código:**
   ```bash
   gcc main.c -o caixa_eletronico
