#pragma once

typedef struct{
    //un tip de data denumit Transaction caracterizat prin:
    //day ziua in care s-a efectuat tranzactiei de tip int
    //type tipul tranzactiei de intrare sau iesire de tip char
    //description descrierea tranzactiei de tip char
    //sum suma tranzactionata de tip int
    int day;
    char* type;
    char* description;
    int sum;
}Transaction;

Transaction* create_transaction(int, char*, char*, int);

void destroy_transaction(Transaction*);

Transaction* copy_tr(Transaction*);

int equal_tr(Transaction*, Transaction*);