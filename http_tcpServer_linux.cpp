#include <http_tcpServer_linux.h>
#include <sys/socket.h>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <string>

#include "routes.h"


namespace
{
    void log(const std::string &massage){
        std::cout << massage << "\n";
    }

    void exitWithError(const std::string &error){
        log("ERROR: " + error);
        exit(1);
    }

    const int BUFFER_SIZE = 30720;

    std::string sendErrorOfNoPath(){
        std::string notFound = "<!DOCTYPE html><html lang=\"en\"><body><h1>404 Not Found</h1><p>The requested file was not found on the server.</p></body></html>";
        std::ostringstream oss;
        oss << "HTTP/1.1 404 Not Found\nContent-Type: text/html\nContent-Length: " << notFound.size() << "\n\n"
            << notFound;
        return oss.str();
    }

    std::string whichTypeOfFile(std::string filePath){
        if (filePath.find(".html") != std::string::npos) {
            return "text/html";
        } else if (filePath.find(".js") != std::string::npos) {
            return "application/javascript";
        } else if (filePath.find(".css") != std::string::npos) {
            return "text/css";
        } else {
            return "text/plain";
        }
    }

    std::string ConstructHTTPresponse(std::string &fileContent, std::string &fileType){
        std::ostringstream oss;
        oss << "HTTP/1.1 200 OK\nContent-Type: " << fileType << "\nContent-Length: " << fileContent.size() << "\n\n"
            << fileContent;
        return oss.str();
    }
}

namespace http
{
    TcpServer::TcpServer(std::string ipAddress, int port) :
        server_ip_address(ipAddress),            
        server_port(port),                       
        server_socket(),                         
        server_new_socket(),                     
        server_incomingMessage(),                
        server_socketAddress(),                  
        server_socketAddress_len(sizeof(server_socketAddress)), 
        server_serverMessage(buildResponse("./index.html"))
    {
        server_socketAddress.sin_family = AF_INET;
        server_socketAddress.sin_port = htons(server_port);
        server_socketAddress.sin_addr.s_addr = inet_addr(server_ip_address.c_str());

        if (startServer() != 0)
        {
            std::ostringstream ss;
            ss << "Failed to start server with PORT: " << ntohs(server_socketAddress.sin_port);
            log(ss.str());
        }
    }
    TcpServer::~TcpServer()
    {
        closeServer();
    }

    int TcpServer::startServer(){
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0)
        {
            exitWithError("Cannot create socket");
            return 1;
        }

        if (bind(server_socket, (sockaddr *)&server_socketAddress, server_socketAddress_len) < 0)
        {
            exitWithError("Cannot connect socket to address");
            return 1;
        }
        return 0;
    };

    void TcpServer::startListen(){
        if (listen(server_socket, 20) < 0)
        {
            exitWithError("Socket listen failed");
        }
        std::ostringstream oss;
        oss << "\n*** Listening on ADDRESS: " 
            << inet_ntoa(server_socketAddress.sin_addr) 
            << " PORT: " << ntohs(server_socketAddress.sin_port) 
            << " ***\n\n";
        log(oss.str());

        int bytesReceived;

        while (true)
        {
            log("====== Waiting for a new connection ======\n\n\n");
            acceptConnection(server_new_socket);

            char buffer[BUFFER_SIZE] = {0};
            bytesReceived = read(server_new_socket, buffer, BUFFER_SIZE);
            std::cout << "buffer = " << buffer << "\n";

            if (bytesReceived < 0)
            {
                exitWithError("Failed to read bytes from client socket connection");
            }

            std::ostringstream oss;
            oss << "------ Received Request from client ------\n\n";
            log(oss.str());

            Routes route(buffer);
            std::string path = route.getPath();
            std::string method = route.getMethod();            

            sendResponse();

            close(server_new_socket);
        }
    }

    void TcpServer::sendResponse()
    {
        server_serverMessage = buildResponse("./index.html");
        long bytesSent;

        bytesSent = write(server_new_socket, server_serverMessage.c_str(), server_serverMessage.size());

        if (bytesSent == server_serverMessage.size())
        {
            log("------ Server Response sent to client ------\n\n");
        }
        else
        {
            log("Error sending response to client");
        }
    }

    void TcpServer::acceptConnection(int &new_socket){
        new_socket = accept(server_socket, (sockaddr *)&server_socketAddress, &server_socketAddress_len);
        if (new_socket < 0)
        {
            std::ostringstream oss;
            oss << "Server failed to accept incoming connection from ADDRESS: " 
            << inet_ntoa(server_socketAddress.sin_addr) << "; PORT: " 
            << ntohs(server_socketAddress.sin_port);
            exitWithError(oss.str());
        }
    }

    std::string TcpServer::buildResponse(const std::string &filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            return sendErrorOfNoPath();
        }

        std::ostringstream fileContent;
        fileContent << file.rdbuf();
        std::string content = fileContent.str();

        std::string contentType = whichTypeOfFile(filePath);
        
        return ConstructHTTPresponse(content, contentType);
    }

    void TcpServer::closeServer(){
        close(server_socket);
        close(server_new_socket);
        exit(0);
    };
    
}