#include<stdio.h>
#include<dirent.h>
#include<string.h>

//                      struct dirent 
//                      {
//                          ino_t          d_ino;       // inode 号
//                          off_t          d_off;       // 下一个条目的偏移
//                          unsigned short d_reclen;    // 这个记录的长度
//                          unsigned char  d_type;      // 文件类型（DT_REG、DT_DIR、DT_LNK...）
//                          char           d_name[256]; // 文件名，以 '\0' 结尾
//                      };


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
    //先统计参数
    int num_a=0;
    int num_l=0;

    for(int i=0;i<argc;i++)
    {
        if(!strcmp(argv[i],"-a"))
        {
            num_a=1;
        }
        else if(!strcmp(argv[i],"-l"))
        {
            num_l=1;
        }
    }

    //执行

    //if(argc==1)//实际上输出了所有
    //{
        DIR *dir=opendir(".");
        if(!dir)
        {
            perror("opendir");
            return 1;
        }
        struct dirent *read;
        while((read=readdir(dir))!=NULL)
        {
            if(!num_a&&read->d_name[0]=='.')
            {
                continue;
            }
            printf("%s\n",read->d_name);
        }
        closedir(dir);
    //}
    printf("-----------check:hello world!\n");
    return 0;
}