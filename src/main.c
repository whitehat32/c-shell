#include "log.h"
#include "shell.h"


int main(int argc,char* argv[]) {
    setbuf(stdout, NULL);
    freopen(argv[1],"r",stdin);
    log_init(&Log); //初始化Log
    prefix(); //显示路径
    size_t len=0;
    char* buffer=NULL;
    while(getline(&buffer,&len,stdin)!=-1){//读取命令
        buffer[strlen(buffer)-1]='\0';//末位设置为0
        if(!execute(buffer)){//执行命令
            break;
        }
	
        prefix();
        free(buffer);//释放内存
        buffer=NULL;
    }
    if(buffer!=NULL){//意外终止的处理
        free(buffer);
        buffer=NULL;
    }
    log_destroy(&Log);
    return 0;
}
