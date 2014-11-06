/*
 * AutomataContainer.h
 *
 *  Created on: Nov 5, 2014
 *      Author: ville
 */

#ifndef SCENES_AUTOMATA_CELLSTATESCONTAINER_H_
#define SCENES_AUTOMATA_CELLSTATESCONTAINER_H_

#include <utility>

namespace mossman {
namespace scenes {
namespace automata {

class CellStatesContainer {
public:
	CellStatesContainer(int width, int height);
	virtual ~CellStatesContainer();
	bool get(int x, int y) const;
	void set(int x, int y, bool state);

private:
	static int wrap(int num, int max);
	int wrapX(int x) const;
	int wrapY(int y) const;
	int index(int x, int y) const;

	int mWidth;
	int mHeight;
	bool* mStates;
};

} /* namespace automata */
} /* namespace scenes */
} /* namespace mossman */

#endif /* SCENES_AUTOMATA_CELLSTATESCONTAINER_H_ */
