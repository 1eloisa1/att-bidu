#pragma once
#include <vector>

using saldo_t = std::vector<float>;

float maior_movimento(const saldo_t& s);
float giro_medio(const saldo_t& s);
saldo_t normalizar(const saldo_t& s);
saldo_t dias_intensos(const saldo_t& s, float limite = 10.0f);
int inversoes(const saldo_t& s);
