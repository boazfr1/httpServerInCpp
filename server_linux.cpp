#include <http_tcpServer_linux.h>

int main()
{
    http::TcpServer server = http::TcpServer("0.0.0.0", 8080);
    return 0;
}