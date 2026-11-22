#include<stdio.h>
#include<dirent.h>
int main(int argc,char *argv[])
{
    //接收检测：
    for(int i=0;i<argc;i++)
    {
        printf("%s\n",argv[i]);
    }

    printf("此时argc=%d,\n",argc);
    printf("----------------\n");

    //执行
    if(argc==1)//实际上输出了所有
    {
        DIR *dir=opendir(".");
        if(!dir)
        {
            perror("opendir");
            return 1;
        }
        struct dirent *read;
        while((read=readdir(dir))!=NULL)
        {
            printf("%s\n",read->d_name);
        }
        closedir(dir);
    }
    printf("jianyan::hello world!\n");
    return 0;
}