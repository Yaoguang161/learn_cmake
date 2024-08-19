#include "catch2/catch.hpp"
#include "Usuario.hpp"

TEST_CASE("Usuário deve saber informar seu primeiro nome") {
    Usuario bruno("Bruno Winkeler");

    std::string primeiroNome = bruno.recuperaPrimeiroNome();

    REQUIRE("Bruno" == primeiroNome);
}
