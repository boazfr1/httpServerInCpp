#include <http_tcpServer_linux.h>
#include <sys/socket.h>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <string>


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
    m_ip_address(ipAddress),            
    m_port(port),                       
    m_socket(),                         
    m_new_socket(),                     
    m_incomingMessage(),                
    m_socketAddress(),                  
    m_socketAddress_len(sizeof(m_socketAddress)), 
    m_serverMessage(buildResponse(""))    
{
    }
    TcpServer::~TcpServer()
    {
        closeServer();
    }

    int TcpServer::startServer(){
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (m_socket < 0)
        {
            exitWithError("Cannot create socket");
            return 1;
        }

        if (bind(m_socket, (sockaddr *)&m_socketAddress, m_socketAddress_len) < 0)
        {
            exitWithError("Cannot connect socket to address");
            return 1;
        }
        return 0;
    };

    void TcpServer::startListen(){
        if (listen(m_socket, 20) < 0)
        {
            exitWithError("Socket listen failed");
        }
        std::ostringstream oss;
        oss << "\n*** Listening on ADDRESS: " 
            << inet_ntoa(m_socketAddress.sin_addr) 
            << " PORT: " << ntohs(m_socketAddress.sin_port) 
            << " ***\n\n";
        log(oss.str());

        int bytesReceived;

        char buffer[BUFFER_SIZE] = {0};
        bytesReceived = read(m_new_socket, buffer, BUFFER_SIZE);
        if (bytesReceived < 0)
        {
            exitWithError("Failed to read bytes from client socket connection");
        }
    }

    void TcpServer::sendResponse()
    {
        long bytesSent;

        bytesSent = write(m_new_socket, m_serverMessage.c_str(), m_serverMessage.size());

        if (bytesSent == m_serverMessage.size())
        {
            log("------ Server Response sent to client ------\n\n");
        }
        else
        {
            log("Error sending response to client");
        }
    }

    void TcpServer::acceptConnection(int &new_socket){
        new_socket = accept(m_socket, (sockaddr *)&m_socketAddress, &m_socketAddress_len);
        if (new_socket < 0)
        {
            std::ostringstream oss;
            oss << "Server failed to accept incoming connection from ADDRESS: " 
            << inet_ntoa(m_socketAddress.sin_addr) << "; PORT: " 
            << ntohs(m_socketAddress.sin_port);
            exitWithError(oss.str());
        }
    }

    std::string TcpServer::buildResponse(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            sendErrorOfNoPath();
        }

        std::ostringstream fileContent;
        fileContent << file.rdbuf();
        std::string content = fileContent.str();

        std::string contentType = whichTypeOfFile(filePath);
        
        return ConstructHTTPresponse(content, contentType);
    }

    void TcpServer::closeServer(){
        close(m_socket);
        close(m_new_socket);
        exit(0);
    };
    
}