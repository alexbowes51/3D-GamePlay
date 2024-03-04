#include <./include/Game.h>
#include <./include/Matrix3f.h>


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube VBO")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

typedef struct
{
	float coordinate[3];
	float color[3];
} Vertex;

Vertex vertex[36];
GLubyte triangles[36];

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glewInit();

	/* Vertices counter-clockwise winding */

	//front face triangle 1

	vertex[0].coordinate[0] = -0.5f;
	vertex[0].coordinate[1] = -0.5f;
	vertex[0].coordinate[2] = 0.0f;

	vertex[1].coordinate[0] = -0.5f;
	vertex[1].coordinate[1] = 0.5f;
	vertex[1].coordinate[2] = 0.0f;

	vertex[2].coordinate[0] = 0.5f;
	vertex[2].coordinate[1] = 0.5f;
	vertex[2].coordinate[2] = 0.0f;

	//front face triangle 2

	vertex[3].coordinate[0] = 0.5f; 
	vertex[3].coordinate[1] = 0.5f;  
	vertex[3].coordinate[2] = 0.0f;

	vertex[4].coordinate[0] = 0.5f; 
	vertex[4].coordinate[1] = -0.5f;  
	vertex[4].coordinate[2] = 0.0f;

	vertex[5].coordinate[0] = -0.5f; 
	vertex[5].coordinate[1] = -0.5f;  
	vertex[5].coordinate[2] = 0.0f;

	//right face triangle 1 
	vertex[6].coordinate[0] = 0.5f;
	vertex[6].coordinate[1] = 0.5f;
	vertex[6].coordinate[2] = 0.0f;

	vertex[7].coordinate[0] = 0.5f;
	vertex[7].coordinate[1] = -0.5f;
	vertex[7].coordinate[2] = 0.0f;

	vertex[8].coordinate[0] = 0.5f;
	vertex[8].coordinate[1] = 0.5f;
	vertex[8].coordinate[2] = 0.5f;

	//right face triangle 2
	vertex[9].coordinate[0] = 0.5f;
	vertex[9].coordinate[1] = 0.5f;
	vertex[9].coordinate[2] = 0.5f;

	vertex[10].coordinate[0] = 0.5f;
	vertex[10].coordinate[1] = -0.5f;
	vertex[10].coordinate[2] = 0.5f;

	vertex[11].coordinate[0] = 0.5f;
	vertex[11].coordinate[1] = -0.5f;
	vertex[11].coordinate[2] = 0.0f;

	//bottom face triangle 1
	vertex[12].coordinate[0] = -0.5f;
	vertex[12].coordinate[1] = -0.5f;
	vertex[12].coordinate[2] = 0.0f;

	vertex[13].coordinate[0] = -0.5f;
	vertex[13].coordinate[1] = -0.5f;
	vertex[13].coordinate[2] = 0.5f;

	vertex[14].coordinate[0] = 0.5f;
	vertex[14].coordinate[1] = -0.5f;
	vertex[14].coordinate[2] = 0.5f;

	//bottom face triangle 2 
	vertex[15].coordinate[0] = 0.5f;
	vertex[15].coordinate[1] = -0.5f;
	vertex[15].coordinate[2] = 0.5f;

	vertex[16].coordinate[0] = 0.5f;
	vertex[16].coordinate[1] = -0.5f;
	vertex[16].coordinate[2] = 0.0f;

	vertex[17].coordinate[0] = -0.5f;
	vertex[17].coordinate[1] = -0.5f;
	vertex[17].coordinate[2] = 0.0f;

	//left face triangle 1 
	vertex[18].coordinate[0] = -0.5f;
	vertex[18].coordinate[1] = 0.5f;
	vertex[18].coordinate[2] = 0.0f;

	vertex[19].coordinate[0] = -0.5f;
	vertex[19].coordinate[1] = -0.5f;
	vertex[19].coordinate[2] = 0.0f;

	vertex[20].coordinate[0] = -0.5f;
	vertex[20].coordinate[1] = 0.5f;
	vertex[20].coordinate[2] = 0.5f;

	//left face triangle 2 
	vertex[21].coordinate[0] = -0.5f;
	vertex[21].coordinate[1] = 0.5f;
	vertex[21].coordinate[2] = 0.5f;

	vertex[22].coordinate[0] = -0.5f;
	vertex[22].coordinate[1] = -0.5f;
	vertex[22].coordinate[2] = 0.5f;

	vertex[23].coordinate[0] = -0.5f;
	vertex[23].coordinate[1] = -0.5f;
	vertex[23].coordinate[2] = 0.0f;


	//top face triangle 1
	vertex[24].coordinate[0] = -0.5f;
	vertex[24].coordinate[1] = 0.5f;
	vertex[24].coordinate[2] = 0.0f;

	vertex[25].coordinate[0] = -0.5f;
	vertex[25].coordinate[1] = 0.5f;
	vertex[25].coordinate[2] = 0.5f;

	vertex[26].coordinate[0] = 0.5f;
	vertex[26].coordinate[1] = 0.5f;
	vertex[26].coordinate[2] = 0.5f;

	//top face triangle 2
	vertex[27].coordinate[0] = 0.5f;
	vertex[27].coordinate[1] = 0.5f;
	vertex[27].coordinate[2] = 0.5f;

	vertex[28].coordinate[0] = 0.5f;
	vertex[28].coordinate[1] = 0.5f;
	vertex[28].coordinate[2] = 0.0f;

	vertex[29].coordinate[0] = -0.5f;
	vertex[29].coordinate[1] = 0.5f;
	vertex[29].coordinate[2] = 0.0f;

	//back face triangle 1 
	vertex[30].coordinate[0] = -0.5f;
	vertex[30].coordinate[1] = -0.5f;
	vertex[30].coordinate[2] = 0.5f;

	vertex[31].coordinate[0] = -0.5f;
	vertex[31].coordinate[1] = 0.5f;
	vertex[31].coordinate[2] = 0.5f;

	vertex[32].coordinate[0] = 0.5f;
	vertex[32].coordinate[1] = 0.5f;
	vertex[32].coordinate[2] = 0.5f;

	//back face triangele 2
	vertex[33].coordinate[0] = 0.5f;
	vertex[33].coordinate[1] = 0.5f;
	vertex[33].coordinate[2] = 0.5f;

	vertex[34].coordinate[0] = 0.5f;
	vertex[34].coordinate[1] = -0.5f;
	vertex[34].coordinate[2] = 0.5f;

	vertex[35].coordinate[0] = -0.5f;
	vertex[35].coordinate[1] = -0.5f;
	vertex[35].coordinate[2] = 0.5f;

	


	/// <summary>
	/// colors 
	/// </summary>
	//front face triangle 1
	vertex[0].color[0] = 0.1f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 0.2f;
	vertex[1].color[1] = 1.0f;
	vertex[1].color[2] = 0.0f;
 
	vertex[2].color[0] = 0.3f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	//front face triangle 2 
	vertex[3].color[0] = 0.4f;
	vertex[3].color[1] = 1.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.5f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.6f;
	vertex[5].color[1] = 1.0f;
	vertex[5].color[2] = 0.0f;
	/// <summary>
	/// ///////////////////////////////////////////////
	/// </summary>

	//right face triangle 1 
	vertex[6].color[0] = 0.1f;
	vertex[6].color[1] = 0.0f;
	vertex[6].color[2] = 1.0f;

	vertex[7].color[0] = 0.2f;
	vertex[7].color[1] = 0.0f;
	vertex[7].color[2] = 1.0f;

	vertex[8].color[0] = 0.3f;
	vertex[8].color[1] = 0.0f;
	vertex[8].color[2] = 1.0f;
	//right face triangle 2 

	vertex[9].color[0] = 0.4f;
	vertex[9].color[1] = 0.0f;
	vertex[9].color[2] = 1.0f;

	vertex[10].color[0] = 0.5f;
	vertex[10].color[1] = 0.0f;
	vertex[10].color[2] = 1.0f;

	vertex[11].color[0] = 0.6f;
	vertex[11].color[1] = 0.0f;
	vertex[11].color[2] = 1.0f;

	/// <summary>
	/// ////////////////////////////////////////////////
	/// </summary>

	//bottom face trinagle 1 
	vertex[12].color[0] = 0.1f;
	vertex[12].color[1] = 1.0f;
	vertex[12].color[2] = 1.0f;

	vertex[13].color[0] = 0.2f;
	vertex[13].color[1] = 1.0f;
	vertex[13].color[2] = 1.0f;

	vertex[14].color[0] = 0.3f;
	vertex[14].color[1] = 1.0f;
	vertex[14].color[2] = 1.0f;

	//bottom face triangle 2 
	vertex[15].color[0] = 0.4f;
	vertex[15].color[1] = 1.0f;
	vertex[15].color[2] = 1.0f;

	vertex[16].color[0] = 0.5f;
	vertex[16].color[1] = 1.0f;
	vertex[16].color[2] = 1.0f;

	vertex[17].color[0] = 0.6f;
	vertex[17].color[1] = 1.0f;
	vertex[17].color[2] = 1.0f;

	/// <summary>
	/// ///////////////////////////////////////////////
	/// </summary>

	//left face trinagle 1
	vertex[18].color[0] = 0.1f;
	vertex[18].color[1] = 0.0f;
	vertex[18].color[2] = 1.0f;

	vertex[19].color[0] = 0.2f;
	vertex[19].color[1] = 0.0f;
	vertex[19].color[2] = 1.0f;

	vertex[20].color[0] = 0.3f;
	vertex[20].color[1] = 0.0f;
	vertex[20].color[2] = 1.0f;

	//left face triangle 2 
	vertex[21].color[0] = 0.4f;
	vertex[21].color[1] = 1.0f;
	vertex[21].color[2] = 0.0f;

	vertex[22].color[0] = 0.5f;
	vertex[22].color[1] = 1.0f;
	vertex[22].color[2] = 0.0f;

	vertex[23].color[0] = 0.6f;
	vertex[23].color[1] = 1.0f;
	vertex[23].color[2] = 0.0f;
	/// <summary>
	/// ////////////////////////////////////////////////
	/// </summary>
	
	//top face trinagle 1
	vertex[24].color[0] = 0.1f;
	vertex[24].color[1] = 0.0f;
	vertex[24].color[2] = 1.0f;

	vertex[25].color[0] = 0.2f;
	vertex[25].color[1] = 0.0f;
	vertex[25].color[2] = 1.0f;

	vertex[26].color[0] = 0.3f;
	vertex[26].color[1] = 0.0f;
	vertex[26].color[2] = 1.0f;

	//top face trinagle 2
	vertex[27].color[0] = 0.4f;
	vertex[27].color[1] = 0.0f;
	vertex[27].color[2] = 1.0f;

	vertex[28].color[0] = 0.5f;
	vertex[28].color[1] = 0.0f;
	vertex[28].color[2] = 1.0f;

	vertex[29].color[0] = 0.6f;
	vertex[29].color[1] = 0.0f;
	vertex[29].color[2] = 1.0f;

	//back face triangle 1
	vertex[30].color[0] = 0.1f;
	vertex[30].color[1] = 1.0f;
	vertex[30].color[2] = 1.0f;

	vertex[31].color[0] = 0.2f;
	vertex[31].color[1] = 1.0f;
	vertex[31].color[2] = 1.0f;

	vertex[32].color[0] = 0.3f;
	vertex[32].color[1] = 1.0f;
	vertex[32].color[2] = 1.0f;

	//back face triangle 2

	vertex[33].color[0] = 0.4f;
	vertex[33].color[1] = 1.0f;
	vertex[33].color[2] = 1.0f;

	vertex[34].color[0] = 0.5f;
	vertex[34].color[1] = 1.0f;
	vertex[34].color[2] = 1.0f;

	vertex[35].color[0] = 0.6f;
	vertex[35].color[1] = 1.0f;
	vertex[35].color[2] = 1.0f;



	//front face triangle 
	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;
	triangles[3] = 3;   triangles[4] = 4;   triangles[5] = 5;

	//right face triangle
	triangles[6] = 6;   triangles[7] = 7;   triangles[8] = 8;
	triangles[9] = 9;   triangles[10] = 10;   triangles[11] = 11;

	//bottom face triangle 
	triangles[12] = 12;   triangles[13] = 13;   triangles[14] = 14;
	triangles[15] = 9;   triangles[16] = 16;   triangles[17] = 17;

	//left face triangle 
	triangles[18] = 18;   triangles[19] = 19;   triangles[20] = 20;
	triangles[21] = 21;   triangles[22] = 22;   triangles[23] = 23;

	//top face triangle
	triangles[24] = 24;   triangles[25] = 25;   triangles[26] = 26;
	triangles[27] = 27;   triangles[28] = 28;   triangles[29] = 29;

	//back face triangle 
	triangles[30] = 30;   triangles[31] = 31;   triangles[32] = 32;
	triangles[33] = 33;   triangles[34] = 34;   triangles[35] = 35;



	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 36, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	cout << "Update up" << endl;

	for (int i = 0; i <= 35; i++) {
		gpp::Vector3f VertexVertex(vertex[i].coordinate[0], vertex[i].coordinate[1], vertex[i].coordinate[2]);

		VertexVertex = gpp::Matrix3f::rotateX(-0.004f) * VertexVertex;
	 	vertex[i].coordinate[0] = VertexVertex.getX();
	 	vertex[i].coordinate[1] = VertexVertex.getY();
	 	vertex[i].coordinate[2] = VertexVertex.getZ();
	}

		for (int i = 0; i <= 35; i++) {
		gpp::Vector3f VertexVertex(vertex[i].coordinate[0], vertex[i].coordinate[1], vertex[i].coordinate[2]);

		VertexVertex = gpp::Matrix3f::rotateZ(-0.004f) * VertexVertex;
	 	vertex[i].coordinate[0] = VertexVertex.getX();
	 	vertex[i].coordinate[1] = VertexVertex.getY();
	 	vertex[i].coordinate[2] = VertexVertex.getZ();
	}
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 36);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

