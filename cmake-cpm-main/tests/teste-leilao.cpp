#include "catch2/catch.hpp"
#include "Leilao.hpp"
#include "Usuario.hpp"

TEST_CASE("Leilão não deve receber lances consecutivos do mesmo usuário") {
    // Arrange
    Leilao leilao("Fiat 147 0Km");
    Usuario bruno("Bruno Winkeler");
    
    Lance primeiroLance(bruno, 1000);
    Lance segundoLance(bruno, 1500);
    
    // Act
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    
    // Assert
    REQUIRE(1 == leilao.recuperaLances().size());
    REQUIRE(1000 == leilao.recuperaLances()[0].recuperaValor());
}
