// Quick sort
void sort(Player* list, int left, int right){
    // Create an auxiliary stack
    int stack[ (right -left) + 1 ];
    // initialize top of stack
    int top = -1;
    // push initial values of l and h to stack
    stack[ ++top ] = left;
    stack[ ++top ] = right;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 ){
        // Pop h and l
        right = stack[ top-- ];
        left = stack[ top-- ];
 
        // Set pivot element at its correct position
        // in sorted array
        int p = partition( list, left, right );
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > left ){
            stack[ ++top ] = left;
            stack[ ++top ] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < right ){
            stack[ ++top ] = p + 1;
            stack[ ++top ] = right;
        }
    }

}

void swap ( Player* a, Player* b ){
    Player t = *a;
    *a = *b;
    *b = t;
}

int partition (Player* list, int left, int right){
    int x = list[right].points;
    int i = (left - 1);
 
    for (int j = left; j <= right- 1; j++){
        if (list[j].points <= x){
            i++;
            swap (&list[i], &list[j]);
        }
    }
    swap (&list[i + 1], &list[right]);
    return (i + 1);
}