#include "socket.h"
#include <string>
#include "iostream"

int main()
{
  // Tello drone IP address and socket port
  std::string destination_ip = "192.168.10.1";
  int socket_port = 8889;

  std::string tello_command = "";

  // UDPServer server(socket_port);
  UDPClient client(socket_port, destination_ip);
  client.send_message("command");

  while (true)
  {

    std::cout << "Type a command: ";
    std::cin >> tello_command;

    client.send_message(tello_command);
    std::cout << "\n";
    std::cout << tello_command;
  }
}