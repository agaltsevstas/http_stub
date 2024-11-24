#include "httplib.h"

#include <string>

const std::string host = "localhost";
constexpr int port = 8500;

int main()
{
    httplib::Client client(host, port);
    std::cout << "Client start" << std::endl;
    if (auto result = client.Get("/v1/health/service/config-service"))
    {
        std::cout << result->status << std::endl;
        std::cout << result->get_header_value("Content-Type") << std::endl;
        std::cout << result->body << std::endl;
    }
    else
    {
        std::cout << "error code: " << result.error() << std::endl;
    }
    return 0;
}
