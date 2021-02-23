//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCAttackArmsOK5.h 
// Written By  : elca@ewestsoft.com
// Description : ��� ����ڴ� �� �� �ְ�, �����ڴ� �� �� ���� ������� ������ ��Ŷ
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_ATTACK_ARMS_OK_5_H__
#define __GC_ATTACK_ARMS_OK_5_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class GCAttackArmsOK5;
//
// ���Ӽ������� Ŭ���̾�Ʈ�� �ڽ��� ����� ������ �˷��ֱ� ���� Ŭ����
//
//////////////////////////////////////////////////////////////////////

class GCAttackArmsOK5 : public Packet {

public :
	
	// constructor
	GCAttackArmsOK5() throw();
	
	// destructor
	~GCAttackArmsOK5() throw();

	
public :
	
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GC_ATTACK_ARMS_OK_5; }
	
	// get packet's body size
	// ����ȭ��, �̸� ���� ������ ����Ѵ�.
	PacketSize_t getPacketSize() const throw() { return szSkillType + szObjectID + szObjectID + szbool; }

	// get packet's name
	string getPacketName() const throw() { return "GCAttackArmsOK5"; }
	
	// get packet's debug string
	string toString() const throw();

	SkillType_t getSkillType() { return m_SkillType; }
	void setSkillType(SkillType_t skillType ) { m_SkillType = skillType; }

	// get / set ObjectID
	ObjectID_t getObjectID() const throw() { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID) throw() { m_ObjectID = ObjectID; }

	// get / set ObjectID
	ObjectID_t getTargetObjectID() const throw() { return m_TargetObjectID; }
	void setTargetObjectID(ObjectID_t TargetObjectID) throw() { m_TargetObjectID = TargetObjectID; }
//	Coord_t getTargetX() const throw() { return m_X;}
//	Coord_t getTargetY() const throw() { return m_Y;}
//	void setTargetXY(Coord_t X, Coord_t Y) throw() { m_X = X; m_Y = Y;}

	// get / set success
	bool getSkillSuccess() const throw() { return m_bSuccess;}
	void setSkillSuccess(bool bSuccess) throw() { m_bSuccess = bSuccess;}

private :
	
	SkillType_t m_SkillType;
	// ObjectID
	ObjectID_t m_ObjectID;
//	Coord_t m_X, m_Y;

	// TargetObjectID
	ObjectID_t m_TargetObjectID;

	// bool
	bool m_bSuccess;

};


//////////////////////////////////////////////////////////////////////
//
// class GCAttackArmsOK5Factory;
//
// Factory for GCAttackArmsOK5
//
//////////////////////////////////////////////////////////////////////

class GCAttackArmsOK5Factory : public PacketFactory {

public :
	
	// constructor
	GCAttackArmsOK5Factory() throw() {}
	
	// destructor
	virtual ~GCAttackArmsOK5Factory() throw() {}

	
public :
	
	// create packet
	Packet* createPacket() throw() { return new GCAttackArmsOK5(); }

	// get packet name
	string getPacketName() const throw() { return "GCAttackArmsOK5"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_ATTACK_ARMS_OK_5; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const throw() { return szSkillType + szObjectID + szObjectID+ szbool; }

};


//////////////////////////////////////////////////////////////////////
//
// class GCAttackArmsOK5Handler;
//
//////////////////////////////////////////////////////////////////////

class GCAttackArmsOK5Handler {

public :

	// execute packet's handler
	static void execute(GCAttackArmsOK5* pGCAttackArmsOK5, Player* pPlayer) throw(Error);

};

#endif