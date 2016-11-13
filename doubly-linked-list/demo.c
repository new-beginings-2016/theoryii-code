#include "llist.h"

int main(int argc, char **argsv)
{
    struct llist_t *myList;
    int i, a;

    make_list(&myList);

    for (i = 1; i < argc; i++) {
	a = atoi(argsv[i]);

	add_to_list(myList, a);
    }

    print_list(myList);
    print_list_backwards(myList);

    free_list(myList);

    return 0;
}




