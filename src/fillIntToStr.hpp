#pragma once

#include <string>

namespace fill5 {
namespace tag {
struct std_stream {};
struct std_to_chars {};
struct c_sprintf {};
struct fmt {};
struct manual {};
}

template<typename Tag>
std::string toString(int x);
}
