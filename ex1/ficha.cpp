#include "ficha.hpp"
#include <sstream>

locadora_error::locadora_error(const std::string& msg)
    : std::runtime_error("[locadora] " + msg) {}

campo_error::campo_error(const std::string& campo)
    : locadora_error("campo nao encontrado: " + campo) {}

tipo_error::tipo_error(const std::string& campo)
    : locadora_error("valor nao e inteiro: " + campo) {}

ficha::ficha(const std::string& conteudo) {
    std::istringstream iss(conteudo);
    std::string linha;
    while (std::getline(iss, linha)) {
        if (linha.empty()) continue;
        
        auto pos = linha.find('=');
        if (pos != std::string::npos) {
            std::string chave = linha.substr(0, pos);
            std::string valor = linha.substr(pos + 1);
            dados[chave] = valor;
        } else {
            std::istringstream liness(linha);
            std::string chave, valor;
            if (liness >> chave >> valor) {
                dados[chave] = valor;
            }
        }
    }
}

std::string ficha::ler(const std::string& campo) const {
    auto it = dados.find(campo);
    if (it == dados.end()) {
        throw campo_error(campo);
    }
    return it->second;
}

int ficha::ler_int(const std::string& campo) const {
    std::string val_str = ler(campo);
    try {
        std::size_t pos_parsed = 0;
        int val = std::stoi(val_str, &pos_parsed);
        if (pos_parsed != val_str.length()) {
            throw tipo_error(campo);
        }
        return val;
    } catch (const std::invalid_argument&) {
        throw tipo_error(campo);
    } catch (const std::out_of_range&) {
        throw tipo_error(campo);
    }
}

std::optional<std::string> ficha::ler_seguro(const std::string& campo) const noexcept {
    auto it = dados.find(campo);
    if (it != dados.end()) {
        return it->second;
    }
    return std::nullopt;
}

std::optional<int> ficha::ler_int_seguro(const std::string& campo) const noexcept {
    try {
        return ler_int(campo);
    } catch (...) {
        return std::nullopt;
    }
}
