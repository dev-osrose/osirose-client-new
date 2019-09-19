// Fill out your copyright notice in the Description page of Project Settings.

#include "Rose.h"
#include "Modules/ModuleManager.h"

class FUE4OsiroseGameModule : public FDefaultGameModuleImpl {
	virtual void StartupModule() override {
		// called right after the module DLL has been loaded and the module object has been created
	}

	virtual void ShutdownModule() {
		// called before the module is unloaded, right before the module object is destroyed
	}
};;

IMPLEMENT_PRIMARY_GAME_MODULE( FUE4OsiroseGameModule, Rose, "Rose" );
