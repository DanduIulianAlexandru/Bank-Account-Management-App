#include "domain.h"
#include <string.h>
#include <stdlib.h>

Transaction* create_transaction(int day, char* type, char* description, int sum){
    //creeaza o variabila de tip Tranzactie cu parametrii dati
    Transaction* tr = malloc(sizeof(Transaction));
    tr->day = day;
    tr->type = malloc((strlen(type) + 1) * sizeof(char));
    tr->description = malloc((strlen(description) + 1) * sizeof(char));
    strcpy(tr->type, type);
    strcpy(tr->description, description);
    tr->sum = sum;
    return tr;
}

void destroy_transaction(Transaction* tr){
    // functie care elibereaza memoria de pe heap de la adresa din variabila tr
    //date intrare: tr - pointer la tipul de data Transaction
    //date iesire: -
    free(tr->type);
    free(tr->description);
    tr->type = NULL;
    tr->description = NULL;
    free(tr);
}

Transaction* copy_tr(Transaction* tr){
    //functie care returneaza o copie e variabilei gasite la adresa din tr
    //date de intrare: tr - pointer la variabila de tip Transaction
    //date de iesire : copie a variabilei de tip Transaction
    return create_transaction(tr->day, tr->type, tr->description, tr->sum);
}

int equal_tr(Transaction* tr1, Transaction* tr2){
    //functie care verifica egalitatea a 2 tranzactii
    int cod = 0;
    if(tr1->day != tr2->day) cod = 1;
    if(tr1->sum != tr2->sum) cod = 1;
    if(strcmp(tr1->description, tr2->description) != 0) cod = 1;
    if(strcmp(tr1->type, tr2->type) != 0) cod = 1;
    return cod;
}