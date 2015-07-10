//
//  LinkedList.c
//  JustForFun
//
//  Created by Max Bilbow on 09/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//



//#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void print_list(node_t * head) {
    node_t * current = head;
    
    do {
        current = current->next;
        printf("%d, ", current->val);
    } while (current->next != NULL) ;
    printf("\n");
}

void ll_int_append(node_t * head, int val) {
    node_t * last = head;//this is -1 (holds no value)
    
    while (last->next != NULL) {
        last = last->next;
    }
    
   
    last->next = malloc(sizeof(node_t));
    last->next->val = val;
    last->next->next =  NULL;
//    last->next->next = NULL;
//    ++_count;
//    return val;
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;
    
    if (*head == NULL) {
        return -1;
    }
    
    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;
    
    return retval;
}

int remove_by_value(node_t ** head, int val) {
    /* TODO: fill in your code here */
    return -1;
}

int reverse_list(node_t ** head) {
    if (*head == NULL) {
        return -1;
    }
    int count = 0;
    node_t * current = *head;
    while (current->next != NULL) {
        current = current->next;
        ++count;
    }
    node_t * nodes[count];
    current = (*head)->next;
    printf("Total : %i\n",count);
    for (int i = 0; i < count; ++i) {
        nodes[i] = current;
//        free(current)
        printf("Value : %i of %i == %i\n",i,count,current->val);
        current = current->next;
    }
    
//    *head = nodes[--count];
    current = *head;
    while (count > 0) {
        current->next = nodes[--count];
        current = current->next;
        printf("Value : %i == %i\n",count,current->val);
    }
    current->next = NULL;
    return count;
}

void RMXLinkedList(void) {
    
    node_t * test_list = malloc(sizeof(node_t));
    ll_int_append(test_list, 1);
    ll_int_append(test_list, 2);
    ll_int_append(test_list, 3);
    ll_int_append(test_list, 4);
    remove_by_value(&test_list, 3);
    
    print_list(test_list);
    reverse_list(&test_list);
    print_list(test_list);
    free(test_list);
//    return 0;
}