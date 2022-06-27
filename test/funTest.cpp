#include <catch2/catch_all.hpp>

#include <fillIntToStr.hpp>

TEST_CASE("strTest")
{
    auto [in, expected] = GENERATE(table<int, std::string>({
        { 0, "00000" },
        { 1, "00001" },
        { 20, "00020" },
        { 9999, "09999" },
        { 99999, "99999" },
        { 2147483647, "2147483647" },
    }));
    
    using namespace fill5::tag;
    CHECK(fill5::toString<std_stream>(in) == expected);
    CHECK(fill5::toString<c_sprintf>(in) == expected);
    CHECK(fill5::toString<std_to_chars>(in) == expected);
    CHECK(fill5::toString<fmt>(in) == expected);
    CHECK(fill5::toString<manual>(in) == expected);
}
