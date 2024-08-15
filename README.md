<h1 align="center">Minitalk</h1>

<div align="center">
<img src="https://github.com/debsalbornoz/minitalk/assets/119970138/24564ded-dcd2-463f-8527-3e1fa67813d2">
</div> 
<div align="center">
<img alt="Static Badge" src="https://img.shields.io/badge/Status-Finished-green">
</div>






[minitalk3.webm](https://github.com/user-attachments/assets/488ee1d8-2918-4741-949c-ef5d4b42bf88)





<h2>Sobre</h2>


O Minitalk é um projeto de comunicação implementado na linguagem de programação C. Ele demonstra a comunicação entre processos entre um cliente e um servidor usando o conceito de sinais para comunicação entre processos. Sinais são mecanismos poderosos em sistemas Unix que permitem que processos enviem notificações assíncronas uns para os outros. No contexto deste projeto, esses sinais são utilizados para representar bits de dados. A comunicação é realizada enviando e recebendo mensagens.

A lógica implementada envolve operações bit a bit para garantir a precisão e confiabilidade na transmissão de mensagens. Cada caractere da mensagem é dividido em bits individuais e transmitido sequencialmente do cliente para o servidor.



<h3>Processo de Envio (Cliente):</h3>


• **Conversão de Bits:**


O cliente converte cada caractere da mensagem em uma sequência de bits. Cada bit é transmitido como um sinal (SIGUSR1 para 0 e SIGUSR2 para 1).

• **Transmissão Assíncrona:**

O cliente envia os bits um a um, aguardando confirmação do servidor após cada bit enviado. Após enviar todos os bits de um caractere, o cliente aguarda confirmação do servidor antes de enviar o próximo caractere.



<h3>Processo de Recebimento (Servidor):</h3>


• **Recepção de Sinais:**



O servidor aguarda continuamente sinais (SIGUSR1 ou SIGUSR2). Quando um sinal é recebido, o servidor o interpreta como um bit (0 ou 1) do caractere.


• **Construção de Caracteres:**


O servidor constrói cada caractere concatenando os bits recebidos. Quando todos os bits do caractere são recebidos, o servidor exibe o caractere na saída padrão.


• **Confirmação para o Cliente:**


Após receber cada bit, o servidor confirma o recebimento enviando um sinal de volta ao cliente. O cliente aguarda essa confirmação antes de enviar o próximo bit ou caractere.

Essa metodologia garante uma comunicação eficiente e confiável entre o cliente e o servidor, demonstrando a aplicação prática de operações bit a bit e sinais em comunicação entre processos baseada em Unix.


<h2>Como Usar:</h2>


Para usar o projeto Minitalk para comunicação entre processos, siga estes passos:


• Clone o repositório:


```
git clone https://github.com/debsalbornoz/minitalk.git

```

<h2>Como Usar:</h2>

Para utilizar o projeto Minitalk para comunicação entre processos, siga estes passos:

- Clone o repositório:
    ```
    git clone https://github.com/debsalbornoz/minitalk.git
    ```

- Compilação:

    Compile os programas `client` e `server` separadamente usando o Makefile fornecido ou executando:
    ```bash
    gcc -o client client.c
    gcc -o server server.c
    ```

- **Executar o Servidor:**

    Inicie o servidor executando o seguinte comando em uma janela de terminal:
    ```bash
    ./server
    ```

    Anote o ID do processo (PID) do servidor exibido durante a inicialização.

- **Executar o Cliente:**

    Execute o cliente em outra janela de terminal, especificando o PID do servidor e a mensagem que deseja enviar:
    ```bash
    ./client [server_PID] [message]
    ```

    Substitua `[server_PID]` pelo PID do servidor exibido durante a inicialização e `[message]` pelo texto que você deseja enviar.

Se você tiver alguma dúvida ou sugestão sobre o código, sinta-se à vontade para me contatar.
