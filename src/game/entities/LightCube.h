#pragma once

#include "../../engine/entities/Entity.h"
#include "../../engine/graphics/models/Model.h"
#include "../../engine/graphics/Light.h"
#include "../../engine/utilities/ResourceManager.h"

class LightCube : public Entity  {
public:
	LightCube(glm::vec3 position, std::shared_ptr<ResourceManager> resourceManager);

	// Setters
	void SetColour(glm::vec3 colour) { _colour = colour; };
	// Getters
	const glm::vec3& GetColour() const { return _colour; };
	std::shared_ptr<PointLight> GetLight() { return _light; };

	// Overrides
	void SetPosition(glm::vec3 position) override;
private:
	std::shared_ptr<PointLight> _light;
	std::shared_ptr<ResourceManager> _resourceManager;
	glm::vec3 _colour = glm::vec3(1.0f, 1.0f, 1.0f);

};