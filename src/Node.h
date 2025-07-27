#pragma once
#include "pch.h"

class Wizard;
struct Node{
    Wizard* prev; 
    Wizard* next; 
    
    Node();
    ~Node();
};
