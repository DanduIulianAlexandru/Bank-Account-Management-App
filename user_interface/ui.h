#pragma once
#include "../service/service.h"
#include "../repository/repo.h"

void append_ui(Repo*);
void delete_ui(Repo*);
void modify_ui(Repo*);
void show_ui(Repo*);

void type_filter_ui(Repo*);
void sum_filter_ui(Repo*);

void day_sort_ui(Repo*);
void sum_sort_ui(Repo*);

void add_10_ui(Repo*);