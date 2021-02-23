//////////////////////////////////////////////////////////////////////////////
// Filename    : Trouser.h
// Written By  : Elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __TROUSER_H__
#define __TROUSER_H__

#include "Item.h"
#include "ConcreteItem.h"
#include "ItemPolicies.h"
#include "ItemInfo.h"
#include "InfoClassManager.h"
#include "ItemFactory.h"
#include "ItemLoader.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class Trouser;
//////////////////////////////////////////////////////////////////////////////

class Trouser : public ConcreteItem<Item::ITEM_CLASS_TROUSER, NoStack, HasDurability, HasOption, ClothGrade, NoAttacking>
{
public:
	Trouser() throw();
	Trouser(ItemType_t itemType, const list<OptionType_t>& optionType) throw();
	
public:
	virtual void create(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y, ItemID_t itemID=0) throw(Error);
	virtual void save(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y) throw(Error);
	void tinysave(const string & field) const throw (Error)	{ tinysave(field.c_str()); }
	void tinysave(const char* field) const throw (Error);
	virtual string toString() const throw();

	static void initItemIDRegistry(void) throw();

public:
//	virtual ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_TROUSER; }
//	virtual string getObjectTableName() const throw() { return "TrouserObject"; }

/*	virtual ItemType_t getItemType() const throw() { return m_ItemType; }
	virtual void setItemType(ItemType_t itemType) throw() { m_ItemType = itemType; }

	virtual bool hasOptionType() const throw() { return !m_OptionType.empty(); }
	virtual int getOptionTypeSize() const throw() { return m_OptionType.size(); }
	virtual int getRandomOptionType() const throw() { if (m_OptionType.empty()) return 0; int pos = rand()%m_OptionType.size(); list<OptionType_t>::const_iterator itr = m_OptionType.begin(); for (int i=0; i<pos; i++) itr++; return *itr; }
	virtual const list<OptionType_t>& getOptionTypeList() const throw() { return m_OptionType; }
	virtual OptionType_t getFirstOptionType() const throw() { if (m_OptionType.empty()) return 0; return m_OptionType.front(); }
	virtual void removeOptionType(OptionType_t OptionType) throw() { list<OptionType_t>::iterator itr = find(m_OptionType.begin(), m_OptionType.end(), OptionType); if (itr!=m_OptionType.end()) m_OptionType.erase(itr); }
	virtual void changeOptionType(OptionType_t currentOptionType, OptionType_t newOptionType) throw() { list<OptionType_t>::iterator itr = find(m_OptionType.begin(), m_OptionType.end(), currentOptionType); if (itr!=m_OptionType.end()) *itr=newOptionType; }
	virtual void addOptionType(OptionType_t OptionType) throw() { m_OptionType.push_back(OptionType); }
	virtual void setOptionType(const list<OptionType_t>& OptionType) throw() { m_OptionType = OptionType; }

	virtual VolumeWidth_t getVolumeWidth() const throw(Error);
	virtual VolumeHeight_t getVolumeHeight() const throw(Error);
	virtual Weight_t getWeight() const throw(Error);

	virtual Durability_t getDurability() const throw(Error) { return m_Durability; }
	void setDurability(Durability_t durability) throw(Error) { m_Durability = durability; }

	virtual Defense_t getDefenseBonus() const throw(Error);
	virtual Protection_t getProtectionBonus() const throw(Error);
*/
private:
//	ItemType_t		m_ItemType;			// ������ Ÿ��
//	list<OptionType_t>	m_OptionType;		// �ɼ� Ÿ��
//	Durability_t	m_Durability;		// ������
	
	static Mutex    m_Mutex;          // ������ ID ���� ��
	static ItemID_t m_ItemIDRegistry; // Ŭ������ ���� ������ ���̵� �߱ޱ�
};


//////////////////////////////////////////////////////////////////////////////
// class TrouserInfo
//////////////////////////////////////////////////////////////////////////////

class TrouserInfo : public ItemInfo 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_TROUSER; }

	virtual Durability_t getDurability() const throw() { return m_Durability; }
	virtual void setDurability(Durability_t durability) throw() { m_Durability = durability; }

	Defense_t getDefenseBonus() const throw() { return m_DefenseBonus; }
	void setDefenseBonus(Defense_t acBonus) throw() { m_DefenseBonus = acBonus; }

	Protection_t getProtectionBonus() const throw() { return m_ProtectionBonus; }
	void setProtectionBonus(Protection_t acBonus) throw() { m_ProtectionBonus = acBonus; }

	virtual uint getItemLevel(void) const throw() { return m_ItemLevel; }
	virtual void setItemLevel(uint level) throw() { m_ItemLevel = level; }

	virtual string toString() const throw();

private:
	Durability_t	m_Durability;		// ������
	Defense_t		m_DefenseBonus;		// ���߷� ���ʽ�
	Protection_t	m_ProtectionBonus;
	uint			m_ItemLevel;
};


//////////////////////////////////////////////////////////////////////////////
// class TrouserInfoManager;
//////////////////////////////////////////////////////////////////////////////

class TrouserInfoManager : public InfoClassManager 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_TROUSER; }
	virtual void load() throw(Error);
};

// global variable declaration
extern TrouserInfoManager* g_pTrouserInfoManager;


//////////////////////////////////////////////////////////////////////////////
// class TrouserFactory
//////////////////////////////////////////////////////////////////////////////

class TrouserFactory : public ItemFactory 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_TROUSER; }
	virtual string getItemClassName() const throw() { return "Trouser"; }
	
public:
	virtual Item* createItem(ItemType_t ItemType, const list<OptionType_t>& OptionType) throw() { return new Trouser(ItemType,OptionType); }
};


//////////////////////////////////////////////////////////////////////////////
// class TrouserLoader;
//////////////////////////////////////////////////////////////////////////////

class TrouserLoader : public ItemLoader 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_TROUSER; }
	virtual string getItemClassName() const throw() { return "Trouser"; }

public:
	virtual void load(Creature* pCreature) throw(Error);
	virtual void load(Zone* pZone) throw(Error);
	virtual void load(StorageID_t storageID, Inventory* pInventory) throw(Error);
};

extern TrouserLoader* g_pTrouserLoader;

#endif