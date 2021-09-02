#pragma once
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include "../graphics/models/Model.h"

class Entity {
public:
	Entity(Model model, Shader shader) : _shader(shader), _model(model) {
		_position = glm::vec3(0);
		_scale = glm::vec3(1);
		_rotation = glm::vec3(0);
	};

	virtual void Draw();

	// Setters
	void SetScale(glm::vec3 scale) { _scale = scale; };
	void SetPosition(glm::vec3 position) { _position = position; };
	void SetRotation(glm::vec3 rotation) { _rotation = rotation; };
	void SetPerspectiveMatrix(glm::mat4 perspectiveMatrix) { _shader.use(); _shader.setMatrix4("perspectiveMatrix", perspectiveMatrix); }
	void SetViewMatrix(glm::mat4 viewMatrix) { _shader.use(); _shader.setMatrix4("viewMatrix", viewMatrix); }
	void SetShader(Shader shader) { _shader = shader; }

	// Getters
	glm::mat4 GetModelMatrix();

protected:
	Shader _shader;
	Model _model;
	glm::vec3 _position;
	glm::vec3 _scale;
	glm::vec3 _rotation;
};