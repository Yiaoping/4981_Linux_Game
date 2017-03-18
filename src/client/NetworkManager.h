#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include <string>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <limits.h>
#include <atomic>
#include <memory>
#include <map>
#include <cassert>
#include "../UDPHeaders.h"


#define STDIN           0
#define TCP_PORT 		35223
#define UDP_PORT 		35222
#define STD_BUFFSIZE    1024
#define MAX_EVENTS 		1
#define MAX_USERS		23
#define UNAME_SIZE      32
#define SYNC_PACKET_MAX USHRT_MAX


//moved enums to the bottom, and commented out

//order matters.
enum class NetworkState {
    NOT_RUNNING,
    INITIALIZING,
    GAME_STARTED
};

class NetworkManager {
public:
    static NetworkManager& instance();

    ~NetworkManager();

    void run(const std::string ip, const std::string username);
    void writeUDPSocket(const char *buf, const int &len) const;
    int32_t getPlayerId() const {return myid;};
    NetworkState getNetworkState() const {return state;};
private:
    std::atomic<NetworkState> state{NetworkState::NOT_RUNNING};
    int32_t myid;  // EY: March 14 - to be removed for game intergration
    int sockTCP;
    int sockUDP;
    sockaddr_in servUDPAddr;
    socklen_t servUDPAddrLen;

    NetworkManager() {};

    void runUDPClient();
    void runTCPClient(const std::string username);
    void handshake(const std::string username) const;
    void waitRecvId();
    void writeTCPSocket(const char *buf, const int len) const;
    int readTCPSocket(char *buf, const int len) const;
    int readUDPSocket(char *buf, const int& len) const;

    static sockaddr_in createAddr(const in_addr_t ip, const int port);
    static int createSock(int);
    static void connectSock(int sock, const sockaddr_in& addr);
    static void bindSock(int sock, sockaddr_in addr);
};

#endif
