#pragma once
#include <iostream>
#include "Predmet.hpp"

class ocjena
{
private:
    predmet *ptr_predmeta;
    int ocjena_;

public:
    ocjena() = default;
    ocjena(predmet *, int);
    std::string get_predmet() const;
    int get_ocjena() const;
};