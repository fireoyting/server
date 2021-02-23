//////////////////////////////////////////////////////////////////////
// 
// Filename    : SGGuildInfo.cpp 
// Written By  :
// Description : 
// 
//////////////////////////////////////////////////////////////////////

// include files
#include "SGGuildInfo.h"


//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
SGGuildInfo::SGGuildInfo()
	throw()
{
}

//////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////
SGGuildInfo::~SGGuildInfo()
	throw()
{
	__BEGIN_TRY
	
	// ��� ����Ʈ�� ��� ��ü ����
	clearGuildInfoList();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
// Datagram ��ü�κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////
void SGGuildInfo::read (SocketInputStream& iStream ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY

	WORD szGuildInfo;

	iStream.read(szGuildInfo);
	for (int i = 0; i < szGuildInfo; i++ )
	{
		GuildInfo2* pGuildInfo = new GuildInfo2();
		pGuildInfo->read(iStream);
		m_GuildInfoList.push_front(pGuildInfo);
	}

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// Datagram ��ü�� ��Ŷ�� ���̳ʸ� �̹����� ������.
//////////////////////////////////////////////////////////////////////
void SGGuildInfo::write (SocketOutputStream& oStream ) const 
     throw(ProtocolException , Error )
{
	__BEGIN_TRY

	WORD szGuildInfo = m_GuildInfoList.size();

	oStream.write(szGuildInfo);
	GuildInfoListConstItor2 itr = m_GuildInfoList.begin();
	for (; itr != m_GuildInfoList.end(); itr++ )
	{
		(*itr)->write(oStream);
	}

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// clear guild info list
//////////////////////////////////////////////////////////////////////
void SGGuildInfo::clearGuildInfoList()
	throw()
{
	__BEGIN_TRY

	// GuildInfoList�� �����Ѵ�.
	while(!m_GuildInfoList.empty() )
	{
		GuildInfo2* pGuildInfo = m_GuildInfoList.front();
		m_GuildInfoList.pop_front();
		SAFE_DELETE(pGuildInfo);
	}

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// execute packet's handler
//////////////////////////////////////////////////////////////////////
void SGGuildInfo::execute (Player * pPlayer ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	SGGuildInfoHandler::execute(this);
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// get packet size
//////////////////////////////////////////////////////////////////////
PacketSize_t SGGuildInfo::getPacketSize() const
	throw()
{
	__BEGIN_TRY
	
	PacketSize_t PacketSize = szWORD;

	GuildInfoListConstItor2 itr = m_GuildInfoList.begin();
	for (; itr != m_GuildInfoList.end(); itr++ )
	{
		PacketSize += (*itr)->getSize();
	}

	return PacketSize;

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
string SGGuildInfo::toString () const
    throw()
{
	StringStream msg;

	msg << "SGGuildInfo()";

	return msg.toString();
}
