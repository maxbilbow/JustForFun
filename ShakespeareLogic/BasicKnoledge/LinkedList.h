//
//  LinkedList.h
//  JustForFun
//
//  Created by Max Bilbow on 09/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#ifndef LinkedList_c
#define LinkedList_c

#include <stdio.h>

#endif /* LinkedList_c */



typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head);

void ll_int_append(node_t * head, int val);

int pop(node_t ** head);

int remove_by_value(node_t ** head, int val);

void RMXLinkedList(void);