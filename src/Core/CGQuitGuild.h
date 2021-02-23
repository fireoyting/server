//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGQuitGuild.h 
// Written By  :
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_QUIT_GUILD_H__
#define __CG_QUIT_GUILD_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGQuitGuild;
//
//////////////////////////////////////////////////////////////////////

class CGQuitGuild : public Packet
{
public:
	CGQuitGuild() {};
    ~CGQuitGuild() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_CG_QUIT_GUILD; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() { return szGuildID; }

	// get packet name
	string getPacketName() const throw() { return "CGQuitGuild"; }

	// get packet's debug string
	string toString() const throw();

	// get/set GuildID
	GuildID_t getGuildID() const throw() { return m_GuildID; }
	void setGuildID(GuildID_t guildID ) throw() { m_GuildID = guildID; }


private :

	//GuildID
	GuildID_t m_GuildID;

};


//////////////////////////////////////////////////////////////////////
//
// class CGQuitGuildFactory;
//
// Factory for CGQuitGuild
//
//////////////////////////////////////////////////////////////////////

class CGQuitGuildFactory : public PacketFactory {

public:
	
	// constructor
	CGQuitGuildFactory() throw() {}
	
	// destructor
	virtual ~CGQuitGuildFactory() throw() {}

	
public:
	
	// create packet
	Packet* createPacket() throw() { return new CGQuitGuild(); }

	// get packet name
	string getPacketName() const throw() { return "CGQuitGuild"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_CG_QUIT_GUILD; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const throw() { return szGuildID; }
};


//////////////////////////////////////////////////////////////////////
//
// class CGQuitGuildHandler;
//
//////////////////////////////////////////////////////////////////////

class CGQuitGuildHandler {

public:

	// execute packet's handler
	static void execute(CGQuitGuild* pCGQuitGuild, Player* pPlayer) throw(Error);

};

#endif