# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

//struct para manter os dados do cliente
typedef struct{
    int senha;
    float saldo;
} Cliente; // nome da struct   

//limpeza de buffer para evitar problemas com scanf
void limpar_buffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}     

//grava saldo do cliente em um arquivo para persistência de dados
void gravar_saldo(Cliente cliente) {
    FILE *f = fopen("saldo_cliente.txt", "w");

    if (f == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }
    fprintf(f, "%.2f\n", cliente.saldo);
    fclose(f);

}

//busca saldo do cliente em um arquivo para persistência de dados
float buscar_saldo() {
    FILE *f = fopen("saldo_cliente.txt", "r");
    float saldo = 0.0;

    if (f == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 0.0;
    }
    fscanf(f, "%f", &saldo);
    fclose(f);
    return saldo;
}


int main(){
    Cliente cliente1; // criando uma variável do tipo Cliente
    cliente1.senha = 1234; 
    cliente1.saldo = buscar_saldo(); // inicializa o saldo com o valor do arquivo
    

    while (true) {
        printf("Simulador de Caixa Eletrônico!\n");

         //sistema de autenticação
        int senha_input;
        int tentativas = 0;
        while (tentativas < 3) {
        
        printf("Digite sua senha para continuar: ");
        scanf("%d", &senha_input);
        
        if (senha_input != cliente1.senha) {
            printf("Senha incorreta. Tente novamente.\n");
            tentativas++;
        } 
        
        else {
         // Senha correta, sai do loop de tentativas
        
        printf("OPÇÕES:\n");
        printf("1 - Consultar Saldo\n");
        printf("2 - Sacar\n");
        printf("3 - Depositar\n");
        printf("4 - Sair\n");
        printf("Digite a opção desejada: ");

        int opcao;
        scanf("%d", &opcao);
        limpar_buffer(); // Limpa o buffer após ler a opção

        switch (opcao) {
            
            case 1:
                printf("Você escolheu Consultar Saldo.\n");
                printf("Seu saldo atual é: %.2f\n", cliente1.saldo);
                break;

            case 2:
                printf("Você escolheu Sacar.\n");
                float valor_saque;
                printf("Digite o valor que deseja sacar: ");
                scanf("%f", &valor_saque);
                
                if (valor_saque > cliente1.saldo) {
                    printf("Saldo insuficiente para realizar o saque.\n");
                } else {
                    cliente1.saldo -= valor_saque;
                    printf("Saque realizado com sucesso! Novo saldo: %.2f\n", cliente1.saldo);

                    if (cliente1.saldo < 0) {
                        printf("Atenção: Seu saldo está negativo. Por favor, regularize sua conta o mais rápido possível.\n");
                    }
                }
                break;

            case 3:
                printf("Você escolheu Depositar.\n");
                float valor_deposito;
                if (valor_deposito <= 0) {
                    printf("Valor de depósito inválido. Por favor, insira um valor positivo.\n");
                }
                 else {
                printf("Digite o valor que deseja depositar: ");
                scanf("%f", &valor_deposito);
                
                cliente1.saldo += valor_deposito;
                gravar_saldo(cliente1); // Atualiza o saldo no arquivo
                printf("Depósito realizado com sucesso! Novo saldo: %.2f\n", cliente1.saldo);
                }
                limpar_buffer();
                break;
                 

            case 4:
                printf("Saindo do sistema. Obrigado por usar nosso serviço!\n");
                return 0; // Encerra o programa
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");

            
        } 

        while (true) {
            printf("Deseja realizar outra operação? (s/n): ");
            char resposta;
            scanf(" %c", &resposta); // Note o espaço antes de %c para consumir o newline

            if (resposta == 's' || resposta == 'S') {
                break; // Volta para o início do loop principal
            }
            
            else if (resposta == 'n' || resposta == 'N') {
                printf("Saindo do sistema. Obrigado por usar nosso serviço!\n");
                return 0; // Encerra o programa
            }
            
            else {
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            }
        }

       
    }

 }
return 0;
}
}


