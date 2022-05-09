#include "console.h"
#include "ui.h"
#include <stdio.h>
#include <string.h>
void menu(){
    printf("Optiuni:\n");
    printf("1.Adaugati o tranzactie                     -press 1\n");
    printf("2.Stergeti o tranzactie                     -press 2\n");
    printf("3.Modificati o tranzactie                   -press 3\n");
    printf("4.Afisati lista de tranzactii               -press 4\n");
    printf("5.Filtrati tranzactiile dupa tipul acestora -press 5\n");
    printf("6.Filtrati tranzactiile dupa o anumita suma -press 6\n");
    printf("7.Sortati tranzactiile dupa ziua acestora   -press 7\n");
    printf("8.Sortati tranzactiile dupa suma acestora   -press 8\n");
    printf("9.Adaugati 10 tranzactii                    -press 9\n");
    printf("Inchideti aplicatia                       -type exit\n");
}

void run(){
    Repo* repo = create_repo();
    while(1){
        printf(">>>");
        char opt[20];
        scanf("%s", opt);
        if(strcmp(opt, "1") == 0)
            append_ui(repo);
        else if(strcmp(opt, "2") == 0)
            delete_ui(repo);
        else if(strcmp(opt, "3") == 0)
            modify_ui(repo);
        else if(strcmp(opt, "exit") == 0)
            return;
        else if(strcmp(opt, "4") == 0)
            show_ui(repo);
        else if(strcmp(opt, "5") == 0)
            type_filter_ui(repo);
        else if(strcmp(opt, "6") == 0)
            sum_filter_ui(repo);
        else if(strcmp(opt, "7") == 0)
            day_sort_ui(repo);
        else if(strcmp(opt, "8") == 0)
            sum_sort_ui(repo);
        else if(strcmp(opt, "9") == 0)
            add_10_ui(repo);
        else
            printf("Comanda invalida!");
    }
    destroy_repo(repo, destroy_transaction);
}