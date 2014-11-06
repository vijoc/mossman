/*
 * AutomataScene.h
 *
 *  Created on: Nov 5, 2014
 *      Author: ville
 */

#ifndef SCENES_AUTOMATASCENE_H_
#define SCENES_AUTOMATASCENE_H_

#include "core/Scene.h"

namespace mossman {
namespace scenes {

class AutomataScene : public Scene {
public:
	AutomataScene(int width, int height);
	virtual ~AutomataScene();

	virtual void update(double dt);

private:
	int mWidth;
	int mHeight;
};

} /* namespace scenes */
} /* namespace mossman */

#endif /* SCENES_AUTOMATASCENE_H_ */
