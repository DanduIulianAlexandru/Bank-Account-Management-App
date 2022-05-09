#pragma once
#include "../repository/repo.h"

typedef int (*for_fct)(Transaction*, Transaction*);

int append_service(Repo*, int, char[100], char[100], int);
int modify_service(Repo*, int, int, char[], char[], int);
int delete_service(Repo*, int);


Repo* type_filter(Repo*, char[]);
Repo* sum_filter(Repo*, char[], int);

Repo* day_sort(Repo*, char[]);
Repo* sum_sort(Repo*, char[]);

int compare_day(Transaction*, Transaction*);
int compare_sum(Transaction*, Transaction*);