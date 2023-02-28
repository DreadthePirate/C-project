/*P O L Y N O M I A L . C*/
#include <stdio.h>
#include <stdlib.h>
#include "term.h"
#include "polynomial.h"
#include "basiclist.h" 

// Allocate memory for a new polynomial
poly_t * new_polynomial() {
    poly_t * poly = (poly_t *) malloc(sizeof(poly_t));
    poly->term = NULL;
    poly->count = 0;
    return poly;
}

// Print a polynomial
void print_polynomial(const poly_t * poly) {
    node_t * curr = poly->term;
    while(curr != NULL){
        term_t * test1 = (term_t *) curr->data;
            printf("%d%c^%d ", test1->coefficient, test1->var,
                test1->exponent);
        curr = curr->next;
    }
    printf("\n");
}

// adds a term to a polynomial then combines like terms
void add_to_polynomial(poly_t * poly, const term_t * term) {
    node_t * curr = poly->term;
    while (curr != NULL) {
        term_t * existing_term = (term_t *)curr->data;
        if (existing_term->exponent == term->exponent) {
            existing_term->coefficient += term->coefficient;
            return;
        }
        curr = curr->next;
    }
    list_add(&(poly->term), term);
    poly->count++;
}

// stores terms in a polynomial
poly_t * combine_like_terms(const poly_t * poly) {
    poly_t * result = new_polynomial();
    result->order = poly->order;
    node_t * curr = poly->term;
    while (curr != NULL) {
        term_t * term = (term_t *) curr->data;
            add_to_polynomial(result, term);
            curr = curr->next;
    }
    return result;
}


// Frees memory allocated for a polynomial
void delete_polynomial(poly_t **poly) {
    free(*poly);
    *poly = NULL;z
}

