/*
 * SceneRenderer.h
 *
 *  Created on: Nov 4, 2014
 *      Author: ville
 */

#ifndef MOSSMAN_SRC_GRAPHICS_SCENERENDERER_H_
#define MOSSMAN_SRC_GRAPHICS_SCENERENDERER_H_

#include "Renderer.h"

namespace mossman {

template<class TScene>
class SceneRenderer : public Renderer {
public:
	SceneRenderer(TScene* scene) {
		mScene = scene;
	}
	virtual ~SceneRenderer() {};
protected:
	TScene* mScene;
};

} /* namespace mossman */

#endif /* MOSSMAN_SRC_GRAPHICS_SCENERENDERER_H_ */
