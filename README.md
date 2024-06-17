# 42-minitalk
### Introduction and Requirements
This project is a small data exchange (client-server) program using UNIX signals.

A communication program should be created in the form of a client and a server.

- The server must be started first. After its launch, it has to print its PID.
- The client takes two parameters:
    - The server PID.
    - The string to send.
- The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
- The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
- Your server should be able to receive strings from several clients in a row without needing to restart.
- The communication between your client and your server has to be done only using UNIX signals.
- You can only use these two signals: SIGUSR1 and SIGUSR2.

### How to run the program

- use `make` to compile both client and server
- start `./server` first: The PID will be displayed on the stdout
- the client takes two arguments: the server PID and a string to send. Run it in a second terminal like so: `./client_bonus {process_id} {your_message}`.

Example:
```shell
./client 325432 "Hello world!"
```
