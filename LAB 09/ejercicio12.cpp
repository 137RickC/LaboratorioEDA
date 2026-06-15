#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

// Implementación simple tipo LinkedHashMap
class LinkedHashMap {
private:
    list<pair<string, string>> order;
    unordered_map<string, list<pair<string, string>>::iterator> map;
public:
    // Insertar elemento
    void put(string key, string value) {
        // Si ya existe, se elimina primero
        if (map.find(key) != map.end()) {
            order.erase(map[key]);
        }

        order.push_back({key, value});
        auto it = order.end();
        --it;

        map[key] = it;
    }
    // Obtener valor
    string get(string key) {
        if (map.find(key) == map.end())
            return "NULL";

        return map[key]->second;
    }

    // Tamaño
    int size() { return order.size(); }
    // Vacío
    bool isEmpty() { return order.empty(); }
    // Contiene clave
    bool containsKey(string key) {
        return map.find(key) != map.end();
    }
    // Contiene valor
    bool containsValue(string value) {
        for (auto &p : order) {
            if (p.second == value)
                return true;
        }

        return false;
    }
    // Eliminar
    string remove(string key) {

        if (map.find(key) == map.end())
            return "";

        auto it = map[key];
        string val = it->second;

        order.erase(it);
        map.erase(key);

        return val;
    }
    // Imprimir (manteniendo orden de inserción)
    void print() {
        cout << "{ ";

        for (auto &p : order) {
            cout << p.first << "=" << p.second << " ";
        }

        cout << "}" << endl;
    }
};
// Programa principal
int main() {
    LinkedHashMap lhm;

    lhm.put("uno", "practice.geeksforgeeks.org");
    lhm.put("dos", "code.geeksforgeeks.org");
    lhm.put("cuatro", "www.geeksforgeeks.org");

    // Imprime en orden de inserción
    lhm.print();

    cout << "Obteniendo valor para la clave 'uno': "
         << lhm.get("uno") << endl;

    cout << "Tamaño del mapa: " << lhm.size() << endl;

    cout << "¿Esta vacio el mapa? " << lhm.isEmpty() << endl;

    cout << "Contains key 'dos'? "
         << lhm.containsKey("dos") << endl;

    cout << "Contiene el valor 'practice.geeksforgeeks.org'? "
         << lhm.containsValue("practice.geeksforgeeks.org") << endl;

    cout << "Eliminando elemento 'uno': "
         << lhm.remove("uno") << endl;

    lhm.print();

    return 0;
}
