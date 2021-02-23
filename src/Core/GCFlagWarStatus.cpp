//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCFlagWarStatus.cpp 
// Written By  : elca@ewestsoft.com
// Description : �ڽſ��� ���� ����� ������ �˸��� ���� ��Ŷ Ŭ������
//               ��� ����.
// 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// include files
//////////////////////////////////////////////////////////////////////
#include "GCFlagWarStatus.h"



//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
GCFlagWarStatus::GCFlagWarStatus () 
     throw()
{
	__BEGIN_TRY
	__END_CATCH
}

	
//////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////
GCFlagWarStatus::~GCFlagWarStatus () 
    throw()
{
	__BEGIN_TRY
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////
void GCFlagWarStatus::read (SocketInputStream & iStream ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	iStream.read(m_TimeRemain);
	iStream.read(m_FlagCount[0]);
	iStream.read(m_FlagCount[1]);
	iStream.read(m_FlagCount[2]);

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
//////////////////////////////////////////////////////////////////////
void GCFlagWarStatus::write (SocketOutputStream & oStream ) 
     const throw(ProtocolException , Error )
{
	__BEGIN_TRY

	oStream.write(m_TimeRemain);
	oStream.write(m_FlagCount[0]);
	oStream.write(m_FlagCount[1]);
	oStream.write(m_FlagCount[2]);
		
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
//
// execute packet's handler
//
//////////////////////////////////////////////////////////////////////
void GCFlagWarStatus::execute (Player * pPlayer ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCFlagWarStatusHandler::execute(this , pPlayer);
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// get packet's debug string
//
//////////////////////////////////////////////////////////////////////
string GCFlagWarStatus::toString () 
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCFlagWarStatus("
		<< ")";
	return msg.toString();

	__END_CATCH
}
