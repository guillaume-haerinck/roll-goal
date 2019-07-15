#include <gtest/gtest.h>
#include <vector>

#include "systems/systems-manager.h"
#include "systems/i-system.h"

class FSystemsManager : public testing::Test {
	public:
		SystemsManager systemsManager;
};


TEST_F(FSystemsManager, InitStates_ShouldInitInTheSameOrder) {
	std::vector<System> systemsToInit {
		System::RENDER,
		System::PHYSIC
	};

	systemsManager.initSystems(systemsToInit);
	auto initSystemNames = systemsManager.getInitSystemNames();

	EXPECT_EQ(systemsToInit, initSystemNames);
}

TEST_F(FSystemsManager, InitStates_ShouldEmptyOldStack) {
	std::vector<System> oldSystems {
		System::RENDER
	};
	systemsManager.initSystems(oldSystems);

	std::vector<System> newSystems {
		System::PHYSIC
	};
	systemsManager.initSystems(newSystems);

	auto initSystemNames = systemsManager.getInitSystemNames();
	EXPECT_EQ(newSystems, initSystemNames);
}
