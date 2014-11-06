/*
 * SceneSFMLRenderer.h
 *
 *  Created on: Nov 5, 2014
 *      Author: ville
 */

#ifndef GRAPHICS_SCENESFMLRENDERER_H_
#define GRAPHICS_SCENESFMLRENDERER_H_

#include "SFMLRenderer.h"
#include "core/SceneRenderer.h"

namespace mossman {
namespace graphics {

template<class TScene>
class SceneSFMLRenderer : public SFMLRenderer, public SceneRenderer<TScene> {
public:
	SceneSFMLRenderer(sf::RenderWindow* window, TScene* scene) : SFMLRenderer(window), SceneRenderer<TScene>(scene) {}
	virtual ~SceneSFMLRenderer() {};
};

} /* namespace graphics */
} /* namespace mossman */

#endif /* GRAPHICS_SCENESFMLRENDERER_H_ */
