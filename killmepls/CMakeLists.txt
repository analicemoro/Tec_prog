cmake_minimum_required(VERSION 3.31)
project(killmepls C)

set(CMAKE_C_STANDARD 11)

add_executable(killmepls main.c
        autor.c
        autor.h
        geral.c
        geral.h
        livro.c
        livro.h
        menu.c
        menu.h
        opcoes_autor.c
        opcoes_autor.h
        opcoes_livro.c
        opcoes_livro.h)
