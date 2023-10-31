<h1 align="center"> Minitalk </h1>

<div align="center">
<img src="https://github.com/debsalbornoz/minitalk/assets/119970138/24564ded-dcd2-463f-8527-3e1fa67813d2">
</div> 
<div align="center">
<img alt="Static Badge" src="https://img.shields.io/badge/Status-Finished-green">
</div>

<h2>About </h2>


Minitalk is a lightweight communication project implemented in C programming language. It demonstrates inter-process communication between a client and a server using the concept of signals (SIGUSR1 and SIGUSR2) for interprocess communication. Signals are potent mechanisms in Unix systems enabling processes to send asynchronous notifications to one another. In the context of this project, these signals are harnessed to represent data bits. The communication is achieved by sending and receiving messages.
 
The implemented logic involves bitwise operations to ensure accuracy and reliability in message transmission. Each character of the message is broken down into individual bits and transmitted sequentially from the client to the server.


<h3>Sending Process (Client): </h3>


•Bit Conversion:


The client converts each character of the message into a sequence of bits.
Each bit is transmitted as a signal (SIGUSR1 for 0 and SIGUSR2 for 1).


•Asynchronous Transmission:


The client sends the bits one by one, awaiting confirmation from the server after each sent bit.
After sending all bits of a character, the client awaits confirmation from the server before sending the next character.


<h3>Receiving Process (Server): </h3>


•Signal Reception:


The server continuously waits for signals (SIGUSR1 or SIGUSR2).
When a signal is received, the server interprets it as a bit (0 or 1) of the character.
Character Construction:

The server constructs each character by concatenating the received bits.
When all bits of the character are received, the server displays the character on the standard output.
Confirmation to Client:

After receiving each bit, the server confirms receipt by sending a signal back to the client.
The client awaits this confirmation before sending the next bit or character.
This methodology ensures efficient and reliable communication between the client and server, showcasing the practical application of bitwise operations and signals in Unix-based interprocess communication.


<h2>How to Use: </h2>

To use the Minitalk project for interprocess communication, follow these steps:

•Clone the repository: 
```
git clone https://github.com/debsalbornoz/minitalk.git
```
•Compilation:

Compile the client and serIf you have any questions or suggestions regarding the code, feel free to contact me.ver programs separately using the provided Makefile or by running:
bash

```
gcc -o client client.c
gcc -o server server.c
```

•Run the Server:

Start the server by running the following command in one terminal window:
bash
```
./server
```

Note down the server's process ID (PID) displayed upon initialization.

•Run the Client:

Run the client in another terminal window, specifying the server's PID and the message you want to send:
bash
```
./client [server_PID] [message]
```
Replace [server_PID] with the server's PID displayed during initialization, and [message] with the text you want to send.

If you have any questions or suggestions regarding the code, feel free to contact me.
