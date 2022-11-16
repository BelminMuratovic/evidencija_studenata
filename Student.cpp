#include "Student.hpp"

student::student(std::string ime_, std::string prezime_, std::string grad_, std::string indeks_)
    : ime{ime_}, prezime{prezime_}, grad{grad_}, broj_indeksa{indeks_} {}

void student::dodaj_ocjenu(int datum, ocjena ocjena_)
{
    ocjene[datum].push_back(ocjena_);
}

std::string student::get_ime() const { return ime; }

std::string student::get_prezime() const { return prezime; }

const std::map<int, std::vector<ocjena>> &student::get_ocjene() const { return ocjene; }