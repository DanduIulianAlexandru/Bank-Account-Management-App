#include "tests_repo.h"
#include "repo.h"
#include "assert.h"


void teste_repository(){
    // funcite care efectueaza teste automate pentru elementele din pachetul repository
    // date de intrare: -
    // date de iesire: -, assertion error daca testul esueaza

    //append + create
    Repo* repo = create_repo();
    Transaction* tr1 = create_transaction(1, "intrare", "ce fa ma", 69);
    Transaction* tr2 = create_transaction(2, "intrare", "ce fa ma", 69);
    Transaction* tr3 = create_transaction(4, "iesire", "ce fa ma", 420);
    append(repo, tr1);
    append(repo, tr2);
    append(repo, tr3);
    assert(number_of_elements(repo) == 3);

    //delete
    delete(repo, 0);
    assert(number_of_elements(repo) == 2);
    delete(repo, 0);
    assert(number_of_elements(repo) == 1);
    Transaction* test = repo->vect[0];
    assert(test->day == 4);
    assert(test->sum == 420);

    //modify
    Transaction* tr4 = create_transaction(5, "iesire", "ce fa", 469);
    modify(repo, 0, tr4);
    Transaction* tr = repo->vect[0];
    assert(tr->sum == 469);
    assert(tr->day == 5);

    Repo* repo2 = copy_repo(repo);
    Transaction* trr = repo2->vect[0];
    assert(trr->sum == 469);
    assert(trr->day == 5);
    destroy_repo(repo, destroy_transaction);
    destroy_repo(repo2, destroy_transaction);
}