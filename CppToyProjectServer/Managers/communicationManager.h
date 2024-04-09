#pragma once
#include "../Main/headers.h"


class CommunicationManager
{
private:
    static CommunicationManager* m_instance;

    CommunicationManager* getInstance()
    {
        if (!m_instance)
        {
            m_instance = this;
        }

        return m_instance;
    }

public: 
	CommunicationManager();

private:
	const unsigned int m_port = 2139;

	HANDLE m_completionPort; 
	SOCKET m_serverSocket;

public:
	void initialization();
	void playerAccept();


};

