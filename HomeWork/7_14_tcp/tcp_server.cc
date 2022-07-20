#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstring>
#include<unistd.h>
#include<cstdlib>
#include<signal.h>

using namespace std;
//const int port=8081;
void Usage(string proc)
{
     cout<<"Usage:"<<proc<<"port"<<endl;
}
void ServiceIO(int new_sock)
{
    while(true)
        {
            char buffer[1024];
            memset(buffer,0,sizeof(buffer));
            ssize_t s=read(new_sock,buffer,sizeof(buffer)-1);//?注意返回值类型是ssize_t，表示有符号的size_t，这样既可以返回正的字节数、0（表示到达文件末尾）也可以返回负值-1（表示出错
            if(s>0)
            {
                 buffer[s]=0;//当成字符串
                 cout<<"clent:#"<<endl;
                 string echo_string=">>>server<<<";
                 echo_string+=buffer;
                 write(new_sock,echo_string.c_str(),sizeof(echo_string));
            }
            else if(s==0)
            {
                cout<<"client quit#"<<endl;
                break;
            }
            else
            {
                 cerr<<"read fail"<<endl;
             break;
            }

            
               
            
        }
}
int main(int argc,char* argv[])
{
    if(argc!=2)
    {
        Usage(argv[0]);
        return 1;
    }
    int Listensock=socket(AF_INET,SOCK_STREAM,0);
    if(Listensock<0)
    {
        cerr<<"sock fail"<<endl;
        return 2;
    }
    struct sockaddr_in local;
    bzero(&local,sizeof(local));
    local.sin_family=AF_INET;
    local.sin_addr.s_addr=htons(atoi(argv[0]));
    if(bind(Listensock,(const sockaddr*)&local,sizeof(local))<0)
    {
        cerr<<"bind fail"<<endl;
        return 3;
    }
    //开始服务
    const int back_log=5;
    if(listen(Listensock,back_log)<0)
    {
        cerr<<"listen fail"<<endl;
        return 4;
    }
    for(;;)
    {
        struct sockaddr_in peer;
        socklen_t len=sizeof(peer);
        int new_sock=accept(Listensock,(struct sockaddr*)&peer,&len);
        if(new_sock<0)
        {
            cerr<<"accept fail"<<endl;
            continue;
        }
        cout<<"get a new link:"<<endl;
        signal(SIGCHLD,SIG_IGN);
        pid_t id=fork();
         //pid_t id = fork();
        if(id < 0){
            continue;
        }
        else if( id == 0 ){
            //child
            ServiceIO(new_sock);
            exit(0);
        }
        else {
            //father
            //do nothing!
        }

        
    }
    return 0;
}