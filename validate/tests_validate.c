#include "tests_validate.h"
#include "../domain/domain.h"
#include "../validate/validate.h"
#include "assert.h"
#include "string.h"

void test_validate(){
    // funcite care efectueaza teste automate pentru elementele din pachetul validate
    // date de intrare: -
    // date de iesire: -, assertion error daca testul esueaza
    Transaction* tr = create_transaction(1, "iesire", "nush man", 420);
    char errors[50];
    validate(tr, errors);
    assert(strlen(errors) == 0);

    Transaction* tr1 = create_transaction(-1, "iesire", "nush man", 420);
    validate(tr1, errors);
    assert(strcmp(errors, "Ziua tranzactiei este invalida!\n") == 0);

    Transaction* tr2 = create_transaction(1, "iesire", "nush man", -30);
    validate(tr2, errors);
    assert(strcmp(errors, "Suma tranzactiei este invalida!\n") == 0);

    Transaction* tr3 = create_transaction(1, "oai", "nush man", 420);
    validate(tr3, errors);
    assert(strcmp(errors, "Tipul tranzactiei este invalida!\n") == 0);

    destroy_transaction(tr);
    destroy_transaction(tr1);
    destroy_transaction(tr2);
    destroy_transaction(tr3);
}