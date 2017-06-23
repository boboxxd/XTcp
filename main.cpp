#include<iostream>
#include"XTcp.h"

int main(int argc,char **argv)
{
    XTcp server;
    server.CreateSocket();
    server.Bind(8080);
    for(;;)
    {
        XTcp client=server.Accept();

        TcpThread *th=new TcpThread();
        th->client=client;
        std::thread sth(&TcpThread::Main,th);
        sth.detach();
    }
    server.Close();
    getchar();
    return 0;
}