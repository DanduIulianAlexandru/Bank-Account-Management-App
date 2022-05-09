#include "ui.h"
#include <stdio.h>

void append_ui(Repo* repo){
    int day;
    char type[100];
    char description[100];
    int sum;
    printf("Introduceti ziua tranzactiei: ");
    scanf("%d", &day);
    printf("Introduceti tipul tranzactiei(intrare/iesire): ");
    scanf("%s", type);
    printf("Introduceti descrierea tranzactiei: ");
    scanf("%s", description);
    printf("Introduceti suma pe care doriti sa o tranzictionati: ");
    scanf("%d", &sum);
    int cod = append_service(repo, day, type, description, sum);
    if(cod == 1)
        printf("Datele introduse sunt invalide!\n");
}

void delete_ui(Repo* repo){
    int indice;
    printf("Introduceti indicele tranzactiei pe care doriti sa o stergeti: ");
    scanf("%d", &indice);
    int cod = delete_service(repo, indice);
    if(cod == 1)
        printf("Indicele pe care l-ati introdus este invalid!\n");
}

void modify_ui(Repo* repo){
    int indice;
    int day;
    char type[100];
    char description[100];
    int sum;
    printf("Introduceti indicele tranzactiei pe care doriti sa o modificati:");
    scanf("%d", &indice);
    printf("Introduceti ziua tranzactiei: ");
    scanf("%d", &day);
    printf("Introduceti tipul tranzactiei(intrare/iesire): ");
    scanf("%s", type);
    printf("Introduceti descrierea tranzactiei: ");
    scanf("%s", description);
    printf("Introduceti suma pe care doriti sa o tranzictionati: ");
    scanf("%d", &sum);
    int cod = modify_service(repo, indice, day, type, description, sum);
    if(cod == 1)
        printf("Indicile pe care l-ati introdus este invalid!\n");
    if(cod == 0)
        return;
    if(cod == 2)
        printf("Datele tranzactiei sunt invalide!\n");
}

void show_ui(Repo* repo){
    if(repo->length == 0){
        printf("Lista este goala!");
        return;
    }
    for(int i = 0; i < repo->length;i ++){
        Transaction* tr = repo->vect[i];
        printf("%d-|Ziua: %d|Tipul: %s|Descriere: %s|Suma: %d|\n",i, tr->day, tr->type, tr->description, tr->sum);
    }
}

void type_filter_ui(Repo* repo){
    char type[100];
    printf("Introduceti tipul dupa care doriti sa filtrati:");
    scanf("%s", type);
    Repo* list = type_filter(repo, type);
    show_ui(list);
}

void sum_filter_ui(Repo* repo){
    int sum;
    char mod[100];
    printf("Introduceti suma dupa care doriti sa filtrati tranzactiile:");
    scanf("%d", &sum);
    printf("Introduceti modul in care sa fie tranzactiile fata de suma (maimic/maimare)");
    scanf("%s", mod);
    Repo* list = sum_filter(repo, mod, sum);
    show_ui(list);
}

void day_sort_ui(Repo* repo){
    char ord[100];
    printf("Introduceti modul in care doriti sa fie sortata lista(crescator/descresctor): ");
    scanf("%s", ord);
    Repo* list = day_sort(repo, ord);
    show_ui(list);
}

void sum_sort_ui(Repo* repo){
    char ord[100];
    printf("Introduceti modul in care doriti sa fie sortata lista(crescator/descresctor): ");
    scanf("%s", ord);
    Repo* list = sum_sort(repo, ord);
    show_ui(list);
}

void add_10_ui(Repo* repo){
    Transaction* tr1 = create_transaction(1, "intrare", "asfs", 783);
    Transaction* tr2 = create_transaction(10, "intrare", "ni ma", 7);
    Transaction* tr3 = create_transaction(244, "intrare", "ce te uiti", 100);
    Transaction* tr4 = create_transaction(33, "intrare", "ce fa ma", 3);
    Transaction* tr5 = create_transaction(233, "intrare", "bruh", 73);
    Transaction* tr6 = create_transaction(99, "iesire", "lmao", 99);
    Transaction* tr7 = create_transaction(23, "iesire", "WOW", 8889);
    Transaction* tr8 = create_transaction(43, "iesire", "oai", 11111);
    Transaction* tr9 = create_transaction(199, "iesire", "caterinca", 244444);
    Transaction* tr10 = create_transaction(55, "iesire", "imi plc c ul", 2455);
    append(repo, tr1);
    append(repo, tr2);
    append(repo, tr3);
    append(repo, tr4);
    append(repo, tr5);
    append(repo, tr6);
    append(repo, tr7);
    append(repo, tr8);
    append(repo, tr9);
    append(repo, tr10);
}
