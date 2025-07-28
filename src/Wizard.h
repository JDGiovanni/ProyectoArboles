#pragma once
#include "pch.h"
using namespace std;

class Wizard{
    private: 
        uint16_t id; // Limite de 0-255
        
    public:
        string name;
        string last_name;
        string gender;
        uint32_t    age;
        uint16_t    id_father;
        uint16_t    is_dead : 1;
        string type_magic;
        uint16_t    is_owner : 1;
        Node*       node;

        inline uint16_t getId() { return this->id; }
        void showInfo();

        Wizard(uint8_t id);
        ~Wizard();

        bool kill();
        bool isOwner();
        bool hasDisciples();
        Wizard* getFirstDisciple();
        Wizard* getFirstDiscipleAlive();
        Wizard* getDiscipleFromTypeMagic(std::string type_magic);
        std::string getTypeMagic();
        void setOwner();
        bool isDead();
};
