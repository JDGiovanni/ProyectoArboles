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

Cli::addCommand("--search", [&](vector<string> args){
        if(args.size() < 2 || args.size() > 2) {
            cout << "--search <id>\n";
            return 0;
        }
        //school.showInfo(school.root);
        auto node = school.searchNode(school.root, stoi(args[1]));
        if(!node) return cout << "Mago no encontrado.\n";
        node->showInfo();
        return 0;
    });

    Cli::addCommand("--showallalive", [&](vector<string> args){
        if(args.size() != 1) {
            cout << "--showallalive\n";
            return 0;
        }
        
        school.showAllInfo(school.root, ThreeWizards::e_info_flags::SHOW_ALIVE);
        return 0;
    });

    Cli::addCommand("--showalldead", [&](vector<string> args){
        if(args.size() != 1) {
            cout << "--showdead\n";
            return 0;
        }
        
        school.showAllInfo(school.root, ThreeWizards::e_info_flags::SHOW_DEAD);
        return 0;
    });

    Cli::addCommand("--owner", [&](vector<string> args){
        if(args.size() != 1) {
            cout << "--owner\n";
            return 0;
        }
        
        school.showAllInfo(school.root, ThreeWizards::e_info_flags::SHOW_OWNER);
        return 0;
    });

    Cli::addCommand("--showall", [&](vector<string> args){
        if(args.size() != 1) {
            cout << "--showall\n";
            return 0;
        }
        
        school.showAllInfo(school.root, 
            ThreeWizards::e_info_flags::SHOW_ALIVE | 
            ThreeWizards::e_info_flags::SHOW_DEAD | 
            ThreeWizards::e_info_flags::SHOW_OWNER
        );
        return 0;
    });

    cout << ">> ";
    do{
        vector<string> args;
        getline(cin, input);

        stringstream   parse(input);
        string         param;
        
        while(getline(parse, param, ' '))
            args.push_back(param);

        cout << string(1, '\n');

        if(Cli::find(args[0])) Cli::commands[args[0]](args);
        else cout << "Command not found\n";

        cout << "\n>> ";
    }while(true);
    return 0;
}
