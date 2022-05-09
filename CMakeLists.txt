cmake_minimum_required(VERSION 3.21)
project(ProjectCfinal C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjectCfinal main.c domain/domain.c domain/domain.h domain/tests_domain.c domain/tests_domain.h repository/repo.c repository/repo.h repository/tests_repo.c repository/tests_repo.h service/service.c service/service.h service/tests_service.c service/tests_service.h validate/validate.c validate/validate.h validate/tests_validate.c validate/tests_validate.h user_interface/ui.c user_interface/ui.h user_interface/console.c user_interface/console.h)

set(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS}-Wall_Wextra")