#include <stdio.h>

#include "devector.h"

int main() {

    devector dv; int elem;

    devector_deploy(&dv, sizeof(elem));//constructor

    while (1) {

        //input:

        printf("\n1. push_back\n2. push_front\n3. pop_back\n4. pop_front\nN. exit\n");

        int choice;
        printf("\nenter choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("\nenter the value: ");
            scanf("%d", &elem);

            if (devector_push_back(&dv, &elem) == INVALID_BUFFER_STATE) {

                printf("FAILURE: MEMORY LIMIT REACHED");

                devector_destroy(&dv);
                return 0;
            }
            break;
        case 2:
            printf("\nenter the value: ");
            scanf("%d", &elem);

            if (devector_push_front(&dv, &elem) == INVALID_BUFFER_STATE) {

                printf("FAILURE: MEMORY LIMIT REACHED");

                devector_destroy(&dv);
                return 0;
            }
            break;
        case 3:
            if( devector_pop_back(&dv) == INVALID_BUFFER_STATE) {

                printf("FAILURE: MEMORY LIMIT REACHED");

                devector_destroy(&dv);
                return 0;
            }
            break;
        case 4:
            if (devector_pop_front(&dv) == INVALID_BUFFER_STATE) {

                printf("FAILURE: MEMORY LIMIT REACHED");

                devector_destroy(&dv);
                return 0;
            }
            break;
        default:
            devector_destroy(&dv);//destructor
            return 0;
        }

        //display:

        printf("\ndata: ");

        for (size_t i = 0; i < devector_size(&dv); i++) {
            printf(" %d ", *(int*)devector_at(&dv, i));

        }

        printf("\n");

    }

    return 0;
}
