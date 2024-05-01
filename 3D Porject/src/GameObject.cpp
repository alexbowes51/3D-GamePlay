/**
 * @file GameObject.h
 * @brief Contains the implementation of the GameObject class, representing a game object with vertex, color, and UV data.
 */

#include <./include/GameObject.h>

using namespace gpp; // GPP namespace

/**
 * @brief Default constructor for the GameObject class.
 *
 * Initializes a GameObject by copying vertex, color, and UV data from the Cube class.
 * UV data is copied to all faces of the GameObject.
 * The position of the GameObject is set to the origin (0, 0, 0).
 */
GameObject::GameObject(TYPE type)
{
    // Copy the Cube contents into GameObject
    memcpy(this->vertex, vertices, sizeof(this->vertex));
    memcpy(this->colour, colours, sizeof(this->colour));
    memcpy(this->uv, uvs, sizeof(this->uv));

    // Copy UV's to all faces
    for (int i = 1; i < 6; i++)
        memcpy(&uv[i * 4 * 2], &uv[0], 2 * 4 * sizeof(GLfloat));

    memcpy(this->index, indices, sizeof(this->index));

    this->position = vec3(0.0f); // Init Position at 0.0f
    this->type = type;

    // Initialize MVP matrix as Identity Matrix
	this->mvp = mat4(
		1.0f // Identity Matrix
	);

    // Initialize Model matrix as Identity Matrix
	this->model = mat4(
		1.0f // Identity Matrix
	);
}


GameObject::~GameObject()
{
}


vec3 GameObject::getPosition() { return this->position; }


void GameObject::setPosition(vec3 position) { this->position = position; }


mat4 GameObject::getModelMatrix() { return this->model; }


void GameObject::setModelMatrix(mat4 model) { this->model = model; }


mat4 GameObject::getMVPMatrix() { return this->mvp; }


void GameObject::setMVPMatrix(mat4 mvp) { this->mvp = mvp; }


GLfloat *GameObject::getVertex() { return this->vertex; }

int GameObject::getVertexCount() { return ARRAY_SIZE(vertex) / 3; }


GLfloat *GameObject::getColor() { return this->colour; }


int GameObject::getColorCount() { return ARRAY_SIZE(colours) / 4; }


GLfloat *GameObject::getUV() { return this->uv; }


int GameObject::getUVCount() { return ARRAY_SIZE(uv); }


GLfloat *GameObject::getIndex() { return this->index; }


int GameObject::getIndexCount() { return ARRAY_SIZE(index) / 3; }


string GameObject::enumToString()
{
    switch (this->type)
    {
    case TYPE::PLAYER:
        return "Player GameObject";
    case TYPE::NPC:
        return "NPC GameObject";
    case TYPE::BOSS:
        return "BOSS GameObject";
    default:
        return "Unknown GameObject";
    }
}

TYPE GameObject::getType() const
{
    return type;
}

