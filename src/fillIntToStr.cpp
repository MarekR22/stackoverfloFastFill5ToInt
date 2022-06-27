#include "fillIntToStr.hpp"
#include <fmt/format.h>
#include <sstream>
#include <charconv>
#include <iomanip>

namespace fill5 {
namespace {
constexpr auto width = 5;
constexpr auto fill = '0';

std::string strBuf() {
    std::string r;
    r.resize(r.capacity());
    return r;
}
}

template<>
std::string toString<tag::std_stream>(int x)
{
    std::ostringstream r;
    r << std::setw(width) << std::setfill(fill) << x;
    return r.str();
}

template<>
std::string toString<tag::std_to_chars>(int value)
{
    auto r = strBuf();
    auto x = std::to_chars(r.data(), r.data() + r.size(), value);
    r.resize(x.ptr - r.data());
    if (r.size() < width) {
        r.insert(0, width - r.size(), fill);
    }
    return r;
}

template<>
std::string toString<tag::c_sprintf>(int value)
{
    auto r = strBuf();
    r.resize(std::sprintf(r.data(), "%05d", value));
    return r;
}

template<>
std::string toString<tag::fmt>(int value)
{
    return fmt::format("{:05}", value);
}

template<>
std::string toString<tag::manual>(int value)
{
    std::string r(5, '0');
    char* s = r.data() + 4;
    do
    {
        *s-- = char(value % 10) + '0';
        value /= 10;
    } while (value > 0);
    return r;
}
}
