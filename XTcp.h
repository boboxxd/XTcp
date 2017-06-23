//
// Created by 徐旭东 on 2017/6/23.
//

#ifndef SOCKET_XTCP_H
#define SOCKET_XTCP_H
#include<thread>//c++11
#include <string>
#include<iostream>


class XTcp {
public:
    int CreateSocket();
    bool Bind(unsigned short port);
    XTcp Accept();
    void Close();
    int Recv(char *buf,int bufsize);
    int Send(const char *buf,int size);
    XTcp();
    virtual ~XTcp();
    int sock=0;
    unsigned  short port=0;
    std::string ip;
};


class TcpThread
{
public:
    void Main()
    {
        char buf[1024]={0};


        for(;;)
        {
            int rlen=client.Recv(buf, sizeof(buf));
            buf[rlen]='\0';
            if(rlen<=0) break;
            if(strstr(buf,"quit")!=NULL)
            {
                std::string re="quit success\n";
                client.Send(re.c_str(),re.size());
                break;
            }
            int sendlen=client.Send("ok\n",4);
            std::cout<<buf<<std::endl;
        }
        client.Close();
        delete this;
    }
    XTcp client;
};


#endif //SOCKET_XTCP_H
