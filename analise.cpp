#include "analise.hpp"
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stdexcept>

float maior_movimento(const saldo_t& s) {
    if (s.empty()) return 0.0f;
    auto it = std::max_element(s.begin(), s.end(), [](float a, float b) {
        return std::abs(a) < std::abs(b);
    });
    return *it;
}

float giro_medio(const saldo_t& s) {
    if (s.empty()) return 0.0f;
    float soma = std::accumulate(s.begin(), s.end(), 0.0f, [](float acc, float v) {
        return acc + std::abs(v);
    });
    return soma / static_cast<float>(s.size());
}

saldo_t normalizar(const saldo_t& s) {
    float pico = std::abs(maior_movimento(s));
    if (pico == 0.0f) throw std::domain_error("pico e zero");
    saldo_t res(s.size());
    std::transform(s.begin(), s.end(), res.begin(), [pico](float v) { return v / pico; });
    return res;
}

saldo_t dias_intensos(const saldo_t& s, float limite) {
    saldo_t res;
    std::copy_if(s.begin(), s.end(), std::back_inserter(res), [limite](float v) { return v > limite; });
    return res;
}

int inversoes(const saldo_t& s) {
    if (s.size() < 2) return 0;
    saldo_t prods(s.size() - 1);
    std::transform(s.begin() + 1, s.end(), s.begin(), prods.begin(), std::multiplies<float>());
    return static_cast<int>(std::count_if(prods.begin(), prods.end(), [](float p) { return p < 0.0f; }));
}
