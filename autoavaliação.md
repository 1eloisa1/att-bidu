# Autoavaliação e Declaração de LLM

## Declaração de Uso de LLM
Usei o LLM Gemini para auxiliar na estruturação das exceções do Ex1, sintaxe dos algoritmos STL do Ex2 e na implementação de partial_sort no Ex3.

---

## Exercício 1 Autoavaliação
- [x] `campo_error` e `tipo_error` herdam de `locadora_error` e incluem o nome do campo no `what()`
  → Ambas derivam de `locadora_error` repassando o nome do campo formatado no construtor.
- [x] `ler()` lança `campo_error`; `ler_int()` lança `campo_error` OU `tipo_error` conforme o caso
  → `ler()` lança `campo_error` se a chave não existir; `ler_int()` chama `ler()` e trata `std::stoi` relançando `tipo_error`.
- [x] `ler_seguro()` e `ler_int_seguro()` são `noexcept` e retornam `nullopt` em caso de falha
  → Implementados com `noexcept` e blocos de captura para retornar `std::nullopt`.
- [x] Captura em cascata: `campo_error` antes de `locadora_error` no bloco `catch`
  → Ordem respeitada conforme fornecido no `main.cpp`.

---

## Exercício 2 Autoavaliação
- [x] Nenhuma função contém loop `for` ou `while` — apenas algoritmos STL
  → Implementadas apenas com `std::max_element`, `std::accumulate`, `std::transform`, `std::copy_if` e `std::count_if`.
- [x] `normalizar()` lança `std::domain_error` quando `pico == 0`
  → Verificação do valor de pico com lançamento explícito de `std::domain_error`.
- [x] `dias_intensos()` usa `std::copy_if` + `std::back_inserter`
  → Implementação direta utilizando essa combinação de algoritmo e inseridor.
- [x] Todas as 5 funções produzem o resultado correto para o buffer do `main()`
  → Lógica testada e compatível com as saídas esperadas do enunciado.

---

## Exercício 3 Autoavaliação
- [x] `registrar()` usa `unordered_map` O(1) médio e lança `veiculo_duplicado` se a placa já existe
  → Utiliza `std::unordered_map` interno e verifica duplicatas com `find()`.
- [x] `buscar()` é `noexcept` e retorna `std::nullopt` quando não encontra
  → Marcado com `noexcept` e retorna `std::nullopt` em caso de falha na busca.
- [x] `top_n()` usa `std::partial_sort` (ou similar) — sem ordenar o mapa original
  → Cópia auxiliar ordenada via `std::partial_sort` mantendo o mapa intacto.
- [x] `remover()` retorna `true` se o veículo existia, `false` se não existia
  → Retorna o resultado lógico de `veiculos_.erase(placa) > 0`.
- [x] Todos os 4 métodos produzem a saída esperada no `main()`
  → Todas as assinaturas e comportamentos atendem o fluxo exigido no `main.cpp`.
