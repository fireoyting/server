//////////////////////////////////////////////////////////////////////
//
// Filename    : GCChangeShapeHandler.cc
// Written By  : elca@ewestsoft.com
// Description :
//
//////////////////////////////////////////////////////////////////////

// include files
#include "GCChangeShape.h"

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void GCChangeShapeHandler::execute (GCChangeShape * pGCChangeShape , Player * pPlayer )
	 throw(Error )
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#if __TEST_CLIENT__

	//cout << pGCChangeShape->toString() << endl;
	
#elif __WINDOWS__

#endif

	__END_DEBUG_EX __END_CATCH
}