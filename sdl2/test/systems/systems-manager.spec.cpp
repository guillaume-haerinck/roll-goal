#include <gtest/gtest.h>
#include <vector>
#include <entt/entt.hpp>

#include "systems/systems-manager.h"
#include "systems/render-system.h"
#include "systems/physic-system.h"
#include "systems/i-system.h"

class SystemsManagerSpec : public testing::Test {
	public:
		entt::registry registry;
		SystemsManager* systemsManager = new SystemsManager(registry);
};

TEST_F(SystemsManagerSpec, InitSystems_ShouldInitInTheSameOrder) {
	std::vector<System> systemsToInit {
		System::RENDER,
		System::PHYSIC
	};

	systemsManager->push<RenderSystem>();
	systemsManager->push<PhysicSystem>();
	auto initSystemNames = systemsManager->getInitSystemNames();

	EXPECT_EQ(systemsToInit, initSystemNames);
}
