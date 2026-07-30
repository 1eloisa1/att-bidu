#include "frota.hpp"
#include <algorithm>

veiculo_duplicado::veiculo_duplicado(const std::string& placa)
    : std::runtime_error("veiculo ja registrado: " + placa) {}

void frota::registrar(const std::string& placa, float diaria) {
    if (veiculos_.find(placa) != veiculos_.end()) {
        throw veiculo_duplicado(placa);
    }
    veiculos_[placa] = diaria;
}

std::optional<float> frota::buscar(const std::string& placa) const noexcept {
    auto it = veiculos_.find(placa);
    if (it != veiculos_.end()) {
        return it->second;
    }
    return std::nullopt;
}

bool frota::remover(const std::string& placa) {
    return veiculos_.erase(placa) > 0;
}

std::vector<std::pair<std::string, float>> frota::top_n(std::size_t n) const {
    std::vector<std::pair<std::string, float>> aux(veiculos_.begin(), veiculos_.end());
    std::size_t k = std::min(n, aux.size());
    
    std::partial_sort(aux.begin(), aux.begin() + k, aux.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

    return std::vector<std::pair<std::string, float>>(aux.begin(), aux.begin() + k);
}

std::size_t frota::tamanho() const noexcept {
    return veiculos_.size();
}
