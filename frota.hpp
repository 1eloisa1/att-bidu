#pragma once
#include <unordered_map>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

class veiculo_duplicado : public std::runtime_error {
public:
    explicit veiculo_duplicado(const std::string& placa);
};

class frota {
    std::unordered_map<std::string, float> veiculos_;
public:
    void registrar(const std::string& placa, float diaria);
    std::optional<float> buscar(const std::string& placa) const noexcept;
    bool remover(const std::string& placa);
    std::vector<std::pair<std::string, float>> top_n(std::size_t n) const;
    std::size_t tamanho() const noexcept;
};
