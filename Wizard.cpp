#include "pch.h"
using namespace std;
Wizard::Wizard(uint8_t id) : id(id){
    this->node = new Node();
}
Wizard::~Wizard(){
    cout << "Mago Borrado." << endl;
    delete this->node;
}

void Wizard::showInfo(){
    auto d = ThreeWizards::searchNode(ThreeWizards::root, this->id_father);
    cout << string(1, '\n');
    cout << this->name << " " << this->last_name << endl;
    cout << "---------------------------------" << endl;
    cout << "ID: " << this->id << endl;
    cout << "Gender: " << this->gender << endl;
    cout << "Age: " << this->age << endl;
    cout << "ID Father: " << this->id_father << endl;
    cout << "Is dead: " << this->is_dead << endl;
    cout << "Type magic: " << this->type_magic << endl;
    cout << "Is owner: " << this->is_owner << endl;

    if(!d) return;
    cout << "Hijo de: " << d->name << " " << d->last_name << endl;
}
