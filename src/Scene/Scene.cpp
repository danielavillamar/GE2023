#include <string>
#include <SDL.h>
#include <print.h>

#include "Scene.h"

#include "ECS/Entity.h"
#include "ECS/Components.h"
#include "ECS/System.h"


Scene::Scene(const std::string& name, entt::registry& r)
  : name(name), r(r)
{
  world = nullptr;
  mainCamera = nullptr;
  player = nullptr;
}

Scene::~Scene()
{
  print("Scene Destroyed!");
}

Entity* Scene::createEntity(const std::string& name, int x, int y)
{
  /* print("Create entity", name); */
  Entity* entity = new Entity(r.create(), this );
  entity->addComponent<NameComponent>(name);
  entity->addComponent<TransformComponent>(x, y);

  return entity;
}

void Scene::setup()
{
  print("Scene Setup", name);
  
  for (auto sys: setupSystems)
  {
    sys->run();
  }
}

void Scene::update(double dT)
{
  // print("Scene Update");
  
  for (auto sys: updateSystems)
  {
    sys->run(dT);
  }
}

void Scene::render(SDL_Renderer* renderer)
{
  // print("Scene Render");
  
  for (auto sys: renderSystems)
  {
    sys->run(renderer);
  }
}

void Scene::processEvents(SDL_Event event)
{
  // print("Scene Events");
  
  for (auto sys: eventSystems)
  {
    sys->run(event);
  }
}

