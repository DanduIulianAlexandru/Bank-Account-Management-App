#include "repo.h"
#include "malloc.h"

Repo* create_repo(){
    Repo* r = malloc(sizeof(Repo));
    r->capacity = 2;
    r->length = 0;
    r->vect = malloc(sizeof(Element) * r->capacity);
    return r;
}

void destroy_repo(Repo* repo, destroy_function destroy_fct){
    // functie care distruge repozitoriu si elibereaza memoria alocata pe heap
    // date de intrare : repo - pointer la Repo
    //					destroyct-de tip destroy_function
    // date de iesire: -
    int i;
    for (i = 0; i < repo->length; i ++){
        destroy_fct(repo->vect[i]);
    }
    free(repo->vect);
    free(repo);
}

void grow_capacity(Repo* repo){
    // functie care creste capacitatea vectorului dinamic daca acesta are toate pozitiile ocupate(capacitatea este egala cu lungimea)
    // date de intrare: repo - pointer la Repo
    // date de iesire : -
    if(repo->length >= repo->capacity){
        int cap2 = repo->capacity + 2;
        Element* vect2 = malloc(cap2 * sizeof(Element));
        int i;
        for (i = 0; i < repo->length; i ++)
            vect2[i] = repo->vect[i];
        free(repo->vect);
        repo->capacity = cap2;
        repo->vect = vect2;
    }
}

void append(Repo* repo, Element el){
    // adauga un element la repozitoriu
    // date de intrare: repo - pointer la tip de data Repo
    //					el - variabila de tip Element
    // date de iesire: -
    grow_capacity(repo);
    repo->vect[repo->length] = el;
    repo->length = repo->length + 1;
}

int number_of_elements(Repo* repo){
    // functie care returneaza numarul de elemente din repo
    // date de intrare: repo - pointer la tip de data Repo
    // date de iesire: numarul de elemente din repzitoriu, numar natural
    return repo->length;
}

void delete(Repo* repo, int indice) {
    // sterge un element din repo
    // date de intrare: repo - pointer la tip de data Repo
    //					indice - numar intreg, indicele elementului care va fi sters
    // date de iesire: -
    if (indice < repo->length) {
        Element *vect2 = malloc(repo->capacity * sizeof(Element));
        int i, ct = 0;
        for (i = 0; i < repo->length; i++)
            if (i != indice)
                vect2[ct++] = repo->vect[i];
        destroy_transaction(repo->vect[indice]);
        free(repo->vect);
        repo->vect = vect2;
        repo->length = ct;
    }

}

void modify(Repo* repo, int indice, Element el){
    // modifica un element din repozitoriu
    // date de intrare: repo - pointer la tip de data Repo
    //                  indice - numar intreg, indicele elementului modificat
    //					ch - variabila de tip Element
    // date de iesire: -
    if(indice < repo->length){
        destroy_transaction(repo->vect[indice]);
        repo->vect[indice] = el;
    }
}

Repo* copy_repo(Repo* repo){
    Repo* rez = create_repo();
    for(int i = 0; i < repo->length; i ++){
        Element tr = repo->vect[i];
        append(rez, copy_tr(tr));
    }
    return rez;
}
