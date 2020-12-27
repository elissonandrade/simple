#include "linked.h"


struct item{
item* next;
int content;
};

void put(linked* l, int number){
        item* operator = (item*) calloc(1,sizeof(item));
        operator->content = number;
    if(l->start == NULL){
        l->start = operator;
    }else{
        item* pivot = l->start;
        while(pivot->next != NULL){
            pivot = pivot->next;
        }
        pivot->next = operator;
    }
    list(l);
}

void get(linked* l, int pos){
    if(l->start != NULL){
        item* pivot = l->start;
        for(int i = 1; i != pos && pivot->next != NULL;i++){
            pivot = pivot->next;
        }
        printf("%d\n", pivot->content);
    }
}

void first(linked* l){
    if(l->start != NULL){
        item* pivot = l->start;
        printf("%d\n", pivot->content);
    }
}

void last(linked* l){
    if(l->start != NULL){
        item* pivot = l->start;
        while(pivot->next != NULL){
            pivot = pivot->next;
        }
        printf("%d\n", pivot->content);
    }
}

void remo(linked* l, int pos){
    if(l->start != NULL){
        item* pivot = l->start;
        item* previous= NULL;
        item* newNext= NULL;
        
        for(int i = 1; i != pos && pivot->next != NULL;i++){
            previous = pivot;
            pivot = pivot->next;
            newNext = pivot->next;
        }
            if(pos > 1){
                previous->next = newNext;
            }else{
                l->start = newNext;
            }
        
        printf("%d\n", pivot->content);
        free(pivot);
        list(l);
    }
}

void list(linked* l){
    if(l->start != NULL){
        item* pivot = l->start;
        while(pivot->next != NULL){
            printf("%d ", pivot->content);
            pivot = pivot->next;
        }
        printf("%d\n", pivot->content);
    }
}

void clear(linked* l){
    if(l->start != NULL){
        item* pivot = l->start;
        item* previous= NULL;
        
        while( pivot->next != NULL){
            previous = pivot;
            pivot = pivot->next;
            free(previous);
        }
        free(pivot);
        l->start = NULL;
    }
}

item* mergeSort(item* x, item* y){
    item* pivot = NULL;
    if(x == NULL){
        return y;
    }
    if(y == NULL){
        return x;
    }
    if((long)x == (long)y){
        return x;
    }
    if((x->content) <= (y->content)){
        pivot = x;
        pivot->next = mergeSort(x->next,y);
    }else{
    
        pivot = y;
        pivot->next = mergeSort(x,y->next);
    }
    return pivot;

}

void sort(linked* l){
    if(l->start != NULL&& l->start->next != NULL){
        
        item* pivot = l->start;
        while(pivot->next != NULL){
            pivot = pivot->next;
        }
        l->start = mergeSort(l->start ,pivot);
        list(l);
    }
}



