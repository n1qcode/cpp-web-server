#include "cpp_web_server.hpp"

namespace cpp_web_server
{

    asio::awaitable<void> worksWithClient(tcp::socket socket)
    {
        asio::streambuf buffer;
        co_await asio::async_read_until(socket, buffer, "\n", asio::use_awaitable);

        std::string name{asio::buffer_cast<const char *>(buffer.data()),
                         buffer.size()};
        boost::trim(name);

        std::cout << "CLIENT NAME:: " << name << std::endl;
        buffer.consume(buffer.size());
    }

    const auto port = 3005;

    asio::awaitable<void> lisen()
    {
        const auto executor = co_await asio::this_coro::executor;
        tcp::acceptor acceptor{executor, {tcp::v4(), port}};
        // throw std::runtime_error{"Error::lisen"};
        for (;;)
        {
            tcp::socket socket =
                co_await acceptor.async_accept(asio::use_awaitable);
            asio::co_spawn(executor, worksWithClient(std::move(socket)),
                           asio::detached);
        }
    }

    void runServer()
    {
        std::cout << "Thread::id " << std::this_thread::get_id()
                  << " Running server..." << std::endl;

        asio::io_context ioContext;

        asio::co_spawn(ioContext, lisen, asio::detached);
        ioContext.run();

        std::cout << "Thread::id " << std::this_thread::get_id()
                  << " Running stoped." << std::endl;
    }
} // namespace cpp_web_server
