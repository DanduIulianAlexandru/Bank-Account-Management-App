#include "tests_domain.h"
#include <string.h>
#include <assert.h>
#include "domain.h"

void test_create_transaction(){
    Transaction* tr = create_transaction(2, "intrare", "ok", 230);
    assert(tr->day == 2);
    assert(tr->sum == 230);
    assert(strcmp(tr->description, "ok") == 0);
    assert(strcmp(tr->type, "intrare") == 0);
    destroy_transaction(tr);
}

void test_destroy_transaction(){
    Transaction* tr = create_transaction(2, "intrare", "ok", 230);
    destroy_transaction(tr);
}

void test_copy_tr(){
    Transaction* tr = create_transaction(2, "intrare", "ok", 230);
    Transaction* tr1 = copy_tr(tr);
    assert(tr->day == tr1->day);
    assert(tr->sum == tr1->sum);
    destroy_transaction(tr);
    destroy_transaction(tr1);
}

void test_equal_tr(){
    Transaction* tr1 = create_transaction(1, "intrare", "sds", 24);
    Transaction* tr2 = create_transaction(1, "intrare", "sds", 24);
    Transaction* tr3 = create_transaction(2, "intrare", "sds", 24);
    Transaction* tr4 = create_transaction(2, "iesire", "sds", 24);
    Transaction* tr5 = create_transaction(2, "iesire", "dsdss", 24);
    Transaction* tr6 = create_transaction(2, "iesire", "dsdss", 255);
    assert(equal_tr(tr1, tr2) == 0);
    assert(equal_tr(tr1, tr3) == 1);
    assert(equal_tr(tr4, tr3) == 1);
    assert(equal_tr(tr4, tr5) == 1);
    assert(equal_tr(tr6, tr5) == 1);
    destroy_transaction(tr1);
    destroy_transaction(tr2);
    destroy_transaction(tr3);
    destroy_transaction(tr4);
    destroy_transaction(tr5);
    destroy_transaction(tr6);

}

void tests_all_domain(){
    test_destroy_transaction();
    test_create_transaction();
    test_copy_tr();
    test_equal_tr();
}