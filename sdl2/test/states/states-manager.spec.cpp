#include <gtest/gtest.h>

#include "states/states-manager.h"
#include "states/i-state.h"

class FStatesManager : public testing::Test {
	public:
		StatesManager statesManager;
};

TEST_F(FStatesManager, isEmpty) {
	EXPECT_EQ(statesManager.isEmpty(), true);

	statesManager.push(GameState::LEVEL);
	EXPECT_EQ(statesManager.isEmpty(), false);
}

TEST_F(FStatesManager, Push_LastPushShouldBeActiveState) {
	statesManager.push(GameState::LEVEL);
	std::shared_ptr<IState> activeState = statesManager.getActiveState();
	ASSERT_FALSE(activeState == nullptr);
	EXPECT_EQ(activeState->getName(), GameState::LEVEL);

	/*
	statesManager.push(GameState::TITLE_SCREEN);
	activeState = statesManager.getActiveState();
	ASSERT_FALSE(activeState == nullptr);
	EXPECT_EQ(activeState->getName(), GameState::TITLE_SCREEN);
	*/
}
