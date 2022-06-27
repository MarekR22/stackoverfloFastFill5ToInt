#include <benchmark/benchmark.h>
#include <fillIntToStr.hpp>

template <typename ImplTag>
void fill5ToString(benchmark::State& state) {
    constexpr int data[] {0, 1, 5, 13, 43, 343, 5344, 4234, 55555, 243422342};
    for (auto _ : state) {
        for (auto x : data) {
            benchmark::DoNotOptimize(x);
            auto r = fill5::toString<ImplTag>(x);
            benchmark::DoNotOptimize(r);
        }
    }
}

using namespace fill5::tag;

BENCHMARK(fill5ToString<std_stream>);
BENCHMARK(fill5ToString<c_sprintf>);
BENCHMARK(fill5ToString<std_to_chars>);
BENCHMARK(fill5ToString<fmt>);
BENCHMARK(fill5ToString<manual>);
