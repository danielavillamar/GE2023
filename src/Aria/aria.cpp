#include "Aria.h"

#include "constants.h"

#include "Game/Systems/SpriteSystems.h"
#include "Game/Systems/Systems.h"
#include "Systems.h"

Aria::Aria()
  : Game("SAMPLE", SCREEN_WIDTH * SCALE, SCREEN_HEIGHT * SCALE) { }

void Aria::setup() {
  Scene* gameplay = createGamePlayScene();

  setScene(gameplay);
}

Scene* Aria::createGamePlayScene() {
  Scene* scene = new Scene("GAMEPLAY SCENE", r);
  addSetupSystem<PhysicsSetupSystem>(scene);
  addSetupSystem<CharacterSetupSystem>(scene);
  addSetupSystem<TilemapSetupSystem>(scene, renderer);
  addSetupSystem<BulletSetupSystem>(scene);

  addSetupSystem<EnemySetupSystem>(scene, 15, 11);
  addSetupSystem<EnemySetupSystem>(scene, 9, 14);
  addSetupSystem<EnemySetupSystem>(scene, 22, 20);
  addSetupSystem<EnemySetupSystem>(scene, 19, 14);

  addSetupSystem<SpriteSetupSystem>(scene, renderer);
  addUpdateSystem<SpriteUpdateSystem>(scene);
  addSetupSystem<CollisionEventSetupSystem>(scene, collisionEvent);
  addEventSystem<ContactEventSystem>(scene, collisionEvent);
  addUpdateSystem<BulletUpdateSystem>(scene);
  addUpdateSystem<HpCheckUpdateSystem>(scene);
  
  addUpdateSystem<PhysicsUpdateSystem>(scene);
  addUpdateSystem<MovementUpdateSystem>(scene);
  addUpdateSystem<EnemyUpdateSystem>(scene);
  addUpdateSystem<EnemyDeathCheckUpSystem>(scene);
  addUpdateSystem<PlayerMovementUpdateSystem>(scene);
  addEventSystem<PlayerInputSystem>(scene);
  
  addRenderSystem<TilemapRenderSystem>(scene);
  addRenderSystem<SpriteRenderSystem>(scene);
  addRenderSystem<FixtureRenderSystem>(scene);
  return scene;
}
