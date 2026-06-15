#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Crear una tabla hash (equivalente a Hashtable en Java)
    unordered_map<int, string> hm;

    // Insertar valores
    hm[1] = "Geeks";
    hm[12] = "paraGeeks";
    hm[15] = "Una computadora";
    hm[3] = "Portal";

    // Imprimir la tabla hash
    cout << "{ ";

    for (auto it = hm.begin(); it != hm.end(); ++it) {
        cout << it->first << "=" << it->second << " ";
    }

    cout << "}" << endl;

    return 0;
}
