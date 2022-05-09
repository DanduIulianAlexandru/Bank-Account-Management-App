#include "validate.h"
#include "string.h"

void validate(Transaction* tr, char* errors)
{
    // functia validare transforma un sir de caractere numit errors in sirul nul daca datele de intrare sunt valide, respectiv
    // in mesaje de eroare care vor fi transmise ulterior daca datele nu sunt valide
    // date de intrare: tr - variabila de tip Transaction
    //                  errors - sir de caractere
    // date de iesire: -
    strcpy(errors, "");
    if(tr->day <= 0)
        strcat(errors, "Ziua tranzactiei este invalida!\n");
    if(tr->sum < 0)
        strcat(errors, "Suma tranzactiei este invalida!\n");
    if((strcmp(tr->type, "intrare") != 0) && (strcmp(tr->type, "iesire") != 0))
        strcat(errors, "Tipul tranzactiei este invalida!\n");
}