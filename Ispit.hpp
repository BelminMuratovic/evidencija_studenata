#pragma once
#include <iostream>
#include "Predmet.hpp"

class ispit
{
private:
    predmet *ptr_predmeta;
    std::string datum_ispita;

public:
    ispit() = default;
    ispit(predmet *, std::string);
    std::string get_naziv() const;
};