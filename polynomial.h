/*P O L Y N O M I A L . H*/ 

#include "term.h"
#include "basiclist.h"

// Define the polynomial structure
typedef struct poly {
    node_t * term;
    int order;
    int count;
} poly_t;

poly_t * new_polynomial();
void print_polynomial(const poly_t *poly);
void add_to_polynomial(poly_t *poly, const term_t *term);
poly_t * combine_like_terms(const poly_t *poly);
void delete_polynomial(poly_t ** poly);
