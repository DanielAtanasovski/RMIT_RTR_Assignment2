#pragma once
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include "../graphics/models/Model.h"

class Entity {
public:
	Entity(Model model, std::shared_ptr<Shader> shader) : _shader(shader), _model(model) {
		_position = glm::vec3(0);
		_scale = glm::vec3(1);
		_rotation = glm::vec3(0);
	};

	virtual void Draw();

	// Setters
	virtual void SetScale(glm::vec3 scale) { _scale = scale; };
	virtual void SetPosition(glm::vec3 position) { _position = position; };
	virtual void SetRotation(glm::vec3 rotation) { _rotation = rotation; };
	virtual void SetPerspectiveMatrix(glm::mat4 perspectiveMatrix) { _shader->use(); _shader->setMatrix4("perspectiveMatrix", perspectiveMatrix); }
	virtual void SetViewMatrix(glm::mat4 viewMatrix) { _shader->use(); _shader->setMatrix4("viewMatrix", viewMatrix); }
	virtual void SetShader(std::shared_ptr<Shader> shader) { _shader = shader; }
	virtual void SetMaterial(Material material, bool textured, bool specular) { _model.SetMaterial(material, textured, specular); }

	// Getters
	glm::mat4 GetModelMatrix();
	Shader& GetShader() { return *_shader; };
	Model& GetModel() { return _model; };
	glm::vec3 GetPosition() { return _position; };
	glm::vec3 GetScale() { return _scale; };
	glm::vec3 GetRotation() { return _rotation; };

protected:
	std::shared_ptr<Shader> _shader;
	Model _model;
	glm::vec3 _position;
	glm::vec3 _scale;
	glm::vec3 _rotation;
};