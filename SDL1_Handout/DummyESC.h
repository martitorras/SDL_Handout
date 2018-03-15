#ifndef __DUMMYESC_H__
#define __DUMMYESC_H__

#include "Module.h"
#include "Globals.h"

class DummyESC : public Module
{
	bool Init()
	{
		LOG("Dummy Init!");
		return true;
	}

	update_status PreUpdate()
	{
		LOG("Dummy PreUpdate!");
		return update_status::UPDATE_CONTINUE;
	}

	update_status Update()
	{
		LOG("Dummy Update!");
		return update_status::UPDATE_CONTINUE;
	}

	update_status PostUpdate()
	{
		LOG("Dummy PostUpdate!");
		return update_status::UPDATE_CONTINUE;
	}

	bool CleanUp()
	{
		LOG("Dummy CleanUp!");
		return true;
	}
};

#endif // __DUMMYESC_H__