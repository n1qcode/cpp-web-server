#ifndef CPP_WEB_SERVER_SRC_CPP_WEB_SERVER_HPP
#define CPP_WEB_SERVER_SRC_CPP_WEB_SERVER_HPP

#include <boost/algorithm/string/trim_all.hpp>
#include <boost/asio/awaitable.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/json.hpp>
#include <iostream>
#include <thread>
#include <vector>

namespace asio = boost::asio;
using tcp = asio::ip::tcp;

namespace cpp_web_server
{

    asio::awaitable<void> worksWithClient(tcp::socket socket);
    asio::awaitable<void> lisen();
    void runServer();

} // namespace cpp_web_server

#endif // CPP_WEB_SERVER_SRC_CPP_WEB_SERVER_HPP