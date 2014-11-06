/*
 * AutomataContainer.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: ville
 */

#include <scenes/automata/CellStatesContainer.h>
#include <cmath>

namespace mossman {
namespace scenes {
namespace automata {

CellStatesContainer::CellStatesContainer(int width, int height) : mWidth(width), mHeight(height) {
	int cellCount = mWidth * mHeight;
	mStates = new bool[cellCount];

	for(int i = 0; i < cellCount; i++) {
		mStates[i] = false;
	}
}

CellStatesContainer::~CellStatesContainer() {
	// TODO Auto-generated destructor stub
}

bool CellStatesContainer::get(int x, int y) const {
	return mStates[index(x, y)];
}

void CellStatesContainer::set(int x, int y, bool state) {
	mStates[index(x,y)] = state;
}

int CellStatesContainer::index(int x, int y) const {
	return wrapY(y) * mWidth + wrapX(x);
}

int CellStatesContainer::wrap(int num, int max) {
	if(num >= 0 && num <= max) {
		return num;
	}

	if(num < 0) {
		return std::abs((max + num) % max);
	} else {
		return num % max;
	}
}

int CellStatesContainer::wrapX(int x) const {
	static int maxX = mWidth-1;
	return wrap(x, maxX);
}

int CellStatesContainer::wrapY(int y) const {
	static int maxY = mHeight-1;
	return wrap(y, maxY);
}

} /* namespace automata */
} /* namespace scenes */
} /* namespace mossman */
