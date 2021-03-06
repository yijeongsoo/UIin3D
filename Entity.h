#pragma once
#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1

#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "Mesh.h"

enum EntityType { NONE, PLAYER, PLATFORM, ENEMY, CUBE, FLOOR, BOX };

class Entity {
public:
    EntityType entityType;
    
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 rotation;
    glm::vec3 scale;
    
    float speed;
    Mesh* mesh;

    bool billboard;
    float width;
    float height;
    float depth;
    

    GLuint textureID;
    
    glm::mat4 modelMatrix;
    
    Entity();
    
    bool CheckCollision(Entity* other);
    void Update(float deltaTime, Entity* player, Entity* objects, int objectCount);
    void DrawBillboard(ShaderProgram* program);
    void Render(ShaderProgram *program);
};



