<h1 align="center">Minitalk</h1>

<div align="center">
<img src="https://github.com/debsalbornoz/minitalk/assets/119970138/24564ded-dcd2-463f-8527-3e1fa67813d2">
</div>

<div align="center">
<img alt="Static Badge" src="https://img.shields.io/badge/Status-Finished-green">
<img alt="Static Badge" src="https://img.shields.io/badge/42-Project-blue">
<img alt="Static Badge" src="https://img.shields.io/badge/Language-C-lightgrey">
</div>

## Demo

[minitalk3.webm](https://github.com/user-attachments/assets/488ee1d8-2918-4741-949c-ef5d4b42bf88)

## About

**Minitalk** is a communication project implemented in C. It demonstrates inter-process communication (IPC) between a client and a server using **UNIX signals**. Signals are a powerful mechanism in Unix systems that allow processes to send asynchronous notifications to one another — in this project, they're used to represent individual bits of data. Communication happens by sending and receiving messages one bit at a time.

The logic relies on bitwise operations to ensure precision and reliability in message transmission. Each character of the message is broken down into individual bits and transmitted sequentially from client to server.

### Sending Process (Client)

- **Bit conversion** — the client converts each character of the message into a sequence of bits. Each bit is transmitted as a signal (`SIGUSR1` for `0` and `SIGUSR2` for `1`).
- **Asynchronous transmission** — the client sends bits one at a time, waiting for the server's acknowledgment after each bit. Once all the bits of a character have been sent, the client waits for confirmation before sending the next character.

### Receiving Process (Server)

- **Signal reception** — the server continuously listens for signals (`SIGUSR1` or `SIGUSR2`). Upon receiving a signal, it interprets it as a bit (`0` or `1`) of the character being built.
- **Character reconstruction** — the server builds each character by concatenating the received bits. Once all the bits of a character have been received, it prints the character to standard output.
- **Client acknowledgment** — after receiving each bit, the server confirms receipt by sending a signal back to the client. The client waits for this acknowledgment before sending the next bit or character.

This approach ensures efficient and reliable communication between client and server, demonstrating a practical application of bitwise operations and signal-based IPC on Unix.

## Table of Contents

- [How to Use](#how-to-use)

## How to Use

To use the Minitalk project for inter-process communication, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/debsalbornoz/minitalk.git
    ```

2. Build the project:

    Compile the `client` and `server` programs separately using the provided Makefile, or by running:

    ```bash
    gcc -o client client.c
    gcc -o server server.c
    ```

3. **Run the server:**

    Start the server by running the following command in a terminal window:

    ```bash
    ./server
    ```

    Note the server's process ID (PID) displayed on startup.

4. **Run the client:**

    Run the client in another terminal window, specifying the server's PID and the message you want to send:

    ```bash
    ./client [server_PID] [message]
    ```

    Replace `[server_PID]` with the PID shown when the server started, and `[message]` with the text you want to send.

If you have any questions or suggestions about the code, feel free to reach out.

---

<p align="center">Built as part of the 42 curriculum 🖥️</p>
