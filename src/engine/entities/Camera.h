// Daniel Atanasovski
#pragma once

#include <glad/glad.h>
#include <sdl/SDL.h>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const float DEFAULT_YAW = -90.0f;
const float DEFAULT_PITCH = 0.0f;
const float DEFAULT_SPEED = -90.0f;
const glm::vec3 DEFAULT_POSITION = glm::vec3(0, 0, 10);
const glm::vec3 DEFAULT_WORLD_UP = glm::vec3(0,1,0);

class Camera
{
public:
	Camera(glm::vec3 position = DEFAULT_POSITION, glm::vec3 worldUp = DEFAULT_WORLD_UP,
		float yaw = DEFAULT_YAW, float pitch = DEFAULT_PITCH) {
		_position = position;
		_worldUp = worldUp;
		_yaw = yaw;
		_pitch = pitch;
		UpdateCamera();
	}

	// Movement
	void Move(glm::vec3 direction, float delta);

	// Setters
	void SetPosition(glm::vec3 position) { _position = position; };
	void SetDirection(float xRot, float yRot);
	void SetSpeed(float speed) { _speed = speed; }

	// Getters
	glm::mat4 GetViewMatrix() const { return glm::lookAt(_position, _position + _front, _up); }
	const glm::mat4& GetPerspectiveMatrix() const {}
	const glm::vec3& GetPosition() const { return _position; }
	const glm::vec3& GetFront() const { return _front; }
	const glm::vec3& GetUp() const { return _up; }

private:
	void UpdateCamera();
	glm::vec3 _position;
	glm::vec3 _worldUp;

	glm::vec3 _front;
	glm::vec3 _right;
	glm::vec3 _up;

	// Controls
	float _speed = 10.0f;
	float _yawSensitivity = 0.15f;
	float _pitchSensitivity = 0.15f;
	float _yaw = -90.0f;
	float _pitch = 0.0f;
};