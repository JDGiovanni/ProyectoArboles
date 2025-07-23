#include "pch.h"
using namespace std;

int main(int argc, char** argv) {
    string input;
    cout << "magOS v1.0\n";
    cout << "--help for help\n";

    ThreeWizards school;
    const bool success = school.loadCsv"list.csv";
    cout << success ? "\nCSV cargado\n" : "Error al cargar el csv\n";

    Cli::addCommand("--help", [](vector<string> args){ 
        cout << "Menu de ayuda\n";
        cout << "--search <id> - Busca un mago especifico\n";
        cout << "--showall - Muestra todos\n";
        cout << "--showallalive - Muestra todos los vivos\n";
        cout << "--showalldead - Muestra todos los muertos\n";
        cout << "--owner - Muestra al owner\n";
        return 0;
    });
