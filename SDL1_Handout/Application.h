#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"
#include "Module.h"
#include "Dummy.h"
#include "ModuleWindow.h"

#define NUM_MODULES 2

class Application
{
public:

	Module* modules[NUM_MODULES];

public:
	~Application() {
		for (int i = NUM_MODULES - 1; i >= 0; --i) {
			delete modules[i];
		}
	}
	Application()
	{
		modules[0] = new ModuleDummy();
		//modules[1] = new ModuleWindow();
		// TODO 7: Create your new module "DummyESC"
		// it should check if player it ESC key use kbhit()
		// http://www.cprogramming.com/fod/kbhit.html
	}

	// INIT all modules
	bool Init() 
	{
		for (int i = 0; i < NUM_MODULES; ++i) {
			if (modules[i]->Init() == false) return false;
		}
		
		// TODO 5: Make sure that if Init() / PreUpdate/Update/PostUpdate/CleanUP return
		// an exit code App exits correctly.
		return true; 
	}

	// TODO 4: Add PreUpdate and PostUpdate cal
	// UPDATE all modules
	// TODO 2: Make sure all modules receive its update
	update_status Update() {
		for (int i = 0; i < NUM_MODULES; ++i) {
			if (modules[i]->PreUpdate() == UPDATE_STOP) return update_status::UPDATE_ERROR;
		}
		//return update_status::UPDATE_CONTINUE;
		for (int i = 0; i < NUM_MODULES; ++i) {
			if (modules[i]->Update() == UPDATE_STOP) return update_status::UPDATE_ERROR;
			//return update_status::UPDATE_CONTINUE;
		}
		for (int i = 0; i < NUM_MODULES; ++i) {
			if (modules[i]->PostUpdate() == UPDATE_STOP) return update_status::UPDATE_ERROR;
		}
		return update_status::UPDATE_CONTINUE;
	}
	// EXIT Update 
	// TODO 3: Make sure all modules have a chance to cleanup
	bool CleanUp()
	{
		for (int i = NUM_MODULES - 1; i >= 0; --i) {
			if (modules[i]->CleanUp() == false) return false;
		}
		return true;
	}
};

#endif // __APPLICATION_H__