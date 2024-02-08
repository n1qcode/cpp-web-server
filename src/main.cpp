#include <iostream>

#include "boost/json.hpp"
#include "cpp_web_server.hpp"

int main()
{
    try
    {
        cpp_web_server::runServer();
        return EXIT_SUCCESS;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Fatal error \"" << ex.what() << "\"." << std::endl;
    }
    catch (...)
    {
        std::cerr << "Fatal UNKNOWN error." << std::endl;
    }
    return EXIT_FAILURE;
}
