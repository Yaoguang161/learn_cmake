#ifndef Lance_hpp
#define Lance_hpp
#include <string>
#include "Usuario.hpp"

class Lance
{
private:
    Usuario usuario;
    float valor;
public:
    Lance(Usuario usuario, float valor);
    float recuperaValor() const;
    std::string recuperaNomeUsuario() const;
};

#endif /* Lance_hpp */
