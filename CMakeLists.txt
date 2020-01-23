cmake_minimum_required(VERSION 3.14)
project(OupusSys C)

set(CMAKE_C_STANDARD 99)

add_executable(OupusSys main.c Cliente.c Cliente.h Produto.c Produto.h Interface.c Interface.h)