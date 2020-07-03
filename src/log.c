/** @file log.c */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "log.h"

/**
对log进行初始化，log的“构造函数”
 */

void log_init(log_t *l) {
    l -> head = NULL;
}

/**
销毁一个log，释放所有内存空间，log的“析构函数”
 */

void log_destroy(log_t* l) {
    node * tmp = l -> head;
    if(tmp == NULL)return;
    while(tmp) {
        free(tmp -> cmd);
        free(tmp);
        tmp = tmp -> next;
    }
    l -> head = NULL;
}

/**
向log中推入一个字符串，你可以将log视为一个由链表组成的栈
 */

void log_push(log_t* l,const char *item) {
    node* t = (node*)malloc(sizeof(node));
    t -> cmd = item;
    t -> next = NULL;
    if(l -> head == NULL) {
        l -> head = t;
        //printf("%s\n",t -> cmd);
    }
    else {
        node * t1 = l -> head;
        while(t1 && t1 -> next != NULL) {
            t1 = t1 -> next;
        }
        t1 -> next = t;
    }
}


/**
搜索log中是否含有对应前缀的字符串
 */

char *log_search(log_t* l, const char *prefix) {
    node* t = l -> head;
    while(t) {
        if(strstr(t -> cmd,prefix) == t -> cmd) {
            return t -> cmd;
        }
        t = t -> next;
    }
    return NULL;
}
