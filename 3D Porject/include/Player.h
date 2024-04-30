#ifndef PLAYER_H
#define PLAYER_H

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

#include <stdio.h>
#include <string.h>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <./include/Cube.h>

using namespace glm;
using namespace std;

namespace gpp
{
	// GameObject Type
	enum class TYPEPLAYER
	{
		PLAYER,
		NPC,
		BOSS
	};


	class Player {
	private:
		GLfloat vertex[ARRAY_SIZE(vertices)]; // Array of vertex positions
		GLfloat colour[ARRAY_SIZE(colours)];  // Array of vertex colours
		GLfloat uv[ARRAY_SIZE(uvs)];		  // Array of texture coordinates
		GLfloat index[ARRAY_SIZE(indices)];	  // Array of vertex indices

		vec3 position; // Position of the game object in 3D space
		mat4 model;	   // Model Matrix for GameObject
		mat4 mvp;	   // Model View Project Matrix
		TYPEPLAYER type;	   // Player name

	public:
		Player(TYPEPLAYER type);
		~Player();

		/*void HandleInput();*/

		vec3 getPosition();
		void setPosition(vec3 position);

		mat4 getModelMatrix();
		void setModelMatrix(mat4 model);

		mat4 getMVPMatrix();
		void setMVPMatrix(mat4 model);

		GLfloat* getVertex();
		int getVertexCount();

		GLfloat* getColor();
		int getColorCount();

		GLfloat* getUV();
		int getUVCount();

		GLfloat* getIndex();
		int getIndexCount();

		string getName();
	};
}
#endif // !PLAYER_H
