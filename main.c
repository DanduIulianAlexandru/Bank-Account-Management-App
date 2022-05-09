#include "domain/tests_domain.h"
#include "repository/tests_repo.h"
#include "validate/tests_validate.h"
#include "service/tests_service.h"
#include "user_interface/console.h"

int main() {
    tests_all_domain();
    teste_repository();
    test_validate();
    test_service();
    menu();
    run();
    return 0;
}
