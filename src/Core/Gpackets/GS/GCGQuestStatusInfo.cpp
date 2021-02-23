//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCGQuestStatusInfo.cpp 
// Written By  : elca@ewestsoft.com
// Description : �ڽſ��� ���� ����� ������ �˸��� ���� ��Ŷ Ŭ������
//               ��� ����.
// 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// include files
//////////////////////////////////////////////////////////////////////
#include "GCGQuestStatusInfo.h"


//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
GCGQuestStatusInfo::GCGQuestStatusInfo () 
     throw ()
{
	__BEGIN_TRY
	__END_CATCH
}

	
//////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////
GCGQuestStatusInfo::~GCGQuestStatusInfo () 
    throw ()
{
	__BEGIN_TRY

/*	list<QuestStatusInfo*>::iterator itr = m_Infos.begin();

	for ( ; itr != m_Infos.end() ; ++itr )
	{
		SAFE_DELETE( (*itr) );
	}*/

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////
void GCGQuestStatusInfo::read ( SocketInputStream & iStream ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY

	BYTE size;
	iStream.read(size);

	for ( int i=0; i<size; ++i )
	{
		QuestStatusInfo* pInfo = new QuestStatusInfo(0);
		pInfo->read(iStream);
		m_Infos.push_back(pInfo);
	}

	
	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
//////////////////////////////////////////////////////////////////////
void GCGQuestStatusInfo::write ( SocketOutputStream & oStream ) 
     const throw ( ProtocolException , Error )
{
	__BEGIN_TRY

	BYTE size = m_Infos.size();
	oStream.write(size);
	//cout << "����Ʈ ���� : " << (int)size << endl;

	list<QuestStatusInfo*>::const_iterator itr = m_Infos.begin();

	for ( ; itr != m_Infos.end(); ++itr )
	{
		(*itr)->write(oStream);
	}
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// execute packet's handler
//
//////////////////////////////////////////////////////////////////////
void GCGQuestStatusInfo::execute ( Player * pPlayer ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCGQuestStatusInfoHandler::execute( this , pPlayer );
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// get packet's debug string
//
//////////////////////////////////////////////////////////////////////
string GCGQuestStatusInfo::toString () 
	const throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCGQuestStatusInfo("
		<< ")";
	return msg.toString();

	__END_CATCH
}

