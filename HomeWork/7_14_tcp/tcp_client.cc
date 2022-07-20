#include<iostream>
#include<string>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstring>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using  namespace std;
void Usage( string proc)
{
    cout<<"Usage"<<proc<<"server_ip server_port"<<endl;
}
int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        Usage(argv[0]);
        return 1;
    }
    string svr_ip=argv[1];
    uint16_t svr_port=(uint16_t)atoi(argv[2]);
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
    {
        cerr<<"socket error"<<endl;
        return 2;
    }
    struct sockaddr_in server;
    memset(&server,0,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=inet_addr(svr_ip.c_str());
    server.sin_port=htons(svr_port);
    if(connect(sock,(struct sockaddr*)&server,sizeof(server))<0)
    {
        cerr<<"connect failed"<<endl;
        return 3;
    }
    cout<<"connect success!"<<endl;
    while(true)
    {
        cout<<"please enter";
        char buffer[1024];
        fgets(buffer,sizeof(buffer)-1,stdin);
        write(sock,buffer,strlen(buffer));
        ssize_t s = read(sock, buffer, sizeof(buffer)-1);
        if(s>0)
        {
            buffer[s] = 0;
            std::cout << "server echo# " << buffer << std::endl;
        }

    }
    return 0;
}