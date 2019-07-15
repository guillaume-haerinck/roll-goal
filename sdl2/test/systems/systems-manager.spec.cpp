#include <gtest/gtest.h>
#include <vector>
#include <entt/entt.hpp>

#include "systems/systems-manager.h"
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

	systemsManager->initSystems(systemsToInit);
	auto initSystemNames = systemsManager->getInitSystemNames();

	EXPECT_EQ(systemsToInit, initSystemNames);
}

TEST_F(SystemsManagerSpec, InitSystems_ShouldEmptyOldStack) {
	std::vector<System> oldSystems {
		System::RENDER
	};
	systemsManager->initSystems(oldSystems);

	std::vector<System> newSystems {
		System::PHYSIC
	};
	systemsManager->initSystems(newSystems);

	auto initSystemNames = systemsManager->getInitSystemNames();
	EXPECT_EQ(newSystems, initSystemNames);
}

TEST_F(SystemsManagerSpec, Clear_ShouldEmptyAll) {
	std::vector<System> systems {
		System::RENDER,
		System::PHYSIC
	};
	systemsManager->initSystems(systems);

	systemsManager->clear();
	auto initSystems = systemsManager->getInitSystemNames();

	EXPECT_EQ(initSystems.size(), 0);
}
