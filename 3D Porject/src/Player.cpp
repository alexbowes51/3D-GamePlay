#include "./include/Player.h"

gpp::Player::Player(TYPEPLAYER type)
{
	memcpy(this->vertex, vertices, sizeof(this->vertex));
	memcpy(this->colour, colours, sizeof(this->colour));
	memcpy(this->uv, uvs, sizeof(this->uv));

	for (int i = 1; i < 6; i++)
		memcpy(&uv[i * 4 * 2], &uv[0], 2 * 4 * sizeof(GLfloat));

	memcpy(this->index, indices, sizeof(this->index));

	this->position = vec3(0.0f); // Init Position at 0.0f

	this->mvp = mat4(
		1.0f // Identity Matrix
	);

	this->model = mat4(
		1.0f // Identity Matrix
	);
}

gpp::Player::~Player()
{

}

vec3 gpp::Player::getPosition()
{
	return this->position;
}

void gpp::Player::setPosition(vec3 position)
{
	this->position = position;
}

mat4 gpp::Player::getModelMatrix()
{
	return this->model;
}

void gpp::Player::setModelMatrix(mat4 model)
{
	this->model = model;
}

mat4 gpp::Player::getMVPMatrix()
{
	return this->mvp;
}

void gpp::Player::setMVPMatrix(mat4 model)
{
	this->mvp = mvp;
}

GLfloat* gpp::Player::getVertex()
{
	return this->vertex;
}

int gpp::Player::getVertexCount()
{
	return ARRAY_SIZE(vertex) / 3;
}

GLfloat* gpp::Player::getColor()
{
	return this->colour;
}

int gpp::Player::getColorCount()
{
	return ARRAY_SIZE(colours) / 4;
}

GLfloat* gpp::Player::getUV()
{
	return this->uv;
}

int gpp::Player::getUVCount()
{
	return ARRAY_SIZE(uv);
}

GLfloat* gpp::Player::getIndex()
{
	return this->index;
}

int gpp::Player::getIndexCount()
{
	return ARRAY_SIZE(index) / 3;
}

string gpp::Player::getName()
{
	return "Player";
}
