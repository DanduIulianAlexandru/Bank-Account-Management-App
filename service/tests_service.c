#include "tests_service.h"
#include "assert.h"
#include "../repository/repo.h"
#include "service.h"
#include "stdlib.h"

void test_service() {
    // funcite care efectueaza teste automate pentru elementele din pachetul service
    // date de intrare: -
    // date de iesire: -, assertion error daca testul esueaza
    Repo *repo = create_repo();
    //append_service:

    //id invalid:
    assert(append_service(repo, -1, "intrare", "sad", 32) == 1);

    //suma invalida:
    assert(append_service(repo, 2, "asdasd", "sdsd", 32) == 1);

    //all good:
    assert(append_service(repo, 1, "intrare", "sd", 69) == 0);
    assert(repo->length == 1);

    //modify_service:

    //indice invalid
    assert(modify_service(repo, -1, 1, "intrare", "sdsd", 233) == 1);
    assert(modify_service(repo, 2, 1, "intrare", "sdsd", 233) == 1);

    //tranzactie nu e valida
    assert(modify_service(repo, 0, -1, "intrare", "asdsad", 3232) == 2);
    assert(modify_service(repo, 0, 1, "dsafdasd", "sdsd", 233) == 2);

    //all good
    assert(modify_service(repo, 0, 1, "intrare", "sdsd", 233) == 0);

    //delete_service

    //indice invalid:
    assert(delete_service(repo, 1) == 1);

    //all good:
    assert(delete_service(repo, 0) == 0);
    assert(repo->length == 0);

    //type filter:
    Transaction* tr = create_transaction(1, "intrare", "asdsd", 23);
    Transaction* tr1 = create_transaction(2, "intrare", "assd", 24);
    Transaction* tr99 = create_transaction(2, "iesire", "assd", 24);
    append(repo, tr);
    append(repo, tr99);
    append(repo, tr1);
    //iesire - 0 tranzactii intrare - 2 tranzactii
    Repo* filter_list2 = type_filter(repo, "intrare");
    Repo* filter_list = type_filter(repo, "iesire");
    assert(filter_list->length == 1);
    assert(filter_list2->length == 2);


    //sum filter:
    Transaction* tr2 = create_transaction(1, "intrare", "asdsd", 10);
    Transaction* tr3 = create_transaction(2, "intrare", "assd", 15);
    Transaction* tr4 = create_transaction(1, "intrare", "asdsd", 60);
    Transaction* tr5 = create_transaction(2, "intrare", "assd", 70);
    append(repo, tr2);
    append(repo, tr3);
    append(repo, tr4);
    append(repo, tr5);
    Repo* sum_list = sum_filter(repo, "maimic", 20);
    Repo* sum_list2 = sum_filter(repo, "maimare", 30);
    assert(sum_list->length == 2);
    assert(sum_list2->length == 2);

    //sort day:
    Repo* repo1 = create_repo();
    Transaction* t2 = create_transaction(5, "intrare", "asdsd", 10);
    Transaction* t3 = create_transaction(3, "intrare", "assd", 15);
    Transaction* t4 = create_transaction(8, "intrare", "asdsd", 60);
    Transaction* t5 = create_transaction(1, "intrare", "assd", 70);
    append(repo1, t2);
    append(repo1, t3);
    append(repo1, t4);
    append(repo1, t5);
    Repo* repo2 = day_sort(repo1, "crescator");
    Transaction* ok = repo2->vect[0];
    assert(equal_tr(t5, ok) == 0);
    Repo* repo3 = day_sort(repo1, "descrescator");
    Transaction* ok2 = repo3->vect[0];
    assert(equal_tr(t4, ok2) == 0);

    //sort sum:
    Repo* repo4 = create_repo();
    Transaction* a1 = create_transaction(5, "intrare", "asdsdfff", 10);
    Transaction* a2 = create_transaction(3, "intrare", "assdddd", 15);
    Transaction* a3 = create_transaction(8, "intrare", "asdsddsd", 60);
    Transaction* a4 = create_transaction(2, "intrare", "assd", 65);
    append(repo4, a1);
    append(repo4, a2);
    append(repo4, a3);
    append(repo4, a4);
    Repo* repo5 = sum_sort(repo4, "crescator");
    Transaction* wow = repo5->vect[3];
    assert(equal_tr(wow, a4) == 0);

    Repo* repo6 = sum_sort(repo4, "descrescator");
    Transaction* bine = repo6->vect[0];
    assert(equal_tr(bine, a4) == 0);
    destroy_repo(repo, destroy_transaction);
    destroy_repo(repo1, destroy_transaction);
    destroy_repo(repo2, destroy_transaction);
    destroy_repo(repo3, destroy_transaction);
    destroy_repo(repo4, destroy_transaction);
    destroy_repo(repo5, destroy_transaction);
    destroy_repo(repo6, destroy_transaction);

    free(filter_list2->vect);
    free(filter_list2);
    free(filter_list->vect);
    free(filter_list);
    free(sum_list->vect);
    free(sum_list);
    free(sum_list2->vect);
    free(sum_list2);

}