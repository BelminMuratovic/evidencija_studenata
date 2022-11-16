#include "Predmet.hpp"

predmet::predmet(std::string naziv_predmeta_)
    : naziv_predmeta{naziv_predmeta_} {}

std::string predmet::get_naziv() const { return naziv_predmeta; }