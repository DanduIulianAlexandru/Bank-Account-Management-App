#pragma once
#include "../domain/domain.h"

typedef void* Element;
typedef struct Repo{
    Element* vect;
    int length;
    int capacity;
}Repo;

typedef void (*destroy_function)(Repo*);

Repo* create_repo();
void destroy_repo(Repo*, destroy_function);
void grow_capacity(Repo*);

Repo* copy_repo(Repo*);

void append(Repo*, Element);
int number_of_elements(Repo*);
void modify(Repo*, int, Element);
void delete(Repo*, int);