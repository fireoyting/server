//////////////////////////////////////////////////////////////////////
//
// Filename    : GCBloodBibleSignInfoHandler.cc
// Written By  : reiot@ewestsoft.com
// Description :
//
//////////////////////////////////////////////////////////////////////

// include files
#include "GCBloodBibleSignInfo.h"

//////////////////////////////////////////////////////////////////////
//
// Ŭ���̾�Ʈ���� �����κ��� �޽����� �޾����� ����Ǵ� �޽���̴�.
//
//////////////////////////////////////////////////////////////////////
void GCBloodBibleSignInfoHandler::execute (GCBloodBibleSignInfo * pPacket , Player * pPlayer )
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
	
#ifdef __GAME_CLIENT__
	//cout << pPacket->toString() << endl;
#endif

	__END_DEBUG_EX __END_CATCH
}