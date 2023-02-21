#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 100

void create(); 
void insert(int); 
void delete(int); 
void display();
void priorityCheck(int); 
 
int priqueue[SIZE]; 
int front, rear; 

void main() 
{ 
    int n, choice;  
    printf("\nPress - 1 to Insert element in Priority Queue "); 
    printf("\nPress - 2 to Delete element in Priority Queue "); 
    printf("\nPress - 3 to Display Priority Queue "); 
    printf("\nPress - 4 to Exit ");  
    create();  
    while (1) 
    { 
        printf("\nSelect your choice : ");    
        scanf("%d", &choice);   
        switch(choice) 
        { 
        case 1: 
            printf("\nEnter element to insert : "); 
            scanf("%d",&n); 
            insert(n); 
            break; 
        case 2: 
            printf("\nEnter element to delete : "); 
            scanf("%d",&n); 
            delete(n); 
            break; 
        case 3: 
            display(); 
            break; 
        case 4: 
            printf("\nExitted Successfuly");
            exit(9); 
        default: 
            printf("\nPlease enter valid choice"); 
        } 
    } 
}  
void create() 
{ 
    front = rear = -1; 
}  
void insert(int element) 
{ 
    if (rear >= SIZE - 1) 
    { 
        printf("\nQueue Overflow"); 
        return; 
    } 
    if ((front == -1) && (rear == -1)) 
    { 
        front++; 
        rear++; 
        priqueue[rear] = element; 
        return; 
    }    
    else 
        priorityCheck(element); 
    rear++; 
}  
void priorityCheck(int element) 
{ 
    int i,j;  
    for (i = 0; i <= rear; i++) 
    { 
        if (element >= priqueue[i]) 
        { 
            for (j = rear + 1; j > i; j--) 
            { 
                priqueue[j] = priqueue[j - 1]; 
            } 
            priqueue[i] = element; 
            return; 
        } 
    } 
    priqueue[i] = element; 
}  
void delete(int element)  
{ 
    int i;  
    if ((front==-1) && (rear==-1)) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    }  
    for (i=0; i <= rear; i++) 
    { 
        if (element == priqueue[i]) 
        { 
            for (i=0; i<rear; i++) 
            { 
                priqueue[i] = priqueue[i + 1]; 
            } 
            priqueue[i] = -99; 
            rear--; 
            if (rear == -1) 
               front = -1; 
            return; 
        } 
    } 
    printf("\n%d Element not found in queue", element); 
} 
void display() 
{ 
    if ((front == -1) && (rear == -1)) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    }  
    for (int i=front; i <= rear; i++) 
    { 
        printf(" %d ", priqueue[i]); 
    } 
     int i = 0; 
} 