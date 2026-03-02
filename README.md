🏦 Caixa Eletrônico (ATM) em C
Este projeto é uma simulação de um terminal bancário desenvolvido inteiramente em C. O objetivo principal foi consolidar os fundamentos da programação, como estruturas de controle, manipulação de variáveis, funções e lógica de repetição.

🚀 Funcionalidades
O sistema opera via terminal e oferece as seguintes opções:

Consultar Saldo: Exibe o valor atual custodiado na conta.

Saque: Realiza a dedução de valores, validando se há saldo suficiente.

Depósito: Incrementa o saldo da conta com novas entradas.

Menu Interativo: Interface via linha de comando (CLI) com loop de repetição até que o usuário decida sair.

🛠️ Tecnologias e Conceitos Aplicados
Para este projeto, foquei no uso da linguagem C Standard, aplicando conceitos essenciais:

Entrada e Saída: Uso de printf e scanf para interação com o usuário.

Estruturas de Controle: if/else para validações de saldo e switch/case para o menu principal.

Laços de Repetição: do-while ou while para manter o programa rodando durante a sessão.

Variáveis e Tipos: Manipulação de tipos float ou double para lidar com valores monetários.

📂 Estrutura de Arquivos
main.c: Contém a lógica principal e o fluxo do programa.

(Opcional) funcoes.c / funcoes.h: Caso você tenha modularizado o código.

⚙️ Como Compilar e Rodar
Você precisará de um compilador de C (como o GCC) instalado em sua máquina.

Clone o repositório:

Bash
git clone https://github.com/kauavcorreia/caixa-eletronico.git
Compile o código:

Bash
gcc main.c -o caixa_eletronico
Execute o programa:

No Windows: caixa_eletronico.exe

No Linux/Mac: ./caixa_eletronico

💡 Aprendizados
Desenvolver este projeto em C permitiu uma compreensão profunda de:

Como a memória armazena valores numéricos.

A importância da inicialização correta de variáveis (evitando "lixo de memória").

Tratamento de erros simples (evitar saques maiores que o saldo).

✒️ Autor
Desenvolvido por Kauã Correia - GitHub
