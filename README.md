# Minitalk

Minitalk is a messaging project that demonstrates inter-process communication through UNIX signals (SIGUSR1 and SIGUSR2). 
The client sends a message to the server by transmitting the message bit by bit, character by character. 
The server receives each signal and reconstructs the message, printing it only once the entire message has been received.

## Features
- **Signal Communication**: Utilizes SIGUSR1 and SIGUSR2 to send bits of data.
- **Message Reconstruction**: The server stores the message in a linked list and prints it after full reception.
- **Bonus**: 
  - Acknowledgement Signal: The server sends an acknowledgment signal back to the client once it has received the entire message.
  
## How It Works
- The client sends each character of a message as a series of bits, through SIGUSR1 (bit = 0) and SIGUSR2 (bit = 1).
- The server receives the signals and builds the message, storing it until fully received.
- After receiving the full message, the server sends a confirmation signal back to the client (bonus feature).

## Usage
1. Compile the program with:
   ```make```
2. Run the server:
  ```./server```
3. Run the client to send a message:
  ```./client <server_pid> "<message>"```
