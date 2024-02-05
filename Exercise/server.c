  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <arpa/inet.h>
  #include <time.h>

  #define PORT 4000
  #define MAX_BUFFER_SIZE 1024

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
  char buffer[MAX_BUFFER_SIZE];

  // Create TCP socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
      perror("Error creating socket");
      exit(EXIT_FAILURE);
  }

  // Seting up server address structure
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Binding the socket to the address and port
  if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
      exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_socket, 5) == -1) {
      // perror("Error listening for connections");
      exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d...\n", PORT);

  // Accept a client connection
  // socklen_t client_addr_len = sizeof(client_addr);
  // client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);

  // if (client_socket == -1) {
  //     perror("Error accepting connection");
  //     exit(EXIT_FAILURE);
  // }

  printf("Client connected\n");

  // Send the current time to the client every 5 minutes
  while (1) {
      time_t current_time = time(NULL);

      snprintf(buffer, sizeof(buffer), "Current Time: %s", ctime(&current_time));
      send(client_socket, buffer, strlen(buffer), 0);

      sleep(5 * 60);  // Sleep for 5 minutes
  }

  close(server_socket);
  return 0;
}
