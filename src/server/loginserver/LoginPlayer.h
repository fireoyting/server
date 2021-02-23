//////////////////////////////////////////////////////////////////////
// 
// Filename    : LoginPlayer.h 
// Written by  : reiot@ewestsoft.com
// Description : ���� ������ �÷��̾� Ŭ����
// 
//////////////////////////////////////////////////////////////////////

#ifndef __LOGIN_PLAYER_H__
#define __LOGIN_PLAYER_H__

// include files
#include "Player.h"
#include "Mutex.h"
#include "PlayerStatus.h"
#include <deque>
#include "Timeval.h"
#include "PaySystem.h"
#include "gameserver/billing/BillingPlayerInfo.h"
#include "chinabilling/CBillingPlayerInfo.h"
#include "Gpackets/GCReconnectLogin.h"

#include "Packet.h"

class LCPCList;

//////////////////////////////////////////////////////////////////////
//
// class LoginPlayer
//
// ���� ������ �÷��̾� Ŭ����
//
// Player Ŭ������ ��ӹ޾Ƽ�, ���� ���������� ���Ǵ� Mutex �� 
// Creature ���� ������ �� �޽��, PreviousPacket ���� ������ ��
// �޼ҵ���� �߰��ߴ�.
//
// Ư�� processOutput() �� sendPacket()�� Race Condition �� �߻��� ��
// �����Ƿ�, Mutex �� ��ȣ�Ǿ�� �Ѵ�. ( MODE-IV�� ����̸�, MODE-I, II
// �� ��쿡�� processInput(), processCommand() ��� Mutex �� ��ȣ�ؾ�
// �Ѵ�.)
//
//////////////////////////////////////////////////////////////////////

class LoginPlayer : public Player, public PaySystem, public BillingPlayerInfo, public CBillingPlayerInfo {

public :

	// �����س��� ���� ��Ŷ�� ����
	static const uint nPacketHistory = 10;

	static const uint maxFailure  = 3;

public :
	
	// constructor
	LoginPlayer (Socket * pSocket) throw ( Error );
	
	// destructor
	~LoginPlayer () throw ( Error );

	// read socket's receive buffer and fill input buffer
	//virtual void processInput () throw ( IOException , Error );
	
	// parse packet and execute handler for the packet
	virtual void processCommand ( bool Option = true ) throw ( IOException , Error );
	
	// flush output buffer to socket's send buffer
	//virtual void processOutput () throw ( IOException , Error );
	
	// send packet to player's output buffer
	virtual void sendPacket ( Packet * packet ) throw ( ProtocolException , Error );

	// disconnect
	// ���� �α׾ƿ��� ��� disconnect(LOGOUT)
	virtual void disconnect ( bool bDisconnected = DISCONNECTED ) throw ( Error );
	virtual void disconnect_nolog ( bool bDisconnected = DISCONNECTED ) throw ( Error );

	
	// get debug string
	virtual string toString () const throw ( Error );
	
public :

	// return recent N-th packet
	// �ֱ� ���۵� N ��° ��Ŷ�� �����Ѵ�.
	Packet * getOldPacket ( uint prev = 0 ) throw ( OutOfBoundException , NoSuchElementException );

	// return recent packet which has packetID
	// Ư�� ID�� ���� ��Ŷ �� ���� �ֱ��� ��Ŷ�� �����Ѵ�.
	Packet * getOldPacket ( PacketID_t packetID ) throw ( NoSuchElementException );

	// get/set player's status
	PlayerStatus getPlayerStatus () const throw () { return m_PlayerStatus; }
	void setPlayerStatus ( PlayerStatus playerStatus ) throw () { m_PlayerStatus = playerStatus; }

	// ������ ȸ��
	uint getFailureCount () const throw () { return m_FailureCount; }
	void setFailureCount ( uint nFailed ) throw () { m_FailureCount = nFailed; }

    // get / set GoreLevel
    bool isAdult() const throw() { return m_isAdult; }
    void setAdult(bool isAdult) throw() { m_isAdult = isAdult; }

public :
	int		getKickCharacterCount() const throw()	{ return m_KickCharacterCount; }	
	void 	setExpireTimeForKickCharacter() throw();

	// ���� ������ ID
	WorldID_t getWorldID() const throw() { return m_WorldID; }
	void setWorldID( WorldID_t WorldID ) throw() { m_WorldID = WorldID; }

	// ���� ������ ID
	WorldID_t getGroupID() const throw() { return m_ServerGroupID; }
	void setGroupID( ServerGroupID_t ServerGroupID ) throw() { m_ServerGroupID = ServerGroupID; }

	// ���� ������ ID
	uint getLastSlot() const throw() { return m_LastSlot; }
	void setLastSlot( uint lastSlot ) throw() { m_LastSlot = lastSlot; }

    // WorldID, GroupID�� �����Ǿ���?
    bool isSetWorldGroupID() const throw() { return m_bSetWorldGroupID; }
    void setWorldGroupID(bool bSet) throw() { m_bSetWorldGroupID = bSet; }

    // ���������� ������ ĳ������ �̸�
	const string& getLastCharacterName() const throw() { return m_LastCharacterName; }
	void setLastCharacterName( const string& name ) throw() { m_LastCharacterName = name; }

	const string& getZipcode() const throw() { return m_Zipcode; }
	void setZipcode( const string& zipcode ) throw() { m_Zipcode = zipcode; }

	const string& getSSN() const throw() { return m_SSN; }
	void setSSN( const string& ssn ) throw() { m_SSN = ssn; }

	bool isFreePass() const	{ return m_bFreePass; }
	void setFreePass(bool bFreePass=true) { m_bFreePass = bFreePass; }

	bool isWebLogin() const { return m_bWebLogin; }
	void setWebLogin( bool bWebLogin = true ) { m_bWebLogin = bWebLogin; }

	void makePCList( LCPCList& lcPCList ) throw( DisconnectException );

public :
	void sendLGKickCharacter() throw();
	void sendLCLoginOK() throw();

public :
	void    setBillingSession() throw (Error)   { BillingPlayerInfo::setBillingSession(this); }
	bool    sendBillingLogin() throw (Error);


private :
	
	// previous packet queue
	deque<Packet *> m_PacketHistory;

	// player status
	PlayerStatus m_PlayerStatus;

	// expire time 
	Timeval m_ExpireTime;

	// ĳ���� ���(CLRegisterPlayer) �Ǵ� �α���(CLLogin)�� ������ ȸ��
	uint m_FailureCount;

	// mutex
	mutable Mutex m_Mutex;

	// ���� ���� ID
	bool			m_bSetWorldGroupID;
	WorldID_t 		m_WorldID;
	ServerGroupID_t m_ServerGroupID;
	uint			m_LastSlot;
	string			m_LastCharacterName;

	// LoginPlayerData������.. T_T;
	string			m_SSN;
	string			m_Zipcode;

	bool m_isAdult;

	// '�̹� ���� ��'�� ��� ĳ���� ���� ���� ���� ��� �ð�
	uint    m_KickCharacterCount;
	Timeval m_ExpireTimeForKickCharacter;	

	// �ٸ� ������ ����(�ݸ���)�� �޾Ҵٰ� �ϰ�.. FreePass�� �޴´�. - -; by sigi. 2002.10.23
	bool 			m_bFreePass;

	// �� �α��� ���
	bool			m_bWebLogin;
};

#endif