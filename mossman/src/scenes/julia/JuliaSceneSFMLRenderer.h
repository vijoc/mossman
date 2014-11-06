/*
 * JuliaSceneSFMLRenderer.h
 *
 *  Created on: Nov 3, 2014
 *      Author: ville
 */

#ifndef MOSSMAN_SRC_SCENES_JULIA_JULIASCENESFMLRENDERER_H_
#define MOSSMAN_SRC_SCENES_JULIA_JULIASCENESFMLRENDERER_H_

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "graphics/SceneSFMLRenderer.h"

namespace mossman {
namespace scenes {

class JuliaScene;

namespace julia {

class JuliaSceneSFMLRenderer : public graphics::SceneSFMLRenderer<JuliaScene> {
public:
	JuliaSceneSFMLRenderer(sf::RenderWindow* context, JuliaScene* scene);
	virtual ~JuliaSceneSFMLRenderer();
	void render() const override;
private:
	mutable sf::Shader mShader;
	sf::VertexArray mVertex;
	sf::Texture mTexture;
	float mShrink;
};

} /* namespace julia */
} /* namespace scenes */
} /* namespace mossman */

#endif /* MOSSMAN_SRC_SCENES_JULIA_JULIASCENESFMLRENDERER_H_ */
