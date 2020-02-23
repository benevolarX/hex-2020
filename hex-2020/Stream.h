#pragma once

#include "Predicate.h"
#include "BiFonction.h"

namespace hex
{

    template<class ELEM>
    class Stream
    {
    public:
        Stream() {
            elements = std::vector<ELEM>();
        }

        Stream(ELEM tab[]) : Stream() {
            for (auto e : tab) {
                add(e);
            }
        }

        Stream(std::vector<ELEM> tab) : Stream() {
            for (auto e : tab) {
                add(e);
            }
        }

        template<class APRES>
        Stream<APRES> to(Fonction<ELEM, APRES> to) {
            Stream<APRES> s;
            for (auto e : this.elements) {
                s.add(to(e));
            }
            return s;
        }

        Stream<ELEM> filtrer(Predicate<ELEM> p) {
            Stream<ELEM> s;
            for (auto e : elements) {
                if (p(e)) {
                    s.add(e);
                }
            }
            return s;
        }

        template<class U>
        U reduce(Generator<U> creator, BiFonction<U, ELEM, U> ajouter) {
            U groupe = creator.generer();
            for (auto e : this.elements) {
                groupe = ajouter(groupe, e);
            }
            return groupe;
        }

        /**
        template<class U>
        U collect(Generator<U> creator, BiFonction<U, ELEM, U> ajouter, BiFonction<U, U, U> fusion) {
            U groupe = creator.generer();
            for (auto e : this.elements) {
                groupe = ajouter(groupe, e);
            }
            return groupe;
        }**/

        void add(ELEM e) {
            this.elements.push_back(e);
        }

    protected:
        std::vector<ELEM> elements;
    };

}
