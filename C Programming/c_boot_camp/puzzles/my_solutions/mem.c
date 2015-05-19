#include <stdlib.h> 

struct person_node { 
    char* name;
    int age;
};

struct pet_node { 
    char* name; 
    char type[10]; 
};

typedef struct person_node person; 
//error corrected here ↓ pointer was missing
typedef struct pet_node* pet;

int main() { 
    /* TODO: dynamically allocate enough memory, assign the blocks to these pointers */
    const int SIZE = 10;
    
    int* A = (int*) malloc(SIZE * sizeof(int));     // Construct a 10-elmeent integer array
    int** B = (int**) malloc(SIZE * sizeof(int*)) ;    // Construct a 2D array of 10 x 10 integers,
    for(register int i=0; i<SIZE; i++) {
    	*B = (int*) malloc(SIZE * sizeof(int));
    }
    person* C = (person*) malloc(SIZE * sizeof(person));  // Construct an array of 10 persons, allocate 10 characters for each name
    for(register int i=0; i<SIZE; i++) {
    	C[i].name = (char*) malloc(SIZE * sizeof(char));
    }
    pet* D = (pet*) malloc(SIZE * sizeof(pet));     // Construct an array of 10 pets, allocate 10 characters for each name;
    for(register int i=0; i<SIZE; i++) {
    	D[i] = (struct pet_node*) malloc(sizeof(struct pet_node));
    	(D[i])->name = (char*) malloc(SIZE * sizeof(char));
    }
    // free any memory you just allocated before you return!
    free(A);
    for(register int i=0; i<SIZE; i++) {
    	free(B[i]);
    	free(C[i].name);
    	free((D[i])->name);
	free(D[i]);
    }
    free(B);
    free(C);
    free(D);

    return 0; 
}
