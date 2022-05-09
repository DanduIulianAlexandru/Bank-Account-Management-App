#include "../repository/repo.h"
#include "service.h"
#include "../validate/validate.h"
#include <stdlib.h>
#include "string.h"

int append_service(Repo* repo, int day, char type[100], char description[100], int sum){
    // adauga un element la repo si il valideaza
    // date de intrare: repo - pointer la tip de data Repo
    //					day - ziua , numar intreg
    //                  sum - suma, numar intreg
    //                  type - tipul , sir de caractere
    //                  description - descriere, sir de caractere
    // date de iesire: 0 - in caz ca totul e in regula, 1 - in caz contrar
    char* errors = malloc(50 * sizeof(char));
    Transaction* tr = create_transaction(day, type, description, sum);
    validate(tr, errors);
    int cod;
    if(strlen(errors) == 0){
        append(repo, tr);
        free(errors);
        cod = 0;
    }
    else{
        destroy_transaction(tr);
        free(errors);
        cod = 1;
    }
    return cod;
}

int modify_service(Repo* repo, int indice, int day, char type[10], char description[100], int sum){
    // modifica un element din repo si il valideaza
    // date de intrare: repo - pointer la tip de data Repo
    //                  indice - indexul elementului care va fi modificat
    //					day - ziua , numar intreg
    //                  sum - suma, numar intreg
    //                  type - tipul , sir de caractere
    //                  description - descrierea, sir caractere
    // date de iesire: 0 daca este in regula, 1 sau 2 in caz contrar
    char* errors = malloc(50 * sizeof(char));
    Transaction* tr = create_transaction(day, type, description, sum);
    validate(tr, errors);
    int cod;
    if(indice < 0 || indice >= number_of_elements(repo)){
        destroy_transaction(tr);
        free(errors);
        cod = 1;
    }
    else if(strlen(errors) != 0){
        destroy_transaction(tr);
        free(errors);
        cod = 2;
    }
    else{
        modify(repo, indice, tr);
        free(errors);
        cod = 0;
    }
    return cod;
}

int delete_service(Repo* repo, int indice){
    // sterge un element din repozitoriu, daca indicele corespunde unui element
    // date de intrare: repo - pointer la tip de data Repo
    //					indice - numar intreg, indicele elementului care va fi sters
    // date de iesire: 0 - in caz ca totul e in regula, 1 - in caz contrar
    int cod;
    if(indice < 0 || indice >= number_of_elements(repo))
        cod = 1;
    else{
        delete(repo, indice);
        cod = 0;
    }
    return cod;
}

Repo* type_filter(Repo* repo, char type[100]){
    //creeaza o variabila de tip Repo care contine toate tranzactiile de un anumit tip
    //date intrare: repo - pointer la tipul de data Repo
    //              type - tipul tranzactiei dupa care sa fie filtrat repo-ul
    //date iesire: list - repo cu tranzactiile de un anumit tip
    int i;
    Repo* list = create_repo();
        for(i = 0; i < repo->length; i ++){
            Transaction* tr = repo->vect[i];
            if(strcmp(tr->type, type) == 0)
                append(list, tr);
        }
        return list;

}

Repo* sum_filter(Repo* repo, char mod[100], int sum){
    //creeaza o variabila de tip Repo care contine toate tranzactiile cu suma mai mic sau mai mare decat o suma data
    //date intrare: repo - pointer la tipul de data Repo
    //              mod - modul in care sa fie sumele tranzactiilor fata de suma data de utilizator (mai mare/mai mic)
    //              sum - suma data de utilizator
    //date iesire: list - repo cu tranzactiile filtrate dupa sume
    int i;
    Repo* list = create_repo();
    for(i = 0; i < repo->length; i ++) {
        Transaction *tr = repo->vect[i];
        if(strcmp(mod, "maimare") == 0 && tr->sum > sum)
            append(list, tr);
        if(strcmp(mod, "maimic") == 0 && tr->sum < sum)
            append(list, tr);
    }
    return list;
}

int compare_day(Transaction* tr1, Transaction* tr2){
    int cod;
    if(tr1->day > tr2->day)
        cod = 1;
    else
        cod = -1;
    return cod;
}

int compare_sum(Transaction* tr1, Transaction* tr2){
    int cod;
    cod = -1;
    return cod;
}

void sort(Repo* repo, int sens, for_fct compare)
{
    // functie care ordoneaza repozitoriul dupa un criteriu dat
    // date de intrare: repo - pointer la tip de data Repozitoriu
    //                 sens -numar intreg: 1 pentru crescator, -1 pentru descrescator
    // date de iesire: aux - copie a repozitoriului dat ca parametru cu elementele sortate
    int i, j;
    for (i = 0; i < repo->length - 1; i++)
        for (j = i + 1; j < repo->length; j++)
        {
            Transaction* c1 = repo->vect[i];
            Transaction* c2 = repo->vect[j];
            if (sens * compare(c1, c2) > 0)
            {
                Transaction sub = *c1;
                *c1 = *c2;
                *c2 = sub;
            }
        }
}

Repo* day_sort(Repo* repo, char ord[100]){
    if(strcmp(ord, "crescator") == 0)
    {
        Repo* list = copy_repo(repo);
        sort(list, 1, compare_day);
        return list;
    }
    if(strcmp(ord, "descrescator") == 0){
        Repo* list = copy_repo(repo);
        sort(list, -1, compare_day);
        return list;
    }
}

Repo* sum_sort(Repo* repo, char ord[100]){
    if(strcmp(ord, "crescator") == 0){
        Repo* list = copy_repo(repo);
        sort(list, 1, compare_sum);
        return list;
    }
    if(strcmp(ord, "descrescator") == 0){
        Repo* list = copy_repo(repo);
        sort(list, -1, compare_sum);
        return list;
    }
}
