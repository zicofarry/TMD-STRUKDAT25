/*Saya Muhammad 'Azmi Salam dengan NIM 2406010
mengerjakan Tugas Masa Depan dalam mata kuliah
Algoritma dan Struktur Data untuk keberkahan-Nya,
maka saya tidak akan melakukan kecurangan seperti
yang telah di spesifikasikan Aamiin.*/

#include "tmdasd25.h" // include header "tmdasd25.h"

// re-declare global variable
stack space; // stack to save number of spation per level
stack maxLen; // stak to save max lenght string per level
int maxLevel = 0; // to save maximum level in this tree, set with 0
int justConseq = 0; // to set mode print (print just consequence or not), set with 0 (false)

// procedure to create the list
void createList(list *L){
    (*L).first = NULL;    
}

// procedure to count the element
int countElementList(list L){
    int result = 0;
    if(L.first != NULL){
        /*list is not empty*/
        element* point;
        /*initialization*/
        point = L.first;
        while(point != NULL){
            /*process*/
            result++;
            
            /*iteration*/
            point = point->next;
        }
    }
    return result;
}

// procedure to add element to the first place
void addFirst(boxList temp, list *L){
    element* new;
    new = (element*) malloc(sizeof(element));
    new->container = temp;

    // if list is empty    
    if((*L).first == NULL){
        new->next = NULL;
    // if list is not empty
    }else{
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

// procedure to add element after element
void addAfter(element* prev, boxList temp, list *L){
    element* new;
    new = (element*) malloc(sizeof(element));
    new->container = temp;
    // if element at the end of list (prev next null)
    if(prev->next == NULL){
        new->next = NULL;
    }
    // if element is not at the end
    else{
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;  
}

// procedure to add element to the last place
void addLast(boxList temp, list *L){
    // is list is empty, call addFirst
    if((*L).first == NULL){
      addFirst(temp, L);
    }
    // if list is not empty 
    else{
        element* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        // call addAfter after finding prev at the end
        addAfter(prev, temp, L);
    }
}

// procedure to create empty stack
void createStack(stack *S){
    (*S).top = NULL;
}

// function to count element of the stack
int countElementStack(stack S){
    int result = 0;
    if(S.top != NULL){
        /* if stack is not empty */
        elementS* point;
        
        /* initialization */
        point = S.top;
        while(point != NULL){
            /* process */
            result = result + 1;
            
            /* iteration */
            point = point->next;
        }
    }
    return result;
}

// procedure to push element to the stack
void push(boxStck tmp, stack *S){
    elementS* new;
    new = (elementS *) malloc (sizeof (elementS));

    new->container = tmp;
    if((*S).top == NULL){
        // if stack is empty
        new->next = NULL;
    }else{
        // if stack is not empty
        new->next = (*S).top;
    }
    (*S).top = new;
    new = NULL;
}

// procedure to pop element from the stack
void pop(stack *S){
    if((*S).top != NULL){
        /*if stack is not empty stack*/
        elementS *delete = (*S).top;
        if(countElementStack(*S) == 1){
            (*S).top = NULL;
        }else{
            (*S).top = (*S).top->next;
        }
        delete->next = NULL;
        free(delete);
    }else{
        printf("empty stack\n");
    }
}

// function to get stack element from its index
int getElement(stack S, int idx){
    elementS* point = S.top; // declare elementS point, start from top
    int i = 0; // declare integer i, start from 0
    while(i < maxLevel - idx){ // loop while i less than maxLevel - idx (to get index of stack)
        point = point->next; // update element point with the next element
        i++; // increment int i
    }
    return point->container.num; // return number from container point
}

// procedure to update stack element from at a specific index
void updateStack(stack *S, int idx, int newVal){
    elementS* point = (*S).top; // declare elementS point, start from top
    int i = 0; // declare integer i, start from 0
    while(i < maxLevel - idx){ // loop while i less than maxLevel - idx (to get index of stack)
        point = point->next; // update element point with the next element
        i++; // increment int i
    }
    point->container.num = newVal; // assign number from container point with newVal
}

// procedure to create empty queue
void createQueue(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}

// function to check if its an empty queue
int isEmpty(queue Q){
    int result = 0;
    if(Q.first == NULL) result = 1;
    return result;
}

// function to count element of the queue
int countElementQueue(queue Q){
    int result = 0;
    if(Q.first != NULL){
        /*queue is not empty*/
        elementQ* point;
        /*initialitazion*/
        point = Q.first;
        while(point != NULL){
            /*process*/
            result = result + 1;
            
            /*iteration*/
            point = point->next;
        }
    }
    return result;
}

// procedure to add element to the queue
void add(boxQue tmp, queue *Q ){
    elementQ* new;
    new = (elementQ *) malloc (sizeof (elementQ));
    new->container = tmp;
    new->next = NULL;
    if((*Q).first == NULL){ // if its an empty queue
        (*Q).first = new;
    }else{ // if its not
        (*Q).last->next = new;
    }
    (*Q).last = new;
    new = NULL;
}

// procedure to delete an element from the queue
void del(queue *Q){
    if((*Q).first != NULL){
        /*if queue is not empty queue*/
        elementQ *delete = (*Q).first;
        if(countElementQueue(*Q) == 1){
            (*Q).first = NULL;
            (*Q).last = NULL;
        }else{
            (*Q).first = (*Q).first->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

// procedure to crate tree
void createTree(box tmp, tree* T){
    node *new; // declare node new
    new = (node *) malloc (sizeof (node)); // malloc node new
    new->container = tmp; // fill new container with tmp
    new->child = NULL; // new point (child) to NULL
    new->sibling = NULL; // new point (sibling) to NULL
    new->parent = NULL; // new point (parent) to NULL
    (*T).root = new; // update root with node new
    new = NULL; // set new with NULL
}

// procedure to add new child node
void addChild(box tmp, node* root){
    if(root != NULL){ // condition to check if the root existed
        node* new; // declare node new
        new = (node*)malloc(sizeof(node)); // malloc node new
        new->container = tmp; // fill new container to tmp
        new->child = NULL; // new point (child) to NULL
         new->parent = root; // new point (parent) to root

        // Condition if the parent node doesn't have a child
        if (root->child == NULL) {
            new->sibling = NULL; // new point (sibling) to NULL
            root->child = new; // root point (child) to new
        }
        // Otherwise, we'll have to append it to the end of the child list
        else { // Condition where there's only 1 child
            if (root->child->sibling == NULL) {
                new->sibling = root->child; // new point (sibling) to root child
                root->child->sibling = new; // root child point (sibling) to NULL
            } else {
                // Loop through to find the last child of the list
                node* last = root->child; // declare node last, set with root child
                while (last->sibling != root->child) { // loop while sibling is not root child
                    last = last->sibling; // update last with the next sibling
                }
                new->sibling = root->child; // new point (sibling) to root child
                last->sibling = new; // last point (sibling) to new
            }
        }
    }
}

// procedure to delete all from node root
void delAll(node* root){
    // Condition to check if root existed
    if (root != NULL) {
        // Condition to check if the parent has a child
        if (root->child != NULL) {
            // Condition where there's only 1 child
            if (root->child->sibling == NULL) {
                delAll(root->child); // Recursively delete the child
            }
            // Condition where there are multiple children
            else {
                node* current;
                node* target;

                // Loop through to delete the children sequentially
                current = root->child;
                while (current->sibling != root->child) {
                    target = current;
                    current = current->sibling;
                    delAll(target); // Delete node recursively
                }
                // Delete the last child node
                if (current != NULL)
                    delAll(current);
            }
        }
        // Finally delete the root node itself
        free(root);
    }
}

// procedure to delete child from parent
void delChild(box tmp, node* root){
    // Condition where the root exist
    if (root != NULL) {
        node* current = root->child;
        if (current != NULL) {
            // Condition where there's only 1 child
            if (current->sibling == NULL) {
                // Found condition
                if (strcmp(root->child->container.name, tmp.name) == 0) {
                    delAll(root->child);
                    root->child = NULL; // Set child to NULL
                    root->parent = NULL; // Set parent to NULL
                } else {
                   // printf("[!] node %c has only one child (%c) and it's not the target\n", root->container.name, root->child->container.name);
                }
            }
            // Condition where there are multiple children
            else {
                node* prev = NULL;
                int found = 0;

                // Loop until every child is checked
                while (current->sibling != root->child && found == 0) {
                    // Found condition
                    if (strcmp(current->container.name, tmp.name) == 0)
                        found = 1;
                    else {
                        prev = current;
                        current = current->sibling;
                    }
                }

                // Check the last remaining child, if it's the target
                if (strcmp(current->container.name, tmp.name) == 0 && found == 0)
                    found = 1;
                if (found == 1) {
                    node* last = root->child;

                    // Loop through to the last child
                    while (last->sibling != root->child) {
                        last = last->sibling;
                    }

                    // Prev is not initialized since the target is root->child in the initial loop
                    if (prev == NULL) {
                        // Condition where there is only 2 children
                        if (current->sibling == last && last->sibling == root->child) {
                            root->child = last;
                            last->sibling = NULL;
                        }
                        // Condition where the children count is above 2
                        else {
                            root->child = current->sibling;
                            last->sibling = root->child;
                        }
                    }
                    // Normal last child condition
                    else {
                        // Find the second child to check number of children
                        node* second_child = root->child->sibling;
                        // Condition where target is last, but there's only 2 children
                        if (prev == root->child && second_child->sibling == root->child) {
                            root->child->sibling = NULL;
                        }
                        // Normal condition where target is last and there is more than 2 children
                        else {
                            prev->sibling = current->sibling;
                            current->sibling = NULL;
                        }
                    }
                    // Delete the target node
                    delAll(current);
                } else {
                    // printf("[!] node with the name %c is not found\n", target->container.name);
                }
            }
        }
    }
}

// function to find node with BFS method
node* findNodeBFS(box find, node* root){
    node *result = NULL; // declare node result, set with NULL
    if(root != NULL){ // if root is not NULL
        queue Q; // declare queue Q
        createQueue(&Q); // call procedure createQueue to create an empty queue
        boxQue tmp; // declare boxQue tmp
        tmp.elementQ = root; // update tmp.element with node root
        add(tmp, &Q); // add tmp to queue Q

        while(!isEmpty(Q) && result == NULL){ // loop while queue is not empty and result is still NULL
            boxQue front = Q.first->container; // declare boxQue front, set with first container
            node *current = front.elementQ; // declare node current, set with front element
            
            if(strcmp(current->container.name, find.name) == 0){ // if its the same
                result = current; // update result with current node
            }else{ // if its not
                node *child = current->child; // declare node child, set with current child
                if(child != NULL){ // if child is not NULL
                    if(child->sibling == NULL){ // if child doesnt have sibling
                        boxQue new; // declare boxQue new
                        new.elementQ = child; // update new element with node child
                        add(new, &Q); // add node new to queue
                    }else{ // if its more than 1 child
                        node *start = child; // declare node start, set with node child
                        do{ // do while child its not start
                            boxQue new; // declare boxQue new 
                            new.elementQ = child; // update new element with node child
                            add(new, &Q); // add node new to queue
                            child = child->sibling; // update child with the next sibling
                        }while(child != start);
                    }
                }
            }
            del(&Q); // delete the first element from queue
        }
    }
    return result; // return the result
}

// procedure to print the node
void printNode(node *root){
    if(justConseq){ // if justConseq is true (print just consequence without space and node)
        if(countElementList(root->container.L) != 0){ // if number of element of the list is not 0
            element *point = root->container.L.first; // delcare element point, start from first
            while(point != NULL){ // loop while point is not NULL
                printf("-%s\n", point->container.consequence); // print consequences
                point = point->next; // update point with the next element
            }
            point = NULL; // update point with NULL, to kill the zombie
        }
    }else{ // if its false (print space, node, and consequence)
        if(!root->container.level){ // if level is 0
            printf("[-%s-]\n", root->container.name); // print the node without space before
        }else{ // if level its not 0
            printf("\n"); // print enter
            for(int i = 0; i < getElement(space, root->container.level); i++) printf(" "); // print the space
            printf("[-%s-]\n", root->container.name); // print the node
        }
        if(countElementList(root->container.L) != 0){ // if number of element of the list is not 0
            element *point = root->container.L.first; // delcare element point, start from first
            while(point != NULL){ // loop while point is not NULL
                for(int j = 0; j < getElement(space, root->container.level); j++) printf(" "); // print the space
                printf(" -%s\n", point->container.consequence); // print the consequences
                point = point->next; // update point with the next element
            }
            point = NULL; // update point with NULL, to kill the zombie
        }
    }
}

// procedure to print the tree by pre order
void printPreOrder(node* root){
    // Condition where root exist
    if (root != NULL) {
        printNode(root);

        node* current = root->child;
        // Check if current node exists
        if (current != NULL) {
            // Condition where current is the only child
            if (current->sibling == NULL) {
                printPreOrder(current);
            }
            // Condition where there are multiple children
            else {
                // Print preorder for each sibling
                do{
                    printPreOrder(current);
                    current = current->sibling;
                }while(current != root->child);
            }
        }
    }
}

// procedure to delete unused node from tree by pre order
void delPreOrder(box target, node* root){
    // Condition where root exist
    if (root != NULL) {
        // base recursive
        if(findNodeBFS(target, root) == NULL){ // if target is not found from this node
            delChild(root->container, root->parent); // delete this node
            return; // return so the recursive will stop
        }
        
        node* current = root->child;
        // Check if current node exists
        if (current != NULL) {
            // Condition where current is the only child
            if (current->sibling == NULL) {
                delPreOrder(target, current);
            }
            // Condition where there are multiple children
            else {
                // Call recursive delete preorder for each sibling
                do{
                    node* next = current->sibling;
                    delPreOrder(target, current);
                    current = next;
                }while(current != NULL);
            }
        }
    }
}

// procedure to create space len
void createSpace(){
    createStack(&space); // create empty stack for space
    createStack(&maxLen); // create empty stack for maxLen
    for(int i = 0; i <= maxLevel; i++){ // loop for until maxLevel
        boxStck tmp; // declare boxStck tmp
        tmp.num = 0; // assign tmp num with 0
        push(tmp, &space); // push tmp to stack space
        push(tmp, &maxLen); // push tmp to stack maxLen
    }
}

// procedure to reset space len
void resetSpace(){
    elementS* point = space.top; // declare elementS point, start from space.top
    while(point != NULL){ // loop while point is not NULL
        point->container.num = 0; // assign num with 0
        point = point->next; // update point with the next element
    }
    point = maxLen.top; // assign elementS point with maxLen.top
    while(point != NULL){ // loop while point is not NULL
        point->container.num = 0; // assign num with 0
        point = point->next; // update point with the next element
    }
    point = NULL; // update point with NULL, to kill the zombie
}

// procedure to make space len
void countSpace(node *root){ 
    if(root != NULL){
        if(!root->container.level){ // if node level is 0
            updateStack(&maxLen, 0, strlen(root->container.name) + 5); // update maxLen at index 0 with node len + 5
            element *point = root->container.L.first; // declare element point, start from first
            while(point != NULL){ // loop while point is not NULL
                if(getElement(maxLen, root->container.level) < strlen(point->container.consequence) + 3){ // if maxLen at index level is less than consequense len + 3
                    updateStack(&maxLen, root->container.level, strlen(point->container.consequence) + 3); // update maxLen at index level is with consequense len + 3
                }
                point = point->next; // update point with the next element
            }
            point = NULL; // update point with NULL, to kill the zombie
        }else{ // if node level is not 0
            if(getElement(maxLen, root->container.level) < strlen(root->container.name) + 5){ // if maxLen at index level is less than node name len + 5
                updateStack(&maxLen, root->container.level, strlen(root->container.name) + 5); // update maxLen at index level with node name len + 5
            }
            element *point = root->container.L.first; // declare element point, start from first
            while(point != NULL){ // loop while point is not NULL
                if(getElement(maxLen, root->container.level) < strlen(point->container.consequence) + 3){ // if maxLen at index level is less than consequense len + 3
                    updateStack(&maxLen, root->container.level, strlen(point->container.consequence) + 3); // update maxLen at index level is with consequense len + 3
                }
                point = point->next; // update point with the next element
            }
            point = NULL; // update point with NULL, to kill the zombie
            updateStack(&space, root->container.level, getElement(space, root->container.level-1) + getElement(maxLen, root->container.level-1)); // update space at index level
        }

        node* current = root->child;
        // Check if current node exists
        if (current != NULL) {
            // Condition where current is the only child
            if (current->sibling == NULL) {
                countSpace(current);
            }
            // Condition where there are multiple children
            else {
                // Call recursive preorder for each sibling
                do{
                    countSpace(current);
                    current = current->sibling;
                }while(current != root->child);
            }
        }
    }
}

// procedure to solve the problem
void solve(){
    tree T; // declare tree T
    int n; // declare n to save number of node
    scanf("%d", &n); // input n value
    for(int i = 0; i < n; i++){ // loop until n
        box new, par; // declare box new and par
        int row; // declare int row
        scanf(" %[^#]#%[^#]#%d", new.name, par.name, &row); // input new name, parent name, and row
        
        if(strcmp(par.name, "null") == 0){ // if parent name is null
            createList(&new.L); // call procedure createList to create an empty list
            for(int j = 0; j < row; j++){ // loop until number of row
                boxList newList; // declare boxList newList
                scanf("%s", newList.consequence); // input consequence
                addLast(newList, &new.L); // addLast consequence to the list
            }
            new.level = 0; // set new.level with 0
            createTree(new, &T); // call procedure createTree to create the tree
        }else{ // if its not null
            node *parent = findNodeBFS(par, T.root); // find the parent
            if(parent != NULL){ // if parent is not NULL
                createList(&new.L); // call procedure createList to create an empty list
                for(int j = 0; j < row; j++){ // loop until number of row
                    boxList newList; // declare boxList newList
                    scanf("%s", newList.consequence); // input consequence
                    addLast(newList, &new.L); // addLast consequence to the list
                }
            }
            new.level = parent->container.level + 1; // set new.level with parent level + 1
            if(maxLevel < new.level) maxLevel = new.level; // update maxLevel
            addChild(new, parent); // call procedure addChild to add new node to the tree
        }
    }
    box chosen_path; // declare box chosen_path
    scanf("%s", chosen_path.name); // input chosen_path value

    createSpace(); // call procedure createSpace to create an empty space until max level
    countSpace(T.root); // call procedure countSpace to count space per level node
    printPreOrder(T.root); // call procedure printPreOrder to print the tree by pre-order
    printf("\n"); // print enter
    
    delPreOrder(chosen_path, T.root); // call procedure delPreOrder to delete unused path
    resetSpace(); // call procedure resetSpace to reset space, set with 0
    countSpace(T.root); // call procedure countSpace to count space per level node
    printPreOrder(T.root); // call procedure printPreOrder to print the tree by pre-order

    justConseq = 1; // update justConseq with 1
    printf("\nKonsekuensi yang Dijalani dengan Pilihan %s:\n", chosen_path.name); // print information
    printPreOrder(T.root); // call procedure printPreOrder to print the tree by pre-order
}