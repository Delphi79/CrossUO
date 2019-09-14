﻿// MIT License
// Copyright (C) August 2016 Hotride

#pragma once

#include "../Network/Connection.h"

class CConnectionManager
{
protected:
    bool m_UseProxy = false;

public:
    bool GetUseProxy() { return m_UseProxy; };
    void SetUseProxy(bool val);

protected:
    std::string m_ProxyAddress = "";

public:
    std::string GetProxyAddress() { return m_ProxyAddress; };
    void SetProxyAddress(const std::string &val);

protected:
    int m_ProxyPort = 0;

public:
    int GetProxyPort() { return m_ProxyPort; };
    void SetProxyPort(int val);

protected:
    bool m_ProxySocks5 = false;

public:
    bool GetProxySocks5() { return m_ProxySocks5; };
    void SetProxySocks5(bool val);

protected:
    std::string m_ProxyAccount = "";

public:
    std::string GetProxyAccount() { return m_ProxyAccount; };
    void SetProxyAccount(const std::string &val);

protected:
    std::string m_ProxyPassword = "";

public:
    std::string GetProxyPassword() { return m_ProxyPassword; };
    void SetProxyPassword(const std::string &val);

private:
    CSocket m_LoginSocket{ CSocket(false) };
    CSocket m_GameSocket{ CSocket(true) };
    // true - m_LoginSocket, false - m_GameSocket
    bool m_IsLoginSocket = true;
    uint8_t m_Seed[4];

    void SendIP(CSocket &socket, uint8_t *ip);

public:
    CConnectionManager();
    ~CConnectionManager();

    void Init();
    void Init(uint8_t *gameSeed);
    bool Connected() { return (m_LoginSocket.Connected || m_GameSocket.Connected); }
    bool Connect(const std::string &address, int port, uint8_t *gameSeed);
    void Disconnect();
    void Recv();
    int Send(uint8_t *buf, int size);
    int Send(const std::vector<uint8_t> &data);
    const uint8_t *GetClientIP() const { return &m_Seed[0]; }
};

extern CConnectionManager g_ConnectionManager;
