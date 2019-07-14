#include <gtest/gtest.h>

#include "states/states-manager.h"
#include "states/i-state.h"

class FStatesManager : public testing::Test {
	public:
		StatesManager statesManager;
};

TEST_F(FStatesManager, Push_ShouldBeActiveState) {
	statesManager.push(GameState::TITLE_SCREEN);
	IState* activeState = statesManager.getActiveState();
	ASSERT_FALSE(activeState == nullptr);
	EXPECT_EQ(activeState->getName(), GameState::TITLE_SCREEN);
}
