#pragma once
#include <optional>
#include <stdexcept>
#include <string>
#include <unordered_map>

class locadora_error : public std::runtime_error {
public:
    explicit locadora_error(const std::string& msg);
};

class campo_error : public locadora_error {
public:
    explicit campo_error(const std::string& campo);
};

class tipo_error : public locadora_error {
public:
    explicit tipo_error(const std::string& campo);
};

class ficha {
    std::unordered_map<std::string, std::string> dados;
public:
    explicit ficha(const std::string& conteudo);
    std::string ler(const std::string& campo) const;
    int ler_int(const std::string& campo) const;
    std::optional<std::string> ler_seguro(const std::string& campo) const noexcept;
    std::optional<int> ler_int_seguro(const std::string& campo) const noexcept;
};
