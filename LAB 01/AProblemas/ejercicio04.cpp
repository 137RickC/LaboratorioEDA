#include <iostream>
using namespace std;
enum DiaSemana {
    LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
};
void tipoDia(DiaSemana d) {
    if (d >= LUNES && d <= VIERNES) {
        cout << "Es dia laborable" << endl;
    } else {
        cout << "Es fin de semana" << endl;
    }
}
int main() {
    tipoDia(LUNES);
    tipoDia(SABADO);
    tipoDia(MIERCOLES);

    return 0;
}