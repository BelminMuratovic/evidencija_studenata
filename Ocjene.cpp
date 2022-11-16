#include "Ocjene.hpp"

ocjena::ocjena(predmet *ptr, int Ocjena_)
    : ptr_predmeta{ptr}, ocjena_{Ocjena_} {}

std::string ocjena::get_predmet() const { return ptr_predmeta->get_naziv(); }

int ocjena::get_ocjena() const { return ocjena_; }