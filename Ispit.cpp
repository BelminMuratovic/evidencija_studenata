#include "Ispit.hpp"
#include "Predmet.hpp"

ispit::ispit(predmet *ptr_predmeta_, std::string datum_ispita_)
    : ptr_predmeta{ptr_predmeta_}, datum_ispita{datum_ispita_} {}

std::string ispit::get_naziv() const { return ptr_predmeta->get_naziv(); }