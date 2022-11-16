#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Ocjene.hpp"

class student
{
private:
    std::string ime;
    std::string prezime;
    std::string grad;
    std::string broj_indeksa;
    std::map<int, std::vector<ocjena>> ocjene;

public:
    student() = default;
    student(std::string, std::string, std::string, std::string);
    void dodaj_ocjenu(int, ocjena);
    std::string get_ime() const;
    std::string get_prezime() const;
    const std::map<int, std::vector<ocjena>> &get_ocjene() const;
};