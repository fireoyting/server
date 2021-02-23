//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCModifyMoney.h 
// Written By  : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_MODIFY_MONEY_H__
#define __GC_MODIFY_MONEY_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"


//////////////////////////////////////////////////////////////////////
//
// class GCModifyMoney;
//
// Ŭ���̾�Ʈ�� ��� ��� â�� ��쵵�� �Ѵ�.
//
//////////////////////////////////////////////////////////////////////

class GCModifyMoney : public Packet {

public :
	GCModifyMoney() {};
    ~GCModifyMoney() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GC_MODIFY_MONEY; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() { return szGold; }

	// get packet name
	string getPacketName() const throw() { return "GCModifyMoney"; }
	
	// get packet's debug string
	string toString() const throw();

	// get/set Amount
	Gold_t getAmount() const throw() { return m_Amount; }
	void setAmount(Gold_t amount ) throw() { m_Amount = amount; }
	

private :
	
	// Registration Fee
	Gold_t m_Amount;
	
};


//////////////////////////////////////////////////////////////////////
//
// class GCModifyMoneyFactory;
//
// Factory for GCModifyMoney
//
//////////////////////////////////////////////////////////////////////

class GCModifyMoneyFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket() throw() { return new GCModifyMoney(); }

	// get packet name
	string getPacketName() const throw() { return "GCModifyMoney"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_MODIFY_MONEY; }

	// get packet's max body size
	// *OPTIMIZATION HINT*
	// const static GCSystemMessagePacketMaxSize �� ����, �����϶�.
	PacketSize_t getPacketMaxSize() const throw() { return szGold; }

};


//////////////////////////////////////////////////////////////////////
//
// class GCModifyMoney;
//
//////////////////////////////////////////////////////////////////////

class GCModifyMoneyHandler {
	
public :
	
	// execute packet's handler
	static void execute(GCModifyMoney* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};

#endif