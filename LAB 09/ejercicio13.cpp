#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Simulación de ConcurrentHashMap (sin concurrencia real)
class ConcurrentHashMap {
private:
    unordered_map<int, string> m;
public:
    // put
    void put(int key, string value) { m[key] = value; }
    // putIfAbsent
    void putIfAbsent(int key, string value) {
        if (m.find(key) == m.end()) {
            m[key] = value;
        }
    }
    // remove con validación de valor
    void remove(int key, string value) {
        if (m.find(key) != m.end() && m[key] == value) {
            m.erase(key);
        }
    }
    // replace con validación
    void replace(int key, string oldValue, string newValue) {
        if (m.find(key) != m.end() && m[key] == oldValue) {
            m[key] = newValue;
        }
    }
    // imprimir
    void print() {
        cout << "ConcurrentHashMap: { ";

        for (auto &p : m) {
            cout << p.first << "=" << p.second << " ";
        }

        cout << "}" << endl;
    }
};

int main() {
    ConcurrentHashMap m;

    m.put(100, "Hola");
    m.put(101, "Geeks");
    m.put(102, "Geeks");
    // Impresión inicial
    m.print();
    // putIfAbsent
    m.putIfAbsent(101, "Hello");
    m.print();
    // remove con validación
    m.remove(101, "Geeks");
    m.print();
    // replace con validación
    m.replace(100, "Hola", "Para");

    m.print();

    return 0;
}
