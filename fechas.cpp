
#include <string>

struct Fecha
 {
     int Dia;
     int Mes;
     int Anyo
 };
typedef struct Fecha FECHA;
class TPersona
{
public:
    FECHA FFechaNac;
    char FSexo
}
{
public:
    TPersona(std::string NumeroIdentdad);
     TPersona();
    Fecha getFechaNac();
    char getSexo();
};
