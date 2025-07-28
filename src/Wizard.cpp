#include "pch.h"
using namespace std;
Wizard::Wizard(uint8_t id) : id(id){
    this->node = new Node();
}
Wizard::~Wizard(){
    cout << "Mago Borrado." << endl;
    delete this->node;
}

bool Wizard::hasDisciples(){
    return this->node->next != nullptr || this->node->prev != nullptr;
}

Wizard* Wizard::getFirstDisciple(){
    return this->node->next != nullptr ? this->node->next : this->node->prev;
}

Wizard* Wizard::getFirstDiscipleAlive(){
    for(uint16_t i = 0; i < 2; i++){
        if(this->node->next && !this->node->next->is_dead) return this->node->next;
        if(this->node->prev && !this->node->prev->is_dead) return this->node->prev;
    }
    return nullptr;
}

std::string Wizard::getTypeMagic(){
    return this->type_magic;
}

void Wizard::setOwner(){
    this->is_owner = 1;
}

bool Wizard::isDead(){
    return this->is_dead;
}

Wizard* Wizard::getDiscipleFromTypeMagic(std::string type_magic){
    if(this->node->next && this->node->next->type_magic == type_magic) return this->node->next;
    if(this->node->prev && this->node->prev->type_magic == type_magic) return this->node->prev;
    return nullptr;
}

bool Wizard::kill(){
    if(this->isDead()) return std::printf("Este mago ya esta muerto.\n");
    this->is_dead = 1;

    //Si el mago es el dueño y tiene discipulos
    if(this->isOwner() && this->hasDisciples()){
        Wizard* disciple = this->getFirstDiscipleAlive();

        //Si no tiene discipulos vivos
        if(!disciple) {
            return std::printf("No hay discipulos vivos\n");
        }
        
        if(disciple->getTypeMagic() == "elemental" || disciple->getTypeMagic() == "unique"){
            //Se le da owner al discipulo con (elemental o unique)
            disciple->setOwner();
            std::printf("Se le dio owner al discipulo: %s %s con magia %s\n", 
                disciple->name.c_str(), disciple->last_name.c_str(), disciple->getTypeMagic().c_str()
            );
        }else{
            //Se le da owner al discipulo con (mixed) si existe alguno.
            Wizard* disciple_mixed = this->getDiscipleFromTypeMagic("mixed");
            if(!disciple_mixed){
                disciple_mixed->setOwner();
            }else{
                //de lo contrario busca al primer hombre vivo
                Wizard* first_alive = ThreeWizards::getFirstAlive(ThreeWizards::root); 
                if(!first_alive) {
                    std::printf("No hay discipulos vivos\n");
                }else{
                    first_alive->setOwner();
                    std::printf("Se le dio owner al primer hombre vivo: %s %s\n", first_alive->name.c_str(), first_alive->last_name.c_str());
                }
            }
        }
    }
    return true;
}

bool Wizard::isOwner(){
    return this->is_owner == 1;
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
