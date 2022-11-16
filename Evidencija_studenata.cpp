#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include "Student.hpp"
#include "Ispit.hpp"
#include "Predmet.hpp"
#include "Ocjene.hpp"
#include "Ocjene.hpp"

int main(int argc, char const *argv[])
{
    size_t choice;
    std::unordered_map<std::string, student> studenti;
    std::unordered_map<std::string, predmet> predmeti;
    std::unordered_map<std::string, std::unordered_map<std::string, ispit>> ispiti;
    std::unordered_map<std::string, std::unordered_map<std::string, ocjena>> rezultati_ispita;

    while (true)
    {
        std::cout << std::endl;
        std::cout << "1. Dodaj novog studenta" << std::endl;
        std::cout << "2. Dodaj novi ispit" << std::endl;
        std::cout << "3. Dodaj novi predmet" << std::endl;
        std::cout << "4. Dodaj novi rezultat ispita" << std::endl;
        std::cout << "5. Dohvati sve ispite za odredjeni datum" << std::endl;
        std::cout << "6. Dohvati po datumu i imenu predmeta, sve studente koji su polozili odredjeni ispit" << std::endl;
        std::cout << "7. Dohvati po indeksu sve ispite koje je polozio student hronoloski, te prosjecnu ocjenu" << std::endl;
        std::cin >> choice;
        if (choice == 1)
        {
            std::string ime;
            std::string prezime;
            std::string grad;
            std::string indeks;
            std::cout << "Ime studenta:  ";
            std::cin.ignore(1, '\n');
            std::getline(std::cin, ime);
            std::cout << "Prezime studenta:  ";
            std::getline(std::cin, prezime);
            std::cout << "Grad:  ";
            std::getline(std::cin, grad);
            std::cout << "Broj indeksa:  ";
            std::cin >> indeks;
            student Student(ime, prezime, grad, indeks);
            studenti[indeks] = Student;
        }
        else if (choice == 2)
        {
            std::string naziv;
            std::string datum;
            std::cout << "Naziv predmeta:  ";
            std::cin.ignore(1, '\n');
            std::getline(std::cin, naziv);
            std::cout << "Datum ispita (DD.MM.GGGG.):  ";
            std::cin >> datum;
            auto i = predmeti.find(naziv);
            if (i == predmeti.end())
                std::cout << "Uneseni predmet ne postoji" << std::endl;
            else
            {
                auto it = ispiti.find(datum);
                if (it == ispiti.end())
                {
                    ispit Ispit(&(i->second), datum);
                    ispiti[datum][naziv] = Ispit;
                }
                else
                {
                    auto it2 = it->second.find(naziv);
                    if (it2 == it->second.end())
                    {
                        ispit Ispit(&(i->second), datum);
                        it->second[naziv] = Ispit;
                    }
                }
            }
        }
        else if (choice == 3)
        {
            std::string naziv_predmeta;
            std::cout << "Naziv predmeta:  ";
            std::cin.ignore(1, '\n');
            std::getline(std::cin, naziv_predmeta);
            predmet Predmet(naziv_predmeta);
            predmeti[naziv_predmeta] = Predmet;
        }
        else if (choice == 4)
        {
            std::string indeks;
            size_t ocjena_;
            std::string datum;
            std::string ime_predmeta;
            std::cout << "Indeks studenta:  ";
            std::cin >> indeks;
            std::cout << "Ocjena:  ";
            std::cin >> ocjena_;
            if (ocjena_ < 6 || ocjena_ > 10)
                std::cout << "Neispravan unos ocjene" << std::endl;
            else
            {
                std::cout << "Datum ispita (DD.MM.GGGG.):  ";
                std::cin >> datum;
                std::cout << "Ime predmeta:  ";
                std::cin.ignore(1);
                std::getline(std::cin, ime_predmeta);
                auto i = ispiti.find(datum);
                if (i == ispiti.end())
                    std::cout << "Nije bilo ispita tog datuma" << std::endl;
                else
                {
                    auto i1 = i->second.find(ime_predmeta);
                    if (i1 == i->second.end())
                        std::cout << "Nije bio ispit iz tog predmeta na taj datum" << std::endl;
                    else
                    {
                        auto it = predmeti.find(ime_predmeta);
                        ocjena Ocjena(&(it->second), ocjena_);
                        auto it2 = rezultati_ispita.find(datum + ime_predmeta);
                        if (it2 == rezultati_ispita.end())
                            rezultati_ispita[datum + ime_predmeta][indeks] = Ocjena;
                        else
                            it2->second[indeks] = Ocjena;
                        std::string dan, mjesec, godina;
                        int datum_;
                        std::replace(datum.begin(), datum.end(), '.', ' ');
                        std::stringstream in(datum);
                        in >> dan >> mjesec >> godina;
                        datum = godina + mjesec + dan;
                        datum_ = std::stoi(datum);
                        studenti[indeks].dodaj_ocjenu(datum_, Ocjena);
                    }
                }
            }
        }
        else if (choice == 5)
        {
            std::string datum;
            std::cout << "Datum (DD.MM.GGGG.):  ";
            std::cin >> datum;
            auto it = ispiti.find(datum);
            if (it == ispiti.end())
                std::cout << "Nema ispita tog datuma" << std::endl;
            else
            {
                for (auto i = it->second.begin(); i != it->second.end(); ++i)
                {
                    std::cout << i->second.get_naziv() << std::endl;
                }
            }
        }
        else if (choice == 6)
        {
            std::string datum;
            std::string ime;
            std::cout << "Datum (DD.MM.GGGG.):  ";
            std::cin >> datum;
            std::cout << "Ime predmeta:  ";
            std::cin.ignore(1, '\n');
            std::getline(std::cin, ime);
            auto it = rezultati_ispita.find(datum + ime);
            if (it == rezultati_ispita.end())
                std::cout << "Nije bio ispit iz navedenog predmeta" << std::endl;
            else
            {
                for (auto i = it->second.begin(); i != it->second.end(); ++i)
                {
                    std::cout << studenti[i->first].get_ime() << " " << studenti[i->first].get_prezime() << std::endl;
                }
                std::cout << std::endl;
            }
        }
        else if (choice == 7)
        {
            std::string indeks;
            std::cout << "Broj indeksa:  ";
            std::cin >> indeks;
            auto it = studenti.find(indeks);
            if (it == studenti.end())
                std::cout << "Navedeni broj indeksa ne postoji" << std::endl;
            else
            {
                double ocjene = 0;
                double suma_ocjena = 0;
                for (auto i = it->second.get_ocjene().begin(); i != it->second.get_ocjene().end(); ++i)
                {
                    for (int i1 = 0; i1 < i->second.size(); ++i1)
                    {
                        std::cout << i->second[i1].get_predmet() << "_____" << i->second[i1].get_ocjena() << std::endl;
                        suma_ocjena += i->second[i1].get_ocjena();
                        ++ocjene;
                    }
                }
                std::cout << std::endl;
                std::cout << "Prosjek ocjena:  " << suma_ocjena / ocjene << std::endl;
            }
        }
        else
        {
            std::cout << "Pogresan unos" << std::endl;
            std::cin.clear();
        }
    }

    return 0;
}
