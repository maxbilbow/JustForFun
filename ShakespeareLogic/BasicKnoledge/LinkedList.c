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
        printf("%d\n", current->val);
        current = current->next;
    } while (current->next != NULL) ;
}

void ll_int_append(node_t * head, int val) {
    node_t * last = head;//this is -1 (holds no value)

    while (last->next != NULL) {
        last = last->next;
    }
    
    last->val = val;
    last->next = malloc(sizeof(node_t));
    
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

void RMXLinkedList(void) {
    
    node_t * test_list = malloc(sizeof(node_t));
//    test_list->val = 1;
//    test_list->next = malloc(sizeof(node_t));
//    test_list->next->val = 2;
//    test_list->next->next = malloc(sizeof(node_t));
//    test_list->next->next->val = 3;
//    test_list->next->next->next = malloc(sizeof(node_t));
//    test_list->next->next->next->val = 4;
//    test_list->next->next->next->next = NULL;

    ll_int_append(test_list, 1);
    ll_int_append(test_list, 2);
    ll_int_append(test_list, 3);
    ll_int_append(test_list, 4);
    remove_by_value(&test_list, 3);
    
    print_list(test_list);
//    return 0;
}