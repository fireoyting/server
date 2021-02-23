//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCReloadOK.cc 
// Written By  : elca@ewestsoft.com
// Description : CGMove�� ���� ������ �ڱ� �ڽſ��� OK ������ ������
//               ���� ��Ŷ Ŭ���� �Լ� ����
// 
//////////////////////////////////////////////////////////////////////

// include files
#include "GCReloadOK.h"

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
GCReloadOK::GCReloadOK()
	throw()
{
	__BEGIN_TRY

	m_BulletNum = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////
GCReloadOK::~GCReloadOK()
	throw()
{
	__BEGIN_TRY
	
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
// �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////
void GCReloadOK::read (SocketInputStream & iStream ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY

	iStream.read(m_BulletNum);

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
//////////////////////////////////////////////////////////////////////
void GCReloadOK::write (SocketOutputStream & oStream ) const 
     throw(ProtocolException , Error )
{
	__BEGIN_TRY

	oStream.write(m_BulletNum);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
// execute packet's handler
//////////////////////////////////////////////////////////////////////
void GCReloadOK::execute (Player * pPlayer ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCReloadOKHandler::execute(this , pPlayer);
		
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
//
// get packet's debug string
//
//////////////////////////////////////////////////////////////////////
string GCReloadOK::toString () const
       throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCReloadOK("
		<< "BulletNum:" << (int)m_BulletNum
		<< ")";
	return msg.toString();

	__END_CATCH
}
