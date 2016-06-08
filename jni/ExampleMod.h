#pragma once

#include "nativetools-api/Mod.h"

class Item;

class ExampleMod : public Mod
{
public:
	static Item* testItem;

	ExampleMod() : Mod() {};
	virtual void initItems();
	virtual void initVanillaCreativeItems();
	virtual void initCustomCreativeItems();
};