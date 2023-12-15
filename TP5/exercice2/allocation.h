#include <stdio.h>
#include <stdlib.h>

#define allocation_malloc(X) allocation_malloc_fonction(X, __LINE__, __FILE__);
#define allocation_bilan(X) allocation_bilan_fonction(__LINE__, __FILE__);
#define allocation_free(X) allocation_free_fonction(X, __LINE__, __FILE__);