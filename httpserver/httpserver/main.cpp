#include "httplib.h"

#include <string>

using namespace httplib;

const std::string host = "0.0.0.0";
constexpr int port = 8500;

int main()
{
    Server server;
    
    // Сервер не отвечает клиенту (обработка запроса крутится в бесконечном цикле)
    {
        server.Get("/v1/health/service/config-service", [&](const Request& request, Response &response) {
            std::cout << "Request: " << request.path << std::endl;
            std::cout << "infinite loop" << std::endl;
            while (true);
        });
    }
    
    // Сервер принимает запрос от клиента и отключается, не отвечая клиенту
    /*
    {
        server.Get("/v1/health/service/config-service", [&](const Request& request, Response &response) {
            std::cout << "Request: " << request.path << std::endl;
            std::cout << "exit" << std::endl;
            exit(1);
        });
    }
    */
    
    std::cout << "Server start" << std::endl;
    server.listen(host, port);
    return 0;
}
