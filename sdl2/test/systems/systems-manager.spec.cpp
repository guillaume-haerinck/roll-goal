#include <gtest/gtest.h>

#include "systems/systems-manager.h"
#include "systems/i-system.h"

class FSystemsManager : public testing::Test {
	public:
		SystemsManager systemsManager;
};

/* 
TEST_F(FSystemsManager, InitStates_ShouldInitInTheSameOrder) {
	// systemsManager.

	// EXPECT_EQ(statesManager.isEmpty(), false);
}
*/
