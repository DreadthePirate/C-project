/*T E R M . C*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "term.h"

// function that prints the terms
    char * term_to_string(const term_t * term){
        char * str = malloc(256);
        sprintf(str, "Coefficient: %d Variable: %c Exponent: %d\n", term->coefficient, term->var, term->exponent);
    return str;
    }

