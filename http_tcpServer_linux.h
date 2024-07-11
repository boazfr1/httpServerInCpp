#ifndef INCLUDED_HTTP_TCPSERVER_LINUX
#define INCLUDED_HTTP_TCPSERVER_LINUX

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string>

namespace http
{
    class TcpServer
    {
    public:
        TcpServer(std::string ipAddress, int port);
        ~TcpServer();
        void startListen();
        
    private:
        std::string server_ip_address;
        int server_port;
        int server_socket;
        int server_new_socket;
        long server_incomingMessage;
        struct sockaddr_in server_socketAddress;
        unsigned int server_socketAddress_len;
        std::string server_serverMessage;

        int startServer();
        void closeServer();
        void acceptConnection(int &new_socket);
        void sendResponse();
        std::string buildResponse(const std::string& filePath);
    };
}

#endif