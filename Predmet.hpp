#pragma once
#include <iostream>

class predmet
{
private:
    std::string naziv_predmeta;

public:
    predmet() = default;
    predmet(std::string);
    std::string get_naziv() const;
};