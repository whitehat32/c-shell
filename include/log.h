/** @file log.h */

#ifndef __LOG_H_
#define __LOG_H_
typedef struct _node{
    char* cmd;
    struct _node* next;
} node;
typedef struct _log_t {
    node* head;
} log_t;

void log_init(log_t *l);
void log_destroy(log_t* l);
void log_push(log_t* l, const char *item);
char *log_search(log_t* l, const char *prefix);

#endif
