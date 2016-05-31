#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "CreativeTab.h"

static void (*_Item$initItems)();
static void Item$initItems()
{
	_Item$initItems();
	
	Item* testItem = new Item("testItem", 4000 - 256);
	testItem->setIcon("string", 0);
	Item::mItems[4000] = testItem;
	
	// Our first step is to make a new CreativeTab.  There are many ways to do that as I will demonstrate below.
	// The first method is just to use the default constructor.
	CreativeTab* exampleTab1 = new CreativeTab(); // you can create a creative tab with no params.  This will set the default icon as a barrier.
	// Next we will begin adding items to this tab.  There are many ways to do this also.
	// The first way we can add items is by simply using the itemId and data values of the item we want to add.
	exampleTab1->addItem(4, 0); // this adds cobblestone to the tab.
	// The next method is by using an Item pointer and a data value.
	exampleTab1->addItem(testItem, 0); // adds an apple to the tab.
	// Another way to add items to the tab is with a Block pointer and data value.
	exampleTab1->addItem(Block::mBlocks[45], 0);  // adds bricks to the tab.
	// Finally, you can add items using ItemInstance pointers to have the most precision over the items being added.
	exampleTab1->addItem(new ItemInstance(50, 1, 0)); // adds a torch to the tab
	// Then you can use any combination of these to add more items!
	exampleTab1->addItem(103, 0);
	exampleTab1->addItem(261, 0);
	exampleTab1->addItem(265, 0);
	exampleTab1->addItem(396, 0);
	exampleTab1->addItem(498, 0);
	exampleTab1->addItem(198, 0);
	exampleTab1->addItem(245, 0);
	exampleTab1->addItem(109, 0);
	exampleTab1->addItem(54, 0);
	exampleTab1->addItem(167, 0);
	exampleTab1->addItem(133, 0);
	exampleTab1->addItem(322, 0);
	exampleTab1->addItem(325, 0);
	exampleTab1->addItem(352, 0);
	// when you are finished adding items, be sure to call this function:
	exampleTab1->addToTabsList();
	// Now the tab is finished and will show up on the second inventory page!
	
	// Here are the other ways to initialize a CreativeTab with a different tab icon
	CreativeTab* exampleTab2 = new CreativeTab(42, 0); // Add a tab with an icon of an Iron Block
	exampleTab2->addItem(322, 0);
	exampleTab2->addItem(325, 0);
	exampleTab2->addItem(396, 0);
	exampleTab2->addItem(498, 0);
	exampleTab2->addItem(167, 0);
	exampleTab2->addItem(261, 0);
	exampleTab2->addItem(103, 0);
	exampleTab2->addItem(245, 0);
	exampleTab2->addItem(109, 0);
	exampleTab2->addItem(54, 0);
	exampleTab2->addItem(265, 0);
	exampleTab2->addItem(198, 0);
	exampleTab2->addItem(352, 0);
	exampleTab2->addItem(133, 0);
	exampleTab2->addToTabsList();
	
	CreativeTab* exampleTab3 = new CreativeTab(Item::mItems[334], 0); // Add a tab with an icon of Leather
	exampleTab3->addItem(498, 0);
	exampleTab3->addItem(109, 0);
	exampleTab3->addItem(198, 0);
	exampleTab3->addItem(322, 0);
	exampleTab3->addItem(352, 0);
	exampleTab3->addItem(325, 0);
	exampleTab3->addItem(396, 0);
	exampleTab3->addItem(261, 0);
	exampleTab3->addItem(54, 0);
	exampleTab3->addItem(265, 0);
	exampleTab3->addItem(167, 0);
	exampleTab3->addItem(103, 0);
	exampleTab3->addItem(245, 0);
	exampleTab3->addItem(133, 0);
	exampleTab3->addToTabsList();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	
	return JNI_VERSION_1_2;
}
