//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCThrowBombOK2.cpp 
// Written By  : elca@ewestsoft.com
// Description : �ڽſ��� ���� ����� ������ �˸��� ���� ��Ŷ Ŭ������
//               ��� ����.
// 
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// include files
//////////////////////////////////////////////////////////////////////
#include "GCThrowBombOK2.h"



//////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////
GCThrowBombOK2::GCThrowBombOK2 () 
     throw()
{
	__BEGIN_TRY

	m_CListNum = 0;

	__END_CATCH
}

	
//////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////
GCThrowBombOK2::~GCThrowBombOK2 () 
    throw()
{
	__BEGIN_TRY
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////
void GCThrowBombOK2::read (SocketInputStream & iStream ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	// ����ȭ �۾��� ���� ũ�⸦ �����ϵ��� �Ѵ�.
	iStream.read(m_ObjectID);
	iStream.read(m_X);
	iStream.read(m_Y);
	iStream.read(m_Dir);
	iStream.read(m_ItemType);
    iStream.read(m_CListNum);

    ObjectID_t m_Value;
	int i;

	for(i = 0; i < m_CListNum; i++ ) {
		iStream.read(m_Value);
		m_CList.push_back(m_Value);
	}

	ModifyInfo::read(iStream);
	
	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
//////////////////////////////////////////////////////////////////////
void GCThrowBombOK2::write (SocketOutputStream & oStream ) 
     const throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	// ����ȭ �۾��� ���� ũ�⸦ �����ϵ��� �Ѵ�.
	oStream.write(m_ObjectID);
	oStream.write(m_X);
	oStream.write(m_Y);
	oStream.write(m_Dir);
	oStream.write(m_ItemType);
	
    oStream.write(m_CListNum);

    for (list<ObjectID_t>::const_iterator itr = m_CList.begin(); itr!= m_CList.end() ; itr++ ) {
		oStream.write(*itr);
	}

	ModifyInfo::write(oStream);
	
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
//
// GCThrowBombOK2::addListElement()
// 
// (��ȭ����, ��ȭ��ġ ) �� �� ���� ����Ʈ�� �ֱ� ���� ��� �Լ�. 
//
//////////////////////////////////////////////////////////////////////
void GCThrowBombOK2::addCListElement(ObjectID_t ObjectID )
    throw()
{
    __BEGIN_TRY

    // Creature ID�� �߰��Ѵ�.
    m_CList.push_back(ObjectID);

    // ũ��ó ID count�� ������Ų��.
    m_CListNum++;

    __END_CATCH

}

/*
//////////////////////////////////////////////////////////////////////
//
// GCThrowBombOK2::deleteCListElement()
// 
// Creature List�� ��Ҹ� ���ﶧ �ʿ��� ��� �Լ�.
//
//////////////////////////////////////////////////////////////////////
void GCThrowBombOK2::deleteCListElement()
    throw()
{
    __BEGIN_TRY

    // ũ���� ���̵� �ϳ� �����.
    m_CList.pop_front();

    // ũ��ó ����Ʈ ī���͸� �ϳ� �����.
    m_CListNum--;

    __END_CATCH
}
*/


//////////////////////////////////////////////////////////////////////
//
// execute packet's handler
//
//////////////////////////////////////////////////////////////////////
void GCThrowBombOK2::execute (Player * pPlayer ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCThrowBombOK2Handler::execute(this , pPlayer);
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// get packet's debug string
//
//////////////////////////////////////////////////////////////////////
string GCThrowBombOK2::toString () const
       throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCThrowBombOK2(ObjectID:" << (int)m_ObjectID 
		<< ",X:" << (int)m_X
		<< ",Y:" << (int)m_Y
		<< ",Dir:" << (int)m_Dir
		<< ",ItemType:" << (int)m_ItemType
		<< ",CListNum: " << (int)m_CListNum 
		<< " CListSet(";

	for (list<ObjectID_t>::const_iterator itr = m_CList.begin(); itr!= m_CList.end() ; itr++ ) {
		msg << (int)(*itr) << ",";
	}

	msg << ")";
	msg << ModifyInfo::toString();

	msg << ")";


	return msg.toString();

	__END_CATCH
}

