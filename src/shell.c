#include "shell.h"
#include <unistd.h>
#include <string.h>

/**
 * shell的入口
 */



void prefix() {
    int ms = 105;
    char dir[ms];
    getcwd(dir,ms);
    printf("%s$ ",dir);
}

int execute(char* buffer) {
    int i = 0;
    char* tmp = malloc((strlen(buffer) + 1));
    memcpy(tmp,buffer,(strlen(buffer) + 1));
    while(buffer[i] == ' ')i++;
    char * p = strtok(buffer+i," ");
    if(strcmp(p,"cd") == 0) {
        log_push(&Log,tmp);
        p = strtok(NULL," ");
        if(!p || chdir(p) != 0) {
            printf("%s: No such file or directory\n",tmp);
        } 
    }
    else if(strcmp(p,"exit") == 0) {
        log_push(&Log,tmp);
        return 0;
    }
    else if(strcmp(p,"!#") == 0) {
        log_t* l = &Log;
        node* t = l -> head;
        while(t != NULL) {
            printf("%s\n",t -> cmd);
            t = t -> next;
        }
    }
    else if(p[0] == '!') {
        char * s = log_search(&Log,p + 1);
        if(s != NULL) {
            log_push(&Log,s);
            execute(s);
        }
        else printf("No Match\n");
    }
    else if(strcmp(p,"ls") == 0) {
        log_push(&Log,tmp);
        system(tmp);
    }
    else {
        log_push(&Log,tmp);
        int i = 0;
        char * marg[105];
        marg[i++] = p;
        while(((p = strtok(NULL," ") )!= NULL)) {
            marg[i] = p; i++;
        }
        marg[i] = NULL;
        int m_pid = fork();
        if(m_pid != 0) {
            waitpid(m_pid,NULL,0);
        }
        else {
            char s[105] = "./";
            strcat(s,marg[0]);
            execv(s,marg);
            execvp(marg[0],marg);
            printf("%s: no such command\n",marg[0]);
            exit(0);
        }
    }
    return 1;
}
