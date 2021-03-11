#include "ItemType.h"

ItemType::ItemType() {
	item = " ";
};

RelationType ItemType::ComparedTo(ItemType inputItem)
{
	if (item > inputItem.Get()) {
		return GREATER;
	} else if (item < inputItem.Get()) {
		return LESS;
	} else
		return EQUAL;
}